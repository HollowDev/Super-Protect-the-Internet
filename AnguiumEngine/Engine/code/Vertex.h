#pragma once
#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "VertexDesc.h"

enum VertexType
{
	VertexType_Pos3 = 0,
	VertexType_Pos4,
	VertexType_Pos3Color,
	VertexType_Pos4Color,
	VertexType_Pos3Tex,
	VertexType_Pos4Tex,
	VertexType_Pos3ColorTex,
	VertexType_Pos4ColorTex,

	VertexType_Count
};

struct VertexPos3
{
	static const u32 id = VertexType_Pos3;

	f32 x, y, z;
};
struct VertexPos4
{
	static const u32 id = VertexType_Pos4;

	f32 x, y, z, w;
};
struct VertexPos3Color
{
	static const u32 id = VertexType_Pos3Color;

	f32 x, y, z;
	f32 r, g, b, a;
};
struct VertexPos4Color
{
	static const u32 id = VertexType_Pos4Color;

	f32 x, y, z, w;
	f32 r, g, b, a;
};
struct VertexPos3Tex
{
	static const u32 id = VertexType_Pos3Tex;

	f32 x, y, z;
	f32 u, v;

	VertexPos3Tex( void ) : x(0.0f), y(0.0f), z(0.0f), u(0.0f), v(0.0f) {}
	VertexPos3Tex( f32 _x, f32 _y, f32 _z, f32 _u, f32 _v ) : x(_x), y(_y), z(_z), u(_u), v(_v) {}
};
struct VertexPos4Tex
{
	static const u32 id = VertexType_Pos4Tex;

	f32 x, y, z, w;
	f32 u, v;
};
struct VertexPos3ColorTex
{
	static const u32 id = VertexType_Pos3ColorTex;

	f32 x, y, z;
	f32 r, g, b, a;
	f32 u, v;
};
struct VertexPos4ColorTex
{
	static const u32 id = VertexType_Pos4ColorTex;

	f32 x, y, z, w;
	f32 r, g, b, a;
	f32 u, v;
};

extern VertexDescs g_VertexDescs;
extern u32 g_VertexStrides[];
extern int g_NumElements[];

#endif