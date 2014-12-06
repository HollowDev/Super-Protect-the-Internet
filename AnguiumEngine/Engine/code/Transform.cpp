#include "AnguiumEngine.h"
#include "Transform.h"
#include "Math.h"

Transform::Transform( void )
{
	D3DXMatrixIdentity( &world );
	pos		= D3DXVECTOR2( 0.0f, 0.0f );
	scale	= D3DXVECTOR2( 1.0f, 1.0f );
	center	= D3DXVECTOR2( 0.0f, 0.0f );
	rot		= 0.0f;

	dir		= D3DXVECTOR2( 0.0f, 1.0f );
}

void Transform::CalcDir( void )
{
	dir = Rotate2D( D3DXVECTOR2( 0.0f, 1.0f ), rot );
}

void Transform::CalcWorld( void )
{
	D3DXMATRIX combined, translateMat, scaleMat, rotationMat;
	// Initialize the Combined matrix.
	D3DXMatrixIdentity(&combined);

	// Scale the sprite.
	D3DXMatrixScaling(&scaleMat, scale.x, scale.y, 1.0f);
	combined *= scaleMat;

	// Rotate the sprite.
	D3DXMatrixRotationZ(&rotationMat, rot);
	combined *= rotationMat;

	// Translate the sprite
	D3DXMatrixTranslation(&translateMat, float(int(pos.x)), float(int(pos.y)), 0.0f);
	combined *= translateMat;

	world = combined;
}
