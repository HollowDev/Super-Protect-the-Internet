#pragma once
#ifndef _BASECOMPONENT_H_
#define _BASECOMPONENT_H_

#include <AnguiumEngine.h>
#include "GameObject.h"

class BaseComponent : public GameObject
{

public:
	BaseComponent( void ){};
	~BaseComponent( void ){};

	virtual void OnDock( void );	
	virtual void OnUnDock( void );

	inline GameObject* GetOwner( void ) { return m_owner;}
	inline void SetOwner( GameObject* owner ){m_owner = owner;}

protected:

	GameObject* m_owner;

};


#endif