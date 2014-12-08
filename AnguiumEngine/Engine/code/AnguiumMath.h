/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Anguium Engine Math
	Desc: Math libraries, both structures and functions
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _ANGUIUM_MATH_H_
#define _ANGUIUM_MATH_H_

#include <math.h>

namespace AnguiumMath
{
	#define AE_EPSILON			(0.001f)
	#define AE_PI				(3.14159265359f)
	#define AE_2PI				(6.28318530718f)
	#define AE_PI2				(1.57079632679f)
	#define AE_DEG_PER_RAD		(57.2957795f)
	#define AE_RAD_PER_DEG		(0.0174532925f)
	#define AE_DEG_TO_RAD(deg)	(AE_RAD_PER_DEG * deg)
	#define AE_RAD_TO_DEG(rad)	(AE_DEG_PER_RAD * rad)

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Summary: Interpolates the type linearly
	Params:
		_a - the starting value
		_b - the ending value
		_step - the step between the value
	Return:
		const type - the value that was solved for
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	template< class type >
	inline const type Lerp( const type& _a, const type& _b, float _step )
	{
		return _a + (_b - _a) * _step;
	}
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Summary: Clamps the value between the min and max
	Params:
		_main - the value to check with
		_min - the minimum value
		_max - the maximum value
	Return:
		const type - the clamped value
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	template< class type >
	inline const type Clamp( const type& _main, const type& _min, const type& _max )
	{
		type ret( _main );
		if( ret < _min )		{ ret = _min; }
		else if( ret > _max )	{ ret = _max; }
		return ret;
	}

	struct Vector2
	{
	public:
		union
		{
			struct
			{
				f32 x;
				f32 y;
			};
	
			f32 v[2];
		};
	
		static const Vector2 ZERO;
		static const Vector2 ONE;
	
		// Constructors
		Vector2( void );
		Vector2( const Vector2& _vec );
		Vector2( const f32 _x, const f32 _y );
		Vector2( const f32 _val );
		Vector2( const f32* _val );
	
		// Returns a normalized version of this vector
		const Vector2 Normalize( void ) const; 
		// Returns the squared length of the vector
		const f32 LengthSq( void ) const;
		// Returns the length of the vector
		const f32 Length( void ) const;
		// Returns the dot product of the current and _other vector
		const f32 DotProduct( const Vector2& _other ) const;
		// Returns the squared distance between the current and _other vector
		const f32 DistanceSq( const Vector2& _other ) const;
		// Returns the distance between the current and _other vector
		const f32 Distance( const Vector2& _other ) const;
		// Returns the angle between the vectors
		const f32 AngleBetween( const Vector2& _other, bool _isRad = true ) const;
		// Returns the absolute value of the vector
		const Vector2 Abs( void ) const;
		// Clamps the value between the min and max
		void Clamp( const Vector2& _min, const Vector2& _max );
		// Rotates the vector
		void Rotate2D( const Vector2& _vec, const f32& _radians );
		// 
		float Steering( const Vector2& _other );
	
		// Operators
		inline Vector2& operator=( const Vector2& _rhs )		{ x = _rhs.x; y = _rhs.y; return *this;			}
		inline Vector2 operator+( const Vector2& _rhs ) const	{ return Vector2( x+_rhs.x, y+_rhs.y	);		}
		inline Vector2 operator+( const f32& _rhs ) const		{ return Vector2( x+_rhs,	y+_rhs		);		}
		inline Vector2 operator-( const Vector2& _rhs ) const	{ return Vector2( x-_rhs.x, y-_rhs.y	);		}
		inline Vector2 operator-( const f32& _rhs ) const		{ return Vector2( x-_rhs,	y-_rhs		);		}
		inline Vector2 operator*( const Vector2& _rhs ) const	{ return Vector2( x*_rhs.x, y*_rhs.y	);		}
		inline Vector2 operator*( const f32& _rhs ) const		{ return Vector2( x*_rhs,	y*_rhs		);		}
		inline Vector2 operator/( const Vector2& _rhs ) const	{ return Vector2( x/_rhs.x, y/_rhs.y	);		}
		inline Vector2 operator/( const f32& _rhs ) const		{ return Vector2( x/_rhs,	y/_rhs		);		}
		inline Vector2 operator-( void ) const					{ return Vector2( -x, -y );						}
		inline Vector2& operator+=( const Vector2& _rhs )		{ x += _rhs.x; y += _rhs.y; return *this;		}
		inline Vector2& operator+=( const f32& _rhs )			{ x += _rhs;   y += _rhs;   return *this;		}
		inline Vector2& operator-=( const Vector2& _rhs )		{ x -= _rhs.x; y -= _rhs.y; return *this;		}
		inline Vector2& operator-=( const f32& _rhs )			{ x -= _rhs;   y -= _rhs;   return *this;		}
		inline Vector2& operator*=( const Vector2& _rhs )		{ x *= _rhs.x; y *= _rhs.y; return *this;		}
		inline Vector2& operator*=( const f32& _rhs )			{ x *= _rhs;   y *= _rhs;   return *this;		}
		inline Vector2& operator/=( const Vector2& _rhs )		{ x /= _rhs.x; y /= _rhs.y; return *this;		}
		inline Vector2& operator/=( const f32& _rhs )			{ x /= _rhs;   y /= _rhs;   return *this;		}
		
