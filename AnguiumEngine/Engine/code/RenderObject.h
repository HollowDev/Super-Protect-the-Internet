#pragma once
#ifndef _RENDER_OBJECT_H_
#define _RENDER_OBJECT_H_

namespace AnguiumEngine
{
	
	class RenderObject
	{
		u32				m_TexID; // the id of the texture, in the asset pool
		f32				m_DrawOrder;
		D3DXMATRIX		m_World;
		bool			m_IsHUD; // means it ignores teh camera
	
		//GameObject* m_Owner;
	
	public:
		RenderObject( void );
		~RenderObject( void );
	
		void Render( IDirect3DDevice9* _device, ID3DXEffect* _effect );
	
		// Accessors
		inline u32 GetTexID( void )				{ return m_TexID;		}
		inline f32 GetDrawOrder( void )			{ return m_DrawOrder;	}
		inline D3DXMATRIX GetWorld( void )		{ return m_World;		}
		inline bool GetIsHUD( void )			{ return m_IsHUD;		}
	
		// Mutators
		inline void SetTexID( u32 _texID )				{ m_TexID = _texID;			}
		inline void SetDrawOrder( f32 _drawOrder )		{ m_DrawOrder = _drawOrder; }
		inline void SetWorld( D3DXMATRIX _world )		{ m_World = _world;			}
		inline void SetIsHUD( bool _isHUD )				{ m_IsHUD = _isHUD;			}
		//inline void SetOwner( GameObject* _owner )		{ m_Owner = _owner;			}
	};

}

#endif