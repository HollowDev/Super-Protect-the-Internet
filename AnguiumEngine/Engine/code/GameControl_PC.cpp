#include "AnguiumEngine.h"

#ifdef AE_PC

GameControl::GameControl( void )
{
}
GameControl::~GameControl( void )
{
	SAFE_DELETE( m_StateSystem );
}

void GameControl::Initialize( const wchar_t* _title, u32 _windowWidth, u32 _windowHeight, GameState* _startState )
{
	m_Instance		= NULL;
	m_Active		= true;

	// Define the window
	WNDCLASSEX wcex;
	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)GameControl::StaticWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_Instance;
	wcex.hIcon			= LoadIcon(0,IDC_ICON);
	wcex.hCursor		= LoadCursor(0, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= _title;
	wcex.hIconSm		= 0;

	// Reguster the window
	RegisterClassEx( &wcex );

	// Create the window
	m_HWND = CreateWindow(
		_title, 
		_title, 
		(true ? WS_OVERLAPPEDWINDOW : WS_POPUP),
		CW_USEDEFAULT,
		0,
		_windowWidth, 
		_windowHeight, 
		0, 
		0, 
		m_Instance, 
		this 
	);

	// Adjust to desired size
	RECT rect = { 0, 0, _windowWidth, _windowHeight };
	AdjustWindowRectEx( 
		&rect, 
		GetWindowLong( m_HWND, GWL_STYLE ),
		FALSE,
		WS_OVERLAPPEDWINDOW
	);

	// Set the windows position
	SetWindowPos( 
		m_HWND, 
		HWND_TOP, 
		0, 
		0, 
		rect.right-rect.left, 
		rect.bottom-rect.top, 
		SWP_NOZORDER | SWP_NOMOVE 
	);

	ShowWindow( m_HWND, SW_SHOW );
	UpdateWindow( m_HWND );

	// Save current location/size
	ZeroMemory( &m_WP, sizeof(WINDOWPLACEMENT) );
	m_WP.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement( m_HWND, &m_WP );

	// Initialize the state system
	m_StateSystem = new StateSystem();
	m_StateSystem->Launch( _startState );
}

void GameControl::Run( void )
{
	MSG msg;
	while( m_Active )
	{
		// Did we recieve a message, or are we idling?
		if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			if( msg.message == WM_QUIT )
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Advance Game Frame
			this->Update();
			this->Render();
		}
	}
}

void GameControl::Update( void )
{
	g_Timer->Update();

	float deltaTime = g_Timer->GetDeltaTime();
	if( deltaTime > 0.25f )
		deltaTime = 0.25f;

	if( m_StateSystem ) m_StateSystem->Update( deltaTime );
}

void GameControl::Render( void )
{
	if( !m_Active ) return;

	g_Renderer->Render();
}

LRESULT CALLBACK GameControl::StaticWndProc( 
	HWND _hWnd, 
	UINT _message, 
	WPARAM _wParam, 
	LPARAM _lParam 
	)
{
	if( _message == WM_CREATE )
        SetWindowLongPtr( _hWnd, GWLP_USERDATA, (LONG)((CREATESTRUCT *)_lParam)->lpCreateParams );

    GameControl *targetControl = (GameControl*)GetWindowLongPtr( _hWnd, GWLP_USERDATA );

    if( targetControl )
        return targetControl->WndProc( _hWnd, _message, _wParam, _lParam );

    return DefWindowProc( _hWnd, _message, _wParam, _lParam );
}

LRESULT CALLBACK GameControl::WndProc( 
	HWND _hWnd,
	UINT _message, 
	WPARAM _wParam, 
	LPARAM _lParam 
	)
{
	switch(_message)
	{
	case WM_DESTROY:
		{
			m_Active = false;
			PostQuitMessage(0);
		}
		break;
	case WM_PAINT:
		{
			ValidateRect(_hWnd, 0);
		}
		break;
	}
	return DefWindowProc(_hWnd, _message, _wParam, _lParam);
}

void GameControl::ChangeState( GameState* _state )
{
	m_StateSystem->ChangeState( _state );
}


#endif