		inline bool operator==( const Vector2& _rhs ) const	{ return x == _rhs.x && y == _rhs.y; }
		inline bool operator!=( const Vector2& _rhs ) const	{ return x != _rhs.x && y != _rhs.y; }
		inline bool operator<( const Vector2& _rhs ) const	{ return x <  _rhs.x && y <  _rhs.y; }
		inline bool operator>( const Vector2& _rhs ) const	{ return x >  _rhs.x && y >  _rhs.y; }
		inline bool operator<=( const Vector2& _rhs ) const	{ return x <= _rhs.x && y <= _rhs.y; }
		inline bool operator>=( const Vector2& _rhs ) const	{ return x >= _rhs.x && y >= _rhs.y; }
	
		inline f32 operator[]( const int& _index ) const	{ return v[_index]; }
		inline f32& operator[]( const int& _index )			{ return v[_index]; }
	};

	struct Vector3
	{
	public:
		union
		{
			struct
			{
				f32 x;
				f32 y;
				f32 z;
			};
	
			f32 v[3];
		};
	
		static const Vector3 ZERO;
		static const Vector3 ONE;
	
		// Constructors
		Vector3( void );
		Vector3( const Vector3& _vec );
		Vector3( const f32 _x, const f32 _y, const f32 _z = 0.0f );
		Vector3( const f32 _val );
		Vector3( const f32* _val );
	
		// Returns a normalized version of this vector
		const Vector3 Normalize( void ) const; 
		// Returns the cross product of the current and _other vector
		const Vector3 CrossProduct( const Vector3& _other ) const;
		// Returns the squared length of the vector
		const f32 LengthSq( void ) const;
		// Returns the length of the vector
		const f32 Length( void ) const;
		// Returns the dot product of the current and _other vector
		const f32 DotProduct( const Vector3& _other ) const;
		// Returns the squared distance between the current and _other vector
		const f32 DistanceSq( const Vector3& _other ) const;
		// Returns the distance between the current and _other vector
		const f32 Distance( const Vector3& _other ) const;
		// Returns the angle between the vectors
		const f32 AngleBetween( const Vector3& _other, bool _isRad = true ) const;
		// Returns the absolute value of the vector
		const Vector3 Abs( void ) const;
		// Clamps the value between the min and max
		void Clamp( const Vector3& _min, const Vector3& _max );
	
