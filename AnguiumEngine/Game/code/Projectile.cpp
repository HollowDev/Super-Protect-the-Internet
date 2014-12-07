#include "Projectile.h"

Projectile::Projectile( void )
{
	m_RenderObject = new RenderObject();
}
Projectile::~Projectile( void )
{
}

void Projectile::Shoot( Vector2 _pos, Vector2 _dir, f32 _speed, f32 _life )
{
	m_Transform.SetPos( _pos );
	if( _dir.Steering( Vector2( 0.0f, 1.0f ) ) > 0.0f )
		m_Transform.SetRot( _dir.AngleBetween( Vector2( 0.0f, 1.0f ), true ) );
	else
		m_Transform.SetRot( -_dir.AngleBetween( Vector2( 0.0f, 1.0f ), true ) );

	m_Speed = _speed;
	m_Life = _life;
}

void Projectile::Release( void )
{
	SAFE_DELETE( m_RenderObject );
	GameObject::Release();
}

void Projectile::Launch( void )
{
	GameObject::Launch();
	
	m_RenderObject->SetTexID( 1 ); // The id of the last texture loaded... HAXXORS YAY
	m_RenderObject->SetDrawOrder( 2 );
	g_Renderer->RegisterRenderObject( m_RenderObject );
}

void Projectile::Exit( void )
{
	GameObject::Exit();
	g_Renderer->UnregisterRenderObject( m_RenderObject );
}

void Projectile::Update( f32 _timing )
{
	m_Life -= _timing;
	if( m_Life <= 0.0f )
	{
		g_ObjectManager->RemoveObject( GetHandle() );
	}

	m_Transform.SetPos( m_Transform.GetPos() + m_Transform.GetDir() * m_Speed*_timing );

	GameObject::Update( _timing );
	m_RenderObject->SetWorld( m_Transform.GetWorld() );
}
