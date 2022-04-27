// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Int64Array.h"
#include "Casting.h"


Int64Array::Int64Array( void )
{
arraySize = 1;
iArray = new Int64[Casting::i32ToU64( arraySize )];
}



Int64Array::Int64Array( const Int64Array &in )
{
arraySize = 1;
iArray = new Int64[Casting::i32ToU64( arraySize )];

// Make the compiler think in is being used.
if( in.testForCopy == 7 )
  return;

const char* showS = "The Int64Array copy"
      " constructor should not be getting"
      " called.";

throw showS;
}



Int64Array::~Int64Array( void )
{
delete[] iArray;
}



void Int64Array::setSize( const Int32 howBig )
{
arraySize = howBig;

delete[] iArray;
iArray = new Int64[Casting::i32ToU64( arraySize )];
}



void Int64Array::increaseAppendSize(
                        const Int32 howMuch )
{
arraySize = arraySize + howMuch;
if( arraySize > 0x3FFFFFFF )
  throw "The Int64Array is too big.";

Int64* tempArray = new Int64[Casting::i32ToU64(
                               arraySize )];

const Int32 max = lastAppend;

for( Int32 count = 0; count < max; count++ )
  tempArray[count] = iArray[count];

delete[] iArray;
iArray = new Int64[Casting::i32ToU64( arraySize )];

for( Int32 count = 0; count < max; count++ )
  iArray[count] = tempArray[count];

delete[] tempArray;
}



void Int64Array::appendVal( const Int64 toSet )
{
if( (lastAppend + 1) >= arraySize )
  increaseAppendSize( (1024 * 32) );

RangeC::test2( lastAppend, 0, arraySize - 1,
            "Int64Array.appendVal arraySize range." );

iArray[lastAppend] = toSet;
lastAppend++;
}


void Int64Array::copy( const Int64Array& in )
{
lastAppend = 0;
const Int32 max = in.getLastAppend();
for( Int32 count = 0; count < max; count++ )
  appendVal( in.getVal( count ));

}
