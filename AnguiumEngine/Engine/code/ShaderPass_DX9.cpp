#include "AnguiumEngine.h"

#ifdef AE_DX9

ShaderPass::ShaderPass( void ) :
	m_Effect( nullptr )
{
}

ShaderPass::~ShaderPass( void )
{
	Release();
}

bool ShaderPass::Initialize( const char* _fileName )
{
	IDirect3DDevice9* device = reinterpret_cast<IDirect3DDevice9*>(g_RenderDevice->GetDevice());
	ASSERT(device); // make sure it exists!
	
	u32 fileNameLength = strlen(_fileName);
	wchar_t* wFileName = new wchar_t[fileNameLength+1];
	for( u32 i = 0; i < fileNameLength; ++i )
		wFileName[i] = _fileName[i];

	wFileName[fileNameLength] = '\0';

	HRESULT hr = D3DXCreateEffectFromFile( device, L"assets/effects/textured.fx", 0, 0, 0, 0, &m_Effect, 0 );
	if( FAILED( hr ) )
	{
		SAFE_DELETE( wFileName );
		return false;
	}
	
	SAFE_DELETE( wFileName );
	return true;
}

void ShaderPass::Release( void )
{
	SAFE_RELEASE( m_Effect );
}

u32 ShaderPass::Begin( void )
{
	u32 passes = 0;
	m_Effect->Begin( &passes, 0 );
	return passes;
}

void ShaderPass::End( void )
{
	m_Effect->End();
}

void ShaderPass::BeginPass( u32 _pass )
{
	m_Effect->BeginPass( _pass );
}

void ShaderPass::EndPass( void )
{
	m_Effect->EndPass();
}

void ShaderPass::Commit( void )
{
	m_Effect->CommitChanges();
}

void ShaderPass::SetMatrix( const char* _name, const Matrix* const _matrix )
{
	D3DXMATRIX mat( _matrix->a );
	m_Effect->SetMatrix( _name, &mat );
}

void ShaderPass::SetVector2( const char* _name, const Vector2* const _vec2 )
{
	//D3DXVECTOR3 vec( _vec2->x, _vec2->y, 0.0f );
	//m_Effect->SetV
}

void ShaderPass::SetVector3( const char* _name, const Vector3* const _vec3 )
{
}
	
void ShaderPass::SetTexture( const char* _name, const void* _texture )
{
	LPDIRECT3DTEXTURE9 tex = (LPDIRECT3DTEXTURE9)_texture;
	m_Effect->SetTexture( "gTexture", tex );
}


#endif