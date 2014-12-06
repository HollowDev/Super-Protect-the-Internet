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

	class GameObject
	{
		static unsigned int s_HandleCounter;
		unsigned int m_Handle;
		bool m_IsActive;
	protected:
		unsigned int m_Type;
	
	public:
		GameObject( void );
		~GameObject( void );
	
		// Interface
		virtual void Release( void );
		virtual void Launch( void );
		virtual void Exit( void );
		virtual void Update( float _timing );

		// Accessors
		unsigned int GetHandle( void ) const { return m_Handle; }
		unsigned int GetType( void ) const { return m_Type; }
		bool IsActive( void ) const { return m_IsActive; }
	};

}

#endif