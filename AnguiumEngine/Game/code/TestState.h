#pragma once
#ifndef _TEST_STATE_H_
#define _TEST_STATE_H_

#include <GameState.h>
using namespace AnguiumEngine;

class GameCamera;
class TestState : public GameState
{
	GameCamera* m_Camera;

public:
	TestState( void );
	~TestState( void );
	
	virtual void Launch( void );
	virtual void Close( void );
	virtual void Update( float _timing );
};

#endif