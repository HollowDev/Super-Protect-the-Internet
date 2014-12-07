/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Game Object
	Desc: The base to all objects in the game
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

namespace AnguiumEngine
{
	using namespace AnguiumMath;

	class GameObject
	{
		static u32 s_HandleCounter;
		u32 m_Handle;
	protected:
		u32 m_Type;
		bool m_IsActive;

		Transform m_Transform;
	
	public:
		GameObject( void );
		~GameObject( void );
	
		// Interface
		virtual void Release( void );
		virtual void Launch( void );
		virtual void Exit( void );
		virtual void Update( f32 _timing );

		// Mutators
		inline void SetType( u32 _type ) { m_Type = _type; }

		// Accessors
		inline u32 GetHandle( void ) const			{ return m_Handle;		}
		inline u32 GetType( void ) const			{ return m_Type;		}
		inline bool IsActive( void ) const			{ return m_IsActive;	}
		inline Transform GetTransform( void ) const { return m_Transform;	}
		
	};

}

#endif