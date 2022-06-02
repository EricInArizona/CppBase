// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Str.h"
#include "Casting.h"


Str::Str( const char* pStr )
{
charBuf.setAppendIncrease( 16 );

if( pStr == nullptr )
  return;

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

const Int32 max = strSize;
for( Int32 count = 0; count < max; count++ )
  {
  char c = *pStr;
  charBuf.appendChar( c );
  pStr++;
  }
}


Str::Str( const CharArray& cArray )
{
charBuf.setAppendIncrease( 16 );
const Int32 max = cArray.getSize();
charBuf.setSize( max + 2 );

for( Int32 count = 0; count < max; count++ )
  charBuf.appendChar( cArray.getC( count ));

}



Str::Str( const Str& in )
{
charBuf.setAppendIncrease( 16 );
const Int32 howMany = in.getLast();
charBuf.setSize( howMany );

for( Int32 count = 0; count < howMany; count++ )
  charBuf.appendChar( in.getC( count ));

}


/*
Str::Str( const Str& in1, const Str& in2 )
{
charBuf.setAppendIncrease( 16 );
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
charBuf.setAppendIncrease( 16 );

if( n == 0 )
  {
  charBuf.appendChar( '0' );
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

charBuf.setSize( last );

// Reverse it.
for( Int32 count = last - 1; count >= 0;
                                       count-- )
  {
  charBuf.appendChar( tempBuf[count] );
  }
}



void Str::copy( const Str& in )
{
charBuf.copy( in.charBuf );
}



void Str::append( const Str& in )
{
const Int32 max = in.getLast();

for( Int32 count = 0; count < max; count++ )
  charBuf.appendChar( in.charBuf.getC( count ));

}



// Surely there is a better algorithm than this
// for reversing a string.


void Str::reverse( void )
{
const Int32 max = charBuf.getLast();
char* tempBuf = new char[Casting::i32ToU64(
                                        max )];

// Reverse it.
Int32 where = 0;
for( Int32 count = max - 1; count >= 0; count-- )
  {
  tempBuf[where] = charBuf.getC( count );
  where++;
  }

charBuf.clear();
for( Int32 count = 0; count < max; count++ )
  charBuf.appendChar( tempBuf[count] );

delete[] tempBuf;
}



/*
void CharBuf::appendCharPt( const char* pStr )
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

// Need the size before I increase it, or not.
if( (last + strSize + 2) >= cArray.getSize() )
  increaseSize( strSize + (1024 * 16) );

// Now it is big enough.
for( Int32 count = 0; count < strSize; count++ )
  {
  cArray.setC( last, *pStr );
  last++;
  pStr++;
  }
}
*/
