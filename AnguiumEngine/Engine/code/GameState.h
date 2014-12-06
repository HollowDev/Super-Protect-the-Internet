#pragma once
#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

namespace AnguiumEngine
{

	class GameState
	{
	public:
		virtual ~GameState( void ) { Close(); }
		
		virtual void Launch( void ) {}
		virtual void Close( void ) {}
		virtual void Update( float _timing ) {}
	};

}

#endif