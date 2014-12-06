#pragma once
#ifndef _GAME_OBJECT_TYPE_INFO_H_
#define _GAME_OBJECT_TYPE_INFO_H_

namespace AnguiumEngine
{
	static const unsigned int MAX_OBJECT_TYPE_INFO = 256;
	extern class GameObjectTypeInfo* g_GameObjectInfo[MAX_OBJECT_TYPE_INFO];
	
	class GameObject;
	class GameObjectTypeInfo
	{
		typedef GameObject* (*BuildObjectFunction)(void);
	
		
		const wchar_t* m_Name;
		unsigned int m_Type;
		unsigned int m_MaxCount;	// maximum number of these in game
		unsigned int m_SizeOf;		// size of the object
		BuildObjectFunction m_BuildObjectFunc;
	public:
		GameObjectTypeInfo( const wchar_t* _name, 
							unsigned int _type, 
							unsigned int _maxCount,
							unsigned int _sizeOf,
							BuildObjectFunction _buildObjectFunc ) :
				m_Name(_name),
				m_Type(_type),
				m_MaxCount(_maxCount),
				m_SizeOf(_sizeOf),
				m_BuildObjectFunc(_buildObjectFunc)
		{
			/*ASSERT(_type < MAX_OBJECT_TYPE_INFO, "GameObjectTypeInfo::Constructor -- type identifier is out of range" );*/
			/*ASSERT(s_ObjectInfo[m_Type] == NULL, "GameObjectTypeInfo::Constructor -- type info already exists!" );*/
			g_GameObjectInfo[m_Type] = this;
		}
		~GameObjectTypeInfo( void ) {}
	
		GameObject* Create( void ) const  { return m_BuildObjectFunc(); }
	
		// Accessors
		const wchar_t* GetName( void ) const { return m_Name; }
		unsigned int GetType( void ) const { return m_Type; }
		unsigned int GetMaxCount( void ) const { return m_MaxCount; }
		unsigned int GetSizeOf( void ) const { return m_SizeOf; }
	};
	
	#define GAME_OBJECT_REGISTER(classType,maxCount)	\
	static GameObject* classType##Build( void )			\
	{ return new classType(); }							\
	static GameObjectTypeInfo classType##Info(L#classType, GOT_##classType, maxCount, sizeof(classType), classType##Build);
}

#endif