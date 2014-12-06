#include "AnguiumEngine.h"

StateSystem::StateSystem( void )
{
}

StateSystem::~StateSystem( void )
{
	Close();
}

void StateSystem::Launch( GameState* _startState )
{
	m_ToChange = _startState;
}

void StateSystem::Close( void )
{
	for( unsigned int i = 0; i < m_States.size(); ++i ) 
	{
		m_States[i]->Close();
		SAFE_DELETE(m_States[i]);
	}
	for( unsigned int i = 0; i < m_ToAdd.size(); ++i ) 
		SAFE_DELETE(m_ToAdd[i]);
	for( unsigned int i = 0; i < m_ToRemove.size(); ++i ) 
		SAFE_DELETE(m_ToRemove[i]);
	
	SAFE_DELETE(m_ToChange);

	m_States.clear();
	m_ToAdd.clear();
	m_ToRemove.clear();
}

void StateSystem::Update( float _timing )
{
	ProcessChanges();

	vector<GameState*>::iterator iter = m_States.begin();
	for( iter; iter != m_States.end(); ++iter )
	{
		(*iter)->Update( _timing );
	}
}

void StateSystem::ProcessChanges( void )
{
	ProcessToChange();
	ProcessToAdd();
	ProcessToRemove();
}

void StateSystem::ProcessToChange( void )
{
	if( m_ToChange )
	{
		for( unsigned int i = 0; i < m_States.size(); ++i )
		{
			m_States[i]->Close();
			SAFE_DELETE(m_States[i]);
		}
		m_States.clear();

		m_ToChange->Launch();
		m_States.push_back(m_ToChange);
		m_ToChange = nullptr;
	}
}

void StateSystem::ProcessToAdd( void )
{
	if( m_ToAdd.size() > 0 )
	{
		for( unsigned int i = 0; i < m_ToAdd.size(); ++i )
		{
			m_ToAdd[i]->Launch();
			m_States.push_back(m_ToAdd[i]);
		}
		m_ToAdd.clear();
	}
}

void StateSystem::ProcessToRemove( void )
{
	if( m_ToRemove.size() > 0 )
	{
		for( unsigned int i = 0; i < m_ToRemove.size(); ++i )
		{
			for( unsigned int j = 0; j < m_States.size(); ++j )
			{
				if( m_States[j] == m_ToRemove[i] )
				{
					m_States[j]->Close();
					m_States.erase(m_States.begin() + j);
					j--;
				}
			}
		}
		m_ToRemove.clear();
	}
}

void StateSystem::ChangeState( GameState* _state )
{
	if( m_ToChange ) SAFE_DELETE( m_ToChange );

	m_ToChange = _state;
}

void StateSystem::AddState( GameState* _state )
{
	m_ToAdd.push_back( _state );
}

void StateSystem::RemoveState( GameState* _state )
{
	m_ToRemove.push_back( _state );
}
