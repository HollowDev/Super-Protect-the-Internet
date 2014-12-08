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
	
void Renderer::Launch( const char* _effectFilePath )
{
	m_Shader.Initialize( _effectFilePath );
}

void Renderer::Render( void )
{
	if( m_UpdateLists )
		ProcessChanges();

	g_RenderDevice->Clear( &Color( 0.1f, 0.1f, 0.2f, 1.0f ), 1.0f, D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET );
	g_RenderDevice->BeginScene();
	{
		RenderObjects();
		//RenderSimpleVerts();
	}
	g_RenderDevice->EndScene();
	g_RenderDevice->Present();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Render out all renderable objects
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::RenderObjects( void )
{
	// Render the sorted objects using the shader
	unsigned passes = m_Shader.Begin();
	for( unsigned int i = 0; i < passes; ++i )
	{
		m_Shader.BeginPass( i );
		{
			vector< RenderObject* >::iterator iter = m_SortedObjects.begin();
			for( iter; iter != m_SortedObjects.end(); ++iter )
			{
				if( (*iter)->GetIsHUD() && m_Camera )
					m_Shader.SetMatrix( "gViewProjection", &m_Camera->GetProj() );
				else if( m_Camera )
					m_Shader.SetMatrix( "gViewProjection", &m_Camera->GetViewProj() );

				(*iter)->Render( &m_Shader );
			}
		}
		m_Shader.EndPass();
	}
	m_Shader.End();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Render out all simple vert types
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::RenderSimpleVerts( void )
{
	RenderSimpleLineVerts();
	RenderSimpleTriVerts();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Render out the simple line verts
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::RenderSimpleLineVerts( void )
{
	if( m_SimpleVertLineCount == 0 ) return;

	// Construct a primitive from the verts
	m_SimpleLines->GetVertexBuffer()->Lock<VertexPos3Color>( m_SimpleVertLineCount );
	{
		//for( u32 i = 0; i < m_SimpleVertLineCount; ++i )
		//{
		//	
		//}
		//float halfWidth = m_Width * 0.5f;
		//float halfHeight = m_Height * 0.5f;
		//
		//verts[0] = VertexPos3Tex(-halfWidth, halfHeight, 0.0f, 0.0f, 0.0f );	//	 0 ---- 1
		//verts[1] = VertexPos3Tex( halfWidth, halfHeight, 0.0f, 1.0f, 0.0f );	//	 |	 /	|
		//verts[2] = VertexPos3Tex(-halfWidth,-halfHeight, 0.0f, 0.0f, 1.0f );	//	 |  /	|
		//verts[3] = VertexPos3Tex( halfWidth,-halfHeight, 0.0f, 1.0f, 1.0f );	//	 2 ---- 3
		//
		//indices[0] = 0; indices[1] = 1; indices[2] = 2;
		//indices[3] = 1; indices[4] = 3; indices[5] = 2;
		//
		//m_SimpleLines->GetVertexBuffer()->Create( m_SimpleVertsLines, m_SimpleVertLineCount, sizeof(VertexPos3Color) * m_SimpleVertLineCount );
	}
	m_SimpleLines->GetVertexBuffer()->Unlock();
	m_SimpleLines->GetIndexBuffer()->Unlock();

	// Render the verts
	unsigned passes = m_BasicShader.Begin();
	for( unsigned int i = 0; i < passes; ++i )
	{
		m_BasicShader.BeginPass( i );
		{
			m_BasicShader.SetMatrix( "gViewProjection", &m_Camera->GetViewProj() );
			g_RenderDevice->Render( &m_Shader, m_SimpleLines );
		}
		m_BasicShader.EndPass();
	}
	m_BasicShader.End();

	m_SimpleVertLineCount = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Render out the simple triangle verts
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::RenderSimpleTriVerts( void )
{
	if( m_SimpleVertTriCount == 0 ) return;

	// Construct a primitive from the 

	// Render the verts
	m_Shader.Begin();
	{
		RenderSimpleVerts();
	}
	m_Shader.End();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Adds an array of vertices into the simpleverts array
Params:
	_pos - position of the vert
	_numVerts - the number of verts in the polygon
	_color - color of the vert
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::AddPolygon( Vector2* _verts, u32 _numVerts, Color* _color )
{
	// Cap the start and end, so there are no connections between the previous poly
	Vector2 startPos = _verts[0];
	CapLineVerts(&startPos);
	
	// Add the verts!
	for( u32 i = 0; i < _numVerts; ++i )
		AddPointToLineVerts( &_verts[i], _color );

	AddPointToLineVerts( &startPos, _color );
	CapLineVerts(&startPos);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Adds an array of vertices into the simpletris array
Params:
	_pos - position of the vert
	_numVerts - the number of verts in the solid polygon
	_color - color of the vert
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::AddSolidPolygon( Vector2* _verts, u32 _numVerts, Color* _color )
{
	// Cap the start and end, so there are no connections between the previous poly
	Vector2 startPos = _verts[0];
	CapTriVerts(&startPos);

	// Get the starting positions of each traversal index
	u32 leftPos = _numVerts-1;
	u32 rightPos = 1;
	
	// Add them into the array like this to create each triangle
	AddPointToTriVerts( &startPos, _color );
	while( true )
	{
		AddPointToTriVerts( &_verts[rightPos++], _color );
		if( rightPos > leftPos ) break;

		AddPointToTriVerts( &_verts[leftPos--], _color );
		if( leftPos < rightPos )
			break;
	}

	const int endVert = _numVerts/2 + _numVerts % 2;
	CapTriVerts(&_verts[endVert]);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Adds a vert into the line verts array
Params:
	_pos - position of the vert
	_color - color of the vert
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::AddPointToLineVerts( Vector2* _pos, Color* _color )
{
	// If it's already reached the cap then render out the verts and start over
	//if( m_SimpleVertLineCount >= s_MaxSimpleVerts )
	//{
	//	VertexPos3Color vert1 = m_SimpleVertsLines[s_MaxSimpleVerts-1];
	//	RenderSimpleLineVerts();
	//	m_SimpleVertsLines[m_SimpleVertLineCount++] = vert1;
	//}
	//
	//// Add the vert into the array
	//VertexPos3Color& vert = m_SimpleVertsLines[m_SimpleVertLineCount++];
	//vert.x = _pos->x;
	//vert.y = _pos->y;
	//vert.z = 0.0f;
	//vert.r = _color->r;
	//vert.g = _color->g;
	//vert.b = _color->b;
	//vert.a = _color->a;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Adds a vert into the triangle verts array
Params:
	_pos - position of the vert
	_color - color of the vert
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Renderer::AddPointToTriVerts( Vector2* _pos, Color* _color )
{
	// If it's already reached the cap then render out the verts and start over
	//if( m_SimpleVertTriCount >= s_MaxSimpleVerts )
	//{
	//	VertexPos3Color vert1 = m_SimpleVertsTris[s_MaxSimpleVerts-2];
	//	VertexPos3Color vert2 = m_SimpleVertsTris[s_MaxSimpleVerts-1];
	//	RenderSimpleTriVerts();
	//	m_SimpleVertsTris[m_SimpleVertTriCount++] = vert1;
	//	m_SimpleVertsTris[m_SimpleVertTriCount++] = vert2;
	//}
	//
	//// Add the vert into the array
	//VertexPos3Color& vert = m_SimpleVertsTris[m_SimpleVertTriCount++];
	//vert.x = _pos->x;
	//vert.y = _pos->y;
	//vert.z = 0.0f;
	//vert.r = _color->r;
	//vert.g = _color->g;
	//vert.b = _color->b;
	//vert.a = _color->a;
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