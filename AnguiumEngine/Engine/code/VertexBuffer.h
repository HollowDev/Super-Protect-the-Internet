#pragma once
#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

namespace AnguiumEngine
{
	// TODO:: Make this more abstract, so it's more easily ported to other rendering systems.
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Description: Custom vertex buffer, currently directly attached to DirectX11.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	class VertexBuffer
	{
		IDirect3DVertexBuffer9*			m_Buffer;
		IDirect3DVertexDeclaration9*	m_Decl;
		Vertex_PosTex*					m_Verts;
		u32								m_NumVerts;
	
	public:
		VertexBuffer( void );
		~VertexBuffer( void );
		
		Vertex_PosTex* Lock( u32 _numVerts );
		bool Unlock( void );
	
		// Accessors
		inline IDirect3DVertexBuffer9* GetBuffer( void )	{ return m_Buffer;		}
		inline IDirect3DVertexDeclaration9* GetDecl( void )	{ return m_Decl;		}
		inline Vertex_PosTex* GetVerts( void )				{ return m_Verts;		}
		inline u32 GetNumVerts( void )						{ return m_NumVerts;	}
		// Mutators
		inline void SetBuffer( IDirect3DVertexBuffer9* _buffer )	{ m_Buffer = _buffer;		}
		inline void SetDecl( IDirect3DVertexDeclaration9* _decl )	{ m_Decl = _decl;			}
		inline void SetVerts( Vertex_PosTex* _verts )				{ m_Verts = _verts;			}
		inline void SetNumVerts( u32 _numVerts )					{ m_NumVerts = _numVerts;	}
	};

}

#endif