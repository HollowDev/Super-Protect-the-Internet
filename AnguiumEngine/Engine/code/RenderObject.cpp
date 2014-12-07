#include "AnguiumEngine.h"

RenderObject::RenderObject( void )
{
	m_TexID = 0;
	m_DrawOrder = 0.0f;
	m_World.Identity();
	m_IsHUD = false;
}

RenderObject::~RenderObject( void )
{

}

void RenderObject::Render( ShaderPass* _effect )
{
	// Get the mesh from the object pool
	// Get the texture from the object pool
	// Draw the mother flubing object, BEACH!
	Quad* quad = g_AssetPool->GetTextureAsset( m_TexID )->m_Quad;
	LPDIRECT3DTEXTURE9 texture = g_AssetPool->GetTextureAsset( m_TexID )->m_Texture;
	
	_effect->SetMatrix( "gWorld", &m_World );
	_effect->SetTexture( "gTexture", texture );
	_effect->Commit();
	
	g_RenderDevice->Render( _effect, quad->GetPrimitive() );
}