// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "RangeC.h"
#include "Casting.h"


class U32ArrayStat8
  {
  private:
  static const Int32 arraySize = 8;
  Uint32 uArray[arraySize] = { 1, 2, 3 };
  bool testForCopy = false;

  public:
  inline U32ArrayStat8( void )
    {
    }

  inline U32ArrayStat8( const U32ArrayStat8 &in )
    {
    if( in.testForCopy )
      return;

    throw "U32ArrayStat8 copy constructor";
    }


  inline ~U32ArrayStat8( void )
    {
    }

  inline Uint32 getVal( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
                  "U32ArrayStat8.getVal() range." );

    return uArray[where];
    }

  inline void setVal( const Int32 where,
                      const Uint32 setTo )
    {
    RangeC::test2( where, 0, arraySize - 1,
                  "U32ArrayStat8.setVal() range." );

    uArray[where] = setTo;
    }

  };
