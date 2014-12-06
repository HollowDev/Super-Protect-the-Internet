#include "AnguiumEngine.h"

D3D9Handler::D3D9Handler( void )
{
	m_Object	= nullptr;
	m_Device	= nullptr;
	m_Sprite	= nullptr;
	m_Line		= nullptr;
}

D3D9Handler::~D3D9Handler( void )
{
	Close();
}

bool D3D9Handler::Launch( HWND _hwnd )
{
	m_hWnd = _hwnd;

	// Create the object
	m_Object = Direct3DCreate9( D3D_SDK_VERSION );

	m_Object->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &m_DisplayMode );
	m_Object->GetDeviceCaps( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &m_Caps );

	if( !BuildPresentParameters() )
	{
		SAFE_RELEASE( m_Object );
		return FALSE;
	}

	// Create the Device
	m_Object->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_PP, &m_Device );
	
	// Create the sprite
	D3DXCreateSprite( m_Device, &m_Sprite );

	// Create the line
	D3DXCreateLine( m_Device, &m_Line );
	m_Line->SetAntialias( TRUE );
	m_Line->SetWidth( 1.0f );
	
	return TRUE;
}

void D3D9Handler::Close( void )
{
	SAFE_RELEASE( m_Device );
	SAFE_RELEASE( m_Object );
	SAFE_RELEASE( m_Sprite );
	SAFE_RELEASE( m_Line   );
}

bool D3D9Handler::BuildPresentParameters( void )
{
	ZeroMemory( &m_PP, sizeof(m_PP) );
	D3DFORMAT adapterFormat = m_DisplayMode.Format;
    if ( SUCCEEDED( m_Object->CheckDeviceFormat( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapterFormat, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, D3DFMT_D24S8 ) ) )
    {
        m_PP.AutoDepthStencilFormat = D3DFMT_D24S8;
    }
    else if ( SUCCEEDED( m_Object->CheckDeviceFormat( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapterFormat, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, D3DFMT_D24X8 ) ) )
    {
        m_PP.AutoDepthStencilFormat = D3DFMT_D24X8;
    }
    else if ( SUCCEEDED( m_Object->CheckDeviceFormat( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapterFormat, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, D3DFMT_D16 ) ) )
    {
        m_PP.AutoDepthStencilFormat = D3DFMT_D16;
    }
	else
	{
		return FALSE;
	}

	m_PP.BackBufferWidth			= 0;
	m_PP.BackBufferHeight           = 0;
	m_PP.BackBufferFormat           = adapterFormat;
	m_PP.BackBufferCount            = 1;
	m_PP.MultiSampleType            = D3DMULTISAMPLE_NONE;
	m_PP.MultiSampleQuality         = 0;
	m_PP.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
	m_PP.hDeviceWindow              = m_hWnd;
	m_PP.Windowed                   = TRUE;
	m_PP.EnableAutoDepthStencil     = TRUE; 
	m_PP.FullScreen_RefreshRateInHz = 0;//m_DisplayMode.RefreshRate;
	m_PP.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

	return TRUE;
}
