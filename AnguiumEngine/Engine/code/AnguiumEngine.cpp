/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Anguium Engine
	Desc: Main include for use in games as well as the precompiled header
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "AnguiumEngine.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Global controls and object
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
GameObjectFactory*	g_ObjectFactory = nullptr;
GameObjectManager*	g_ObjectManager = nullptr;
GameControl*		g_GameControl	= nullptr;
D3D9Handler*		g_D3D9Handler	= nullptr;
AssetPool*			g_AssetPool		= nullptr;
Renderer*			g_Renderer		= nullptr;
Timer*				g_Timer			= nullptr;

f32 g_AspectRatio		= 0.0f;
u32 g_BackBufferWidth	= 0;
u32 g_BackBufferHeight	= 0;
bool g_EnableVsync		= true;

void AnguiumEngineLaunch( const wchar_t* _title, u32 _width, u32 _height, GameState* _startState )
{
	g_ObjectFactory = new GameObjectFactory();
	g_ObjectManager = new GameObjectManager();
	g_GameControl	= new GameControl();
	g_D3D9Handler	= new D3D9Handler();
	g_AssetPool		= new AssetPool();
	g_Renderer		= new Renderer();
	g_Timer			= new Timer();
	
	g_ObjectFactory->Launch(); // launch here, not in constructor
	g_GameControl->Initialize( _title, _width, _height, _startState );
	g_D3D9Handler->Launch( g_GameControl->GetHWND() );
	g_Renderer->Launch( g_D3D9Handler->m_Device, "assets/effects/textured.fx" );
}

void AnguiumEngineRun( void )
{
	g_GameControl->Run();
}

void AnguiumEngineCleanup( void )
{
	g_ObjectFactory->Release();

	SAFE_DELETE( g_ObjectFactory );
	SAFE_DELETE( g_ObjectManager );
	SAFE_DELETE( g_GameControl );
	SAFE_DELETE( g_D3D9Handler );
	SAFE_DELETE( g_AssetPool );
	SAFE_DELETE( g_Renderer );
	SAFE_DELETE( g_Timer );
}