		// Operators
		inline Vector3& operator=( const Vector3& _rhs )		{ x = _rhs.x; y = _rhs.y; z = _rhs.z; return *this;			}
		inline Vector3& operator=( const Vector2& _rhs )		{ x = _rhs.x; y = _rhs.y; z = 0.0f;   return *this;			}
		inline Vector3 operator+( const Vector3& _rhs ) const	{ return Vector3( x+_rhs.x, y+_rhs.y,	z+_rhs.z	);		}
		inline Vector3 operator+( const Vector2& _rhs ) const	{ return Vector3( x+_rhs.x, y+_rhs.y,	z			);		}
		inline Vector3 operator+( const f32& _rhs ) const		{ return Vector3( x+_rhs,	y+_rhs,		z+_rhs		);		}
		inline Vector3 operator-( const Vector3& _rhs ) const	{ return Vector3( x-_rhs.x, y-_rhs.y,	z-_rhs.z	);		}
		inline Vector3 operator-( const Vector2& _rhs ) const	{ return Vector3( x-_rhs.x, y-_rhs.y,	z			);		}
		inline Vector3 operator-( const f32& _rhs ) const		{ return Vector3( x-_rhs,	y-_rhs,		z-_rhs		);		}
		inline Vector3 operator*( const Vector3& _rhs ) const	{ return Vector3( x*_rhs.x, y*_rhs.y,	z*_rhs.z	);		}
		inline Vector3 operator*( const Vector2& _rhs ) const	{ return Vector3( x*_rhs.x, y*_rhs.y,	z			);		}
		inline Vector3 operator*( const f32& _rhs ) const		{ return Vector3( x*_rhs,	y*_rhs,		z*_rhs		);		}
		inline Vector3 operator/( const Vector3& _rhs ) const	{ return Vector3( x/_rhs.x, y/_rhs.y,	z/_rhs.z	);		}
		inline Vector3 operator/( const Vector2& _rhs ) const	{ return Vector3( x/_rhs.x, y/_rhs.y,	z			);		}
		inline Vector3 operator/( const f32& _rhs ) const		{ return Vector3( x/_rhs,	y/_rhs,		z/_rhs		);		}
		inline Vector3 operator-( void ) const					{ return Vector3( -x, -y, -z );								}
		inline Vector3& operator+=( const Vector3& _rhs )		{ x += _rhs.x; y += _rhs.y; z += _rhs.z; return *this;		}
		inline Vector3& operator+=( const Vector2& _rhs )		{ x += _rhs.x; y += _rhs.y;				 return *this;		}
		inline Vector3& operator+=( const f32& _rhs )			{ x += _rhs;   y += _rhs;   z += _rhs;   return *this;		}
		inline Vector3& operator-=( const Vector3& _rhs )		{ x -= _rhs.x; y -= _rhs.y; z -= _rhs.z; return *this;		}
		inline Vector3& operator-=( const Vector2& _rhs )		{ x -= _rhs.x; y -= _rhs.y;				 return *this;		}
		inline Vector3& operator-=( const f32& _rhs )			{ x -= _rhs;   y -= _rhs;   z -= _rhs;   return *this;		}
		inline Vector3& operator*=( const Vector3& _rhs )		{ x *= _rhs.x; y *= _rhs.y; z *= _rhs.z; return *this;		}
		inline Vector3& operator*=( const Vector2& _rhs )		{ x *= _rhs.x; y *= _rhs.y;				 return *this;		}
		inline Vector3& operator*=( const f32& _rhs )			{ x *= _rhs;   y *= _rhs;   z *= _rhs;   return *this;		}
		inline Vector3& operator/=( const Vector3& _rhs )		{ x /= _rhs.x; y /= _rhs.y; z /= _rhs.z; return *this;		}
		inline Vector3& operator/=( const Vector2& _rhs )		{ x /= _rhs.x; y /= _rhs.y;				 return *this;		}
		inline Vector3& operator/=( const f32& _rhs )			{ x /= _rhs;   y /= _rhs;   z /= _rhs;   return *this;		}
		
		inline bool operator==( const Vector3& _rhs ) const	{ return x == _rhs.x && y == _rhs.y && z == _rhs.z; }
		inline bool operator!=( const Vector3& _rhs ) const	{ return x != _rhs.x && y != _rhs.y && z != _rhs.z; }
		inline bool operator<( const Vector3& _rhs ) const	{ return x <  _rhs.x && y <  _rhs.y && z <  _rhs.z; }
		inline bool operator>( const Vector3& _rhs ) const	{ return x >  _rhs.x && y >  _rhs.y && z >  _rhs.z; }
		inline bool operator<=( const Vector3& _rhs ) const	{ return x <= _rhs.x && y <= _rhs.y && z <= _rhs.z; }
		inline bool operator>=( const Vector3& _rhs ) const	{ return x >= _rhs.x && y >= _rhs.y && z >= _rhs.z; }
	
