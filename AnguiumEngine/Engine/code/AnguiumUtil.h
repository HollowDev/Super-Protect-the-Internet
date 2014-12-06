/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Name: Anguium Engine Util
	Desc: Utilities to make engine work easier.
	
	Copyright 2014 Hollow Dev - http://www.hollowgamedev.com
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma once
#ifndef _ANGUIUM_UTIL_H_
#define _ANGUIUM_UTIL_H_

#include <assert.h>
#include <stdint.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Summary: Shorted names for data types, makes life easier/simpler
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
// signed ints
typedef int8_t		s8;
typedef int16_t		s16;
typedef int32_t		s32;
typedef int64_t		s64;
// unsigned ints
typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;
// floats
typedef float		f32;
typedef double		f64;

namespace AnguiumUtil
{
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Summary: Safely deletes an object
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	#define SAFE_DELETE( v ) { if( v ) delete v; v = nullptr; }
	
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Summary: Safely release an object
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	#define SAFE_RELEASE( v ) { if( v ) v->Release(); v = nullptr; }

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Summary: Writes directly to the debuggers output log
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	#define DEBUG_OUTPUT( v ) _DEBUG_OUTPUT( #v, v )
	#define _DEBUG_OUTPUT( n, v )					\
	{												\
		std::wostringstream string;					\
		string << (n) << " = " << (v) << L"\n";		\
		OutputDebugStringW(string.str().c_str());	\
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	Summary: Override for assert
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	#ifdef _DEBUG
		#define ASSERT(e) assert(e)
	#else
		#define ASSERT(unused) {}
	#endif

	// get the number of elements in an array
	#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))
}

#endif