#if !defined(_STDTYPE_)
    #define _STDTYPE_
#pragma once
#if defined(__cplusplus) 
    #include <iostream>
    #include <vcruntime.h>
#endif

using String	= char;
using lPString	= String * ;
using lPCString = const String *;
using w8		= String;
using w16       = signed short;
using w32       = signed int;
using w64       = signed long long;
using wlong     = signed long;

using uString   = unsigned char;
using u8        = uString;
using u16       = unsigned short;
using u32       = unsigned int;
using ulong		= unsigned long;
using u64       = unsigned long long;

/// A - U
#if defined ( UNICODE ) && defined ( TEXT )
	#define CryString(x)		(TEXT(x))
#else	
	#define CryString(...)			u8##__VA_ARGS__
#endif

#endif