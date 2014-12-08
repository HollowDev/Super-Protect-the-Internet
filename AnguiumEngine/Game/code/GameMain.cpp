#include "GameDefines.h"
#include "TestState.h"

#include "Projectile.h"

s32 FindIndexInArray1( GameObject* _start, GameObject* _toFind, s32 _size );
s32 FindIndexInArray2( Projectile* _start, Projectile* _toFind, s32 _size );

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

/*

	//static GameObject* classType##Cast(GameObject**_obj1,GameObject*_obj2)	\
	//{ return ((classType*)*_obj1) = &(classType*)&_obj2; }					\
*/


s32 FindIndexInArray1( GameObject* _start, GameObject* _toFind, s32 _size )
{
	return ((s32)_toFind - (s32)_start) / _size;
}

s32 FindIndexInArray2( Projectile* _start, Projectile* _toFind, s32 _size )
{
	return ((s32)_toFind - (s32)_start) / _size;
}