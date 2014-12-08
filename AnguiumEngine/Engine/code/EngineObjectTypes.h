#pragma once
#ifndef _ENGINE_OBJECT_TYPES_H_
#define _ENGINE_OBJECT_TYPES_H_

enum ObjectTypes
{
	OT_TransformComponent = 0,
	OT_RenderComponent,
	OT_CollisionComponent,

	OT_GameTypesStart = OT_CollisionComponent
};

#endif