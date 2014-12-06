#include "AnguiumEngine.h"

Quad::Quad( unsigned int _width, unsigned int _height )
{
	m_Width		= _width;
	m_Height	= _height;

	// Initialize the buffers
	m_VertexBuffer = new VertexBuffer();
	m_IndexBuffer = new IndexBuffer();
	
	// Construct the vertex buffer and index buffer
	Vertex_PosTex* verts = m_VertexBuffer->Lock( 4 );
	unsigned int* indices = m_IndexBuffer->Lock( 6 );
	{
		float halfWidth = m_Width * 0.5f;
		float halfHeight = m_Height * 0.5f;

		verts[0] = Vertex_PosTex(-halfWidth, halfHeight, 0.0f, 0.0f, 0.0f );	//	 0 ---- 1
		verts[1] = Vertex_PosTex( halfWidth, halfHeight, 0.0f, 1.0f, 0.0f );	//	 |	 /	|
		verts[2] = Vertex_PosTex(-halfWidth,-halfHeight, 0.0f, 0.0f, 1.0f );	//	 |  /	|
		verts[3] = Vertex_PosTex( halfWidth,-halfHeight, 0.0f, 1.0f, 1.0f );	//	 2 ---- 3

		indices[0] = 0; indices[1] = 1; indices[2] = 2;
		indices[3] = 1; indices[4] = 3; indices[5] = 2;
	}
	if( !m_VertexBuffer->Unlock() || !m_IndexBuffer->Unlock() )
	{
		// FAILED! 
		int x = 0;
	}
}

Quad::~Quad( void )
{
	SAFE_DELETE( m_VertexBuffer );
	SAFE_DELETE( m_IndexBuffer );
}
