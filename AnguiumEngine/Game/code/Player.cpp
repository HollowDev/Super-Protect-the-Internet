#include "Player.h"

#include "Projectile.h"

Player::Player( void ) :
	hasFired(false),
	fireTimer(0.0f),
	m_RenderObject(nullptr)
{
}

Player::~Player( void )
{
	Release();
}

void Player::Release( void )
{
	GameObject::Release();
	SAFE_DELETE( m_RenderObject );
}

void Player::Launch( void )
{
	GameObject::Launch();
	
	if( m_RenderObject == nullptr )	m_RenderObject = new RenderObject();
	m_RenderObject->SetTexID( 0 ); // The id of the last texture loaded... HAXXORS YAY
	m_RenderObject->SetDrawOrder( 2 );

	g_Renderer->RegisterRenderObject( m_RenderObject );

	hasFired = false;
	fireTimer = 0.0f;
}

void Player::Exit( void )
{
	GameObject::Exit();
	
	g_Renderer->UnregisterRenderObject( m_RenderObject );
}

void Player::Update( f32 _timing )
{
	if( _timing == 0.0f ) return;

	Vector2 scale = Vector2::ZERO;
	Vector2 vel = Vector2::ZERO;
	f32 moveSpeed = 150.0f; // in pixels a second
	f32 scaleSpeed = 1.0f; // in pixels a second
	f32 rotSpeed = AE_DEG_TO_RAD(90.0f); // in pixels a second
	
	// Movemement test
	if( GetAsyncKeyState( 'W' ) )
		vel.y += moveSpeed * _timing;
	else if( GetAsyncKeyState( 'S' ) )
		vel.y -= moveSpeed * _timing;
	
	if( GetAsyncKeyState( 'D' ) )
		vel.x += moveSpeed * _timing;
	else if( GetAsyncKeyState( 'A' ) )
		vel.x -= moveSpeed * _timing;
	
	if( vel.Length() > moveSpeed )
	{
		vel = vel.Normalize();
		vel *= moveSpeed*_timing;
	}
	m_Transform.SetPos( m_Transform.GetPos() + m_Transform.GetDir() * vel.y );

	// Scaling test
	if( GetAsyncKeyState( 'I' ) )
		scale.y += scaleSpeed * _timing;
	else if( GetAsyncKeyState( 'K' ) )
		scale.y -= scaleSpeed * _timing;
	
	if( GetAsyncKeyState( 'L' ) )
		scale.x += scaleSpeed * _timing;
	else if( GetAsyncKeyState( 'J' ) )
		scale.x -= scaleSpeed * _timing;
	
	m_Transform.SetScale( m_Transform.GetScale() + scale );
	
	// Scaling test
	if( GetAsyncKeyState( 'D' ) )
		m_Transform.SetRot( m_Transform.GetRot() + rotSpeed * _timing );
	else if( GetAsyncKeyState( 'A' ) )
		m_Transform.SetRot( m_Transform.GetRot() - rotSpeed * _timing );

	if( GetAsyncKeyState( 'P' ) )
	{
		m_Transform.SetScale( Vector2::ONE );
		m_Transform.SetRot( 0.0f );
	}

	if( GetAsyncKeyState( VK_SPACE ) )
	{
		if( !hasFired )
		{
			Projectile* bullet = reinterpret_cast<Projectile*>( g_ObjectManager->AddObject( OT_Projectile ) );
			bullet->Shoot( m_Transform.GetPos(), m_Transform.GetDir(), moveSpeed+25.0f, 2.5f );
			hasFired = true;
		}
	}
	else
		hasFired = false;

	GameObject::Update( _timing );
	m_RenderObject->SetWorld( m_Transform.GetWorld() );
}
