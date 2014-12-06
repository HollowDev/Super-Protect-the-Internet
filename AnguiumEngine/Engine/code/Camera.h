#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

namespace AnguiumEngine
{

	class Camera
	{
	protected:
		D3DXMATRIX m_View;
		D3DXMATRIX m_Projection;
		D3DXMATRIX m_ViewProjection;
		D3DXVECTOR2 m_Pos;
	
	public:
		Camera( void );
		~Camera( void );
	
		virtual void Update( float _timing );
		void CreateOrthographic( float _halfWidth, float _halfHeight );
	
		// Accessors
		inline D3DXMATRIX GetView( void ) const			{ return m_View;			}
		inline D3DXMATRIX GetProj( void ) const			{ return m_Projection;		}
		inline D3DXMATRIX GetViewProj( void ) const		{ return m_ViewProjection;	}
		inline D3DXVECTOR2 GetPos( void ) const			{ return m_Pos;				}
	
		// Mutators
		inline void SetPos( D3DXVECTOR2 _pos ) { m_Pos = _pos; }
	};

}

#endif