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




class CharBuf
  {
  private:
  Int32 testForCopy = 123;
  CharArray cArray;
  Int32 last = 0;

  void increaseSize( Int32 howMuch );

  public:
  CharBuf( void );
  CharBuf( const CharBuf &in );
  // Can't make a constructor for a Str because
  // Str.h contains CharBuf.h.
  ~CharBuf( void );

  void setSize( const Int32 howBig );

  inline Int32 getLast( void ) const
    {
    return last;
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

  void copy( const CharBuf& toCopy );

  };
