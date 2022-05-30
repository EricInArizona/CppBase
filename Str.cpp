// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Str.h"
#include "Casting.h"


Str::Str( const char* pStr )
{
if( pStr == nullptr )
  {
  cArray.setSize( 1 );
  cArray.setC( 0, 0 );
  return;
  }

if( *pStr == 0 )
  {
  cArray.setSize( 1 );
  cArray.setC( 0, 0 );
  return;
  }

const char* sizePoint = pStr;

Int32 strSize = 0;
// Make it a reasonable size so it doesn't
// go forever if it never finds zero.
for( Int32 count = 0; count < 10000; count++ )
  {
  char c = *sizePoint;
  if( c == 0 )
    break;

  sizePoint++;
  strSize++;
  }

cArray.setSize( strSize );
const Int32 max = strSize;
for( Int32 count = 0; count < max; count++ )
  {
  char c = *pStr;
  cArray.setC( count, c );
  pStr++;
  }
}



Str::Str( const CharArray& charArray,
          const Int32 howMany )
{
if( howMany < 1 )
  {
  cArray.setSize( 1 );
  cArray.setC( 0, 0 );
  return;
  }

Int32 maxLength = howMany;
Int32 zeroAt = cArray.getFirstChar( Casting::
                                i32ToChar( 0 ));
if( zeroAt <= 0 )
  {
  cArray.setSize( 1 );
  cArray.setC( 0, 0 );
  return;
  }

if( zeroAt < maxLength )
  maxLength = zeroAt;

cArray.setSize( maxLength );

const Int32 max = maxLength;
for( Int32 count = 0; count < max; count++ )
  cArray.setC( count, charArray.getC( count ));

}



Str::Str( const Str& in )
{
const Int32 howMany = in.getSize();
cArray.setSize( howMany );

for( Int32 count = 0; count < howMany; count++ )
  cArray.setC( count, in.charAt( count ));

}


/*
Str::Str( const Str& in1, const Str& in2 )
{
cArray.setSize( = in1.getSize() + in2.getSize() );


Int32 last = 0;
for( Int32 count = 0; count < in1.arraySize;
                                     count++ )
  {
  cArray.setC( last, in1.charAt( count ));
  last++;
  }

for( Int32 count = 0; count < in2.arraySize;
                                     count++ )
  {
  cArray.setC( last, in2.charAt( count ));
  last++;
  }
}
*/



Str::Str( Int64 n )
{
if( n == 0 )
  {
  cArray.setSize( 1 );
  cArray.setC( 0, '0' );
  return;
  }

char tempBuf[100] = { 1,2,3 };

Int32 last = 0;
bool isNegative = false;
if( n < 0 )
  {
  isNegative = true;
  n = n * -1;
  }

Int64 toDivide = n;
while( toDivide != 0 )
  {
  Int64 digit = toDivide % 10;
  // Ascii values go from '0' up to '9'.
  tempBuf[last] = Casting::i32ToChar(
               Casting::i64ToI32(('0' + digit)));
  last++;

  toDivide = toDivide / 10;
  }

if( isNegative )
  {
  tempBuf[last] = '-';
  last++;
  }

cArray.setSize( last );

// Reverse it.
Int32 where = 0;
for( Int32 count = last - 1; count >= 0;
                                       count-- )
  {
  cArray.setC( where, tempBuf[count] );
  where++;
  }
}



void Str::copy( const Str& in )
{
const Int32 max = in.getSize();
cArray.copy( in.cArray, max );
}


void Str::append( const Str& in )
{
const Int32 max = in.getSize();

cArray.copy( in.cArray, max );
}


// static
Int32 Str::charsLength( const char* pStr )
{
const char* sizePoint = pStr;

Int32 howMany = 0;
for( Int32 count = 0; count < 10000; count++ )
  {
  char c = *sizePoint;
  if( c == 0 )
    break;

  sizePoint++;
  howMany++;
  }

return howMany;
}


// Surely there is a better algorithm than this
// for reversing a string.


void Str::reverse( void )
{
const Int32 max = cArray.getSize();
char* tempBuf = new char[Casting::i32ToU64(
                                        max )];

// Reverse it.
Int32 where = 0;
for( Int32 count = max - 1; count >= 0; count-- )
  {
  tempBuf[where] = cArray.getC( count );
  where++;
  }

for( Int32 count = 0; count < max; count++ )
  cArray.setC( count, tempBuf[count] );

delete[] tempBuf;
}
