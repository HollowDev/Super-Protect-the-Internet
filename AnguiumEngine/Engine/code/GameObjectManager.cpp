#include "AnguiumEngine.h"

GameObjectManager::GameObjectManager( void )
{
}

GameObjectManager::~GameObjectManager( void )
{
}

void GameObjectManager::Update( float _timing )
{
	typedef hash_map<unsigned int, GameObject*>::iterator GameObjectIter;

	for( GameObjectIter iter = m_Objects.begin(); iter != m_Objects.end(); ++iter )
	{
		iter->second->Update( _timing );
	}
}

GameObject* GameObjectManager::AddObject( unsigned int _type )
{
	// Create object based on type info
	GameObject* newObject = g_ObjectFactory->Alloc( _type );
	// Add it to the hash map via it's unique handle
	m_Objects[newObject->GetHandle()] = newObject;
	// Launch the object
	newObject->Launch();
	// return it to the user
	return newObject;
}

void GameObjectManager::RemoveObject( unsigned int _handle )
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
