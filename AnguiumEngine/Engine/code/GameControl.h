#pragma once
#ifndef _GAME_CONTROL_H_
#define _GAME_CONTROL_H_

namespace AnguiumEngine
{
	
	class GameControl
	{
#ifdef AE_PC
		HWND			m_HWND;
		HINSTANCE		m_Instance;
		WINDOWPLACEMENT	m_WP;
	
		LRESULT CALLBACK WndProc( HWND _hWnd,
								  UINT _message,
								  WPARAM _wParam,
								  LPARAM _lParam );
#endif
		bool			m_Active;
		bool			m_IsClosing;
		
		StateSystem*	m_StateSystem;
	
	public:
		GameControl( void );
		~GameControl( void );
	
		void Initialize( const wchar_t* _title, u32 _windowWidth, u32 _windowHeight, GameState* _startState );
	
		void Run( void );
		void Update( void );
		void Render( void );
	
		void ChangeState( GameState* _state );
	
#ifdef AE_PC
		static LRESULT CALLBACK StaticWndProc( HWND _hWnd, 
											   UINT _message, 
											   WPARAM _wParam, 
											   LPARAM _lParam );
	
		inline HWND GetHWND( void ) { return m_HWND; }
#endif
	};

}

#endif