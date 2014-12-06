#pragma once
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

namespace AnguiumEngine
{

	struct Transform
	{
		D3DXMATRIX	world;
		D3DXVECTOR2 pos;
		D3DXVECTOR2 scale;
		D3DXVECTOR2 center;
		float rot;
		
		D3DXVECTOR2 dir;
	
		Transform( void );
	
		void CalcDir( void );
		void CalcWorld( void );
	};

}

#endif