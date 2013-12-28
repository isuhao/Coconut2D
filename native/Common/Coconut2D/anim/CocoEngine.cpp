#include "CocoEngine.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoEngine::CocoEngine()
{
	__currentState = NULL;
	__nextState = NULL;
	__stateStart = 0.0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoEngineState* CocoEngine::currentState()
{
	return __currentState;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoEngine::setState(CocoEngineState* state)
{
	__nextState = state;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoEngine::tick(WebGLRenderingContext* gl, float time)
{
	if(__nextState != NULL)
	{
		__currentState = __nextState;
		__stateStart = time;
		__nextState = NULL;
	}
	__currentState->tick(this, gl, time - __stateStart);
}