// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "CharBuf.h"



// Str.isEqual( "a quoted string" )

// append a quoted string.

// Other things I want to do with strings.


class Str
  {
  private:
  CharBuf charBuf;

  public:
  Str( const char* pStr );
  Str( const Str& in );
  Str( const CharArray& cArray );
  Str( Int64 n );
  inline ~Str( void )
    {
    // charBuf goes out of scope.
    }

  inline Int32 getLast( void ) const
    {
    return charBuf.getLast();
    }

  void copy( const Str& in );
  void append( const Str& in );

  inline char getC( const Int32 where ) const
    {
    return charBuf.getC( where );
    }

  // static Int32 charsLength( const char* pStr );
  void reverse( void );

  inline void clear( void )
    {
    charBuf.clear();
    }

  };
