#pragma once
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include <AnguiumEngine.h>
using namespace AnguiumEngine;

#include "GameObjectDefines.h"

class Projectile : public GameObject
{
	RenderObject* m_RenderObject;
	f32 m_Speed;
	f32 m_Life;

public:
	Projectile( void );
	~Projectile( void );

	void Shoot( Vector2 _pos, Vector2 _dir, f32 _speed, f32 _life = 2.0f ); 
	
	void Release( void );
	void Launch( void );
	void Exit( void );
	void Update( f32 _timing );
};

GAME_OBJECT_REGISTER(Projectile, 50)

#endif