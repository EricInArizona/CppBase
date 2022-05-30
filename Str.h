// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "CharArray.h"



// Str.isEqual( "a quoted string" )

// append a quoted string.

// Other things I want to do with strings.


class Str
  {
  private:
  CharArray cArray;
  char* copyBuffer = nullptr;

  public:
  Str( const char* pStr );
  Str( const Str& in );
  Str( const CharArray& charArray,
       const Int32 howMany );

  Str( Int64 n );
  inline ~Str( void )
    {
    // cArray goes out of scope.

    if( copyBuffer != nullptr )
      delete[] copyBuffer;

    }


  inline const char* getCopyBufferPoint( void )
    {
    if( copyBuffer != nullptr )
      delete[] copyBuffer;

    const Int32 max = getSize();
    copyBuffer = new char[
                Casting::i32ToU64( max + 1 )];

    for( Int32 count = 0; count < max; count++ )
      copyBuffer[count] = charAt( count );

    // It has to have that zero, or really
    // bad things happen.
    copyBuffer[max] = 0;

    return copyBuffer;
    }

  inline Int32 getSize() const
    {
    return cArray.getSize();
    }

  void copy( const Str& in );
  void append( const Str& in );

  inline char charAt( const Int32 where ) const
    {
    return cArray.getC( where );
    }

  static Int32 charsLength( const char* pStr );
  void reverse( void );

  };
