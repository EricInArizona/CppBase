// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "BasicTypes.h"
#include "CharArray.h"
#include "RangeC.h"
#include "OpenCharArray.h"


// CharBuf is a sequence of bytes.  It can
// be interpreted in different ways, as char
// values or Uint8, or Uint32 values or anything
// else.  Some stdio.h functions use void pointers
// to refer to a series of bytes.  This can
// be used for any series of bytes like that.



class CharBuf
  {
  private:
  bool testForCopy = false;
  CharArray cArray;
  Int32 last = 0;

  void increaseSize( Int32 howMuch );

  public:
  CharBuf( void );
  CharBuf( const CharBuf &in );
  ~CharBuf( void );

  void setSize( const Int32 howBig );

  inline Int32 getLast( void ) const
    {
    return last;
    }

  inline void truncateLast( Int32 setTo )
    {
    if( setTo < 0 )
      throw "CharBuf.truncateLast < zero.";

    if( setTo > last )
      throw "CharBuf.truncateLast too big.";

    last = setTo;
    }

  inline void clear( void )
    {
    last = 0;
    }

  void copyToCharArray( CharArray& copyTo );
  void copyToOpenCharArray(
                  OpenCharArray& copyTo ) const;
  void copyFromOpenCharArray(
                  const OpenCharArray& copyFrom );

  void appendChar( const char toSet,
                   const Int32 increase );

  void appendCharArray( const CharArray& toAdd,
                        const Int32 howMany );

  void appendCharBuf( const CharBuf& charBuf );

  inline char getC( const Int32 where ) const
    {
    return cArray.getC( where );
    }

  inline Uint8 getU8( const Int32 where ) const
    {
    return cArray.getU8( where );
    }

  void copy( const CharBuf& toCopy );

  Int32 findChar( const Int32 start,
                  const char toFind );

  void appendU8( const Uint8 toSet,
                 const Int32 increase );

  void appendU32( const Uint32 toSet,
                  const Int32 increase );

  void appendU64( const Uint64 toSet,
                  const Int32 increase );

  Uint32 getU32( const Int32 where ) const;
  Uint64 getU64( const Int32 where ) const;

  void testBasics( void );

  };
