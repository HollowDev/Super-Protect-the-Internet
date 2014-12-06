#include "AnguiumEngine.h"
#include "GameObjectFactory.h"
#include "GameObjectTypeInfo.h"
#include "GameObject.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
GameObjectFactory::GameObjectFactory( void )
{
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Destructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
GameObjectFactory::~GameObjectFactory( void )
{
	Release();
}

void GameObjectFactory::Launch( void )
{
	for( unsigned int i = 0; i < 256; ++i )
	{
		// Check if the object has info
		GameObjectTypeInfo* info = g_GameObjectInfo[i];
		if( !info ) continue;

		// Initialize an array of the requested size
		unsigned int allocSize = info->GetMaxCount();
		m_Pool[i] = new GameObject*[allocSize];
		for( unsigned int x = 0; x < allocSize; ++x )
		{
			// Create the object from the info and plug it into the array
			m_Pool[i][x] = info->Create();
			// Push the indices into the open list.
			m_OpenList[i].push(x);
		}
	}
}

void GameObjectFactory::Release( void )
{
	for( unsigned int i = 0; i < 256; ++i )
	{
		// Check if the object has info
		GameObjectTypeInfo* info = g_GameObjectInfo[i];
		if( !info || !m_Pool[i] ) continue;

		// Grab the size of the allocated array
		unsigned int allocSize = info->GetMaxCount();
		for( unsigned int x = 0; x < allocSize; ++x )
		{
			// Delete each game object from the factory
			m_Pool[i][x]->Release();
			delete m_Pool[i][x];
			m_Pool[i][x] = nullptr;
		}
		// Delete the array of objects
		delete [] m_Pool[i];
		m_Pool[i] = nullptr;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Grabs memory from the factory to plug into _object
Params:
	_type - the type of object to create
Return:
	_object - the object that was created
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
GameObject* GameObjectFactory::Alloc( unsigned int _type )
{
	// If the open list is empty there is nothing we can do
	queue<unsigned int>& openList = m_OpenList[_type];
	/* ASSERT( openList.empty(), "GameObjectFactory::Alloc -- no open slots for _type" ); */

	// Grab the first index in the open list
	unsigned int index = openList.front();
	openList.pop();
	
	// return the object to the user
	return m_Pool[_type][index];
}

	
void GameObjectFactory::Free( GameObject* _object, unsigned int _type )
{
	GameObjectTypeInfo* info = g_GameObjectInfo[_type];
	/* ASSERT( info ) */

	// Grab the information for this object
	unsigned int allocSize = info->GetMaxCount();
	unsigned int sizeOf = info->GetSizeOf();

	// Pointer math to determine the index of the object
	unsigned int loc = ((int)_object - (int)&(m_Pool[_type])[0]) / sizeOf;
	if( loc < 0 || loc > allocSize )
	{
		// FAILED
	}
	
	// Push it back into the open list!
	m_OpenList[_type].push(loc);
}