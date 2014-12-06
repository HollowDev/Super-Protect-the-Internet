#pragma once
#ifndef _D3D9_HANDLER_H_
#define _D3D9_HANDLER_H_

namespace AnguiumEngine
{

	class D3D9Handler
	{
	public:
		HWND					m_hWnd;
		HINSTANCE				m_hInstance;
		D3DCAPS9				m_Caps;
		D3DPRESENT_PARAMETERS	m_PP;
		D3DDISPLAYMODE			m_DisplayMode;
		IDirect3D9*				m_Object;
		IDirect3DDevice9*		m_Device;
		ID3DXSprite*			m_Sprite;
		ID3DXLine*				m_Line;
	
		D3D9Handler( void );
		~D3D9Handler( void );
		bool Launch( HWND _hwnd );
		void Close( void );
		bool BuildPresentParameters( void );
	};

}

#endif