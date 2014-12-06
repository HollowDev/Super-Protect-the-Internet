#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <AnguiumEngine.h>
using namespace AnguiumEngine;

#include "GameObjectDefines.h"

class Player : public GameObject
{
	RenderObject* m_RenderObject;

public:
	Player( void );
	~Player( void );
	
	void Release( void );
	void Launch( void );
	void Exit( void );
	void Update( f32 _timing );
};

GAME_OBJECT_REGISTER(Player,1)

#endif