#pragma once
#ifndef _GAME_OBJECT_MANAGER_H_
#define _GAME_OBJECT_MANAGER_H_

#include "GameObject.h"
#include <hash_map>
#include <vector>
using std::vector;
using std::hash_map;

namespace AnguiumEngine
{
	class GameObjectManager
	{
		hash_map<u32, GameObject*> m_Objects;
		vector<u32> m_ToRemove;
	
		void Remove( u32 _handle );
	public:
		GameObjectManager( void );
		~GameObjectManager( void );
	
		void Update( f32 _timing );

		GameObject* AddObject( u32 _type );
		void RemoveObject( u32 _handle, bool _now = false );
	};
}

#endif