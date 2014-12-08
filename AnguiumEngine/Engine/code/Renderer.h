#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "RenderObject.h"
#include "Camera.h"

#include <vector>
using std::vector;

namespace AnguiumEngine
{
	class Renderer
	{
		Camera*				m_Camera;
		D3DCOLOR			m_ClearColor;

		ShaderPass m_Shader;
		ShaderPass m_BasicShader;
		
		static const int s_MaxSimpleVerts = 2000;
		VertexPos3Color* m_SimpleVertsLines[s_MaxSimpleVerts];
		VertexPos3Color* m_SimpleVertsTris[s_MaxSimpleVerts];
		int m_SimpleVertLineCount;
		int m_SimpleVertTriCount;

		RenderPrimitive* m_SimpleLines;
		RenderPrimitive* m_SimpleTris;
	
		bool m_UpdateLists;
		vector< RenderObject* > m_SortedObjects;
		vector< RenderObject* > m_RenderObjects;
		vector< RenderObject* > m_ToRegister;
		vector< RenderObject* > m_ToUnregister;
	
		void ProcessChanges( void );
		void ProcessToRegister( void );
		void ProcessToUnregister( void );
		void Sort( void );
	
	public:
		Renderer( void );
		~Renderer( void );
	
		void Launch( const char* _effectFilePath );
		void Render( void );
		
		void RenderObjects( void );
		void RenderSimpleVerts( void );
		void RenderSimpleLineVerts( void );
		void RenderSimpleTriVerts( void );

		void AddPolygon( Vector2* _verts, u32 _numVerts, Color* _color );
		void AddSolidPolygon( Vector2* _verts, u32 _numVerts, Color* _color );

		void AddPointToLineVerts( Vector2* _pos, Color* _color );
		void AddPointToTriVerts( Vector2* _pos, Color* _color );

		void CapLineVerts( Vector2* _pos ) { AddPointToLineVerts( _pos, &Color::CLEAR ); }
		void CapTriVerts( Vector2* _pos ) { AddPointToTriVerts( _pos, &Color::CLEAR ); }
	
		void RegisterRenderObject( RenderObject* _renderObject );
		void UnregisterRenderObject( RenderObject* _renderObject );
	
		// Accessors
		inline Camera* GetCamera( void ) const		{ return m_Camera;		}
	
		// Mutators
		inline void SetCamera( Camera* _camera ) { m_Camera = _camera; }
	};

}

#endif