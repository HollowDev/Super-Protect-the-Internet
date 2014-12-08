#include "TestState.h"
#include "GameCamera.h"

#include <AnguiumEngine.h>


#include "Player.h"

TestState::TestState( void )
{
	m_Camera		= nullptr;
}
TestState::~TestState( void )
{
}

void TestState::Launch( void )
{
	m_Camera = new GameCamera();
	m_Camera->Launch( Vector2( 0.0f, 300.0f ) );

	g_AssetPool->AddTexture( L"assets/textures/super_ship_yay.png" );
	g_AssetPool->AddTexture( L"assets/textures/projectile.png" );

	g_Renderer->SetCamera( m_Camera );

	GameObject* player = g_ObjectManager->AddObject( OT_Player );
}

void TestState::Close( void )
{
	SAFE_DELETE( m_Camera );
}

void TestState::Update( float _timing )
{
	m_Camera->Update( _timing );

	g_ObjectManager->Update( _timing );
}