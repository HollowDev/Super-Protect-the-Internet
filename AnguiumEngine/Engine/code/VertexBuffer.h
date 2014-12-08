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
		void*							m_Verts;
		u32								m_NumVerts;
		u32								m_TypeLength;
	
	public:
		VertexBuffer( void );
		~VertexBuffer( void );
		
		template<typename VERTEX>
		VERTEX* Lock( u32 _numVerts )
		{
			if( m_Verts ) SAFE_DELETE( m_Verts );
			if( m_Decl ) SAFE_RELEASE( m_Decl );
			
			SetupDecl<VERTEX>();

			m_NumVerts = _numVerts;
			m_Verts = new VERTEX[m_NumVerts];
			m_TypeLength = sizeof(VERTEX);
			return (VERTEX*)m_Verts;
		}
		bool Unlock( void );
	
		template<typename VERTEX>
		void SetupDecl( void )
		{
#ifdef AE_DX9
			IDirect3DDevice9* device = reinterpret_cast<IDirect3DDevice9*>(g_RenderDevice->GetDevice());
			ASSERT(device); // make sure it exists!
			device->CreateVertexDeclaration( (_D3DVERTEXELEMENT9*)g_VertexDescs[VERTEX::id], &m_Decl  );
#endif
		}

		// Accessors
		inline IDirect3DVertexBuffer9* GetBuffer( void )	{ return m_Buffer;					}
		inline IDirect3DVertexDeclaration9* GetDecl( void )	{ return m_Decl;					}
		inline void* GetVerts( void )						{ return m_Verts;					}
		inline u32 GetNumVerts( void )						{ return m_NumVerts;				}
		inline u32 GetTypeLength( void )					{ return m_TypeLength;				}
		inline u32 GetStride( void )						{ return m_NumVerts * m_TypeLength; }
		// Mutators
		inline void SetBuffer( IDirect3DVertexBuffer9* _buffer )	{ m_Buffer = _buffer;		}
		inline void SetDecl( IDirect3DVertexDeclaration9* _decl )	{ m_Decl = _decl;			}
		inline void SetVerts( void* _verts )						{ m_Verts = _verts;			}
		inline void SetNumVerts( u32 _numVerts )					{ m_NumVerts = _numVerts;	}
	};

}

#endif