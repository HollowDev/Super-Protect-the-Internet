/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: RenderPrimitive
	Desc: Contains all necessary render data for objects
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _RENDER_PRIMITIVE_H_
#define _RENDER_PRIMITIVE_H_

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace AnguiumEngine
{
	class RenderPrimitive
	{
		VertexBuffer m_VertexBuffer;
		IndexBuffer m_IndexBuffer;

		u32 m_PrimitiveType;
	
	public:
		RenderPrimitive( void );
		~RenderPrimitive( void );
	
		// Accessors
		inline VertexBuffer* GetVertexBuffer( void )	{ return &m_VertexBuffer;	}
		inline IndexBuffer* GetIndexBuffer( void )		{ return &m_IndexBuffer;	}
		inline u32 GetPrimitiveType( void )				{ return m_PrimitiveType;	}

		// Mutators
		inline void SetPrimitiveType( u32 _type ) { m_PrimitiveType = _type; }

	};
}

#endif