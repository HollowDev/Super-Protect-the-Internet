/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Game Object
	Desc: The base to all game objects
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

namespace AnguiumEngine
{
	using namespace AnguiumMath;

	class GameObject : public Object
	{
	protected:
		Transform m_Transform;
	
	public:
		GameObject( void );
		virtual ~GameObject( void );
	
		// Interface
		virtual void Release( void );
		virtual void Launch( void );
		virtual void Exit( void );
		virtual void Update( f32 _timing );

		// Mutators
		inline void SetPos( const Vector2& _pos ) { m_Transform.SetPos( _pos ); }
		inline void SetType( u32 _type ) { m_Type = _type; }

		// Accessors
		inline Transform GetTransform( void ) const { return m_Transform;	}
		
	};

}

#endif