// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "RangeC.h"


class Uint16Buf
  {
  private:
  Uint16* cArray;
  Int32 arraySize = 0;
  Int32 last = 0;
  void increaseSize( const Int32 howMuch );

  public:
  Uint16Buf( void );
  Uint16Buf( const Uint16Buf &in );
  ~Uint16Buf( void );
  inline Int32 getLast( void ) const
    {
    return last;
    }

  inline void clear( void )
    {
    last = 0;
    }

  inline Uint16 valAt( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
                  "UTF16Buf.valAt() range." );

    // It might not be using append().
    // RangeC::test( where, 0, last - 1,
      //       "UTF16Buf.valAt() past last." );

    return cArray[where];
    }

  void appendVal( const Uint16 toSet );

  };
