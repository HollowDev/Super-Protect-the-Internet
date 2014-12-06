#pragma once
#ifndef _ASSET_POOL_H_
#define _ASSET_POOL_H_

#include <vector>
using std::vector;

namespace AnguiumEngine
{
	
	struct TextureAsset
	{
		LPDIRECT3DTEXTURE9	m_Texture;
		Quad*				m_Quad;
	
		TextureAsset( const wchar_t* _textureFilePath );
		~TextureAsset( void );
	};
	
	class AssetPool
	{
		vector<TextureAsset*> m_Textures;
	
	public:
		AssetPool( void );
		~AssetPool( void );
	
		void Close( void );
	
		u32 AddTexture( const wchar_t* _filePath );
	
		// Accessors
		TextureAsset* GetTextureAsset( u32 _id ) { return m_Textures[_id]; }
	};

}

#endif