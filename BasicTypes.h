// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


// Basic type definitions.
// This file is #included in just about every
// file I write.

// See basicThingsAreRight().


// I never use the C Preprocessor except for
// #include statements.  I never include any
// standard header files in my own header files,
// they are only in .cpp files, where they will
// affect only that compilation unit.  That way
// I can #include my own header files without
// having to worry about how they can corrupt
// other files with macros.
// So I don't #include here any types that are
// defined in standard header files like a
// types.h kind of file.

// Also, in my BuildProj.sh file, I have it
// warn about everything: -Weverything
// So I can fix any problems, like type cast
// warnings.



// typedef char Int8;
typedef unsigned char Uint8;
typedef unsigned short Uint16;

// For Linux:
// typedef int Int32;
// typedef unsigned int Uint32;

// For Windows.
typedef int Int32;
typedef unsigned int Uint32;
typedef long Int32L;
typedef unsigned long Uint32L;

// These are right with Clang on my 64 bit machine.

// This is on Linux:
// typedef long Int64;
// typedef unsigned long Uint64;

// This is on Windows.
typedef long long Int64;
typedef unsigned long long Uint64;

// 128 bit?
// typedef long long Int64; // A constant 123LL
//                         // is long long.

// typedef unsigned long long Uint64; // 123ULL

typedef float Float32;
typedef double Float64;

// On Linux.
// typedef long double Float128;



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
