#pragma once
#ifndef _SHADER_PASS_H_
#define _SHADER_PASS_H_

namespace AnguiumEngine
{
	using namespace AnguiumMath;

	class ShaderPass
	{
	#ifdef AE_DX9
		ID3DXEffect* m_Effect;
	#endif
	
	public:
		ShaderPass( void );
		~ShaderPass( void );
	
		bool Initialize( const char* _fileName );
		void Release( void );
	
		u32 Begin( void );
		void End( void );
		void BeginPass( u32 _pass );
		void EndPass( void );

		void Commit( void );
	
		void SetMatrix( const char* _name, const Matrix* const _matrix );
		void SetVector2( const char* _name, const Vector2* const _vec2 );
		void SetVector3( const char* _name, const Vector3* const _vec3 );
		void SetTexture( const char* _name, const void* _texture );
	};

}

#endif