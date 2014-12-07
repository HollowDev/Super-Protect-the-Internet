#pragma once
#ifndef _QUAD_H_
#define _QUAD_H_

namespace AnguiumEngine
{

	class Quad
	{
		RenderPrimitive*	m_Primitive;
		u32					m_Width;
		u32					m_Height;
	
	public:
		Quad( u32 _width, u32 _height );
		~Quad( void );
	
		// Accessors
		inline RenderPrimitive* GetPrimitive( void )	{ return m_Primitive;		}
		inline u32 GetWidth( void )						{ return m_Width;			}
		inline u32 GetHeight( void )					{ return m_Height;			}
	};

}

#endif