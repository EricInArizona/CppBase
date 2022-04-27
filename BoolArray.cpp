// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL), version 2.  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "BoolArray.h"
#include "Casting.h"


BoolArray::BoolArray( void )
{
arraySize = 1;
bArray = new bool[Casting::i32ToU64( arraySize )];
}


BoolArray::BoolArray( const BoolArray &in )
{
arraySize = 1;
bArray = new bool[Casting::i32ToU64( arraySize )];

// Make the compiler think in is being used.
if( in.testForCopy == 7 )
  return;

const char* showS = "The BoolArray copy"
      " constructor should not be getting"
      " called.";

throw showS;
}



BoolArray::~BoolArray( void )
{
delete[] bArray;
}



void BoolArray::setSize( const Int32 howBig )
{
if( howBig < 0 )
  throw "BoolArray array size < 0.";

arraySize = howBig;

delete[] bArray;
bArray = new bool[Casting::i32ToU64( arraySize )];
}
