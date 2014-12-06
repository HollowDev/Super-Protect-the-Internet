#pragma once
#ifndef _STATE_SYSTEM_H_
#define _STATE_SYSTEM_H_

namespace AnguiumEngine
{

	class StateSystem
	{
		vector<GameState*> m_States;
		
		GameState*			m_ToChange;
		vector<GameState*> m_ToAdd;
		vector<GameState*> m_ToRemove;
	
		void ProcessChanges( void );
		void ProcessToChange( void );
		void ProcessToAdd( void );
		void ProcessToRemove( void );
	public:
		StateSystem( void );
		~StateSystem( void );
	
		void Launch( GameState* _startState );
		void Close( void );
	
		void Update( float _timing );
		
		void ChangeState( GameState* _state );
		void AddState( GameState* _state );
		void RemoveState( GameState* _state );
	};

}

#endif