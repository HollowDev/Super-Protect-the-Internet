#include "AnguiumEngine.h"
#include "Vertex.h"


// VertexType_Pos3
VertexDesc VertexPos3Desc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT3, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	AE_DESC_END( 12 )
};

// VertexType_Pos4
VertexDesc VertexPos4Desc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT4, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	AE_DESC_END( 16 )
};

// VertexType_Pos3Color
VertexDesc VertexPos3ColorDesc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT3, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	{ 0, 12, VertexElement::TYPE_COLOR,	 VertexElement::METHOD_DEFAULT, VertexElement::USAGE_COLOR,    0 },
	AE_DESC_END( 28 )
};

// VertexType_Pos4Color
VertexDesc VertexPos4ColorDesc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT4, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	{ 0, 16, VertexElement::TYPE_COLOR,	 VertexElement::METHOD_DEFAULT, VertexElement::USAGE_COLOR,    0 },
	AE_DESC_END( 32 )
};

// VertexType_Pos3Tex
VertexDesc VertexPos3TexDesc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT3, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	{ 0, 12, VertexElement::TYPE_FLOAT2, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_TEXCOORD, 0 },
	AE_DESC_END( 20 )
};

// VertexType_Pos4Tex
VertexDesc VertexPos4TexDesc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT4, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	{ 0, 16, VertexElement::TYPE_FLOAT2, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_TEXCOORD, 0 },
	AE_DESC_END( 24 )
};

// VertexType_Pos3ColorTex
VertexDesc VertexPos3ColorTexDesc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT3, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	{ 0, 12, VertexElement::TYPE_COLOR,	 VertexElement::METHOD_DEFAULT, VertexElement::USAGE_COLOR,    0 },
	{ 0, 28, VertexElement::TYPE_FLOAT2, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_TEXCOORD, 0 },
	AE_DESC_END( 36 )
};

// VertexType_Pos4ColorTex
VertexDesc VertexPos4ColorTexDesc =
{
	{ 0, 0,  VertexElement::TYPE_FLOAT4, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_POSITION, 0 },
	{ 0, 16, VertexElement::TYPE_COLOR,	 VertexElement::METHOD_DEFAULT, VertexElement::USAGE_COLOR,    0 },
	{ 0, 32, VertexElement::TYPE_FLOAT2, VertexElement::METHOD_DEFAULT, VertexElement::USAGE_TEXCOORD, 0 },
	AE_DESC_END( 40 )
};

// Match the VertexType order
VertexDescs g_VertexDescs =
{
	VertexPos3Desc,
	VertexPos4Desc,
	VertexPos3ColorDesc,
	VertexPos4ColorDesc,
	VertexPos3TexDesc,
	VertexPos4TexDesc,
	VertexPos3ColorTexDesc,
	VertexPos4ColorTexDesc
};

// Match the VertexType order
#define GET_STRIDE( _descName ) _descName[ARRAY_SIZE(_descName)-1].m_offset
u32 g_VertexStrides[] =
{
	GET_STRIDE( VertexPos3Desc ),
	GET_STRIDE( VertexPos4Desc ),
	GET_STRIDE( VertexPos3ColorDesc ),
	GET_STRIDE( VertexPos4ColorDesc ),
	GET_STRIDE( VertexPos3TexDesc ),
	GET_STRIDE( VertexPos4TexDesc ),
	GET_STRIDE( VertexPos3ColorTexDesc ),
	GET_STRIDE( VertexPos4ColorTexDesc )
};

// Match the VertexType order
#define GET_NUM_ELEMENTS( _descName ) (ARRAY_SIZE(_descName)-1)
int g_NumElements[] =
{
	GET_NUM_ELEMENTS( VertexPos3Desc ),
	GET_NUM_ELEMENTS( VertexPos4Desc ),
	GET_NUM_ELEMENTS( VertexPos3ColorDesc ),
	GET_NUM_ELEMENTS( VertexPos4ColorDesc ),
	GET_NUM_ELEMENTS( VertexPos3TexDesc ),
	GET_NUM_ELEMENTS( VertexPos4TexDesc ),
	GET_NUM_ELEMENTS( VertexPos3ColorTexDesc ),
	GET_NUM_ELEMENTS( VertexPos4ColorTexDesc )
};