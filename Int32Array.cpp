// Copyright Eric Chauvin 2022
// This copyright notice has to stay at the top.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Int32Array.h"
#include "Casting.h"


Int32Array::Int32Array( void )
{
arraySize = 1;
iArray = new Int32[Casting::i32ToU64( arraySize )];
}



Int32Array::Int32Array( const Int32Array &in )
{
arraySize = 1;
iArray = new Int32[Casting::i32ToU64( arraySize )];

// Make the compiler think in is being used.
if( in.testForCopy == 7 )
  return;

const char* showS = "The Int32Array copy"
      " constructor should not be getting"
      " called.";

throw showS;
}



Int32Array::~Int32Array( void )
{
delete[] iArray;
}



void Int32Array::setSize( const Int32 howBig )
{
arraySize = howBig;

delete[] iArray;
iArray = new Int32[Casting::i32ToU64( arraySize )];
}



void Int32Array::increaseAppendSize(
                        const Int32 howMuch )
{
Int32* tempArray = new Int32[Casting::i32ToU64(
                               arraySize )];

const Int32 max = lastAppend;

for( Int32 count = 0; count < max; count++ )
  tempArray[count] = iArray[count];

delete[] iArray;

arraySize = arraySize + howMuch;

iArray = new Int32[Casting::i32ToU64( arraySize )];

for( Int32 count = 0; count < max; count++ )
  iArray[count] = tempArray[count];

delete[] tempArray;
}



void Int32Array::appendVal( const Int32 toSet )
{
if( (lastAppend + 1) >= arraySize )
  increaseAppendSize( (1024 * 64) );

RangeC::test2( lastAppend, 0, arraySize - 1,
            "Int32Array.appendVal arraySize range." );

iArray[lastAppend] = toSet;
lastAppend++;
}


void Int32Array::copy( const Int32Array& in )
{
lastAppend = 0;
const Int32 max = in.getLastAppend();
for( Int32 count = 0; count < max; count++ )
  appendVal( in.getVal( count ));

}
