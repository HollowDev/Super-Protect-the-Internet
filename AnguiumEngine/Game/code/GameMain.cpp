#include "GameDefines.h"
#include "TestState.h"

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
    // Enable run-time memory check for debug builds.
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	#endif
	
	AnguiumEngineLaunch( GAME_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, new TestState() );
	{
		AnguiumEngineRun();
	}
	AnguiumEngineCleanup();

	return 0;
}
