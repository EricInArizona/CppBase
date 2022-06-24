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


void CharBuf::appendU8( const Uint8 toSet,
                        const Int32 increase )
{
if( increase < 1 )
  throw "CharBuf.appendU8 Increase.";

// It's good if you can set the size ahead
// of time.
if( (last + 1) >= cArray.getSize() )
  increaseSize( increase );

cArray.setU8( last, toSet );
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



void CharBuf::copyToOpenCharArray(
                     OpenCharArray& copyTo ) const
{
const Int32 max = getLast();
copyTo.setSize( max );

// Memory::copy()  Memory.cpp

for( Int32 count = 0; count < max; count++ )
  copyTo.setC( count, cArray.getC( count ));

}


void CharBuf::copyFromOpenCharArray(
                 const OpenCharArray& copyFrom )
{
const Int32 max = copyFrom.getSize();
cArray.setSize( max + 1024);

// Memory::copy()  Memory.cpp

for( Int32 count = 0; count < max; count++ )
  cArray.setC( count, copyFrom.getC( count ));

last = max;
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
