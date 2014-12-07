#include "AnguiumEngine.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
VertexBuffer::VertexBuffer( void )
{
	m_Buffer	= nullptr;
	m_Decl		= nullptr;
	m_Verts		= nullptr;
	m_NumVerts	= 0;

	// TODO:: Remove this and make it abstract
	D3DVERTEXELEMENT9 decl[] =
	{
		{ 0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		{ 0, 12, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
		D3DDECL_END(),
	};

	IDirect3DDevice9* device = reinterpret_cast<IDirect3DDevice9*>(g_RenderDevice->GetDevice());
	ASSERT(device); // make sure it exists!
	device->CreateVertexDeclaration( decl, &m_Decl );
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
Vertex_PosTex* VertexBuffer::Lock( u32 _numVerts )
{
	if( m_Verts ) SAFE_DELETE( m_Verts );

	m_NumVerts = _numVerts;
	m_Verts = new Vertex_PosTex[m_NumVerts];
	return m_Verts;
}

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

	HRESULT hr = device->CreateVertexBuffer( sizeof(Vertex_PosTex) * m_NumVerts, 0, 0, D3DPOOL_MANAGED, &m_Buffer, NULL );
	if( FAILED( hr ) ) return false;

	void *vram = 0;
	hr = m_Buffer->Lock( 0, 0, &vram, 0 );
	if( FAILED( hr ) ) return false;
	{
		memcpy( vram, m_Verts, sizeof(Vertex_PosTex) * m_NumVerts );
	}
	m_Buffer->Unlock();
	if( FAILED( hr ) ) return false;
	
	return true;
}
