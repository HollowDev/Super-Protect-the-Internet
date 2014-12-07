/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Anguium Engine
	Desc: Main include for use in games as well as the precompiled header
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _ANGUIUM_ENGINE_H_
#define _ANGUIUM_ENGINE_H_

#define ANGUIUM_ENGINE
#define AnguiumEngineName		(L"Anguium Engine")
#define AnguiumEngineVersion	(L"0.01f")

// Engine Defines
#define FILENAME_STRING_LENGTH	(64)
#define DEFAULT_STRING_LENGTH	(255)
#define ENGINE_FPS				(60)
#define ENGINE_TIME_STEP		(1.0f/ENGINE_FPS)

// Rendering define
#define AE_DX9
#define AE_PC

#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>

#include <vector>
using std::vector;

#ifdef AE_DX9
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9core.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#include <dinput.h>
#endif

#include "AnguiumUtil.h"
#include "AnguiumMath.h"
#include "GameObject.h"
#include "GameObjectTypeInfo.h"
#include "GameObjectFactory.h"
#include "GameObjectManager.h"
#include "D3D9Handler.h"
#include "ShaderPass.h"
#include "Renderer.h"
#include "Vertex.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Quad.h"
#include "AssetPool.h"
#include "GameState.h"
#include "StateSystem.h"
#include "Timer.h"
#include "GameControl.h"
#include "Camera.h"
#include "RenderObject.h"

using namespace std; // Oh noes, I has std's!
using namespace AnguiumMath;
using namespace AnguiumUtil;
using namespace AnguiumEngine;

// Global variables
extern GameObjectFactory* g_ObjectFactory;
extern GameObjectManager* g_ObjectManager;
extern GameControl* g_GameControl;
extern D3D9Handler*	g_D3D9Handler;
extern AssetPool*	g_AssetPool;
extern Renderer*	g_Renderer;
extern Timer*		g_Timer;

extern f32 g_AspectRatio;
extern u32 g_BackBufferWidth;
extern u32 g_BackBufferHeight;
extern bool g_EnableVsync;

// Engine helper functions
void AnguiumEngineLaunch( const wchar_t* _title, u32 _width, u32 _height, GameState* _startState );
void AnguiumEngineRun( void );
void AnguiumEngineCleanup( void );

#endif