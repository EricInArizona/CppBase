// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "CharBuf.h"
#include "StIO.h"
#include "Casting.h"



CharBuf::CharBuf( void )
{
arraySize = 1024 * 2;
cArray = new char[Casting::i32ToU64( arraySize )];
}



CharBuf::CharBuf( const CharBuf& in )
{
cArray = new char[Casting::i32ToU64( arraySize )];

// Make the compiler think the in value is
// being used.
if( in.testForCopy == 123 )
  return;

// Don't copy a giant buffer.
const char* showS = "The CharBuf copy constructor"
         " should not be getting called.\n";

throw showS;
}



CharBuf::~CharBuf( void )
{
delete[] cArray;
}



void CharBuf::increaseSize( const Int32 howMuch )
{
arraySize = arraySize + howMuch;
char* tempArray = new char[Casting::i32ToU64(
                                 arraySize )];

const Int32 max = last;

for( Int32 count = 0; count < max; count++ )
  tempArray[count] = cArray[count];

delete[] cArray;
cArray = new char[Casting::i32ToU64( arraySize )];

for( Int32 count = 0; count < max; count++ )
  cArray[count] = tempArray[count];

delete[] tempArray;
}



Str CharBuf::getStr( void ) const
{
Str result( cArray, last );
// It will do the copy constructor.
return result;
}



void CharBuf::appendChar( const char toSet )
{
if( (last + 2) <= arraySize )
  increaseSize( (1024 * 16) );

cArray[last] = toSet;
last++;
}



void CharBuf::appendChars( const char* pStr )
{
const char* sizePoint = pStr;
Int32 strSize = 0;
for( Int32 count = 0; count < 10000; count++ )
  {
  char c = *sizePoint;
  if( c == 0 )
    break;

  sizePoint++;
  strSize++;
  }

if( (arraySize + strSize + 2) <= arraySize )
  increaseSize( strSize + (1024 * 16) );

for( Int32 count = 0; count < strSize; count++ )
  {
  cArray[last] = *pStr;
  last++;
  pStr++;
  }
}



void CharBuf::appendCharBuf( const char* buf,
                             const Int32 howMany )
{
if( (arraySize + howMany + 2) <= arraySize )
  increaseSize( howMany + (1024 * 16) );

for( Int32 count = 0; count < howMany; count++ )
  {
  cArray[last] = *buf;
  last++;
  buf++;
  }
}



void CharBuf::appendStr( const Str& in )
{
Int32 howMany = in.getSize();
if( ((last + 2) + howMany) <= arraySize )
  increaseSize( howMany + (1024 * 16) );

for( Int32 count = 0; count < howMany; count++ )
  {
  cArray[last] = in.charAt( count );
  last++;
  }
}




/*

void Int8Array::reverse( void )
{
const Int32 max = last;

Int8* tempA = new Int8[CastE::i32ToU64( max )];
Int32 where = 0;
for( Int32 count = max - 1; count >= 0; count-- )
  {
  tempA[where] = cArray[count];
  where++;
  }

for( Int32 count = 0; count < max; count++ )
  cArray[count] = tempA[count];

delete[] tempA;
}



bool Int8Array::isAllZero( void ) const
{
const Int32 max = last;

for( Int32 count = 0; count < max; count++ )
  {
  if( cArray[count] != 0 )
    return false;

  }

return true;
}



// Use getStr()
Str Int8Array::makeStr( void )
{
Str result( cArray, last );
return result;
}

*/
