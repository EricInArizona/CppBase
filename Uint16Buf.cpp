// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Uint16Buf.h"
#include "Casting.h"


Uint16Buf::Uint16Buf( void )
{
arraySize = 1024 * 2;
cArray = new Uint16[Casting::i32ToU64( arraySize )];
}


Uint16Buf::Uint16Buf( const Uint16Buf &in )
{
// Make the compiler think the in value is
// being used.
if( in.last == 123 )
  return;

// Don't copy a giant buffer.
const char* showS =
         "The Uint16Buf copy constructor"
         " should not be getting called.\n";

throw showS;
}



Uint16Buf::~Uint16Buf( void )
{
delete[] cArray;
}



void Uint16Buf::increaseSize( const Int32 howMuch )
{
arraySize = arraySize + howMuch;
Uint16* tempArray = new Uint16[Casting::i32ToU64(
                                      arraySize )];

const Int32 max = last;

for( Int32 count = 0; count < max; count++ )
  tempArray[count] = cArray[count];

delete[] cArray;
cArray = new Uint16[Casting::i32ToU64( arraySize )];

for( Int32 count = 0; count < max; count++ )
  cArray[count] = tempArray[count];

delete[] tempArray;
}



void Uint16Buf::appendVal( const Uint16 toSet )
{
if( (last + 2) <= arraySize )
  increaseSize( (1024 * 16) );

cArray[last] = toSet;
last++;
}
