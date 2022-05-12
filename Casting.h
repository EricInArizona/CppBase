// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


// If I have to cast something to a different
// type I want to make sure it does it right.
// Like for example that it's not changing a
// negative number into a very large unsigned
// number or something bad like that.
// Or that I'm not truncating a bigger
// number into a smaller number unless that's
// what I intend to do.


#include "BasicTypes.h"



// static_cast is not being used.
// Int32 result = static_cast<Int32>( x );



class Casting
  {
  private:

  public:

  // Yet another reason why you should not
  // #define macros.
  inline static Int32 u32ToI32ForMacro( Uint32 x )
    {
    Int32 result = x & 0x7FFFFFFF;
    result |= 0x80000000;
    return result;
    }



  inline static Uint64 i32ToU64( Int32 x )
    {
    if( x < 0 )
      throw "Casting negative x to U64.";

    Uint64 result = x & 0x7FFFFFFF;
    return result;
    }

  inline static Uint32 i32ToU32( Int32 x )
    {
    if( x < 0 )
      throw "Casting negative x to U32.";

    Uint32 result = x & 0x7FFFFFFF;
    return result;
    }

  inline static Uint64 i64ToU64( Int64 x )
    {
    if( x < 0 )
      throw "Casting negative x to U64.";

    //                0x7FFF FFFF FFFF FFFF
    Uint64 result = x & 0x7FFFFFFFFFFFFFFFLL;
    return result;
    }

  inline static Int32 U16ToI32( Uint16 x )
    {
    Int32 result = x & 0xFFFF;
    return result;
    }

  inline static Int32 U64ToI32( Uint64 x )
    {
    if( x > 0x7FFFFFFF )
      throw "U64ToI32: Casting from too big of an x.";

    Int32 result = x & 0x7FFFFFFF;
    return result;
    }


  inline static Uint16 U64ToU16ByteTruncate(
                                  Uint64 x )
    {
    // Just truncate anything over 8 bits
    // and lose any higher bits without
    // checking them.

    Uint16 result = x & 0xFF;
    return result;
    }

  inline static Int32 i64ToI32( Int64 x )
    {
    if( x < 0 )
      throw "Truncating from a negative x.";

    if( x > 0x7FFFFFFF )
      throw "Truncating too big of an x.";

    // Int32 result = static_cast<Int32>( x );
    Int32 result = x & 0x7FFFFFFF;
    return result;
    }


  inline static char i32ToChar( Int32 x )
    {
    if( x < 0 )
      throw "Truncating a negative: char x.";

    // For an ASCII value I don't want to
    // include the value 0x7F.
    if( x >= 0x7F )
      throw "Truncating too big of a char x.";

    // char result = static_cast<char>( x );
    char result = x & 0x7F;
    return result;
    }


  };
