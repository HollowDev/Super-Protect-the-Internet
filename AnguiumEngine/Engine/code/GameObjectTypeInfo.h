#pragma once
#ifndef _GAME_OBJECT_TYPE_INFO_H_
#define _GAME_OBJECT_TYPE_INFO_H_

namespace AnguiumEngine
{
	static const u32 MAX_OBJECT_TYPE_INFO = 256;
	extern class GameObjectTypeInfo* g_GameObjectInfo[MAX_OBJECT_TYPE_INFO];
	
	class GameObjectTypeInfo
	{
		typedef Object* (*BuildObjectFunction)(u32);
		typedef void (*DestroyObjectFunction)(Object*);
		typedef void (*CastObjectFunction)(Object**,Object*,u32);
	
		const wchar_t* m_Name;
		u32 m_Type;
		u32 m_MaxCount;	// maximum number of these in game
		u32 m_SizeOf;		// size of the object
		BuildObjectFunction m_BuildObjectFunc;
		DestroyObjectFunction m_DestroyObjectFunc;
		CastObjectFunction m_CastObjectFunc;
	public:
		GameObjectTypeInfo( const wchar_t* _name, 
							u32 _type, 
							u32 _maxCount,
							u32 _sizeOf,
							BuildObjectFunction _buildObjectFunc,
							DestroyObjectFunction _destroyObjectFunc,
							CastObjectFunction _castObjectFunc ) :
				m_Name(_name),
				m_Type(_type),
				m_MaxCount(_maxCount),
				m_SizeOf(_sizeOf),
				m_BuildObjectFunc(_buildObjectFunc),
				m_DestroyObjectFunc(_destroyObjectFunc),
				m_CastObjectFunc(_castObjectFunc)
		{
			ASSERT( _type < MAX_OBJECT_TYPE_INFO && "<GameObjectTypeInfo::Constructor> -- type identifier is out of range" );
			g_GameObjectInfo[m_Type] = this;
		}
		~GameObjectTypeInfo( void ) {}
	
		Object* Create( u32 _num ) const  { return m_BuildObjectFunc(_num); }
		void Destroy( Object* _obj ) { m_DestroyObjectFunc(_obj); }
		void Cast( Object** _obj1, Object* _obj2, u32 _index ) { m_CastObjectFunc(_obj1, _obj2, _index); }
	
		// Accessors
		const wchar_t* GetName( void ) const	{ return m_Name;		}
		u32 GetType( void ) const				{ return m_Type;		}
		u32 GetMaxCount( void ) const			{ return m_MaxCount;	}
		u32 GetSizeOf( void ) const				{ return m_SizeOf;		}
	};
	
	#define GAME_OBJECT_REGISTER(classType,maxCount)	\
	static Object* classType##Build(u32 _num)	\
	{ return new classType[_num](); }			\
	static void classType##Destroy(Object*_obj)		\
	{ delete [] (classType*)_obj; _obj = nullptr; }	\
	static void classType##Cast(Object**_obj1,Object*_obj2,u32 _index)	\
	{ *_obj1 = &((classType*)_obj2)[_index]; }							\
	static GameObjectTypeInfo classType##Info(L#classType, OT_##classType, maxCount, sizeof(classType), classType##Build, classType##Destroy, classType##Cast);
}

#endif