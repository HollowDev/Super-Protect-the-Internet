#pragma once
#ifndef _INDEX_BUFFER_H_
#define _INDEX_BUFFER_H_

namespace AnguiumEngine
{
	// TODO:: Make this more abstract, so it's more easily ported to other rendering systems.
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Description: Custom index buffer, currently directly attached to DirectX11.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	class IndexBuffer
	{
		IDirect3DIndexBuffer9*	m_Buffer;
		u32*					m_Indices;
		u32						m_NumIndices;
	public:
		IndexBuffer( void );
		~IndexBuffer( void );
	
		u32* Lock( u32 _numIndices );
		bool Unlock( void );
	
		// Accessors
		inline IDirect3DIndexBuffer9* GetBuffer( void )	{ return m_Buffer;		}
		inline u32* GetIndices( void )					{ return m_Indices;		}
		inline u32 GetNumIndices( void )				{ return m_NumIndices;	}
		// Mutators
		inline void SetBuffer( IDirect3DIndexBuffer9* _buffer )	{ m_Buffer = _buffer;			}
		inline void SetIndices( u32* _indices )					{ m_Indices = _indices;			}
		inline void SetNumIndices( u32 _numIndices )			{ m_NumIndices = _numIndices;	}
	};

}

#endif