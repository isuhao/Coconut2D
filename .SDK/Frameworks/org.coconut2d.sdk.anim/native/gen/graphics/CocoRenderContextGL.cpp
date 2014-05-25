/* Generated by Coconut2D C++ Compiler from file CocoRenderContextGL.jspp */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CocoRenderContextGL.hpp"
#include "CocoMatrix.hpp"
#include "WebGLRenderingContext.hpp"
#include "HTMLCanvasElement.hpp"
#include "CocoScene.hpp"
#include "HTMLWindow.hpp"
#include "ICocoImageRenderData.hpp"
#include "CocoImage.hpp"
#include "HTMLImageElement.hpp"
#include "CocoTimeline.hpp"
#include "Constants.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoImageRenderDataGL::CocoImageRenderDataGL()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoImageRenderDataGL::~CocoImageRenderDataGL()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoRenderContextGL::CocoRenderContextGL(WebGLRenderingContext* ctx)
{
	gl = ctx;
	__modelViewMatrix = new CocoMatrix();
	__modelViewMatrix->identity();
	__projectionMatrix = new CocoMatrix();
	__glProgram = nullptr;
	__glProgram_Simple = nullptr;
	__glProgram_SimpleWithAlpha = nullptr;
	__glProgram_SaturationWithAlpha = nullptr;
	__vertex_shader_Common = String("attribute vec2 iVecCoords;attribute vec2 iTexCoords;uniform mat4 uProjMat;uniform mat4 uMVMat;uniform vec2 uSprSize;uniform vec2 uSprFrame;uniform vec2 uSprFlip;varying vec2 pTexCoord;void main(void){ gl_Position = uProjMat * uMVMat * vec4(iVecCoords, 0.0, 1.0); pTexCoord = vec2(((abs(iTexCoords.x - uSprFlip.x) + uSprFrame.x) * uSprSize.x), ((abs(iTexCoords.y - uSprFlip.y) + uSprFrame.y) * uSprSize.y));}");
	__fragment_shader_Simple = String("#ifdef GL_ES\nprecision lowp float;\n#endif\nuniform sampler2D uSampler;\nvarying vec2 pTexCoord; \n \nvoid main(void)\n{\n gl_FragColor = texture2D(uSampler, pTexCoord); }");
	__fragment_shader_SimpleWithAlpha = String("#ifdef GL_ES\nprecision lowp float;\n#endif\nuniform sampler2D uSampler;\nuniform float uAlpha;\nvarying vec2 pTexCoord; \n \nvoid main(void)\n{\n vec4 texColor = texture2D(uSampler, pTexCoord);\n gl_FragColor = vec4(texColor.rgb, texColor.a * uAlpha); }");
	__fragment_shader_SaturationWithAlpha = String("#ifdef GL_ES\nprecision lowp float;\n#endif\nuniform sampler2D uSampler;\nuniform vec4 uColor;\nvarying vec2 pTexCoord; \n \nvoid main(void)\n{\n vec4 texColor = texture2D(uSampler, pTexCoord);\n float c = (texColor.r + texColor.g + texColor.b) / 3.0; \n gl_FragColor = vec4((1.0 - uColor.r) * c + texColor.r * uColor.r, (1.0 - uColor.g) * c + texColor.g * uColor.g, (1.0 - uColor.b) * c + texColor.b * uColor.b, texColor.a * uColor.a);}");
	__boundingBoxVertexShader = String("attribute vec2 iVec2Coords;uniform mat4 uProjMat;void main(void){ gl_Position = uProjMat * vec4(iVec2Coords, 0.0, 1.0);}");
	__boundingBoxFragmentShader = String("#ifdef GL_ES\nprecision lowp float;\n#endif\nvoid main(void){ gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);}");
	__boundingBoxProgram = nullptr;
	__boundingBoxBuffer = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoRenderContextGL::~CocoRenderContextGL()
{
	if(__modelViewMatrix)
	{
		__modelViewMatrix = (delete __modelViewMatrix, nullptr);
	}
	if(__projectionMatrix)
	{
		__projectionMatrix = (delete __projectionMatrix, nullptr);
	}
	if(__glProgram_Simple)
	{
		__glProgram_Simple = (delete __glProgram_Simple, nullptr);
	}
	if(__glProgram_SimpleWithAlpha)
	{
		__glProgram_SimpleWithAlpha = (delete __glProgram_SimpleWithAlpha, nullptr);
	}
	if(__glProgram_SaturationWithAlpha)
	{
		__glProgram_SaturationWithAlpha = (delete __glProgram_SaturationWithAlpha, nullptr);
	}
	if(__boundingBoxProgram)
	{
		__boundingBoxProgram = (delete __boundingBoxProgram, nullptr);
	}
	if(__boundingBoxBuffer)
	{
		__boundingBoxBuffer = (delete __boundingBoxBuffer, nullptr);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoRenderContextGL::flush()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoMatrix* CocoRenderContextGL::getModelViewMatrix()
{
	return __modelViewMatrix;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoMatrix* CocoRenderContextGL::getProjectionMatrix()
{
	return __projectionMatrix;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoRenderContextGL::getWidth()
{
	return gl->canvas->width;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoRenderContextGL::getHeight()
{
	return gl->canvas->height;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoRenderContextGL::cls()
{
	__modelViewMatrix->identity();
	gl->clearColor(0, 0, 0, 1);
	gl->clear(gl->COLOR_BUFFER_BIT);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CocoRenderContextGL::ready()
{
	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoRenderContextGL::prepare(CocoScene* scene)
{
	gl->disable(gl->DEPTH_TEST);
	gl->enable(gl->BLEND);
	gl->blendFunc(gl->SRC_ALPHA, gl->ONE_MINUS_SRC_ALPHA);
	gl->disable(gl->CULL_FACE);
	if(window->deviceRotation)
	{
		float c = cos(window->deviceRotation);
		float s = sin(window->deviceRotation);
		float orthoWidth = abs(c * ((float)gl->canvas->width) + s * ((float)gl->canvas->height));
		float orthoHeight = abs(-s * ((float)gl->canvas->width) + c * ((float)gl->canvas->height));
		__projectionMatrix->ortho((float)(-orthoWidth) / (float)(2.0), (float)(orthoWidth) / (float)(2.0), (float)(orthoHeight) / (float)(2.0), (float)(-orthoHeight) / (float)(2.0),  -1.0, 1.0);
		__projectionMatrix->rotateZ(-window->deviceRotation);
	}
	else
	{
		__projectionMatrix->ortho(-((float)(((float)gl->canvas->width)) / (float)(2.0)), (float)(((float)gl->canvas->width)) / (float)(2.0), (float)(((float)gl->canvas->height)) / (float)(2.0),  -((float)(((float)gl->canvas->height)) / (float)(2.0)),  -1.0, 1.0);
	}
	__projectionMatrix->scale(scene->__view_scale, scene->__view_scale);
	__boundingBoxProgram = makeProgram(gl, __boundingBoxVertexShader, __boundingBoxFragmentShader);
	gl->useProgram(__boundingBoxProgram);
	__boundingBoxProgram->GLSLiVec2Coords = gl->getAttribLocation(__boundingBoxProgram, String("iVec2Coords"));
	__boundingBoxProgram->GLSLuProjMat = gl->getUniformLocation(__boundingBoxProgram, String("uProjMat"));
	__boundingBoxBuffer = gl->createBuffer();
	gl->bindBuffer(gl->ARRAY_BUFFER, __boundingBoxBuffer);
	gl->bufferData(gl->ARRAY_BUFFER, new Float32Array((new Array<float> ())->push(0.0)->push(0.0)->push(0.0)->push(0.0)->push(0.0)->push(0.0)->push(0.0)->push(0.0)), gl->DYNAMIC_DRAW);
	__glProgram_Simple = makeProgram(gl, __vertex_shader_Common, __fragment_shader_Simple);
	gl->useProgram(__glProgram_Simple);
	__glProgram_Simple->GLSLiVecCoords = gl->getAttribLocation(__glProgram_Simple, String("iVecCoords"));
	__glProgram_Simple->GLSLiTexCoords = gl->getAttribLocation(__glProgram_Simple, String("iTexCoords"));
	__glProgram_Simple->GLSLuProjMat = gl->getUniformLocation(__glProgram_Simple, String("uProjMat"));
	__glProgram_Simple->GLSLuMVMat = gl->getUniformLocation(__glProgram_Simple, String("uMVMat"));
	__glProgram_Simple->GLSLuSprSize = gl->getUniformLocation(__glProgram_Simple, String("uSprSize"));
	__glProgram_Simple->GLSLuSprFrame = gl->getUniformLocation(__glProgram_Simple, String("uSprFrame"));
	__glProgram_Simple->GLSLuSprFlip = gl->getUniformLocation(__glProgram_Simple, String("uSprFlip"));
	__glProgram_Simple->GLSLuSampler = gl->getUniformLocation(__glProgram_Simple, String("uSampler"));
	gl->enableVertexAttribArray(__glProgram_Simple->GLSLiVecCoords);
	gl->enableVertexAttribArray(__glProgram_Simple->GLSLiTexCoords);
	gl->uniform1i(__glProgram_Simple->GLSLuSampler, 0);
	update(__modelViewMatrix, __glProgram_Simple->GLSLuMVMat);
	update(__projectionMatrix, __glProgram_Simple->GLSLuProjMat);
	__glProgram_SimpleWithAlpha = makeProgram(gl, __vertex_shader_Common, __fragment_shader_SimpleWithAlpha);
	gl->useProgram(__glProgram_SimpleWithAlpha);
	__glProgram_SimpleWithAlpha->GLSLiVecCoords = gl->getAttribLocation(__glProgram_SimpleWithAlpha, String("iVecCoords"));
	__glProgram_SimpleWithAlpha->GLSLiTexCoords = gl->getAttribLocation(__glProgram_SimpleWithAlpha, String("iTexCoords"));
	__glProgram_SimpleWithAlpha->GLSLuProjMat = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uProjMat"));
	__glProgram_SimpleWithAlpha->GLSLuMVMat = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uMVMat"));
	__glProgram_SimpleWithAlpha->GLSLuSprSize = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uSprSize"));
	__glProgram_SimpleWithAlpha->GLSLuSprFrame = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uSprFrame"));
	__glProgram_SimpleWithAlpha->GLSLuSprFlip = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uSprFlip"));
	__glProgram_SimpleWithAlpha->GLSLuSampler = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uSampler"));
	__glProgram_SimpleWithAlpha->GLSLuAlpha = gl->getUniformLocation(__glProgram_SimpleWithAlpha, String("uAlpha"));
	gl->enableVertexAttribArray(__glProgram_SimpleWithAlpha->GLSLiVecCoords);
	gl->enableVertexAttribArray(__glProgram_SimpleWithAlpha->GLSLiTexCoords);
	gl->uniform1i(__glProgram_SimpleWithAlpha->GLSLuSampler, 0);
	update(__modelViewMatrix, __glProgram_SimpleWithAlpha->GLSLuMVMat);
	update(__projectionMatrix, __glProgram_SimpleWithAlpha->GLSLuProjMat);
	__glProgram_SaturationWithAlpha = makeProgram(gl, __vertex_shader_Common, __fragment_shader_SaturationWithAlpha);
	gl->useProgram(__glProgram_SaturationWithAlpha);
	__glProgram_SaturationWithAlpha->GLSLiVecCoords = gl->getAttribLocation(__glProgram_SaturationWithAlpha, String("iVecCoords"));
	__glProgram_SaturationWithAlpha->GLSLiTexCoords = gl->getAttribLocation(__glProgram_SaturationWithAlpha, String("iTexCoords"));
	__glProgram_SaturationWithAlpha->GLSLuProjMat = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uProjMat"));
	__glProgram_SaturationWithAlpha->GLSLuMVMat = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uMVMat"));
	__glProgram_SaturationWithAlpha->GLSLuSprSize = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uSprSize"));
	__glProgram_SaturationWithAlpha->GLSLuSprFrame = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uSprFrame"));
	__glProgram_SaturationWithAlpha->GLSLuSprFlip = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uSprFlip"));
	__glProgram_SaturationWithAlpha->GLSLuSampler = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uSampler"));
	__glProgram_SaturationWithAlpha->GLSLuColor = gl->getUniformLocation(__glProgram_SaturationWithAlpha, String("uColor"));
	gl->enableVertexAttribArray(__glProgram_SaturationWithAlpha->GLSLiVecCoords);
	gl->enableVertexAttribArray(__glProgram_SaturationWithAlpha->GLSLiTexCoords);
	gl->uniform1i(__glProgram_SaturationWithAlpha->GLSLuSampler, 0);
	update(__modelViewMatrix, __glProgram_SaturationWithAlpha->GLSLuMVMat);
	update(__projectionMatrix, __glProgram_SaturationWithAlpha->GLSLuProjMat);
	__glProgram = __glProgram_Simple;
	gl->useProgram(__glProgram);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
WebGLProgram* CocoRenderContextGL::makeProgram(WebGLRenderingContext* gl, String vs, String fs)
{
	WebGLShader* vshader = gl->createShader(gl->VERTEX_SHADER);
	WebGLShader* fshader = gl->createShader(gl->FRAGMENT_SHADER);
	gl->shaderSource(vshader, vs);
	gl->shaderSource(fshader, fs);
	gl->compileShader(vshader);
	gl->compileShader(fshader);
	WebGLProgram* program = gl->createProgram();
	gl->attachShader(program, vshader);
	gl->attachShader(program, fshader);
	gl->linkProgram(program);
	return program;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
ICocoImageRenderData* CocoRenderContextGL::prepareImage(CocoImage* img)
{
	CocoImageRenderDataGL* data = new CocoImageRenderDataGL();
	img->texSize = new Float32Array((new Array<float> ())->push((float)(img->textureCellWidth) / (float)(img->image->naturalWidth))->push((float)(img->textureCellHeight) / (float)(img->image->naturalHeight)));
	data->texture = gl->createTexture();
	gl->bindTexture(gl->TEXTURE_2D, data->texture);
	gl->texImage2D(gl->TEXTURE_2D, 0, gl->RGBA, gl->RGBA, gl->UNSIGNED_BYTE, img->image);
	gl->texParameteri(gl->TEXTURE_2D, gl->TEXTURE_WRAP_S, gl->CLAMP_TO_EDGE);
	gl->texParameteri(gl->TEXTURE_2D, gl->TEXTURE_WRAP_T, gl->CLAMP_TO_EDGE);
	gl->texParameteri(gl->TEXTURE_2D, gl->TEXTURE_MAG_FILTER, gl->LINEAR);
	gl->texParameteri(gl->TEXTURE_2D, gl->TEXTURE_MIN_FILTER, gl->LINEAR_MIPMAP_NEAREST);
	gl->generateMipmap(gl->TEXTURE_2D);
	gl->bindTexture(gl->TEXTURE_2D, nullptr);
	float w2 = (float)(img->textureCellWidth) / (float)(2.0);
	float h2 = (float)(img->textureCellHeight) / (float)(2.0);
	Float32Array* texData = new Float32Array((new Array<float> ())->push(0.0)->push(0.0)->push(-w2)->push(-h2)->push(0.0)->push(1.0)->push(-w2)->push(h2)->push(1.0)->push(0.0)->push(w2)->push(-h2)->push(1.0)->push(1.0)->push(w2)->push(h2));
	data->buffer = gl->createBuffer();
	gl->bindBuffer(gl->ARRAY_BUFFER, data->buffer);
	gl->bufferData(gl->ARRAY_BUFFER, texData, gl->STATIC_DRAW);
	gl->bindBuffer(gl->ARRAY_BUFFER, nullptr);
	if(texData)
	{
		texData = (delete texData, nullptr);
	}
	return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoRenderContextGL::update(CocoMatrix* m, WebGLUniformLocation* ul)
{
	if(!ul)
	{
		return;
	}
	if(m->__dirty)
	{
		m->refresh();
	}
	gl->uniformMatrix4fv(ul, false, m->__data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoRenderContextGL::drawFrame(CocoScene* scene, CocoImage* image, int frame, CocoKeyFrame* KF)
{
	if(!image->renderData)
	{
		return;
	}
	if(setFilter(KF->filter) || __modelViewMatrix->__dirty)
	{
		update(__modelViewMatrix, __glProgram->GLSLuMVMat);
	}
	gl->uniform2f(__glProgram->GLSLuSprSize, (*image->texSize)[0], (*image->texSize)[1]);
	gl->uniform2f(__glProgram->GLSLuSprFrame, (*image->textureGrid)[frame * 2 + 1], (*image->textureGrid)[frame * 2]);
	gl->uniform2f(__glProgram->GLSLuSprFlip, (KF->flipH ? 1.0 : 0.0), (KF->flipV ? 1.0 : 0.0));
	gl->bindBuffer(gl->ARRAY_BUFFER, ((CocoImageRenderDataGL*)image->renderData)->buffer);
	gl->vertexAttribPointer(__glProgram->GLSLiTexCoords, 2, gl->FLOAT, false, 16, 0);
	gl->vertexAttribPointer(__glProgram->GLSLiVecCoords, 2, gl->FLOAT, false, 16, 8);
	gl->bindTexture(gl->TEXTURE_2D, ((CocoImageRenderDataGL*)image->renderData)->texture);
	switch(KF->filter)
	{
		case COCO_FILTER_ENUM::FILTER_INHERIT:
		{
		}
		break;
		case COCO_FILTER_ENUM::FILTER_SIMPLE:
		{
			break;
		}
		break;
		case COCO_FILTER_ENUM::FILTER_SIMPLE_WITH_ALPHA:
		{
			gl->uniform1f(__glProgram->GLSLuAlpha, KF->alpha);
			break;
		}
		break;
		case COCO_FILTER_ENUM::FILTER_SATURATION_WITH_ALPHA:
		{
			gl->uniform4f(__glProgram->GLSLuColor, KF->red, KF->green, KF->blue, KF->alpha);
			break;
		}
		break;
	}
	gl->drawArrays(gl->TRIANGLE_STRIP, 0, 4);
	gl->bindBuffer(gl->ARRAY_BUFFER, nullptr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CocoRenderContextGL::setFilter(int filter)
{
	bool changed = false;
	switch(filter)
	{
		case COCO_FILTER_ENUM::FILTER_INHERIT:
		{
			if(__glProgram != __glProgram_Simple)
			{
				__glProgram = __glProgram_Simple;
				changed = true;
			}
			break;
		}
		break;
		case COCO_FILTER_ENUM::FILTER_SIMPLE:
		{
			if(__glProgram != __glProgram_Simple)
			{
				__glProgram = __glProgram_Simple;
				changed = true;
			}
			break;
		}
		break;
		case COCO_FILTER_ENUM::FILTER_SIMPLE_WITH_ALPHA:
		{
			if(__glProgram != __glProgram_SimpleWithAlpha)
			{
				__glProgram = __glProgram_SimpleWithAlpha;
				changed = true;
			}
			break;
		}
		break;
		case COCO_FILTER_ENUM::FILTER_SATURATION_WITH_ALPHA:
		{
			if(__glProgram != __glProgram_SaturationWithAlpha)
			{
				__glProgram = __glProgram_SaturationWithAlpha;
				changed = true;
			}
			break;
		}
		break;
	}
	if(changed)
	{
		gl->useProgram(__glProgram);
	}
	return changed;
}