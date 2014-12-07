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
	
		void RegisterRenderObject( RenderObject* _renderObject );
		void UnregisterRenderObject( RenderObject* _renderObject );
	
		// Accessors
		inline Camera* GetCamera( void ) const		{ return m_Camera;		}
	
		// Mutators
		inline void SetCamera( Camera* _camera ) { m_Camera = _camera; }
	};

}

#endif