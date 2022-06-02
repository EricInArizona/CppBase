// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#pragma once



#include "BasicTypes.h"
#include "CharArray.h"
#include "RangeC.h"




class CharBuf
  {
  private:
  Int32 testForCopy = 123;
  CharArray cArray;
  Int32 last = 0;
  Int32 appendIncrease = 1024 * 16;
  void increaseSize( Int32 howMuch );

  public:
  CharBuf( void );
  CharBuf( const CharBuf &in );
  ~CharBuf( void );
  void setSize( Int32 howBig );

  inline Int32 getLast( void ) const
    {
    return last;
    }

  inline void clear( void )
    {
    last = 0;
    }

  inline void setAppendIncrease( Int32 setTo )
    {
    if( setTo < 1 )
      throw "CharBuf.setAppendIncrease.";

    appendIncrease = setTo;
    }

  void copyToCharArray( CharArray& copyTo );

  void appendChar( const char toSet );
  void appendCharArray( const CharArray& toAdd,
                        const Int32 howMany );
  void appendCharBuf( const CharBuf& charBuf );
  inline char getC( const Int32 where ) const
    {
    return cArray.getC( where );
    }

  void copy( const CharBuf& toCopy );

  };
