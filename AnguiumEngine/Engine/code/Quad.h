#pragma once
#ifndef _QUAD_H_
#define _QUAD_H_

namespace AnguiumEngine
{

	class Quad
	{
		VertexBuffer*	m_VertexBuffer;
		IndexBuffer*	m_IndexBuffer;
		u32				m_Width;
		u32				m_Height;
	
	public:
		Quad( u32 _width, u32 _height );
		~Quad( void );
	
		// Accessors
		inline VertexBuffer* GetVertexBuffer( void )	{ return m_VertexBuffer;	}
		inline IndexBuffer* GetIndexBuffer( void )		{ return m_IndexBuffer;		}
		inline u32 GetWidth( void )						{ return m_Width;			}
		inline u32 GetHeight( void )					{ return m_Height;			}
	};

}

#endif