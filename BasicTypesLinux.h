// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


=====
Fix this up for Linux.


#pragma once


// See basicThingsAreRight().


// typedef char Int8;
typedef unsigned char Uint8;
typedef unsigned short Uint16;

// For Linux:
typedef int Int32;
typedef unsigned int Uint32;

// For Windows.
// typedef int Int32;
// typedef unsigned int Uint32;

// For Windows compatibility.
// typedef long Int32L;
// typedef unsigned long Uint32L;


// These are right with Clang on my 64 bit machine.

// This is on Linux:
typedef long Int64;
typedef unsigned long Uint64;

// This is on Windows.
// typedef long long Int64;
// typedef unsigned long long Uint64;

What is this?
// 128 bit?
// typedef long long Int64; // A constant 123LL
//                         // is long long.

// typedef unsigned long long Uint64; // 123ULL

typedef float Float32;
typedef double Float64;

// On Linux.
// typedef long double Float128;

typedef Uint64 SocketCpp; // Windows
// typedef Int32 SocketCpp; // Linux





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

    // Compiler flags to force the size of this.
    // But it defaults to 128 bits on this machine.

    // -mlong-double-128
    // Force long double to be 128 bits

    // -mlong-double-64
    // Force long double to be 64 bits

    // -mlong-double-80
    // Force long double to be 80 bits, padded to 128 bits
    // for storage

/*
This is on Linux.
    if( sizeof( Float128 ) != 16 )
      throw "Float128 type is not the right size.";
*/

    }

  };
