/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Object
	Desc: The base to all objects in the game
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

namespace AnguiumEngine
{
	class Object
	{
		static u32 s_HandleCounter;
		u32 m_Handle;
	protected:
		u32 m_Type;
		bool m_IsActive;
	public:
		Object( void );
		virtual ~Object( void ) {}
	
		// Interface
		virtual void Update( f32 _timing ) = 0;
		
		// Accessors
		inline u32 GetHandle( void ) const	{ return m_Handle;		}
		inline u32 GetType( void ) const	{ return m_Type;		}
		inline bool IsActive( void ) const	{ return m_IsActive;	}
	};

}

#endif