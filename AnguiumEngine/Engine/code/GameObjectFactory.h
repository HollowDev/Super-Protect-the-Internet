#pragma once
#ifndef _GAME_OBJECT_FACTORY_H_
#define _GAME_OBJECT_FACTORY_H_

#include <queue>
using std::queue;

namespace AnguiumEngine
{
	class GameObjectFactory
	{
		// Array of memory
		Object* m_Pool[MAX_OBJECT_TYPE_INFO];
		// Queue of open data indices
		queue<u32> m_OpenList[MAX_OBJECT_TYPE_INFO];
	
	public:
		GameObjectFactory( void );
		~GameObjectFactory( void );
	
		void Launch( void );
		void Release( void );	
	
		void Alloc( Object** _object, u32 _type );
		void Free( Object* _object, u32 _type );
	};
}

#endif