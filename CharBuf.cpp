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
setSize( 16 );
}


CharBuf::CharBuf( const char* pStr )
{
setSize( 16 );
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
setSize( max + 1 );

for( Int32 count = 0; count < max; count++ )
  {
  char c = *pStr;
  appendChar( c, 32 );
  pStr++;
  }
}


CharBuf::CharBuf( Int64 n )
{
if( n == 0 )
  {
  appendChar( '0', 32 );
  return;
  }

CharArray tempBuf;
tempBuf.setSize( 1024 );

Int32 lastTemp = 0;
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
  tempBuf.setC( lastTemp, Casting::i32ToChar(
               Casting::i64ToI32(('0' + digit))));
  lastTemp++;

  toDivide = toDivide / 10;
  }

if( isNegative )
  {
  tempBuf.setC( lastTemp, '-' );
  lastTemp++;
  }

// Clears it too.
setSize( lastTemp );

// Reverse it.
for( Int32 count = lastTemp - 1; count >= 0;
                                       count-- )
  {
  appendChar( tempBuf.getC( count ), 32 );
  }
}



CharBuf::CharBuf( const CharBuf& in )
{
// Make the compiler think the in value is
// being used.
if( in.testForCopy )
  return;

throw "CharBuf copy constructor called.";
}



CharBuf::~CharBuf( void )
{
}



void CharBuf::setSize( const Int32 howBig )
{
last = 0;
cArray.setSize( howBig );
}


void CharBuf::increaseSize( const Int32 howMuch )
{
cArray.increaseSize( howMuch );
}



void CharBuf::appendChar( const char toSet,
                          const Int32 increase )
{
if( increase < 1 )
  throw "CharBuf.appendChar Increase.";

// It's good if you can set the size ahead
// of time.
if( (last + 1) >= cArray.getSize() )
  increaseSize( increase );

cArray.setC( last, toSet );
last++;
}


void CharBuf::appendU8( const Uint32 toSet,
                        const Int32 increase )
{
if( increase < 1 )
  throw "CharBuf.appendU8 Increase.";

// It's good if you can set the size ahead
// of time.
if( (last + 1) >= cArray.getSize() )
  increaseSize( increase );

cArray.setU8( last, (toSet & 0xFF) );
last++;
}


void CharBuf::appendU16( const Uint32 toSet,
                        const Int32 increase )
{
if( increase < 1 )
  throw "CharBuf.appendU16 Increase.";

// It's good if you can set the size ahead
// of time.
if( (last + 1) >= cArray.getSize() )
  increaseSize( increase );

cArray.setU8( last, ((toSet >> 8) & 0xFF) );
last++;

cArray.setU8( last, (toSet & 0xFF) );
last++;
}



