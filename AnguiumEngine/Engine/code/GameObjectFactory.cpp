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
	for( u32 i = 0; i < MAX_OBJECT_TYPE_INFO; ++i )
	{
		// Check if the object has info
		GameObjectTypeInfo* info = g_GameObjectInfo[i];
		if( !info )
		{
			m_Pool[i] = nullptr;
			continue;
		}

		// Initialize an array of the requested size
		u32 allocSize = info->GetMaxCount();
		// Create the object from the info and plug it into the array
		m_Pool[i] = info->Create(allocSize);
		for( u32 x = 0; x < allocSize; ++x )
		{
			// Push the indices into the open list.
			m_OpenList[i].push(x);
		}
	}
}

void GameObjectFactory::Release( void )
{
	for( u32 i = 0; i < MAX_OBJECT_TYPE_INFO; ++i )
	{
		// Check if the object has info
		GameObjectTypeInfo* info = g_GameObjectInfo[i];
		if( !info || !m_Pool[i] ) continue;

		// Delete the array of objects
		info->Destroy(m_Pool[i]);
		m_Pool[i] = nullptr;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Grabs memory from the factory to plug into _object
Params:
	_object - the object to plug the information into
	_type - the type of object to create
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void GameObjectFactory::Alloc( Object** _object, u32 _type )
{
	// If the open list is empty there is nothing we can do
	queue<u32>& openList = m_OpenList[_type];
	ASSERT( !openList.empty() && "<GameObjectFactory::Alloc> :: no open slots for current type!" );

	// Grab the first index in the open list
	u32 index = openList.front();
	openList.pop();
	
	// Grab the type info for this object
	GameObjectTypeInfo* info = g_GameObjectInfo[_type];
	ASSERT( info );
	// return the object to the user
	info->Cast( _object, m_Pool[_type], index );
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Frees the memory back into the object factory
Params:
	_object - the object to plug the information into
	_type - the type of object to create
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void GameObjectFactory::Free( Object* _object, u32 _type )
{
	GameObjectTypeInfo* info = g_GameObjectInfo[_type];
	ASSERT( info );

	// Grab the information for this object
	u32 allocSize = info->GetMaxCount();
	u32 sizeOf = info->GetSizeOf();

	// Pointer math to determine the index of the object
	u32 loc = ((s32)_object - (s32)&m_Pool[_type][0]) / sizeOf;
	ASSERT( !( loc < 0 || loc > allocSize ) );
	
	// Push it back into the open list!
	m_OpenList[_type].push(loc);
}