		inline f32 operator[]( const int& _index ) const	{ return v[_index]; }
		inline f32& operator[]( const int& _index )			{ return v[_index]; }
	};

	struct Color
	{
		union
		{
			struct
			{
				f32 r;
				f32 g;
				f32 b;
				f32 a;
			};
			f32 c[4];
		};

		Color( void ) : r(1.0f), g(1.0f), b(1.0f), a(1.0f) {}
		Color( f32 _val ) : r(_val), g(_val), b(_val), a(_val) {}
		Color( f32 _r, f32 _g, f32 _b, f32 _a ) : r(_r), g(_g), b(_b), a(_a) {}
		
		D3DXCOLOR GetD3DColor( void ) { return D3DXCOLOR( r, g, b, a ); }
		
		static Color CLEAR;
		static Color BLACK;
		static Color RED;
		static Color GREEN;
		static Color BLUE;
		static Color WHITE;
		static Color YELLOW;
		static Color MAGENTA;
	};
	
	class Matrix
	{
	public:
		union
		{
			struct
			{
				float _00, _01, _02, _03;
				float _10, _11, _12, _13;
				float _20, _21, _22, _23;
				float _30, _31, _32, _33;
			};
			float m[4][4];
			float a[16];
		};
		
		static const Matrix IDENTITY;
		
		// Constructors
		Matrix( void );
		Matrix( const Matrix& _mat );
		Matrix( const float* _mat );
		Matrix( const Vector3& _row0, const Vector3& _row1, const Vector3& _row2 );
		Matrix( 
			const float _00, const float _01, const float _02, const float _03,
			const float _10, const float _11, const float _12, const float _13,
			const float _20, const float _21, const float _22, const float _23,
			const float _30, const float _31, const float _32, const float _33 
		);
	
		// Resets this matrix back to an identity matrix
		void Identity( void );
		// Scales the matrix 
		void Scale( const Vector3& _scale );
		void Scale( const float& _scale );
		// Rotation
		void RotateZ( const float& _angle );
		// Translates the matrix 
		void Translate( const Vector3& _translation );
		// Create projection matrices
		void CreateOrthoOffCenterLH( f32 _l, f32 _r, f32 _b, f32 _t, f32 _zn, f32 _zf );
		// Inverses the matrix
		bool Inverse( void );
		// Returns the position of the matrix
		const Vector3 Position( void ) const;
	
		void Multiply( Matrix* _out, const Matrix* _lhs, const Matrix* _rhs ) const;

		// Operator
		Matrix operator*( const Matrix& _rhs ) const;
		Matrix operator+( const Matrix& _rhs ) const;
		Matrix& operator*=( const Matrix& _rhs );
		Matrix& operator+=( const Matrix& _rhs );
		inline Matrix& operator=( const Matrix& _rhs ) { for( int i = 0; i < 16; ++i ) a[i] = _rhs.a[i]; return *this;	}
		inline float operator[]( const unsigned int& _index ) const	{ return a[_index]; }
		inline float& operator[]( const unsigned int& _index )		{ return a[_index]; }
	};

	class Transform
	{
		Matrix	world;
		Vector2 pos;
		Vector2 scale;
		Vector2 center;
		Vector2 dir;
		f32		rot;
		bool isDirty;
		
		void CalcDir( void );
		void CalcWorld( void );
	public:
		Transform( void );
		
		void Update( f32 _timing );
		
		// Accessors
		inline Matrix GetWorld( void ) const	{ return world;	 }
		inline Vector2 GetPos( void ) const		{ return pos;	 }
		inline Vector2 GetScale( void ) const	{ return scale;	 }
		inline Vector2 GetCenter( void ) const	{ return center; }
		inline Vector2 GetDir( void ) const		{ return dir;	 }
		inline f32 GetRot( void ) const			{ return rot;	 }

		// Mutators
		void SetPos( const Vector2& _pos )			{ pos = _pos;		isDirty = true; }
		void SetScale( const Vector2& _scale )		{ scale = _scale;	isDirty = true; }
		void SetCenter( const Vector2& _center )	{ center = _center; isDirty = true; }
		void SetRot( const f32& _rot )				{ rot = _rot;		isDirty = true; }
	};
}

#endif