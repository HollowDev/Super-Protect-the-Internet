#pragma once
#ifndef _VERTEX_H_
#define _VERTEX_H_

struct Vertex_PosTex
{
	float x, y, z;
	float u, v;

	Vertex_PosTex( void )
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		u = 0.0f;
		v = 0.0f;
	}
	Vertex_PosTex( float _x, float _y, float _z, float _u, float _v )
	{
		x = _x;
		y = _y;
		z = _z;
		u = _u;
		v = _v;
	}
};

#endif