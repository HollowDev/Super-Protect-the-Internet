#include "AnguiumEngine.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
IndexBuffer::IndexBuffer( void )
{
	m_Buffer		= nullptr;
	m_Indices		= nullptr;
	m_NumIndices	= 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Destructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
IndexBuffer::~IndexBuffer( void )
{
	SAFE_RELEASE( m_Buffer );
	SAFE_DELETE( m_Indices );
	m_NumIndices = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: 'Locks' the index buffer so you can construct the new indicies
Params:
	_numIndicies - the number of indices you will be needing
Return:
	u32* - Pointer to the indicies
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
u32* IndexBuffer::Lock( u32 _numIndices )
{
	if( m_Indices ) SAFE_DELETE( m_Indices );

	m_NumIndices = _numIndices;
	m_Indices = new u32[m_NumIndices];
	return m_Indices;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Create the index buffer.
Return:
	bool - True if successfully built else false.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool IndexBuffer::Unlock( void )
{
	if( !m_Indices || m_NumIndices == 0 ) return false;

	// Create the index buffer
	IDirect3DDevice9* device = reinterpret_cast<IDirect3DDevice9*>(g_RenderDevice->GetDevice());
	ASSERT(device); // make sure it exists!

	HRESULT hr = device->CreateIndexBuffer( sizeof(u32) * m_NumIndices, 0, D3DFMT_INDEX32, D3DPOOL_MANAGED, &m_Buffer, 0 );
	if( FAILED( hr ) ) return false;
	
	void *vram = 0;
	hr = m_Buffer->Lock( 0, 0, &vram, 0 );
	if( FAILED( hr ) ) return false;
	{
		memcpy( vram, m_Indices, sizeof(u32) * m_NumIndices );
	}
	m_Buffer->Unlock();
	if( FAILED( hr ) ) return false;

	return true;
}
