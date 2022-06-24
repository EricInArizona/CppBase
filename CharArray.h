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
  bool testForCopy = false;

  char* cArray;

  // I don't want to use any single array that
  // is bigger than 0x7FFFFFFF.  Like 2
  // gigabytes. If I need it to be bigger than
  // that then I'll use multiple arrays.  I'll
  // make a HugeArray class.

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

    if( in.testForCopy )
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
    if( howBig == arraySize )
      return;

    if( howBig < 1 )
      throw "CharArray.setSize howBig.";

    arraySize = howBig;
    delete[] cArray;
    // Casting.h is meant to throw exceptions
    // when it has something like a negative
    // number being cast to an unsigned number.
    cArray = new char[Casting::i32ToU64(
                                    arraySize )];
    }

  inline Int32 getSize() const
    {
    return arraySize;
    }

  inline void copy( const CharArray& copyFrom )
    {
    const Int32 fromSize = copyFrom.getSize();
    setSize( fromSize );

    // Memory::copy()

    for( Int32 count = 0; count < fromSize; count++ )
      cArray[count] = copyFrom.cArray[count];

    }


  inline void increaseSize( const Int32 howMuch )
    {
    if( howMuch < 1 )
      throw "CharArray.increaseSize() howMuch.";

    if( ( Casting::i32ToU64( arraySize ) +
          Casting::i32ToU64( howMuch ) ) >=
        0x7FFFFFFF )
      throw "CharArray.increaseSize too big.";

    const Int32 max = arraySize;
    arraySize = arraySize + howMuch;

    char* tempArray = new char[Casting::i32ToU64(
                                 arraySize )];

    // Memory.cpp ?
    for( Int32 count = 0; count < max; count++ )
      tempArray[count] = cArray[count];

    delete[] cArray;

    // Assign the pointer to the new array.
    cArray = tempArray;
    }

  inline char getC( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.getC() arraySize." );

    return cArray[where];
    }

  inline Uint8 getU8( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.getU8() arraySize." );

    return cArray[where] & 0xFF;
    }

  inline void setC( const Int32 where,
                    const char toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.setC() arraySize." );

    cArray[where] = toSet;
    }

  inline void setU8( const Int32 where,
                     const Uint8 toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.setU8() arraySize." );

    char changeIt = toSet & 0x7F;
    if( (toSet & 0x80) != 0 )
      changeIt |= 0x80;

    cArray[where] = changeIt;
    }

  };
