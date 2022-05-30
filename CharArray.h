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

  // Don't return a pointer directly to this.
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

  inline Int32 getFirstChar( const char toFind )
    {
    const Int32 max = arraySize;

    for( Int32 count = 0; count < max; count++ )
      {
      if( cArray[count] == toFind )
        return count;
      }

    return -1; // Didn't find it.
    }

  inline void copy( const CharArray& copyFrom,
                    const Int32 howMany )
    {
    const Int32 fromSize = copyFrom.getSize();
    if( howMany > fromSize )
      throw "CharArray.copy fromSize.";

    setSize( howMany );

    // Memory::copy()

    for( Int32 count = 0; count < howMany; count++ )
      cArray[count] = copyFrom.cArray[count];

    }

  inline void append( const CharArray& copyFrom,
                    const Int32 howMany )
    {
    const Int32 fromSize = copyFrom.getSize();
    if( howMany > fromSize )
      throw "CharArray.append fromSize.";

    Int32 last = arraySize;
    increaseSize( howMany );

    // Memory::copy()

    for( Int32 count = 0; count < howMany; count++ )
      {
      cArray[last] = copyFrom.cArray[count];
      last++;
      }
    }


  inline void copyToCharPt( char* pointTo,
                            const Int32 howMany )
    {
    if( arraySize < howMany )
      throw "CharArray.copyToCharPt howMany.";

    // Memory::copy()

    char* pointChar = pointTo;

    for( Int32 count = 0; count < howMany; count++ )
      {
      *pointChar = cArray[count];
      pointChar++;
      }
    }


  inline void copyFromCharPt( const char* pointTo,
                            const Int32 howMany )
    {
    // Memory::copy()

    setSize( howMany );

    const char* pointChar = pointTo;

    for( Int32 count = 0; count < howMany; count++ )
      {
      cArray[count] = *pointChar;
      pointChar++;
      }
    }



  inline void increaseSize( const Int32 howMuch )
    {
    if( howMuch < 1 )
      throw "CharArray.increaseSize() howMuch.";

    if( ( Casting::i32ToU64( arraySize ) +
          Casting::i32ToU64( howMuch ) ) >=
        0x7FFFFFFF )
      throw "CharArray.increaseSize too big.";

    char* tempArray = new char[Casting::i32ToU64(
                                 arraySize )];

    const Int32 max = arraySize;

    // For later optimizing:
    // What is the assembly language code for
    // a memory copy?

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

  inline char getC( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.getC() arraySize." );

    return cArray[where];
    }

  inline void setC( const Int32 where,
                    const char toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
             "CharArray.setC() arraySize." );

    cArray[where] = toSet;
    }

  };
