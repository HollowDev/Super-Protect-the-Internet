#include "AnguiumEngine.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
VertexBuffer::VertexBuffer( void )
{
	m_Buffer		= nullptr;
	m_Decl			= nullptr;
	m_Verts			= nullptr;
	m_NumVerts		= 0;
	m_TypeLength	= 0;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Destructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
VertexBuffer::~VertexBuffer( void )
{
	SAFE_DELETE( m_Verts );
	SAFE_RELEASE( m_Decl );
	SAFE_RELEASE( m_Buffer );
	m_NumVerts = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Locks the vertex buffer so you can construct the new verts
Params:
	_numVerts - the number of verts you will be needing
Return:
	Vertex_PosTex* - Pointer to the verts
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Create the vertex buffer.
Return:
	bool - True if successfully built else false.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool VertexBuffer::Unlock( void )
{
	if( !m_Verts || m_NumVerts == 0 ) return false;

	// Create vertex buffer
	IDirect3DDevice9* device = reinterpret_cast<IDirect3DDevice9*>(g_RenderDevice->GetDevice());
	ASSERT(device); // make sure it exists!

	HRESULT hr = device->CreateVertexBuffer( m_TypeLength * m_NumVerts, 0, 0, D3DPOOL_MANAGED, &m_Buffer, NULL );
	if( FAILED( hr ) ) return false;

	void *vram = 0;
	hr = m_Buffer->Lock( 0, 0, &vram, 0 );
	if( FAILED( hr ) ) return false;
	{
		memcpy( vram, m_Verts, m_TypeLength * m_NumVerts );
	}
	m_Buffer->Unlock();
	if( FAILED( hr ) ) return false;
	
	return true;
}
