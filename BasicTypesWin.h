// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



// See basicThingsAreRight().


// typedef char Int8;
typedef unsigned char Uint8;
typedef unsigned short Uint16;

typedef int Int32;
typedef unsigned int Uint32;

// For Windows compatibility.
typedef long Int32L;
typedef unsigned long Uint32L;

typedef long long Int64;
typedef unsigned long long Uint64;

typedef float Float32;
typedef double Float64;
// typedef long double Float128;

typedef Uint64 SocketCpp;



class BasicTypes
  {
  public:

  inline static void thingsAreRight( void )
    {
    // These are actually checked at compile time
    // and you get a warning that the function
    // could be declared with the attribute
    // noreturn.  So you don't actually have
    // to call this function to see if things
    // are right.

    if( sizeof( Uint8 ) != 1 )
      throw "Uint8 type is not the right size.";

    if( sizeof( Uint16 ) != 2 )
      throw "Uint16 type is not the right size.";

    if( sizeof( Int32 ) != 4 )
      throw "Int32 type is not the right size.";

    if( sizeof( Uint32 ) != 4 )
      throw "Uint32 type is not the right size.";

    if( sizeof( Int32L ) != 4 )
      throw "Int32L type is not the right size.";

    if( sizeof( Uint32L ) != 4 )
      throw "Uint32L type is not the right size.";

    if( sizeof( Int64 ) != 8 )
      throw "Int64 type is not the right size.";

    if( sizeof( Uint64 ) != 8 )
      throw "Uint64 type is not the right size.";

    if( sizeof( Float32 ) != 4 )
      throw "Float32 type is not the right size.";

    if( sizeof( Float64 ) != 8 )
      throw "Float64 type is not the right size.";

    // Compiler flag.
    // -mlong-double-128
    // Force long double to be 128 bits

    // -mlong-double-64
    // Force long double to be 64 bits

    // -mlong-double-80
    // Force long double to be 80 bits, padded to 128 bits
    // for storage

// if( sizeof( Float128 ) != 16 )
//      throw "Float128 type is not the right size.";


    }

  };
