#pragma once
#ifndef _RENDER_DEVICE_H_
#define _RENDER_DEVICE_H_

#include "ShaderPass.h"

namespace AnguiumEngine
{
	//class RenderPrimitive;
	class RenderDevice
	{
#ifdef AE_PC
		HWND					m_hWnd;
		HINSTANCE				m_hInstance;
#endif
#ifdef AE_DX9
		IDirect3D9*				m_Object;
		IDirect3DDevice9*		m_Device;
		D3DCAPS9				m_Caps;
		D3DPRESENT_PARAMETERS	m_PP;
		D3DDISPLAYMODE			m_DisplayMode;
#endif

		u32 m_WindowWidth;
		u32 m_WindowHeight;
		u32 m_ScreenWidth;
		u32 m_ScreenHeight;
		u32 m_BackBufferWidth;
		u32 m_BackBufferHeight;

	public:
		RenderDevice( void );
		~RenderDevice( void );

		bool Initialize( void );
		void Release( void );

		//void Render( const ShaderPass* _shader, RenderPrimitive* _primitive );
	
		void BeginScene( void );
		void EndScene( void );
		void Clear( void );
		void Clear( Color* _color );
		void Clear( Color* _color, int _flags );
		void Clear( Color* _color, float _depth );
		void Clear( Color* _color, float _depth, int _flags );
		void Present( void );
		
		// Accessors
		void* GetDevice( void );

		u32 GetWindowWidth( void ) const		{ return m_WindowWidth;			}
		u32 GetWindowHeight( void ) const		{ return m_WindowHeight;		}
		u32 GetScreenWidth( void ) const		{ return m_ScreenWidth;			}
		u32 GetScreenHeight( void ) const		{ return m_ScreenHeight;		}
		u32 GetBackBufferWidth( void ) const	{ return m_BackBufferWidth;		}
		u32 GetBackBufferHeight( void ) const	{ return m_BackBufferHeight;	}

#ifdef AE_DX9
		bool BuildPresentParameters( void );
		D3DPRESENT_PARAMETERS GetPresentParameters( void ) const { return m_PP; }
#endif
	};
}

#endif