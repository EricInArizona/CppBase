// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "CharBuf.h"
#include "OpenCharArray.h"



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

  void reverse( void );

  inline void clear( void )
    {
    charBuf.clear();
    }

  inline void copyToOpenArray(
                  OpenCharArray& openArray ) const
    {
    const Int32 max = charBuf.getLast();
    openArray.setSize( max + 1 );

    for( Int32 count = 0; count < max; count++ )
      openArray.setC( count, charBuf.getC( count ));

    openArray.setC( max, 0 );
    }

  };
