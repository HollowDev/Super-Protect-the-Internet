#pragma once
#ifndef _VERTEX_DESC_H_
#define _VERTEX_DESC_H_

struct VertexElement
{
	enum Type
	{
#ifdef AE_DX9
		TYPE_FLOAT1      = D3DDECLTYPE_FLOAT1,    
		TYPE_FLOAT2      = D3DDECLTYPE_FLOAT2,    
		TYPE_FLOAT3      = D3DDECLTYPE_FLOAT3,    
		TYPE_FLOAT4      = D3DDECLTYPE_FLOAT4,    
		TYPE_COLOR       = D3DDECLTYPE_D3DCOLOR,  
		TYPE_UBYTE4      = D3DDECLTYPE_UBYTE4,    
		TYPE_SHORT2      = D3DDECLTYPE_SHORT2,    
		TYPE_SHORT4      = D3DDECLTYPE_SHORT4,    
		TYPE_UBYTE4N     = D3DDECLTYPE_UBYTE4N,   
		TYPE_SHORT2N     = D3DDECLTYPE_SHORT2N,   
		TYPE_SHORT4N     = D3DDECLTYPE_SHORT4N,   
		TYPE_FLOAT16_2   = D3DDECLTYPE_FLOAT16_2, 
		TYPE_FLOAT16_4   = D3DDECLTYPE_FLOAT16_4, 
		TYPE_UINT1		 = D3DDECLTYPE_UBYTE4,
		TYPE_UINT2		 = D3DDECLTYPE_SHORT4,
		TYPE_UNUSED      = D3DDECLTYPE_UNUSED,    
#endif
	};

	enum Method
	{
#ifdef AE_DX9
		METHOD_DEFAULT          = D3DDECLMETHOD_DEFAULT,
		METHOD_PARTIALU         = D3DDECLMETHOD_PARTIALU,
		METHOD_PARTIALV         = D3DDECLMETHOD_PARTIALV,
		METHOD_CROSSUV          = D3DDECLMETHOD_CROSSUV,          
		METHOD_UV               = D3DDECLMETHOD_UV,
		METHOD_LOOKUP           = D3DDECLMETHOD_LOOKUP,           
		METHOD_LOOKUPPRESAMPLED = D3DDECLMETHOD_LOOKUPPRESAMPLED, 
#endif
	};

	enum Usage
	{
#ifdef AE_DX9
		USAGE_POSITION     = D3DDECLUSAGE_POSITION,
		USAGE_BLENDWEIGHT  = D3DDECLUSAGE_BLENDWEIGHT,
		USAGE_BLENDINDICES = D3DDECLUSAGE_BLENDINDICES,
		USAGE_NORMAL       = D3DDECLUSAGE_NORMAL,
		USAGE_PSIZE        = D3DDECLUSAGE_PSIZE,
		USAGE_TEXCOORD     = D3DDECLUSAGE_TEXCOORD,
		USAGE_TANGENT      = D3DDECLUSAGE_TANGENT,
		USAGE_BINORMAL     = D3DDECLUSAGE_BINORMAL,
		USAGE_TESSFACTOR   = D3DDECLUSAGE_TESSFACTOR,
		USAGE_COLOR        = D3DDECLUSAGE_COLOR,
		USAGE_FOG          = D3DDECLUSAGE_FOG,
#endif
	};

	#ifdef AE_DX9
		u16 m_stream;
		u16 m_offset;
		u8  m_type;
		u8  m_method;
		u8  m_usage;
		u8  m_usageIndex;
	#endif
};

#if defined AE_DX9
#define AE_DESC_END( stride ) { 0xFF, 0, VertexElement::TYPE_UNUSED, 0, 0, 0 }
#endif

typedef VertexElement  VertexDesc[];
typedef VertexElement* VertexDescs[];

#endif