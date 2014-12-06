#pragma once
#ifndef _GAME_OBJECT_FACTORY_H_
#define _GAME_OBJECT_FACTORY_H_

#include <queue>
using std::queue;

namespace AnguiumEngine
{
	class GameObject;
	class GameObjectFactory
	{
		// Array of memory
		GameObject** m_Pool[256];
		// Queue of open data indices
		queue<unsigned int> m_OpenList[256];
	
	public:
		GameObjectFactory( void );
		~GameObjectFactory( void );
	
		void Launch( void );
		void Release( void );	
	
		GameObject* Alloc( unsigned int _type );
		void Free( GameObject* _object, unsigned int _type );
	};
}

#endif