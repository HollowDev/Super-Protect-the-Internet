#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

namespace AnguiumEngine
{

	class Camera
	{
	protected:
		Matrix m_View;
		Matrix m_Projection;
		Matrix m_ViewProjection;
		Vector2 m_Pos;
	
	public:
		Camera( void );
		~Camera( void );
	
		virtual void Update( float _timing );
		void CreateOrthographic( float _halfWidth, float _halfHeight );
	
		// Accessors
		inline Matrix GetView( void ) const			{ return m_View;			}
		inline Matrix GetProj( void ) const			{ return m_Projection;		}
		inline Matrix GetViewProj( void ) const		{ return m_ViewProjection;	}
		inline Vector2 GetPos( void ) const			{ return m_Pos;				}
	
		// Mutators
		inline void SetPos( Vector2 _pos ) { m_Pos = _pos; }
	};

}

#endif