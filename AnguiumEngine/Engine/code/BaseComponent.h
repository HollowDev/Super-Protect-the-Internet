#pragma once
#ifndef _BASECOMPONENT_H_
#define _BASECOMPONENT_H_

#include <AnguiumEngine.h>

namespace AnguiumEngine
{

	class BaseComponent : public Object
	{
	public:
		virtual ~BaseComponent( void ) = {}
	
		virtual void OnDock( void ) = 0;
		virtual void OnUnDock( void ) = 0;
	
		inline GameObject* GetOwner( void )			{ return m_Owner;	}
		inline void SetOwner( GameObject* owner )	{ m_Owner = owner;	}
	
	protected:
		GameObject* m_Owner;
	};

}

#endif