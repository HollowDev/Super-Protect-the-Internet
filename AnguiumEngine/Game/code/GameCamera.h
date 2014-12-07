#pragma once
#ifndef _GAME_CAMERA_H_
#define _GAME_CAMERA_H_

#include <AnguiumEngine.h>

#define MAX_SCREEN_SHAKE	10.0f

class GameCamera : public Camera
{
	//GameObject* m_Target;
	//float m_ScreenShake;
	//float m_TotalTime;

	void FollowTarget( float _timing );

public:
	GameCamera( void );
	~GameCamera( void );

	void Launch( Vector2 _startPos );
	void Close( void );

	virtual void Update( float _timing );
};

#endif