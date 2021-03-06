﻿/* ***** BEGIN LICENSE BLOCK *****
 *
 * Copyright (C) 2013-2014 www.coconut2D.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * ***** END LICENSE BLOCK ***** */

// ==================================================================================================================================
//	   ______              ______                           __                ____  __            _
//	  / ____/__    __     / ____/__  ____  ___  _________ _/ /_____  _____   / __ \/ /_  ______ _(_)___
//	 / /  __/ /___/ /_   / / __/ _ \/ __ \/ _ \/ ___/ __ `/ __/ __ \/ ___/  / /_/ / / / / / __ `/ / __ \
//	/ /__/_  __/_  __/  / /_/ /  __/ / / /  __/ /  / /_/ / /_/ /_/ / /     / ____/ / /_/ / /_/ / / / / /
//	\____//_/   /_/     \____/\___/_/ /_/\___/_/   \__,_/\__/\____/_/     /_/   /_/\__,_/\__, /_/_/ /_/
//	                                                                                    /____/
// ==================================================================================================================================
// This code transforms an AST to C++ .hpp and .cpp files.
// Since CocoScript is strongly typed and very similar to C++, the generation is straight forward.
// The generated code is used by Coconut2D IDE in conjunction with the Coconut2D Device Wrappers.
// Please send bugs/suggestions to elias.politakis@mobilefx.com

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
function CompilerCppPlugin(compiler)
{
	var _this = this._this = compiler;

	_this.classList 	= {};
	_this.in_setter 	= false;
	_this.in_event_call = false;
	_this.NULL_GEN 		= { CPP:"", HPP:"" };
	_this.currClass 	= null;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_this.cpp_types =
	{
		"Boolean"	: { "default": "false" },
		"Function"	: {	"default": "NULL" },
		"Null"		: { "default": "NULL" },
		"Number"	: {	"default": "0" },
		"Float"		: { "default": "0.0" },
		"Integer"	: { "default": "0" },
		"Object"	: { "default": "nullptr" },
		"String"	: { "default": '""' }
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Add * to subtype in an Array vartype.
	// eg. "Array<Object>" to "Array<Object*>"
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_this.VTCPP = function(vartype)
	{
		if(vartype.charAt(vartype.length-1)!='>') return vartype;
		var subtype = /<(\w+)(?:\*)*>/.exec(vartype)[1];
		if(_this.isPointer(subtype)) subtype+="*";
		return "Array<" + subtype + ">";
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_this.generate_cpp = function(ast)
	{
		var _this = this, CPP = [], HPP = [], ast = ast || _this.ast;

		var generate_cpp = function()
		{
			return _this.generate_cpp.apply(_this, Array.prototype.slice.call(arguments,0));
		};

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		switch(ast.type)
		{
		// ==================================================================================================================================
		//	    _   _____    __  ______________ ____  ___   ____________
		//	   / | / /   |  /  |/  / ____/ ___// __ \/   | / ____/ ____/
		//	  /  |/ / /| | / /|_/ / __/  \__ \/ /_/ / /| |/ /   / __/
		//	 / /|  / ___ |/ /  / / /___ ___/ / ____/ ___ / /___/ /___
		//	/_/ |_/_/  |_/_/  /_/_____//____/_/   /_/  |_\____/_____/
		//
		// ==================================================================================================================================
		/*@@ NAMESPACE @@*/

		case jsdef.NAMESPACE:
			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
			break;

		// ==================================================================================================================================
		//	   _____ __                  __
		//	  / ___// /________  _______/ /_
		//	  \__ \/ __/ ___/ / / / ___/ __/
		//	 ___/ / /_/ /  / /_/ / /__/ /_
		//	/____/\__/_/   \__,_/\___/\__/
		//
		// ==================================================================================================================================
		/*@@ STRUCT @@*/

		case jsdef.STRUCT:

			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;

			var items = [];
			var clone = [];
			for(item in ast)
			{
				if(!isFinite(item)) break;
				var field =  ast[item];
				items.push("\t" + field.vartype + (field.pointer ? "*" : "") + " " + field.name + ";");
				var value = field.symbol.value;
				if(value==null) value = "nullptr";
				if(value=='""') value = 'String("")';
				clone.push( "\t\t" + field.name + " = T->" + field.name + ";");
			}
			items.push("\t" + ast.name + "()\n\t{\n\t};");
			items.push("\t" + ast.name + "(" + ast.name + "* T)\n\t{\n" + clone.join("\n") + "\n\t};");
			HPP.push("struct " + ast.name + "\n{\n" + items.join("\n") + "\n\t};");

			// Push code into native file node
			var native_file = _this.native_files[ast.symbol.file];
			native_file.hpp.body.push(formatCPP(HPP.join("")));
			native_file.cpp.body.push(formatCPP(CPP.join("")));
			break;

		// ==================================================================================================================================
		//	   ________
		//	  / ____/ /___ ___________
		//	 / /   / / __ `/ ___/ ___/
		//	/ /___/ / /_/ (__  |__  )
		//	\____/_/\__,_/____/____/
		//
		// ==================================================================================================================================
		/*@@ CLASS @@*/

		case jsdef.INTERFACE:
		case jsdef.CLASS:

			if(!ast.scope) return _this.NULL_GEN;
			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;

		 	_this.currClassName = ast.name;

			// Add class to class list
		 	if(ast.file!="externs.jspp")
		 		_this.classList[ast.name] = ast;

			var ext = [];
			if(ast.symbol.base) ext.push("public " + ast.symbol.base + (ast.symbol.subtype ? ("<" + ast.symbol.subtype + (_this.isPointer(ast.symbol.subtype) ? "*" : "") + ">") : ""));
			for(var i = 0; i < ast.symbol.interfaces.length; i++)
				ext.push("public " + ast.symbol.interfaces[i]);

			HPP.push("class " + ast.name + (ext.length ? " : " + ext.join(",") : "") + "\n{\npublic:\n");

			var result;

			for(var item in ast.body)
			{
				if(!isFinite(item)) break;
				if(ast.body[item].type==jsdef.FUNCTION && ast.body[item].name=="Constructor")
				{
					ast.isConstructor = ast.body[item];
					break;
				}
			}

			for(var item in ast.body)
			{
				if(!isFinite(item)) break;
				switch(ast.body[item].type)
				{
				case jsdef.CONST:
					result = generate_cpp(ast.body[item]);
					HPP.push(result.HPP);
					break;
				case jsdef.ENUM:
					result = generate_cpp(ast.body[item]);
					HPP.push(result.HPP);
					break;
				case jsdef.VAR:
				case jsdef.EVENT:
					result = generate_cpp(ast.body[item]);
					CPP.push(result.CPP);
					HPP.push(result.HPP);
					break;
				}
			}

			for(var item in ast.body)
			{
				if(!isFinite(item)) break;
				switch(ast.body[item].type)
				{
				case jsdef.PROPERTY:
				case jsdef.STATE:
				case jsdef.FUNCTION:
					result = generate_cpp(ast.body[item]);
					if(result.CPP) CPP.push(result.CPP);
					if(result.HPP) HPP.push(result.HPP);
					break;
				}
			}

			/*@@ CLASS:EVENTS @@*/

			// Create events dispatch static function with dispatch switch.
			if(!ast.interface && _this.implementsInterface(ast.symbol, "IEventListener"))
			{
				// ==================================================================
				// Create event handler Dispatch ID constants
				// ==================================================================
				var classSymbol = ast.symbol;
				var list = [].concat(classSymbol.__event_bindings).concat(classSymbol.__event_unbindings);
				for(i=0;i<list.length;i++)
				{
					var event_ast = list[i];
					var ebd = event_ast.__event_descriptor;
					_this.native_files['Constants.jspp'].hpp.dispIds[ebd.uid] = "#define " + ebd.uid + " " + ebd.id;
				}

				// ==================================================================
				// Create dispatchEvent function
				// ==================================================================

				var local_handler = "dispatchEvent(CocoEvent* Event)";

				HPP.push("virtual void " + local_handler + ";");

				CPP.push("\n////////////////////////////////////////////////////////////////////////////////////////////////////\n");
				CPP.push("void " + ast.name + "::" + local_handler + "\n{");

				var hasDispIds = false;
				for(var uid in classSymbol.__event_descriptors) { hasDispIds=true; break; };

				if(hasDispIds)
				{

					CPP.push("\tfor(int i = __eventListeners->size() - 1; i>=0; i--)\n\t{\n\t\tCocoEventConnectionPoint* cp = (*__eventListeners)[i];\n");
					CPP.push("\t\tif(cp->Event->is(Event))\n\t\t{\n\t\tbool cancel = false;");

					// Create dispatch switch:

					CPP.push("switch(cp->DispID)\n{");
					{
						for(var uid in classSymbol.__event_descriptors)
						{
							var ebd = classSymbol.__event_descriptors[uid];
							CPP.push("case " + ebd.uid+ ":\n{\n");
							{
								CPP.push(ebd.event_listener.name + "* L = reinterpret_cast<"+ebd.event_listener.name+"*>(cp->Listener);");
								CPP.push("//Event Listener\n");

								CPP.push(ebd.event_handler.paramsList[0].vartype + "* S = reinterpret_cast<"+ebd.event_handler.paramsList[0].vartype+"*>(this);");
								CPP.push("//Event Source type-casted to what event handler argument needs\n");

								CPP.push(ebd.event_symbol.name + "* E = reinterpret_cast<"+ebd.event_symbol.name+"*>(Event);");
								CPP.push("//Event object type-casted to what event handler argument needs\n");

								// Collect event handler flat arguments
								var flat_arguments = [];
								for(j=2;j<ebd.event_handler.paramsList.length;j++)
								{
									var event_parm = ebd.event_handler.paramsList[j];
									flat_arguments.push("E->"+event_parm.name);
									CPP.push(event_parm.vartype + " " + event_parm.name + " = E->" + event_parm.name + ";");
								}
								flat_arguments = (flat_arguments.length>0 ? ", " + flat_arguments.join(", ") : "");

								// Make the call to the event handler
								CPP.push("cancel = L->" + ebd.event_handler.name + "(S,E"+flat_arguments+");");

							}
							CPP.push("}\n");
							CPP.push("break;\n");
						}
						CPP.push("}\n");
					}

					CPP.push("\tif(cancel)\n\t{\n\t\tcp->Event->cancelBubble();\n\t}\n\tif(cp->Event->stopPropagation)\n\t{\n\t\treturn;\n\t}\n}\n}");
				}

				// Call base class dispatchEvent
				if(classSymbol.baseSymbol.name!="CocoEventSource")
					CPP.push(classSymbol.baseSymbol.name + "::dispatchEvent(Event);\n");

				CPP.push("}\n");
			}

			HPP.push("};\n");

			_this.currClassName = null;

			// Push code into native file node
			var native_file = _this.native_files[ast.symbol.file];
			native_file.hpp.body.push(formatCPP(HPP.join("")));
			native_file.cpp.body.push(formatCPP(CPP.join("")));
			break;

		// ==================================================================================================================================
		//	    ______                 __  _
		//	   / ____/_  ______  _____/ /_(_)___  ____
		//	  / /_  / / / / __ \/ ___/ __/ / __ \/ __ \
		//	 / __/ / /_/ / / / / /__/ /_/ / /_/ / / / /
		//	/_/    \__,_/_/ /_/\___/\__/_/\____/_/ /_/
		//
		// ==================================================================================================================================
		/*@@ FUNCTION @@*/

		case jsdef.FUNCTION:

			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
			if(!_this.currClassName) return _this.NULL_GEN;

			if(!ast.returntype) ast.returntype = "void";
			var name = (ast.isConstructor ? _this.currClassName : (ast.isDestructor ? "~" + _this.currClassName : ast.name ));
			var param, cppParamsList = "(", hppParamList = "(";

			for(var i=0; i<ast.paramsList.length; i++)
			{
				param = ast.paramsList[i];
				cppParamsList += _this.VTCPP(param.vartype) + (param.pointer ? "*" : "") + " " + param.name;
				var def = (_this.cpp_types.hasOwnProperty(param.vartype) ? _this.cpp_types[param.vartype].default : "nullptr");
				hppParamList += _this.VTCPP(param.vartype) + (param.pointer ? "*" : "") + " " + param.name + (param.optional ? "=" + def : "");
				if(i!=ast.paramsList.length-1)
				{
					cppParamsList +=", ";
					hppParamList +=", ";
				}
			}

			// Rest arguments
			if(ast.symbol.restArguments)
			{
				hppParamList+=", ...";
				cppParamsList+=", ...";
			}

			cppParamsList += ")";
			hppParamList += ")";

			var fn = (ast.static ? "static " :"") + (ast.symbol.virtual ? "virtual " : "") + (ast.isConstructor || ast.isDestructor ? "" : ast.returntype + (ast.pointer ? "*" : "") + " ") + name + hppParamList + (ast.symbol.abstract ? "=0":"") +";";
			HPP.push(fn);

			if(!ast.symbol.abstract && ast.inClass && !ast.inClass.symbol.interface)
			{
		        CPP.push("\n////////////////////////////////////////////////////////////////////////////////////////////////////\n");
				CPP.push( (ast.isConstructor || ast.isDestructor ? "" : ast.returntype +(ast.pointer?"*":"") + " ") + _this.currClassName+"::" + (_this.in_state ? ast.symbol.scope.parentScope.ast.name + "::" : "") + name + cppParamsList);

				if(ast.isConstructor && ast.inClass.base_init)
				{
					var baseConstructorArguments = [];
					for(var item in ast.inClass.base_init[1])
					{
						if(!isFinite(item)) break;
						var arg = ast.inClass.base_init[1][item];
						if(arg.type==jsdef.IDENTIFIER)
						{
							baseConstructorArguments.push(arg.value);
						}
						else
						{
							var gen = _this.generate_cpp(arg);
							baseConstructorArguments.push(gen.CPP);
						}
					}
					CPP.push(" : " + ast.inClass.extends + "(" + formatCPP(baseConstructorArguments.join(",")) + ")");
				}

		        CPP.push("\n{\n");

		        if(ast.isConstructor)
		        {
		        	for(item in ast.inClass.symbol.events)
		        	{
		        		var ev = ast.inClass.symbol.events[item];
		        		CPP.push("this->"+ev.runtime+" = new " + ev.vartype+";");
		        	}
		        }

		        if(ast.isDestructor)
		        {
		        	for(item in ast.inClass.symbol.events)
		        	{
		        		var ev = ast.inClass.symbol.events[item];
		        		var id = "this->"+ev.runtime;
		        		CPP.push("if(" + id + ") " + id + " = (delete " + id + ", nullptr);");
		        	}
		        }
		        if(ast.body)
					CPP.push(generate_cpp(ast.body).CPP);

				CPP.push("}\n");
			}

			break;

		// ==================================================================================================================================
		//	 _    __           _       __    __
		//	| |  / /___ ______(_)___ _/ /_  / /__  _____
		//	| | / / __ `/ ___/ / __ `/ __ \/ / _ \/ ___/
		//	| |/ / /_/ / /  / / /_/ / /_/ / /  __(__  )
		//	|___/\__,_/_/  /_/\__,_/_.___/_/\___/____/
		//
		// ==================================================================================================================================
		/*@@ VAR @@*/

		case jsdef.VAR:
		case jsdef.CONST:

			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
	        var isConst = (ast.type == jsdef.CONST);

			// Var as class member
			if(ast.inClass && !ast.inFunction && !ast.scope.isState)
			{
				for(i=0;i<ast.length;i++)
				{
					if(isConst)
					{
						val = "const " + vartype(ast[i]) + ast[i].name + initializer(ast[i]) + ";";
						HPP.push(val);
					}
					else if(ast.static)
					{
						// static var needs to be defined in .cpp as well
						val = vartype(ast[i]) + _this.currClassName + "::" + ast[i].name + ";";
						CPP.push(val);

						val = "static " + (isConst ? "constexpr " : "") + vartype(ast[i]) + ast[i].name + ";";
						HPP.push(val);
					}
					else
					{
						val = vartype(ast[i]) + ast[i].name + ";";
						HPP.push(val);
					}
				}
			}

			// Var in state
			else if(ast.scope.isState)
			{
				HPP.push(vartype(ast[0]));
				for(i=0;i<ast.length;i++)
				{
					val = ast[i].name + initializer(ast[i]) + (i<ast.length-1 ? ", " : "");
					HPP.push(val);
				}
				HPP.push(";");
			}

			// Var in function
			else if(ast.inFunction)
			{
				CPP.push(vartype(ast[0]));
				for(i=0;i<ast.length;i++)
				{
					val = ast[i].name + initializer(ast[i]) + (i<ast.length-1 ? ", " : "");
					CPP.push(val);
				}
				CPP.push(";");
			}

			// Var in global
			else
			{
				for(i=0;i<ast.length;i++)
				{
					val = "#define " + ast[i].name + " " + initializer(ast[i]).replace("=", "");
					_this.native_files['Constants.jspp'].hpp.constants[ast[i].name] = val;
				}
			}

			//==================================================================
			// Return vartype in C++ form and handle typed-arrays
			function vartype(vitem)
			{
				return _this.VTCPP(vitem.vartype) + (vitem.pointer ? "* " : " ");
			}

			//==================================================================
			// Get value initializer or default value
			function initializer(vitem)
			{
				var init;
				if(vitem.initializer)
				{
					return " = " + generate_cpp(vitem.initializer).CPP;
				}
				else
				{
					var vartype = vitem.vartype;
					if(vartype && vartype.indexOf("<")!=-1)
						vartype = vartype.substr(0, vartype.indexOf("<"));
					if(_this.cpp_types.hasOwnProperty(vartype))
						return " = " + _this.cpp_types[vartype].default;
					else if(ast.scope.isClass)
						return " = nullptr";
					else
						return "";
				}
			}

			break;

		// ==================================================================================================================================
		//	   ______      ______               __      ____       _____       _ __  _
		//	  / ____/___ _/ / / /_  ____ ______/ /__   / __ \___  / __(_)___  (_) /_(_)___  ____
		//	 / /   / __ `/ / / __ \/ __ `/ ___/ //_/  / / / / _ \/ /_/ / __ \/ / __/ / __ \/ __ \
		//	/ /___/ /_/ / / / /_/ / /_/ / /__/ ,<    / /_/ /  __/ __/ / / / / / /_/ / /_/ / / / /
		//	\____/\__,_/_/_/_.___/\__,_/\___/_/|_|  /_____/\___/_/ /_/_/ /_/_/\__/_/\____/_/ /_/
		//
		// ==================================================================================================================================
		/*@@ CALLBACK @@*/

		case jsdef.CALLBACK:

			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
			break;

		// ==================================================================================================================================
		//	    ______                 __
		//	   / ____/   _____  ____  / /______
		//	  / __/ | | / / _ \/ __ \/ __/ ___/
		//	 / /___ | |/ /  __/ / / / /_(__  )
		//	/_____/ |___/\___/_/ /_/\__/____/
		//
		// ==================================================================================================================================
		/*@@ EVENT @@*/

		case jsdef.EVENT:

			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
			if(!_this.currClassName) return _this.NULL_GEN;

			// Define event class
			HPP.push("// Event " + _this.currClassName + "::" + ast.event_class_symbol.runtime + "\nclass " + ast.event_class_symbol.name + " : public CocoEvent\n{\npublic:\n");

			// Event params
			for(item in ast.event_class_symbol.vars)
			{
				var field = ast.event_class_symbol.vars[item].ast;
				HPP.push("\n\t"+ _this.VTCPP(field.vartype) + " " + field.name +";");
			}

			// Event constructor and initialization of params
			HPP.push(ast.event_class_symbol.name + "() : CocoEvent(\"" + ast.symbol.name + "\", true, true)\n{");
			for(item in ast.event_class_symbol.vars)
			{
				var field = ast.event_class_symbol.vars[item].ast;
				HPP.push(field.name + " = " + (_this.cpp_types.hasOwnProperty(field.vartype) ? _this.cpp_types[field.vartype].default : "nullptr") + ";");
			}
			HPP.push("\n}");

			HPP.push("\n};\n");

			// Add event class to hpp file
			_this.native_files[ast.file].hpp.body.insert(0, formatCPP(HPP.join("")));

			// Declare an event object in the class
			HPP=[];
			HPP.push(ast.event_class_symbol.name + "* " + ast.symbol.name +"; // Event\n");
			break;

		// ==================================================================================================================================
		//	    ______
		//	   / ____/___  __  ______ ___  _____
		//	  / __/ / __ \/ / / / __ `__ \/ ___/
		//	 / /___/ / / / /_/ / / / / / (__  )
		//	/_____/_/ /_/\__,_/_/ /_/ /_/____/
		//
		// ==================================================================================================================================
		/*@@ ENUM @@*/

		case jsdef.ENUM:

			if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;

			HPP.push("\nenum " + ast.name + " {\n");
			var firstItem = true;
			for(item in ast)
			{
				if(!isFinite(item)) break;
				if(!firstItem) HPP.push("," + "\n");
				HPP.push(ast[item].name + " = " + ast[item].value);
				firstItem = false;
			}
			HPP.push("\n};\n");

			// Push code into native file node
			var native_file = _this.native_files[ast.symbol.file];
			native_file.hpp.body.push(formatCPP(HPP.join("")));
			native_file.cpp.body.push(formatCPP(CPP.join("")));
			break;

		// ==================================================================================================================================
		//	    ____                             __
		//	   / __ \_________  ____  ___  _____/ /___  __
		//	  / /_/ / ___/ __ \/ __ \/ _ \/ ___/ __/ / / /
		//	 / ____/ /  / /_/ / /_/ /  __/ /  / /_/ /_/ /
		//	/_/   /_/   \____/ .___/\___/_/   \__/\__, /
		//	                /_/                  /____/
		// ==================================================================================================================================
		/*@@ PROPERTY @@*/

	    case jsdef.PROPERTY:

	    	if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
	    	if(!_this.currClassName) return _this.NULL_GEN;

	    	if(ast.getter)
	    	{
				var name = "__get_" + ast.name;
				var ret = (ast.getter.returntype + (ast.getter.pointer ? "*" : "") + " ");
				HPP.push((ast.symbol.virtual ? "virtual " : "") + ret + name + "();");
		        CPP.push("\n////////////////////////////////////////////////////////////////////////////////////////////////////\n");
				CPP.push( ret + _this.currClassName + "::" + (_this.in_state ? ast.symbol.scope.parentScope.ast.name + "::" : "") + name + "()");
		        CPP.push("\n{\n");
				CPP.push(generate_cpp(ast.getter.body).CPP);
				CPP.push("}\n");
	    	}
	    	if(ast.setter)
	    	{
				var name = "__set_" + ast.name;
				var param = "(" + ast.vartype + (ast.pointer?"*":"") + " v)";
				HPP.push((ast.symbol.virtual ? "virtual " : "") + ("void ") + name + param + ";");
		        CPP.push("\n////////////////////////////////////////////////////////////////////////////////////////////////////\n");
				CPP.push( "void " + _this.currClassName + "::" + (_this.in_state ? ast.symbol.scope.parentScope.ast.name + "::" : "") + name + param);
		        CPP.push("\n{\n");
				CPP.push(generate_cpp(ast.setter.body).CPP);
				CPP.push("}\n");
	    	}
	    	break;

		// ==================================================================================================================================
		//	    ___________ __  ___   _____ __        __
		//	   / ____/ ___//  |/  /  / ___// /_____ _/ /____
		//	  / /_   \__ \/ /|_/ /   \__ \/ __/ __ `/ __/ _ \
		//	 / __/  ___/ / /  / /   ___/ / /_/ /_/ / /_/  __/
		//	/_/    /____/_/  /_/   /____/\__/\__,_/\__/\___/
		//
		// ==================================================================================================================================
		/*@@ STATE @@*/

		case jsdef.STATE:

		    if(!ast.EXPORT_NATIVE) return _this.NULL_GEN;
		    if(!_this.currClassName || !ast.scope) return _this.NULL_GEN;

		    _this.in_state = true;

			HPP.push("struct " + ast.name + " : State {");
			HPP.push(_this.currClassName + "* self;");
			CPP.push("\n\n//=======================================================\n");
			CPP.push("// State: " + ast.name + "\n");
			CPP.push("//=======================================================\n");
			var result;
			for(var item in ast.body)
			{
				if(!isFinite(item)) break;
				switch(ast.body[item].type)
				{
				case jsdef.CONST:
				case jsdef.VAR:
					result = generate_cpp(ast.body[item]);
					HPP.push(result.HPP);
					break;
				}
			}
			HPP.push(ast.name + "(" + _this.currClassName + "* self) : self(self) {}\n");
			for(var item in ast.body)
			{
				if(!isFinite(item)) break;
				switch(ast.body[item].type)
				{
				case jsdef.FUNCTION:
					result = generate_cpp(ast.body[item]);
					HPP.push(result.HPP);
					CPP.push(result.CPP);
					break;
				}
			}
			HPP.push("} *" + ast.name + " = new struct " + ast.name + "(this);");

	        _this.in_state = false;
			break;

		// ==================================================================================================================================
		//	    ____    __           __  _ _____
		//	   /  _/___/ /__  ____  / /_(_) __(_)__  _____
		//	   / // __  / _ \/ __ \/ __/ / /_/ / _ \/ ___/
		//	 _/ // /_/ /  __/ / / / /_/ / __/ /  __/ /
		//	/___/\__,_/\___/_/ /_/\__/_/_/ /_/\___/_/
		//
		// ==================================================================================================================================
		/*@@ IDENTIFIER @@*/

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.SUPER:
			if(_this.currClassName && _this.classList[_this.currClassName] && _this.classList[_this.currClassName].extends)
			{
				CPP.push(_this.classList[_this.currClassName].extends);
			}
			else
			{
				CPP.push("super");
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.THIS:
			if(_this.currClassName && ast.inDot && ast.inDot.identifier_first == ast && ast.inDot.identifier_last.symbol.type == jsdef.FUNCTION && ast.inDot.identifier_last.symbol.virtual)
			{
				CPP.push(_this.currClassName);
			}
			else
			{
				CPP.push(_this.in_state ? "self" : "this");
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.IDENTIFIER:

			var isProp = false;
			var name = ast.value.replace(/\$\d+/,'');

			if(ast.symbol.delegated)
				CPP.push(ast.symbol.scope.ast.name + "->");

			if(ast.symbol && ast.symbol.type==jsdef.FUNCTION && ast.parent.type==jsdef.LIST)
			{
				CPP.push("&" + ast.symbol.ast.scope.className + "::" + name);
				break;
			}
			else if(ast.symbol && ast.symbol.type == jsdef.PROPERTY)
			{
				CPP.push(_this.in_setter ? "__set_" : "__get_");
				isProp = true;
			}
			else if(_this.in_state)
			{
				if(ast.symbol.ast.parent.scope && ast.symbol.ast.parent.scope.isClass && (ast.parent.type != jsdef.DOT || (ast.parent[0] == ast)))
					CPP.push("self->");
				else if(ast.symbol.ast.parent.parent && ast.symbol.ast.parent.parent.scope && ast.symbol.ast.parent.parent.scope.isClass && (ast.parent.type != jsdef.DOT || (ast.parent[0] == ast)))
					CPP.push("self->");
			}

			if(ast.symbol.static && !ast.symbol.extern && !ast.symbol.enum && !ast.symbol.state && !ast.inDot)
				CPP.push(ast.symbol.scope.className+"::");

			CPP.push(name + (isProp && !_this.in_setter ? "()" : ""));
			break;

		// ==================================================================================================================================
		//	   ______      ____
		//	  / ____/___ _/ / /____
		//	 / /   / __ `/ / / ___/
		//	/ /___/ /_/ / / (__  )
		//	\____/\__,_/_/_/____/
		//
		// ==================================================================================================================================

		case jsdef.SCRIPT:
			var result;
			for(var item in ast)
			{
				if(!isFinite(item)) break;
			    result = generate_cpp(ast[item]);
				HPP.push(result.HPP);
				CPP.push(result.CPP);
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.BLOCK:
			CPP.push("{\n");
			for(var item in ast)
			{
				if(!isFinite(item)) break;
				CPP.push(generate_cpp(ast[item]).CPP);
			}
			CPP.push("}\n");
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.CALLBACK:

			if(!ast.returntype) ast.returntype = "void";

			var name = ast.name;
			var param, ParamList = "(";

			for(var i=0; i < ast.paramsList.length; i++)
			{
				param = ast.paramsList[i];
				ParamList += param.vartype + (_this.isPointer(param.vartype) ? "*" : "");
				if(i!=ast.paramsList.length-1)
					ParamList +=", ";
			}
			ParamList += ")";

			var fn = "typedef " + (ast.returntype + (ast.pointer ? "*" : "") + " ") + "(" + name + ")" + ParamList + ";";
			HPP.push(fn);

			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.CALL:

			if(ast.typecasting)
			{
				var vartype = generate_cpp(ast[0]).CPP;
				if(ast.castToType=="String")
				{
					switch(ast.castFromType)
					{
					case "Float":
					case "Number":
					case "Integer":
						CPP.push("(String(toString(" + generate_cpp(ast[1]).CPP + ")))");
						break;

					case "Boolean":
						CPP.push("(String(" + generate_cpp(ast[1]).CPP + " ? \"true\" : \"false\"))");
						break;

					case "String":
						CPP.push("("+generate_cpp(ast[1]).CPP+")");
						break;
					}
				}
				else
				{
					CPP.push("((");
					CPP.push(vartype + (_this.isPointer(vartype) ? "*":""));
					CPP.push(")");
					CPP.push(generate_cpp(ast[1]).CPP);
					CPP.push(")");
				}
			}
			else
			{
				/*@@ CALL:EVENTS @@*/

				// Dectect if we are registering/unregistering/dispatching an event
				var call_fn = _this.getCallIdentifier(ast);
				_this.in_event_call = (call_fn.__event && (call_fn.value==_this.DISPATCH_EVENT || call_fn.value==_this.ADD_EVENT || call_fn.value==_this.REMOVE_EVENT)) ? call_fn : null;

				// If we are dispatching an event we need to set event parameters
				if(_this.in_event_call && _this.in_event_call.value==_this.DISPATCH_EVENT)
				{
					var list = _this.getCallList(_this.in_event_call);
					var event_symbol = _this.in_event_call.__event_descriptor.event_symbol;
					CPP.push((_this.in_state ? "self" : "this") + "->" + event_symbol.runtime + "->reset();");
					var i=1;
					for(item in event_symbol.vars)
					{
						CPP.push((_this.in_state ? "self" : "this") + "->" + event_symbol.runtime + "->" + item + " = " + generate_cpp(list[i]).CPP + ";\n");
						i++;
					}
				}

				CPP.push(generate_cpp(ast[0]).CPP);
				CPP.push("(");
				CPP.push(generate_cpp(ast[1]).CPP);
				CPP.push(")");

				_this.in_event_call = null;
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/*@@ LIST @@*/

		case jsdef.LIST:
		case jsdef.COMMA:

			// Handle addEventListener, removeEventListener,
			// dispatchEvent for Coconut2D native events.
			if(_this.in_event_call)
			{
				/*@@ LIST:EVENTS @@*/

				switch(_this.in_event_call.value)
				{
				case _this.DISPATCH_EVENT:
					CPP.push(generate_cpp(ast[0]).CPP);
					break;

				case _this.ADD_EVENT:
					var event_descr = _this.in_event_call.__event_descriptor;
					CPP.push(generate_cpp(ast[0]).CPP + ",");
					CPP.push((_this.in_state ? "self" : "this")+",");
					CPP.push(event_descr.uid);
					break;

				case _this.REMOVE_EVENT:
					var event_descr = _this.in_event_call.__event_descriptor;
					CPP.push(generate_cpp(ast[0]).CPP + ",");
					CPP.push((_this.in_state ? "self" : "this")+",");
					CPP.push(event_descr.uid);
					break;
				}
				break;
			}

			for(i=0;i<ast.length;i++)
			{
				if(i>0) CPP.push(", ");
				CPP.push( generate_cpp(ast[i]).CPP);
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.GROUP:
			CPP.push("(");
			for(var item in ast)
			{
				if(!isFinite(item)) break;
				CPP.push(generate_cpp(ast[item]).CPP);
			}
			CPP.push(")");
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.ARRAY_INIT:

			// Case1: new Float32Arra([...])
			// Case2: new CocoSequence(params, [...]) or foo([...])
			// Case3: a = [...]
			// Case4: var x:Array<T> = [...]

			//(*(new Array<CocoClip*>()))(__root);

			var fnSymbol = null;
			var vartype = null;
			var subtype = null;

	        if(ast.parent.parent.type==jsdef.VAR)
	        {
	        	vartype = ast.parent.parent[0].symbol.vartype;
	        	subtype = ast.parent.parent[0].symbol.subtype;
	        }
			else if(ast.parent.type==jsdef.ASSIGN)
			{
				vartype = ast.parent.parent.expression[0].symbol.vartype;
				subtype = ast.parent.parent.expression[0].symbol.subtype;
			}
			else if(ast.parent.type==jsdef.LIST)
			{
				// Get ast index in function call list
				var index = -1;
				for(item in ast.parent)
				{
					if(!isFinite(item)) break;
					index++;
				}

				switch(ast.parent.parent.type)
				{
				case jsdef.CALL:
					switch(ast.inCall[0].type)
					{
					case jsdef.IDENTIFIER:
						fnSymbol = ast.inCall[0].symbol;
						break;
					case jsdef.DOT:
					  	fnSymbol = ast.inCall.inCall[0].identifier_last.symbol;
					  	break;
					}
					break;

				case jsdef.NEW_WITH_ARGS:
					for(item in ast.parent.parent[0].symbol.methods)
					{
						if(item=="Constructor")
						{
							fnSymbol = ast.parent.parent[0].symbol.methods[item];
							break;
						}
					}
					if(!fnSymbol)
					{
						// Float32Array, etc.
						item = ast.parent.parent[0].symbol;
						if(item.name.indexOf("Array")!=-1)
						{
							vartype = "Array<" + item.subtype + (_this.isPointer(item.subtype) ? "*":"") +">";
							subtype = item.subtype;
						}
					}
					break;
				}

				// From function symbol arguments get ast datatype
				if(fnSymbol)
				{
					var arg = fnSymbol.paramsList[index];
					vartype = arg.vartype;
					subtype = arg.subtype;
				}
			}

			vartype = _this.VTCPP(vartype);

			var out=[];
		 	out.push("(new " + vartype.trim()+"())");
			for(var item in ast)
			{
				if(!isFinite(item)) break;
				out.push("->push("+generate_cpp(ast[item]).CPP+")");
			}
			out = out.join("");
			CPP.push(out);
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.OBJECT_INIT:
			CPP.push("{ ");
			var firstItem = true;
			for(var item in ast)
			{
				if(!isFinite(item)) break;
				if(!firstItem) CPP.push(", ");
				ast[item].parent = ast;
				CPP.push(generate_cpp(ast[item]).CPP);
				firstItem=false;
			}
			CPP.push("}");
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.PROPERTY_INIT:
			CPP.push(generate_cpp(ast[0]).CPP + ":");
			CPP.push(generate_cpp(ast[1]).CPP);
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.ASSIGN:
			if(ast[1].type==jsdef.ARRAY_INIT)
			{
				var isEmpty = true;
				for(var i in ast[1])
				{
					if(!isFinite(i)) break;
					isEmpty=false;
					break;
				}
				if(isEmpty) return _this.NULL_GEN;
			}

	     	if(ast[0].symbol && ast[0].symbol.type == jsdef.PROPERTY)
	     	{
	     		if(ast[0].symbol.ast.setter)
	     		{
					_this.in_setter = true;
					CPP.push(generate_cpp(ast[0]).CPP);
					_this.in_setter = false;
					CPP.push("(" + generate_cpp(ast[1]).CPP + ")");
	     		}
	     	}
	     	else if(ast[0].type == jsdef.DOT && ast[0].identifier_last.symbol && ast[0].identifier_last.symbol.type == jsdef.PROPERTY)
			{
				if(ast[0].identifier_last.symbol.ast.setter)
	     		{
					_this.in_setter = true;
					CPP.push(generate_cpp(ast[0]).CPP);
					_this.in_setter = false;
					CPP.push("(" + generate_cpp(ast[1]).CPP + ")");
	     		}
			}
			else
			{
				CPP.push(generate_cpp(ast[0]).CPP);
				CPP.push(ast.value);
				if(ast.value != "=") CPP.push("=");
				CPP.push(generate_cpp(ast[1]).CPP);
			}
			break;

		// ==================================================================================================================================
		//	   ______                ___ __  _                   __
		//	  / ____/___  ____  ____/ (_) /_(_)___  ____  ____ _/ /____
		//	 / /   / __ \/ __ \/ __  / / __/ / __ \/ __ \/ __ `/ / ___/
		//	/ /___/ /_/ / / / / /_/ / / /_/ / /_/ / / / / /_/ / (__  )
		//	\____/\____/_/ /_/\__,_/_/\__/_/\____/_/ /_/\__,_/_/____/
		//
		// ==================================================================================================================================

		case jsdef.IF:
			CPP.push("if(");
			CPP.push(generate_cpp(ast.condition).CPP);
			CPP.push(")\n");
			CPP.push(generate_cpp(ast.thenPart).CPP);
			if(ast.elsePart)
			{
				CPP.push("else ");
				CPP.push(generate_cpp(ast.elsePart).CPP);
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.SWITCH:

			// Detect if the switch should be converted to if
			var type = _this.getTypeName(ast.discriminant);

			ast.__switch_to_if = false;
			switch(type)
			{
				case "Number":
				case "Integer":
				case "Float":
				case "Time":
					break;

				default:
					ast.__switch_to_if = !_this.getClass(type).enum;
					break;
			}

			if(!ast.__switch_to_if)
			{
				CPP.push("switch(" + generate_cpp(ast.discriminant).CPP + "){");
				for(var _case in ast.cases)
				{
					if(!isFinite(_case)) break;
					CPP.push(generate_cpp(ast.cases[_case]).CPP);
					CPP.push("break;");
				}
				CPP.push("}");
			}
			else
			{
				var cond =  generate_cpp(ast.discriminant).CPP;
				for(var i=0; i<ast.cases.length; i++)
				{
					var label = generate_cpp(ast.cases[i].caseLabel).CPP;
					CPP.push("if(" + cond + "==" + label + ") { while(true)");
					CPP.push(generate_cpp(ast.cases[i].statements).CPP);
					CPP.push("}");
					if(i<ast.cases.length-1) CPP.push("else ");
				}
			}
			break;

		case jsdef.CASE:
			CPP.push("case " + generate_cpp(ast.caseLabel).CPP + ":");
			CPP.push(generate_cpp(ast.statements).CPP);
			break;


		// ==================================================================================================================================
		//	    ____              __
		//	   / __/___  _____   / /   ____  ____  ____
		//	  / /_/ __ \/ ___/  / /   / __ \/ __ \/ __ \
		//	 / __/ /_/ / /     / /___/ /_/ / /_/ / /_/ /
		//	/_/  \____/_/     /_____/\____/\____/ .___/
		//	                                   /_/
		// ==================================================================================================================================

		case jsdef.FOR:
			var setupFor = ast.setup ? generate_cpp(ast.setup).CPP : ";";
			setupFor=setupFor.trim();
			CPP.push("for(" + setupFor + (setupFor.slice(-1) == ";" ? "": ";"));
			CPP.push((ast.condition ? generate_cpp(ast.condition).CPP : "") + ";");
			CPP.push((ast.update ? generate_cpp(ast.update).CPP : "") + ")\n");
			CPP.push(generate_cpp(ast.body).CPP);
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.FOR_IN:
			CPP.push("for(" + (ast.iterator.type == jsdef.VAR ?	"auto " + ast.iterator[0].value : ast.iterator.value));
			CPP.push(" : " + (ast.object ? generate_cpp(ast.object).CPP : "") + ")\n");
			CPP.push(generate_cpp(ast.body).CPP);
			break;

		// ==================================================================================================================================
		//	    __  ____                ____
		//	   /  |/  (_)____________  / / /___ _____  ___  ____  __  _______
		//	  / /|_/ / / ___/ ___/ _ \/ / / __ `/ __ \/ _ \/ __ \/ / / / ___/
		//	 / /  / / (__  ) /__/  __/ / / /_/ / / / /  __/ /_/ / /_/ (__  )
		//	/_/  /_/_/____/\___/\___/_/_/\__,_/_/ /_/\___/\____/\__,_/____/
		//
		// ==================================================================================================================================

		case jsdef.STRING:

			switch(ast.value)
			{
			case "#ignore_errors_begin":
			case "#ignore_errors_end":
				break;

			default:
				CPP.push('String("' + ast.value + '")');
			}

			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.TRY:
			CPP.push("try");
			CPP.push(generate_cpp(ast.tryBlock).CPP);
			for(var catchClause in ast.catchClauses)
			{
				if(!isFinite(catchClause)) break;
				CPP.push("catch(" + ast.catchClauses[catchClause].varName + ")");
				CPP.push(generate_cpp(ast.catchClauses[catchClause].block).CPP);
				ast.finallyBlock && CPP.push("finally" + generate_cpp(ast.finallyBlock).CPP);
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.INDEX:
			var out = [];
			var type = ast[0].vartype;
			var pointerAccess = true;// !__isVector(type);
			if(pointerAccess) out.push("(*");
			out.push(generate_cpp(ast[0]).CPP);
			if(pointerAccess) out.push(")");
			out.push("[");
			out.push(generate_cpp(ast[1]).CPP);
			out.push("]");
			CPP.push(out.join(""));
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.DOT:

			CPP.push(generate_cpp(ast[0]).CPP);

			if(ast[1].symbol.static && ast[1].symbol.enum)
			{
				CPP.push("::");
			}
			else if(ast[1].symbol.static && ast[1].symbol.state)
			{
				CPP.push("->");
			}
			else if(ast[1].symbol.static)
			{
				CPP.push("::");
			}
			else if(ast[1].symbol.type==jsdef.FUNCTION && ast[1].symbol.virtual && (ast[0].type==jsdef.SUPER || ast[0].type==jsdef.THIS))
			{
				CPP.push("::");
			}
			else
			{
				CPP.push(_this.isPointer(ast[0].vartype) ? "->" : ".");
			}

			CPP.push(generate_cpp(ast[1]).CPP);
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.DELETE:
			if(ast[0].symbol && ast[0].symbol.pointer)
			{
				var id = generate_cpp(ast[0]).CPP;
				CPP.push("if(" + id + ") " + id + " = (delete " + id + ", nullptr)");
			}
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.DEBUGGER:			CPP.push("assert(false);"); break;
		case jsdef.EXPONENT:			CPP.push("std::pow(" + generate_cpp(ast[0]).CPP + "," + generate_cpp(ast[1]).CPP + ")");break;
		case jsdef.MOD:					CPP.push("(int)" + generate_cpp(ast[0]).CPP); CPP.push("%"); CPP.push("(int)" + generate_cpp(ast[1]).CPP); break;
		case jsdef.THROW:				CPP.push("throw CocoException("); CPP.push(generate_cpp(ast.exception).CPP); CPP.push(");"); break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case jsdef.NEW:
		case jsdef.NEW_WITH_ARGS:
			CPP.push("new ");
			CPP.push(generate_cpp(ast[0]).CPP);

			if(ast.subtype)
			{
				CPP.push("<" + (ast.subtype + (_this.isPointer(ast.subtype) ? "*":"")) + ">");
			}

			CPP.push("(");

			if(ast[1])
				CPP.push(generate_cpp(ast[1]).CPP);

			CPP.push(")");
			break;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		case jsdef.AND:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("&&"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.BITWISE_AND:			CPP.push(generate_cpp(ast[0]).CPP); CPP.push("&"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.BITWISE_NOT:			CPP.push("~"); CPP.push(generate_cpp(ast[0]).CPP); break;
		case jsdef.BITWISE_OR:			CPP.push(generate_cpp(ast[0]).CPP); CPP.push("|"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.BITWISE_XOR:			CPP.push(generate_cpp(ast[0]).CPP); CPP.push("^"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.BREAK:				CPP.push("break;"); break;
		case jsdef.CONTINUE:			CPP.push("continue;"); break;
		case jsdef.DECREMENT:			if(ast.postfix) { CPP.push(generate_cpp(ast[0]).CPP); CPP.push("--"); } else { CPP.push("--"); CPP.push(generate_cpp(ast[0]).CPP); } break;
		case jsdef.DEFAULT:				CPP.push("default:"); CPP.push(generate_cpp(ast.statements).CPP); break;
		case jsdef.DIV:					CPP.push( "(float)(" + generate_cpp(ast[0]).CPP + ")"); CPP.push("/"); CPP.push( "(float)(" + generate_cpp(ast[1]).CPP + ")"); break;
		case jsdef.DO: 					ast.body.isLoop = true; CPP.push("do"); CPP.push(generate_cpp(ast.body).CPP); CPP.push("while(" + generate_cpp(ast.condition).CPP + ");"); break;
		case jsdef.EQ: 					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("==");	 CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.FALSE:				CPP.push("false"); break;
		case jsdef.GE:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push(">=");  CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.GT:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push(">");   CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.HOOK:				CPP.push(generate_cpp(ast[0]).CPP); CPP.push("?"); CPP.push(generate_cpp(ast[1]).CPP); CPP.push(":"); CPP.push(generate_cpp(ast[2]).CPP); break;
		case jsdef.INCREMENT:			if(ast.postfix) { CPP.push(generate_cpp(ast[0]).CPP); CPP.push("++"); } else { CPP.push("++"); CPP.push(generate_cpp(ast[0]).CPP); } break;
		case jsdef.INSTANCEOF: 			CPP.push(generate_cpp(ast[0]).CPP); CPP.push(" instanceof "); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.LABEL:				CPP.push(ast.label + ":"); CPP.push(generate_cpp(ast.statement).CPP); break;
		case jsdef.LE:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("<=");  CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.LSH:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("<<"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.LT:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("<");   CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.MINUS: 				CPP.push(generate_cpp(ast[0]).CPP); CPP.push("-"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.MUL: 				CPP.push(generate_cpp(ast[0]).CPP); CPP.push("*"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.NE:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("!=");	 CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.NOT:					CPP.push("!"); CPP.push(generate_cpp(ast[0]).CPP); break;
		case jsdef.NULL:				CPP.push("nullptr"); break;
		case jsdef.NUMBER:				CPP.push(ast.value); break;
		case jsdef.OR:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push("||"); CPP.push(generate_cpp(ast[1]).CPP);	break;
		case jsdef.PLUS: 				CPP.push(generate_cpp(ast[0]).CPP); CPP.push("+"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.RETURN:				CPP.push("return"); if(ast.value) CPP.push(" " + generate_cpp(ast.value).CPP); CPP.push(";\n"); break;
		case jsdef.RSH:					CPP.push(generate_cpp(ast[0]).CPP); CPP.push(">>"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.STRICT_EQ:			CPP.push(generate_cpp(ast[0]).CPP); CPP.push("=="); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.STRICT_NE:			CPP.push(generate_cpp(ast[0]).CPP);	CPP.push("!="); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.TRUE:				CPP.push("true"); break;
		case jsdef.TYPEOF:				CPP.push("typeof "); CPP.push(generate_cpp(ast[0]).CPP); break;
		case jsdef.UNARY_MINUS:			CPP.push(" -"); CPP.push(generate_cpp(ast[0]).CPP); break;
		case jsdef.UNARY_PLUS:			CPP.push(" +"); CPP.push(generate_cpp(ast[0]).CPP); break;
		case jsdef.URSH:				CPP.push(generate_cpp(ast[0]).CPP); CPP.push(">>"); CPP.push(generate_cpp(ast[1]).CPP); break;
		case jsdef.VOID:				CPP.push("void "); CPP.push(generate_cpp(ast[0]).CPP); break;
		case jsdef.WHILE:				ast.body.isLoop=true; CPP.push("while(" + generate_cpp(ast.condition).CPP + ")"); CPP.push(generate_cpp(ast.body).CPP); break;

		case jsdef.SEMICOLON:
			var expr = (ast.expression ? generate_cpp(ast.expression).CPP : "");
			if(ast.expression && ast.expression[0] && ast.expression[0].type==jsdef.SUPER && ast.expression[1].symbol.type==jsdef.FUNCTION)
			{
				var params = [];
				for(item in ast.inFunction.symbol.paramsList)
				{
					if(!isFinite(item)) break;
					var param = ast.inFunction.symbol.paramsList[item];
					params.push(param.name);
				}
				expr += "(" + params.join(",") + ")";
			}
			if(expr) CPP.push(expr + ";\n");
			break;

		}
		return {CPP:CPP.join(""), HPP:HPP.join("")};
	};
}










/*

//
// The following code type-casts objects according to what the callee function needs.
// This casting is required to obtain compatibility with Interfaces and derivative classes.
//
// Example:
//
// addTickListener needs ITickable:
//
// 		void CocoEngine::addTickListener(ITickable* tickable)
//
// A CocoTickable passes itself casted to ITickable automatically:
//
//		void CocoTickable::RegisterTickable()
//		{
//			engine->addTickListener(((ITickable*)(this)));
//		}
//

if(!isReference && !ast.parent.typecasting)
{
	if(ast.parent[0].identifier_last && ast.parent[0].identifier_last.symbol && !ast.parent[0].identifier_last.symbol.extern)
	{
		if(ast.parent[0].identifier_last.symbol.paramsList.length==ast.length)
		{
			vartype = ast.parent[0].identifier_last.symbol.paramsList[i].vartype;
			if(_this.isPointer(vartype))
			{
				var cls = _this.getClass(vartype);
				if(cls)
				{
					if(cls.interface)
					{
						CPP.push( "((" + vartype + "*)(" + generate_cpp(ast[i]).CPP + "))" );
						continue;
					}
					else if(!_this.isVector(vartype) && !_this.isECMA(vartype))
					{
						//trace("**CASTING: " + vartype);
						CPP.push( "((" + vartype + "*)(" + generate_cpp(ast[i]).CPP + "))" );
						continue;
					}
				}
			}
		}
	}
}
*/