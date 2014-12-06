#pragma once
#ifndef _GAME_OBJECT_MANAGER_H_
#define _GAME_OBJECT_MANAGER_H_

#include "GameObject.h"
#include <hash_map>
using std::hash_map;

namespace AnguiumEngine
{
	class GameObjectManager
	{
		hash_map<unsigned int, GameObject*> m_Objects;
	
	public:
		GameObjectManager( void );
		~GameObjectManager( void );
	
		void Update( float _timing );
	
		GameObject* AddObject( unsigned int _type );
		void RemoveObject( unsigned int _handle );
	};
}

#endif