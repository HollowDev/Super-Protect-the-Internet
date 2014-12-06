#include "Player.h"

Player::Player( void )
{
	m_RenderObject = new RenderObject();
}

Player::~Player( void )
{
}

void Player::Release( void )
{
	SAFE_DELETE( m_RenderObject );
}

void Player::Launch( void )
{
	GameObject::Launch();

	m_RenderObject->SetTexID( 0 ); // The id of the last texture loaded... HAXXORS YAY
	m_RenderObject->SetDrawOrder( 2 );

	g_Renderer->RegisterRenderObject( m_RenderObject );
}

void Player::Exit( void )
{
	GameObject::Exit();
	
	g_Renderer->UnregisterRenderObject( m_RenderObject );
}

void Player::Update( f32 _timing )
{
}
