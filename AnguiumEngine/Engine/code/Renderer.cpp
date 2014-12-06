#include "AnguiumEngine.h"

#include "Renderer.h"

#include <algorithm>
#include <fstream>
using std::fstream;
using std::ios_base;

Renderer::Renderer( void )
{
	m_ClearColor = D3DXCOLOR( 0.15f, 0.15f, 0.2f, 1.0f );
}

Renderer::~Renderer( void )
{

}
	
void Renderer::Launch( IDirect3DDevice9* _d3d9device, const wchar_t* _effectFilePath )
{
	m_D3D9Device = _d3d9device;
	D3DXCreateEffectFromFile( m_D3D9Device, _effectFilePath, 0, 0, 0, 0, &m_Effect, 0 );
}

void Renderer::Render( void )
{
	if( m_UpdateLists )
		ProcessChanges();

	m_D3D9Device->Clear( 0, 0, D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET, m_ClearColor, 1.0f, 0 );
	m_D3D9Device->BeginScene();
	{
		// setup the alpha blending
		m_D3D9Device->SetRenderState( D3DRENDERSTATETYPE::D3DRS_ALPHABLENDENABLE, TRUE );
		m_D3D9Device->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
		m_D3D9Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
		

		// Render the sorted objects using the shader
		unsigned passes = 0;
		m_Effect->Begin( &passes, 0 );
		for( unsigned int i = 0; i < passes; ++i )
		{
			m_Effect->BeginPass( i );
			{
				if( m_Camera )
				{
					m_Effect->SetMatrix( "gViewProjection", &m_Camera->GetViewProj() );
				}

				vector< RenderObject* >::iterator iter = m_SortedObjects.begin();
				for( iter; iter != m_SortedObjects.end(); ++iter )
				{
					if( (*iter)->GetIsHUD() )
						m_Effect->SetMatrix( "gViewProjection", &m_Camera->GetProj() );
					else
						m_Effect->SetMatrix( "gViewProjection", &m_Camera->GetViewProj() );


					(*iter)->Render( m_D3D9Device, m_Effect );
				}
			}
			m_Effect->EndPass();
		}
		m_Effect->End();
	}

	m_D3D9Device->EndScene();
	m_D3D9Device->Present( 0, 0, 0, 0 );
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Registers new objects, removed unregister objects and then sorts the new list
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::ProcessChanges( void )
{
	ProcessToRegister();
	ProcessToUnregister();
	Sort();

	m_UpdateLists = false;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Registers the new render objects, by adding them to the main render list
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::ProcessToRegister( void )
{
	for( unsigned int i = 0; i < m_ToRegister.size(); ++i )
	{	
		m_RenderObjects.push_back( m_ToRegister[i] );
	}

	m_ToRegister.clear();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Unregisters the unwanter render objects, by removing them to the main render list
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::ProcessToUnregister( void )
{
	for( unsigned int x = 0; x < m_ToUnregister.size(); ++x )
	{
		vector< RenderObject* > newList;
		for( unsigned int i = 0; i < m_RenderObjects.size(); ++i )
		{
			if( m_RenderObjects[i] != m_ToUnregister[x] || m_RenderObjects[i]->GetTexID() > 10000 )
				newList.push_back( m_RenderObjects[i] );
		}
		m_RenderObjects.clear();
		m_RenderObjects = newList;
	}

	m_ToUnregister.clear();
}

bool compareByDrawOrder( RenderObject* a, RenderObject* b )
{
	return a->GetDrawOrder() < b->GetDrawOrder();
};

void Renderer::Sort( void )
{
	// TODO:: Sort the list based on the object's Z
	m_SortedObjects.clear();
	m_SortedObjects = m_RenderObjects;

	std::sort( m_SortedObjects.begin(), m_SortedObjects.end(), compareByDrawOrder );

	int x = 0;
}

void Renderer::RegisterRenderObject( RenderObject* _renderObject )
{
	m_ToRegister.push_back( _renderObject );
	m_UpdateLists = true;
}

void Renderer::UnregisterRenderObject( RenderObject* _renderObject )
{
	m_ToUnregister.push_back( _renderObject );
	m_UpdateLists = true;
}