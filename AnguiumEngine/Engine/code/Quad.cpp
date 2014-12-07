#include "AnguiumEngine.h"

Quad::Quad( unsigned int _width, unsigned int _height )
{
	m_Width		= _width;
	m_Height	= _height;

	// Initialize the buffers
	m_Primitive = new RenderPrimitive();
	VertexBuffer* m_VertexBuffer = m_Primitive->GetVertexBuffer();
	IndexBuffer* m_IndexBuffer = m_Primitive->GetIndexBuffer();
	
	// Construct the vertex buffer and index buffer
	VertexPos3Tex* verts = m_VertexBuffer->Lock<VertexPos3Tex>( 4 );
	unsigned int* indices = m_IndexBuffer->Lock( 6 );
	{
		float halfWidth = m_Width * 0.5f;
		float halfHeight = m_Height * 0.5f;

		verts[0] = VertexPos3Tex(-halfWidth, halfHeight, 0.0f, 0.0f, 0.0f );	//	 0 ---- 1
		verts[1] = VertexPos3Tex( halfWidth, halfHeight, 0.0f, 1.0f, 0.0f );	//	 |	 /	|
		verts[2] = VertexPos3Tex(-halfWidth,-halfHeight, 0.0f, 0.0f, 1.0f );	//	 |  /	|
		verts[3] = VertexPos3Tex( halfWidth,-halfHeight, 0.0f, 1.0f, 1.0f );	//	 2 ---- 3

		indices[0] = 0; indices[1] = 1; indices[2] = 2;
		indices[3] = 1; indices[4] = 3; indices[5] = 2;
	}
	if( !m_VertexBuffer->Unlock() || !m_IndexBuffer->Unlock() )
	{
		// FAILED! 
		int x = 0;
	}

	m_Primitive->SetPrimitiveType( (u32)D3DPT_TRIANGLELIST );
}

Quad::~Quad( void )
{
	SAFE_DELETE( m_Primitive );
}
