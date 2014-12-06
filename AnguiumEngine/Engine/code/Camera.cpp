#include "AnguiumEngine.h"

Camera::Camera( void )
{
	D3DXMatrixIdentity( &m_View );
	D3DXMatrixIdentity( &m_Projection );
	D3DXMatrixIdentity( &m_ViewProjection );
	m_Pos = D3DXVECTOR2( 0.0f, 0.0f );
}
Camera::~Camera( void )
{
}

void Camera::Update( float _timing )
{
	D3DXMatrixIdentity( &m_View );
	D3DXMatrixTranslation( &m_View, float(int(m_Pos.x)), float(int(m_Pos.y)), 0.0f );
	
	m_ViewProjection = m_View * m_Projection;
}

void Camera::CreateOrthographic( float _halfWidth, float _halfHeight )
{
	D3DXMatrixOrthoOffCenterLH( &m_Projection, -_halfWidth, _halfWidth, -_halfHeight, _halfHeight, 0.0f, 1.0f );

	m_ViewProjection = m_View * m_Projection;
}
