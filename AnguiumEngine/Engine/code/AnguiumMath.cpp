/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Anguium Engine Math
	Desc: Math libraries, both structures and functions
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "AnguiumEngine.h"

const Vector2 Vector2::ZERO( 0.0f, 0.0f );
const Vector3 Vector3::ZERO( 0.0f, 0.0f, 0.0f );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector2::Vector2( void ) : 
	x( 0.0f ), 
	y( 0.0f )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Copy constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector2::Vector2( const Vector2& _vec ) : 
	x( _vec.x ), 
	y( _vec.y )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
Params:
	_x - starting x
	_y - starting y
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector2::Vector2( const f32 _x, const f32 _y ) : 
	x( _x ), 
	y( _y )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
Params:
	_val - the float to set all elements to
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector2::Vector2( const f32 _val ) : 
	x( _val ), 
	y( _val )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
Params:
	_val - the float array to set the vector to
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector2::Vector2( const f32* _val ) : 
	x( _val[0] ), 
	y( _val[1] )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns a normalized version of this vector
Return:
	const kVec - the normalized vector
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const Vector2 Vector2::Normalize( void ) const
{
	const f32 length = this->Length();
	if( length != 0.0f )
	{
		return this->operator*( 1.0f / length );
	}
	return *this;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the squared length of the vector
Return:
	const float - squared length
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector2::LengthSq( void ) const
{
	return (x * x) + (y * y);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the length of the current vector
Return:
	const float - vector's length
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector2::Length( void ) const
{
	return sqrtf( LengthSq() );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the dot product of the current vector and _vec
Params:
	_other - the vector to dot product with
Return:
	const float - dot product result
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector2::DotProduct( const Vector2& _other ) const
{
	return (this->x * _other.x) + (this->y * _other.y);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the squared distance between the current and _other vector
Params:
	_other - the vector to check the distance with
Return:
	const float - squared distance
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector2::DistanceSq( const Vector2& _other ) const
{
	return ((x - _other.x) * (x - _other.x)) + ((y - _other.y) * (y - _other.y));
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the distance between the current and _other vector
Params:
	_other - the vector to check the distance with
Return:
	const float - distance
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector2::Distance( const Vector2& _other ) const
{
	return sqrtf( DistanceSq(_other) );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the angle--in radians--between the vectors
Params:
	_other - the vector to check the angle between
	_isRad - is the returned angle in radians?
Return:
	const float - the angle in radian
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector2::AngleBetween( const Vector2& _other, bool _isRad ) const
{
	// Dot product
	f32 dot = DotProduct( _other );
	// Length of those vectors
	const f32 length = this->Length() * _other.Length();
	// Make sure we don't get a divide by zero error.
	if( length == 0.0f ) return 0.0f;
	// Calculate the angle between the two vectors
	f32 angle = acos( dot / length );
	// Make sure the number is not indefinite.
	angle = ( angle != angle ? 0.0f : angle );

	return ( _isRad ? angle : AE_RAD_TO_DEG( angle ) );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the absolute value of the vector
Return:
	const kVec - abs version of this vector
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const Vector2 Vector2::Abs( void ) const
{
	return Vector2( fabs(x), fabs(y) );
}	
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Clamps the vector between the min and max
Params:
	_min - the minimum value
	_max - the maximum value
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Vector2::Clamp( const Vector2& _min, const Vector2& _max )
{
	Vector2(	
		AnguiumMath::Clamp( this->x, _min.x, _max.x ),
		AnguiumMath::Clamp( this->y, _min.y, _max.y )
	);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector3::Vector3( void ) : 
	x( 0.0f ), 
	y( 0.0f ), 
	z( 0.0f )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Copy constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector3::Vector3( const Vector3& _vec ) : 
	x( _vec.x ), 
	y( _vec.y ), 
	z( _vec.z )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
Params:
	_x - starting x
	_y - starting y
	_z - starting z
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector3::Vector3( const f32 _x, const f32 _y, const f32 _z ) : 
	x( _x ), 
	y( _y ), 
	z( _z )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
Params:
	_val - the float to set all elements to
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector3::Vector3( const float _val ) : 
	x( _val ), 
	y( _val ), 
	z( _val )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
Params:
	_val - the float array to set the vector to
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Vector3::Vector3( const f32* _val ) : 
	x( _val[0] ), 
	y( _val[1] ), 
	z( _val[2] )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns a normalized version of this vector
Return:
	const kVec - the normalized vector
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const Vector3 Vector3::Normalize( void ) const
{
	const f32 length = this->Length();
	if( length != 0.0f )
	{
		return this->operator*( 1.0f / length );
	}
	return *this;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Locks the vertex buffer so you can construct the new verts
Return:
	Vertex_PosTex* - Pointer to the verts
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// Returns the cross product of the current and _other vector
const Vector3 Vector3::CrossProduct( const Vector3& _other ) const
{
	return Vector3((y * _other.z) - (z * _other.y), (z * _other.x) - (x * _other.z), (x * _other.y) - (y * _other.x));
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the squared length of the vector
Return:
	const float - squared length
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector3::LengthSq( void ) const
{
	return (x * x) + (y * y) + (z * z);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the length of the current vector
Return:
	const float - vector's length
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector3::Length( void ) const
{
	return sqrtf( LengthSq() );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the dot product of the current vector and _vec
Params:
	_other - the vector to dot product with
Return:
	const float - dot product result
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector3::DotProduct( const Vector3& _other ) const
{
	return (this->x * _other.x) + (this->y * _other.y) + (this->z * _other.z);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the squared distance between the current and _other vector
Params:
	_other - the vector to check the distance with
Return:
	const float - squared distance
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector3::DistanceSq( const Vector3& _other ) const
{
	return ((x - _other.x) * (x - _other.x)) + ((y - _other.y) * (y - _other.y))  + ((z - _other.z) * (z - _other.z));
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the distance between the current and _other vector
Params:
	_other - the vector to check the distance with
Return:
	const float - distance
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector3::Distance( const Vector3& _other ) const
{
	return sqrtf( DistanceSq(_other) );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the angle--in radians--between the vectors
Params:
	_other - the vector to check the angle between
	_isRad - is the returned angle in radians?
Return:
	const float - the angle in radian
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const f32 Vector3::AngleBetween( const Vector3& _other, bool _isRad ) const
{
	// Dot product
	f32 dot = DotProduct( _other );
	// Length of those vectors
	const f32 length = this->Length() * _other.Length();
	// Make sure we don't get a divide by zero error.
	if( length == 0.0f ) return 0.0f;
	// Calculate the angle between the two vectors
	f32 angle = acos( dot / length );
	// Make sure the number is not indefinite.
	angle = ( angle != angle ? 0.0f : angle );

	return ( _isRad ? angle : AE_RAD_TO_DEG( angle ) );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the absolute value of the vector
Return:
	const kVec - abs version of this vector
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const Vector3 Vector3::Abs( void ) const
{
	return Vector3( fabs(x), fabs(y), fabs(z) );
}	
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Clamps the vector between the min and max
Params:
	_min - the minimum value
	_max - the maximum value
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Vector3::Clamp( const Vector3& _min, const Vector3& _max )
{
	Vector3(	
		AnguiumMath::Clamp( this->x, _min.x, _max.x ),
		AnguiumMath::Clamp( this->y, _min.y, _max.y ),
		AnguiumMath::Clamp( this->z, _min.z, _max.z )
	);
}

Color Color::CLEAR		= Color( 0.0f, 0.0f, 0.0f, 0.0f );
Color Color::BLACK		= Color( 0.0f, 0.0f, 0.0f, 1.0f );
Color Color::RED		= Color( 1.0f, 0.0f, 0.0f, 1.0f );
Color Color::GREEN		= Color( 0.0f, 1.0f, 0.0f, 1.0f );
Color Color::BLUE		= Color( 0.0f, 0.0f, 1.0f, 1.0f );
Color Color::WHITE		= Color( 1.0f, 1.0f, 1.0f, 1.0f );
Color Color::YELLOW		= Color( 1.0f, 1.0f, 0.0f, 1.0f );
Color Color::MAGENTA	= Color( 0.0f, 1.0f, 1.0f, 1.0f );

const Matrix Matrix::IDENTITY(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix::Matrix( void )
{
	Identity();
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Copy constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix::Matrix( const Matrix& _mat )
{
	this->operator=( _mat );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix::Matrix( const float* _mat )
{
	for( unsigned int i = 0; i < 16; ++i )
		a[i] = _mat[i];
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix::Matrix( const Vector3& _row0, const Vector3& _row1, const Vector3& _row2 )
{
	_00 = _row0.x; _01 = _row0.y; _02 = _row0.z; _03 = 0.0f;
	_10 = _row1.x; _11 = _row1.y; _12 = _row1.z; _13 = 0.0f;
	_20 = _row2.x; _21 = _row2.y; _22 = _row2.z; _23 = 0.0f;
	_30 = 0.0f;	   _31 = 0.0f;    _32 = 0.0f;    _33 = 1.0f;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Overloaded constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix::Matrix( 
	const float __00, const float __01, const float __02, const float __03,
	const float __10, const float __11, const float __12, const float __13,
	const float __20, const float __21, const float __22, const float __23,
	const float __30, const float __31, const float __32, const float __33 
) :
	_00( __00 ), _01( __01 ), _02( __02 ), _03( __03 ),
	_10( __10 ), _11( __11 ), _12( __12 ), _13( __13 ),
	_20( __20 ), _21( __21 ), _22( __22 ), _23( __23 ),
	_30( __30 ), _31( __31 ), _32( __32 ), _33( __33 )
{
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Resets this matrix back to an identity matrix
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Matrix::Identity( void )
{
	this->operator=( IDENTITY );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Scales the matrix 
Params:
	_scale - the vector to scale by
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Matrix::Scale( const Vector3& _scale )
{
	this->_00 *= _scale.x; this->_01 *= _scale.y; this->_02 *= _scale.z; 
	this->_10 *= _scale.x; this->_11 *= _scale.y; this->_12 *= _scale.z; 
	this->_20 *= _scale.x; this->_21 *= _scale.y; this->_22 *= _scale.z; 
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Scales the matrix 
Params:
	_scale - the float to scale by
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Matrix::Scale( const float& _scale )
{
	this->_00 *= _scale; this->_01 *= _scale; this->_02 *= _scale; 
	this->_10 *= _scale; this->_11 *= _scale; this->_12 *= _scale; 
	this->_20 *= _scale; this->_21 *= _scale; this->_22 *= _scale; 
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Translates the matrix 
Params:
	_translation - the vector to translate by
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Matrix::Translate( const Vector3& _translation )
{
	this->_03 += _translation.x;
	this->_13 += _translation.y;
	this->_23 += _translation.z;
}
// Create projection matrices
void Matrix::CreateOrthoOffCenterLH( f32 _l, f32 _r, f32 _b, f32 _t, f32 _zn, f32 _zf )
{	
	Matrix mat(
		2.0f/(_r-_l),		0.0f,				0.0f,			0.0f,
		0.0f,				2.0f/(_t-_b),		0.0f,			0.0f,
		0.0f,				0.0f,				1.0f/(_zf-_zn), 0.0f,
		(_l+_r)/(_l-_r),	(_t+_b)/(_b-_t),	_zn/(_zn-_zf),	1.0f
	);

	this->operator=( mat );
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Inverses the matrix
Return:
	bool - true if successful
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool Matrix::Inverse( void )
{
	const float d00_11 = this->m[0][0] * this->m[1][1];
	const float d01_10 = this->m[0][1] * this->m[1][0];
	const float d22_33 = this->m[2][2] * this->m[3][3];
	const float d23_32 = this->m[2][3] * this->m[3][2];
	
	const float d00_12 = this->m[0][0] * this->m[1][2];
	const float d02_10 = this->m[0][2] * this->m[1][0];
	const float d21_33 = this->m[2][1] * this->m[3][3];
	const float d23_31 = this->m[2][3] * this->m[3][1];

	const float d00_13 = this->m[0][0] * this->m[1][3];
	const float d03_10 = this->m[0][3] * this->m[1][0];
	const float d21_32 = this->m[2][1] * this->m[3][2];
	const float d22_31 = this->m[2][2] * this->m[3][1];

	const float d01_12 = this->m[0][1] * this->m[1][2];
	const float d02_11 = this->m[0][2] * this->m[1][1];
	const float d20_33 = this->m[2][0] * this->m[3][3];
	const float d23_30 = this->m[2][3] * this->m[3][0];

	const float d01_13 = this->m[0][1] * this->m[1][3];
	const float d03_11 = this->m[0][3] * this->m[1][1];
	const float d20_32 = this->m[2][0] * this->m[3][2];
	const float d22_30 = this->m[2][2] * this->m[3][0];

	const float d02_13 = this->m[0][2] * this->m[1][3];
	const float d03_12 = this->m[0][3] * this->m[1][2];
	const float d20_31 = this->m[2][0] * this->m[3][1];
	const float d21_30 = this->m[2][1] * this->m[3][0];

	float d =	(d00_11 - d01_10) * (d22_33 - d23_32) -
				(d00_12 - d02_10) * (d21_33 - d23_31) +
				(d00_13 - d03_10) * (d21_32 - d22_31) +
				(d01_12 - d02_11) * (d20_33 - d23_30) -
				(d01_13 - d03_11) * (d20_32 - d22_30) +
				(d02_13 - d03_12) * (d20_31 - d21_30);

	if( d == 0.0f )	return false;

	const float d02_33 = this->m[0][2] * this->m[3][3];
	const float d03_32 = this->m[0][3] * this->m[3][2];
	const float d03_31 = this->m[0][3] * this->m[3][1];
	const float d01_33 = this->m[0][1] * this->m[3][3];
	const float d01_32 = this->m[0][1] * this->m[3][2];
	const float d02_31 = this->m[0][2] * this->m[3][1];

	const float d13_22 = this->m[1][3] * this->m[2][2];
	const float d12_23 = this->m[1][2] * this->m[2][3];
	const float d11_23 = this->m[1][1] * this->m[2][3];
	const float d13_21 = this->m[1][3] * this->m[2][1];
	const float d12_21 = this->m[1][2] * this->m[2][1];
	const float d11_22 = this->m[1][1] * this->m[2][2];

	const float d00_33 = this->m[0][0] * this->m[3][3];
	const float d03_30 = this->m[0][3] * this->m[3][0];
	const float d02_30 = this->m[0][2] * this->m[3][0];
	const float d00_32 = this->m[0][0] * this->m[3][2];
	const float d10_23 = this->m[1][0] * this->m[2][3];
	const float d10_22 = this->m[1][0] * this->m[2][2];
	const float d12_20 = this->m[1][2] * this->m[2][0];
	const float d13_20 = this->m[1][3] * this->m[2][0];

	const float d00_31 = this->m[0][0] * this->m[3][1];
	const float d01_30 = this->m[0][1] * this->m[3][0];

	const float d11_20 = this->m[1][1] * this->m[2][0];
	const float d10_21 = this->m[1][0] * this->m[2][1];

	d = 1.0f / d;

	this->_00 = d * (this->m[1][1] * (d22_33 - d23_32) + this->m[1][2] * (d23_31 - d21_33) + this->m[1][3] * (d21_32 - d22_31));
	this->_01 = d * (this->m[2][1] * (d02_33 - d03_32) + this->m[2][2] * (d03_31 - d03_31) + this->m[2][3] * (d01_32 - d02_31));
	this->_02 = d * (this->m[3][1] * (d02_13 - d03_12) + this->m[3][2] * (d03_11 - d01_13) + this->m[3][3] * (d01_12 - d02_11));
	this->_03 = d * (this->m[0][1] * (d13_22 - d12_23) + this->m[0][2] * (d11_23 - d13_21) + this->m[0][3] * (d12_21 - d11_22));
	this->_10 = d * (this->m[1][2] * (d20_33 - d23_30) + this->m[1][3] * (d22_30 - d20_32) + this->m[1][0] * (d23_32 - d22_33));
	this->_11 = d * (this->m[2][2] * (d00_33 - d03_30) + this->m[2][3] * (d02_30 - d00_32) + this->m[2][0] * (d03_32 - d02_33));
	this->_12 = d * (this->m[3][2] * (d00_13 - d03_10) + this->m[3][3] * (d02_10 - d00_12) + this->m[3][0] * (d03_12 - d02_13));
	this->_13 = d * (this->m[0][2] * (d13_20 - d10_23) + this->m[0][3] * (d10_22 - d12_20) + this->m[0][0] * (d12_23 - d13_22));
	this->_20 = d * (this->m[1][3] * (d20_31 - d21_30) + this->m[1][0] * (d21_33 - d23_31) + this->m[1][1] * (d23_30 - d20_33));
	this->_21 = d * (this->m[2][3] * (d00_31 - d01_30) + this->m[2][0] * (d01_33 - d03_31) + this->m[2][1] * (d03_30 - d00_33));
	this->_22 = d * (this->m[3][3] * (d00_11 - d01_10) + this->m[3][0] * (d01_13 - d03_11) + this->m[3][1] * (d03_10 - d00_13));
	this->_23 = d * (this->m[0][3] * (d11_20 - d10_21) + this->m[0][0] * (d13_21 - d11_23) + this->m[0][1] * (d10_23 - d13_20));
	this->_30 = d * (this->m[1][0] * (d22_31 - d21_32) + this->m[1][1] * (d20_32 - d22_30) + this->m[1][2] * (d21_30 - d20_31));
	this->_31 = d * (this->m[2][0] * (d02_31 - d01_32) + this->m[2][1] * (d00_32 - d02_30) + this->m[2][2] * (d01_30 - d00_31));
	this->_32 = d * (this->m[3][0] * (d02_11 - d01_12) + this->m[3][1] * (d00_12 - d02_10) + this->m[3][2] * (d01_10 - d00_11));
	this->_33 = d * (this->m[0][0] * (d11_22 - d12_21) + this->m[0][1] * (d12_20 - d10_22) + this->m[0][2] * (d10_21 - d11_20));

	return true;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Returns the position of the matrix
Return:
	const Vector3 - the position of the matrix
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const Vector3 Matrix::Position( void ) const
{
	return Vector3( _03, _13, _23 );
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: operator* overload
Params:
	_rhs - the matrix to multiply with
Return:
	Matrix - the resulting multiplied matrix
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix Matrix::operator*( const Matrix& _rhs ) const
{
	return Matrix(
		(_00 * this->_00) + (_01 * this->_10) + (_02 * this->_20) + (_03 * this->_30),
		(_00 * this->_01) + (_01 * this->_11) + (_02 * this->_21) + (_03 * this->_31),
		(_00 * this->_02) + (_01 * this->_12) + (_02 * this->_22) + (_03 * this->_32),
		(_00 * this->_03) + (_01 * this->_13) + (_02 * this->_23) + (_03 * this->_33),

		(_10 * this->_00) + (_11 * this->_10) + (_12 * this->_20) + (_13 * this->_30),
		(_10 * this->_01) + (_11 * this->_11) + (_12 * this->_21) + (_13 * this->_31),
		(_10 * this->_02) + (_11 * this->_12) + (_12 * this->_22) + (_13 * this->_32),
		(_10 * this->_03) + (_11 * this->_13) + (_12 * this->_23) + (_13 * this->_33),

		(_20 * this->_00) + (_21 * this->_10) + (_22 * this->_20) + (_23 * this->_30),
		(_20 * this->_01) + (_21 * this->_11) + (_22 * this->_21) + (_23 * this->_31),
		(_20 * this->_02) + (_21 * this->_12) + (_22 * this->_22) + (_23 * this->_32),
		(_20 * this->_03) + (_21 * this->_13) + (_22 * this->_23) + (_23 * this->_33),

		(_30 * this->_00) + (_31 * this->_10) + (_32 * this->_20) + (_33 * this->_30),
		(_30 * this->_01) + (_31 * this->_11) + (_32 * this->_21) + (_33 * this->_31),
		(_30 * this->_02) + (_31 * this->_12) + (_32 * this->_22) + (_33 * this->_32),
		(_30 * this->_03) + (_31 * this->_13) + (_32 * this->_23) + (_33 * this->_33)
	);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: operator* overload
Params:
	_rhs - the matrix to multiply with
Return:
	Matrix - the resulting multiplied matrix
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Matrix Matrix::operator+( const Matrix& _rhs ) const
{
	return Matrix(
		_00 + _rhs._00, _01 + _rhs._01, _02 + _rhs._02, _03 + _rhs._03,
		_10 + _rhs._10, _11 + _rhs._11, _12 + _rhs._12, _13 + _rhs._13,
		_20 + _rhs._20, _21 + _rhs._21, _22 + _rhs._22, _23 + _rhs._23,
		_30 + _rhs._30, _31 + _rhs._31, _32 + _rhs._32, _33 + _rhs._33
	);
}