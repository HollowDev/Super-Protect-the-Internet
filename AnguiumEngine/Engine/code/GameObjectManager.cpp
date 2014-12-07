#include "AnguiumEngine.h"

GameObjectManager::GameObjectManager( void )
{
}

GameObjectManager::~GameObjectManager( void )
{
}

void GameObjectManager::Update( f32 _timing )
{
	typedef hash_map<u32, GameObject*>::iterator GameObjectIter;

	for( GameObjectIter iter = m_Objects.begin(); iter != m_Objects.end(); ++iter )
	{
		iter->second->Update( _timing );
	}

	for( u32 i = 0; i < m_ToRemove.size(); ++i )
	{
		Remove( m_ToRemove[i] );
	}
	m_ToRemove.clear();
}

GameObject* GameObjectManager::AddObject( u32 _type )
{
	// Create object based on type info
	GameObject* newObject = g_ObjectFactory->Alloc( _type );
	// Add it to the hash map via it's unique handle
	m_Objects[newObject->GetHandle()] = newObject;
	// Launch the object
	newObject->SetType( _type );
	newObject->Launch();
	// return it to the user
	return newObject;
}

void GameObjectManager::RemoveObject( u32 _handle, bool _now )
{
	if( _now )
		Remove( _handle );
	else
		m_ToRemove.push_back( _handle );
}

void GameObjectManager::Remove( u32 _handle )
{
	if( m_Objects.find(_handle) == m_Objects.end() )
	{
		/* FAILED to find it*/
		return;
	}
	// Grab the object from it's handle
	GameObject* oldObject = m_Objects[_handle];
	// Remove from the hash map
	m_Objects.erase(_handle);
	// Exit the object
	oldObject->Exit();
	// Put back into the factory!
	g_ObjectFactory->Free(oldObject, oldObject->GetType());
}