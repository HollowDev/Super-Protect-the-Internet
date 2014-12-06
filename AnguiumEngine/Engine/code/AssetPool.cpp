#include "AnguiumEngine.h"

TextureAsset::TextureAsset( const wchar_t* _textureFilePath )
{
	// Create the texture
	D3DXCreateTextureFromFile( g_D3D9Handler->m_Device, _textureFilePath, &m_Texture );
	
	// Get surface description (to find Width/Height of the texture)
	D3DSURFACE_DESC d3dSurfDesc;
	ZeroMemory(&d3dSurfDesc, sizeof(d3dSurfDesc));

	m_Texture->GetLevelDesc(0, &d3dSurfDesc);

	// Remember the Width and Height
	m_Quad = new Quad( d3dSurfDesc.Width, d3dSurfDesc.Height );
}

TextureAsset::~TextureAsset( void )
{
	SAFE_RELEASE( m_Texture );
	SAFE_DELETE( m_Quad );
}

AssetPool::AssetPool( void )
{

}
AssetPool::~AssetPool( void )
{
	Close();
}

void AssetPool::Close( void )
{
	for( u32 i = 0; i < m_Textures.size(); ++i )
	{
		SAFE_DELETE( m_Textures[i] );
	}
	m_Textures.clear();
}

unsigned int AssetPool::AddTexture( const wchar_t* _filePath )
{
	// Add it to the list of textures
	m_Textures.push_back( new TextureAsset( _filePath ) );
	return m_Textures.size() - 1;
}