void CharBuf::appendU32( const Uint32 toSet,
                         const Int32 increase )
{
// Big endian.
Uint8 toAdd = Casting::u32ToU8(
                         toSet >> (3 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u32ToU8(
                         toSet >> (2 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u32ToU8(
                         toSet >> (1 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u32ToU8( toSet );
appendU8( toAdd, increase );
}



void CharBuf::appendU64( const Uint64 toSet,
                         const Int32 increase )
{
// Big endian.
Uint8 toAdd = Casting::u64ToU8(
                         toSet >> (7 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet >> (6 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet >> (5 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet >> (4 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet >> (3 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet >> (2 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet >> (1 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u64ToU8( toSet );
appendU8( toAdd, increase );
}



Uint32 CharBuf::getU32( const Int32 where ) const
{
// Big endian.
Uint32 toSet = getU8( where );
toSet <<= 8;

Uint32 nextC = getU8( where + 1 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 2 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 3 );
toSet |= nextC;

return toSet;
}


Uint64 CharBuf::getU64( const Int32 where ) const
{
// Big endian.
Uint64 toSet = getU8( where );
toSet <<= 8;

Uint64 nextC = getU8( where + 1 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 2 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 3 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 4 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 5 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 6 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 7 );
toSet |= nextC;

return toSet;
}



// Used in Base64 encoding.
Uint32 CharBuf::get24Bits( const Int32 where ) const
{
// Big endian.
Uint32 toSet = getU8( where );
toSet <<= 8;

Uint32 nextC = getU8( where + 1 );
toSet |= nextC;
toSet <<= 8;

nextC = getU8( where + 2 );
toSet |= nextC;

return toSet;
}



Uint32 CharBuf::get16Bits( const Int32 where ) const
{
// Big endian.
Uint32 toSet = getU8( where );
toSet <<= 8;

Uint32 nextC = getU8( where + 1 );
toSet |= nextC;

return toSet;
}



void CharBuf::append24Bits( const Uint32 toSet,
                             const Int32 increase )
{
// Big endian.
Uint8 toAdd = Casting::u32ToU8(
                         toSet >> (2 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u32ToU8(
                         toSet >> (1 * 8) );
appendU8( toAdd, increase );

toAdd = Casting::u32ToU8( toSet );
appendU8( toAdd, increase );
}


void CharBuf::appendCharArray(
                       const CharArray& toAdd,
                       const Int32 howMany )
{
if( (last + howMany + 2) >= cArray.getSize() )
  increaseSize( howMany + (1024 * 16) );

for( Int32 count = 0; count < howMany; count++ )
  {
  cArray.setC( last, toAdd.getC( count ) );
  last++;
  }
}


void CharBuf::appendCharBuf( const CharBuf& charBuf )
{
const Int32 howMany = charBuf.getLast();

if( (last + howMany + 2) >= cArray.getSize() )
  increaseSize( howMany + (1024 * 16) );

for( Int32 count = 0; count < howMany; count++ )
  {
  cArray.setC( last, charBuf.getC( count ));
  last++;
  }
}



void CharBuf::copy( const CharBuf& toCopy )
{
last = toCopy.last;

cArray.copy( toCopy.cArray );
}



void CharBuf::copyToCharArray( CharArray& copyTo )
{
const Int32 max = getLast();
copyTo.setSize( max );
for( Int32 count = 0; count < max; count++ )
  copyTo.setC( count, cArray.getC( count ));

}



void CharBuf::copyToOpenCharArrayNoNull(
                     OpenCharArray& copyTo ) const
{
const Int32 max = getLast();
copyTo.setSize( max );

// Memory::copy()  Memory.cpp

for( Int32 count = 0; count < max; count++ )
  copyTo.setC( count, cArray.getC( count ));

}


void CharBuf::copyToOpenCharArrayNull(
                     OpenCharArray& copyTo ) const
{
const Int32 max = getLast();
copyTo.setSize( max + 1 );

// Memory::copy()  Memory.cpp

for( Int32 count = 0; count < max; count++ )
  copyTo.setC( count, cArray.getC( count ));

copyTo.setC( max, 0 );
}


void CharBuf::copyFromOpenCharArrayNoNull(
                 const OpenCharArray& copyFrom )
{
const Int32 max = copyFrom.getSize();
cArray.setSize( max + 1024);

// Memory::copy()  Memory.cpp

for( Int32 count = 0; count < max; count++ )
  cArray.setC( count, copyFrom.getC( count ));

last = max;
}



void CharBuf::copyFromOpenCharArrayNull(
                 const OpenCharArray& copyFrom )
{
const Int32 max = copyFrom.getSize();
setSize( max + 1024);

// Memory::copy()  Memory.cpp

for( Int32 count = 0; count < max; count++ )
  {
  char c = copyFrom.getC( count );
  if( c == 0 )
    return;

  appendChar( c, 1024 );
  }
}



void CharBuf::testBasics( void )
{
Uint64 test1 = 135;
appendU64( test1, 1024 );

Uint64 test2 = 0xF123345678543219ULL;
appendU64( test2, 1024 );

Uint64 test = getU64( 0 );
if( test != test1 )
  throw "CharBuf test basics.";

// Make sure the offset is right.
// A multiple of 4 for Uint32.
// 8 for Uint64.

test = getU64( 8 );
if( test != test2 )
  throw "CharBuf test basics.";

}



Int32 CharBuf::findChar( const Int32 start,
                         const char toFind )
{
const Int32 max = last;
if( start < 0 )
  return -1;

if( start >= max )
  return -1;

for( Int32 count = start; count < max; count++ )
  {
  if( cArray.getC( count ) == toFind )
    return count;

  }

return -1; // Didn't find it.
}


bool CharBuf::equalsCBuf( CharBuf& toCheck )
{
if( last != toCheck.last )
  return false;

const Int32 max = last;
for( Int32 count = 0; count < max; count++ )
  {
  if( cArray.getC( count ) !=
                  toCheck.cArray.getC( count ) )
    return false;

  }

return true;
}


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

const Int32 max = strSize;

// Now it is big enough.
for( Int32 count = 0; count < max; count++ )
  {
  appendChar( *pStr, max + 2 );
  pStr++;
  }
}



void CharBuf::reverse( void )
{
const Int32 max = getLast();

CharArray tempBuf;
tempBuf.setSize( max );

// Reverse it.
Int32 where = 0;
for( Int32 count = max - 1; count >= 0; count-- )
  {
  tempBuf.setC( where, getC( count ));
  where++;
  }

clear();
for( Int32 count = 0; count < max; count++ )
  appendChar( tempBuf.getC( count ), 32 );

}
