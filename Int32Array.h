// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "RangeC.h"
#include "Casting.h"


class Int32Array
  {
  private:
  Int32 testForCopy = 123;
  Int32 arraySize = 1;
  Int32* iArray;

  public:
  inline Int32Array( void )
    {
    arraySize = 1;
    iArray = new Int32[
                  Casting::i32ToU64( arraySize )];
    }


  inline Int32Array( const Int32Array& in )
    {
    arraySize = 1;
    iArray = new Int32[
               Casting::i32ToU64( arraySize )];

    // Make the compiler think in is being used.
    if( in.testForCopy == 7 )
      return;

    throw "Int32Array copy constructor.";
    }


  inline ~Int32Array( void )
    {
    delete[] iArray;
    }

  inline void setSize( const Int32 howBig )
    {
    if( howBig == arraySize )
      return;

    arraySize = howBig;
    delete[] iArray;
    iArray = new Int32[
                 Casting::i32ToU64( arraySize )];
    }


  inline Int32 getSize( void ) const
    {
    return arraySize;
    }

  inline Int32 getVal( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
      "Int32Array.getVal arraySize range." );

    return iArray[where];
    }

  inline void setVal( const Int32 where,
                      const Int32 toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
           "Int32Array.setVal where range." );

    iArray[where] = toSet;
    }


  inline void copy( const Int32Array& in )
    {
    setSize( in.arraySize );

    const Int32 max = arraySize;
    for( Int32 count = 0; count < max; count++ )
      iArray[count] = in.iArray[count];

    }

  };
