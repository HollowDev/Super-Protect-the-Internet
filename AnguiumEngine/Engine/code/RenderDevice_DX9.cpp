#include "AnguiumEngine.h"
#include "RenderDevice.h"

//#include "RenderPrimitive.h"

#ifdef AE_DX9

RenderDevice::RenderDevice( void ) :
#ifdef AE_PC
		m_hWnd( 0 ),
		m_hInstance( 0 ),
#endif
		m_Object( nullptr ),
		m_Device( nullptr ),
		m_WindowWidth( 0 ),
		m_WindowHeight( 0 ),
		m_ScreenWidth( 0 ),
		m_ScreenHeight( 0 ),
		m_BackBufferWidth( 0 ),
		m_BackBufferHeight( 0 )
{
}

RenderDevice::~RenderDevice( void )
{
	Release();
}

bool RenderDevice::Initialize( void )
{
	m_hWnd = g_GameControl->GetHWND();

	// Create the object
	m_Object = Direct3DCreate9( D3D_SDK_VERSION );

	m_Object->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &m_DisplayMode );
	m_Object->GetDeviceCaps( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &m_Caps );

	if( !BuildPresentParameters() )
	{
		SAFE_RELEASE( m_Object );
		return false;
	}

	// Create the Device
	m_Object->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_PP, &m_Device );

	return true;
}

void RenderDevice::Release( void )
{
	SAFE_RELEASE( m_Object );
	SAFE_RELEASE( m_Device );
}

//void RenderDevice::Render( const ShaderPass* _shader, RenderPrimitive* _primitive )
//{
//	IDirect3DVertexBuffer9* vbuffer		= _primitive->GetVertexBuffer()->GetBuffer();
//	IDirect3DVertexDeclaration9* decl	= _primitive->GetVertexBuffer()->GetDecl();
//	IDirect3DIndexBuffer9* ibuffer		= _primitive->GetIndexBuffer()->GetBuffer();
//
//	unsigned int numVerts	= _primitive->GetVertexBuffer()->GetNumVerts();
//	unsigned int numIndices = _primitive->GetIndexBuffer()->GetNumIndices();
//
//	m_Device->SetVertexDeclaration( decl );
//	m_Device->SetStreamSource( 0, vbuffer, 0, _primitive->GetVertexBuffer()->GetStride() );
//	m_Device->DrawPrimitive( D3DPT_TRIANGLELIST, 0, numIndices/3 );
//}

void RenderDevice::BeginScene( void )
{
	m_Device->BeginScene();
}

void RenderDevice::EndScene( void )
{
	m_Device->EndScene();
}

void RenderDevice::Clear( void )
{
	Clear( (Color*)&Color::BLACK, 0.0f, 0 );
}

void RenderDevice::Clear( Color* _color )
{
	Clear( _color, 0.0f, 0 );
}
		
void RenderDevice::Clear( Color* _color, int _flags )
{
	Clear( _color, 0.0f, _flags );
}

void RenderDevice::Clear( Color* _color, float _depth )
{
	Clear( _color, _depth, 0 );
}
		
void RenderDevice::Clear( Color* _color, float _depth, int _flags )
{
	m_Device->Clear( 0, 0, _flags, _color->GetD3DColor(), _depth, 0 );
}

void RenderDevice::Present( void )
{
	m_Device->Present( 0, 0, 0, 0 );
}

bool RenderDevice::BuildPresentParameters( void )
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
		return false;
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

	return true;
}

// Accessors
void* RenderDevice::GetDevice( void )
{
	return (void*)m_Device;
}

#endif