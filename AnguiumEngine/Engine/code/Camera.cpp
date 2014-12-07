#include "AnguiumEngine.h"

Camera::Camera( void ) :
	m_View( Matrix::IDENTITY ),
	m_Projection( Matrix::IDENTITY ),
	m_ViewProjection( Matrix::IDENTITY ),
	m_Pos( Vector2::ONE )
{
}
Camera::~Camera( void )
{
}

void Camera::Update( float _timing )
{
	m_View.Identity();
	m_View.Translate( Vector3( m_Pos.x, m_Pos.y, 0.0f ) );
	
	m_ViewProjection = m_View * m_Projection;
}

void Camera::CreateOrthographic( float _halfWidth, float _halfHeight )
{
	m_Projection.CreateOrthoOffCenterLH( -_halfWidth, _halfWidth, -_halfHeight, _halfHeight, 0.0f, 1.0f );
	m_ViewProjection = m_View * m_Projection;
}
