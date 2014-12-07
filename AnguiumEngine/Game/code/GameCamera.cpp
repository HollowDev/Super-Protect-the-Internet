#include "GameCamera.h"
#include "GameDefines.h"

#define FOLLOW_LOCK_DIST	2.0f
#define FOLLOW_SPEED		64.0f

GameCamera::GameCamera( void )
{
}
GameCamera::~GameCamera( void )
{
}

void GameCamera::Launch( Vector2 _startPos )
{	
	Camera::CreateOrthographic( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 );
	m_Pos = -_startPos;
	g_Renderer->SetCamera( this );
}

void GameCamera::Close( void )
{
	g_Renderer->SetCamera( nullptr );
}

void GameCamera::Update( float _timing )
{
	//if( m_Target )
	//	FollowTarget( _timing );
	//
	//if( m_ScreenShake > 0.0f )
	//{
	//	m_ScreenShake -= _timing;
	//	m_Pos += D3DXVECTOR2( sinf( m_TotalTime * 32.0f ) * 128.0f * m_ScreenShake, sinf( -m_TotalTime * 32.0f ) * 128.0f * m_ScreenShake ) * _timing;
	//}
	//
	//m_TotalTime += _timing;
	Camera::Update( _timing );
}

void GameCamera::FollowTarget( float _timing )
{
	//D3DXVECTOR2 toTarget = (m_Target->GetPos() + m_Target->GetDir()*16.0f) + m_Pos;
	//float dist = D3DXVec2Length( &toTarget );
	//
	//// chase down that target
	//D3DXVec2Normalize( &toTarget, &toTarget );
	//m_Pos -= toTarget * dist * 3.0f * _timing;
}
