// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#pragma once



#include "BasicTypes.h"
#include "RangeC.h"
#include "Casting.h"




class CharArray
  {
  private:
  Int32 testForCopy = 123;
  char* cArray;
  Int32 arraySize = 1;

  public:
  inline CharArray( void )
    {
    arraySize = 1;
    cArray = new char[Casting::i32ToU64(
                                 arraySize )];
    }

  inline CharArray( const CharArray& in )
    {
    arraySize = 1;
    cArray = new char[Casting::i32ToU64(
                                     arraySize )];

    if( in.testForCopy == 123 )
      return;

    const char* showS = "The CharArray copy"
        " constructor should not get called.";

    throw showS;
    }

  inline ~CharArray( void )
    {
    delete[] cArray;
    }

  inline void setSize( const Int32 howBig )
    {
    arraySize = howBig;
    delete[] cArray;
    cArray = new char[Casting::i32ToU64(
                                    arraySize )];
    }

  inline Int32 getSize()
    {
    return arraySize;
    }

  inline void increaseSize( const Int32 howMuch )
    {
    char* tempArray = new char[Casting::i32ToU64(
                                 arraySize )];

    const Int32 max = arraySize;

    // What is the assembly language code for
    // a memory copy?  Or make a .cpp file for
    // memcpy().

    for( Int32 count = 0; count < max; count++ )
      tempArray[count] = cArray[count];

    delete[] cArray;

    arraySize = arraySize + howMuch;

    cArray = new char[Casting::i32ToU64(
                                     arraySize )];

    for( Int32 count = 0; count < max; count++ )
      cArray[count] = tempArray[count];

    delete[] tempArray;
    }

  inline const char* getBufPoint( Int32 index )
                                        const
    {
    return &cArray[index];
    }

  inline char getC( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.getC() arraySize." );

    return cArray[where];
    }

  inline void setC( const Int32 where,
                    const char toSet ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.setC() arraySize." );

    cArray[where] = toSet;
    }

  };
