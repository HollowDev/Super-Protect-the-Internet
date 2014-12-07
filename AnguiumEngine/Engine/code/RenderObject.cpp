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

void RenderObject::Render( IDirect3DDevice9* _device, ShaderPass* _effect )
{
	// Get the mesh from the object pool
	// Get the texture from the object pool
	// Draw the mother flubing object, BEACH!
	Quad* quad = g_AssetPool->GetTextureAsset( m_TexID )->m_Quad;
	LPDIRECT3DTEXTURE9 texture = g_AssetPool->GetTextureAsset( m_TexID )->m_Texture;
	
	if( !quad || !texture )
	{
		int x = 0;
	}
	
	_effect->SetMatrix( "gWorld", &m_World );
	_effect->SetTexture( "gTexture", texture );
	_effect->Commit();

	IDirect3DVertexBuffer9* vbuffer		= quad->GetVertexBuffer()->GetBuffer();
	IDirect3DVertexDeclaration9* decl	= quad->GetVertexBuffer()->GetDecl();
	IDirect3DIndexBuffer9* ibuffer		= quad->GetIndexBuffer()->GetBuffer();

	u32 numVerts	= quad->GetVertexBuffer()->GetNumVerts();
	u32 numIndices = quad->GetIndexBuffer()->GetNumIndices();

	_device->SetVertexDeclaration( decl );
	_device->SetStreamSource( 0, vbuffer, 0, sizeof(Vertex_PosTex) );
	_device->SetIndices( ibuffer );
	_device->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2 );
}