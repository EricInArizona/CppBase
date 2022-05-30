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
}



CharBuf::CharBuf( const CharBuf& in )
{
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
}



void CharBuf::setSize( const Int32 howBig )
{
cArray.setSize( howBig );
}


void CharBuf::increaseSize( const Int32 howMuch )
{
cArray.increaseSize( howMuch );
}



Str CharBuf::getStr( void ) const
{
if( last == 0 )
  return Str( "" );

// This will stop at a zero character.
Str result( cArray, last );

// It will do the copy constructor.
return result;
}



void CharBuf::appendChar( const char toSet )
{
if( (last + 2) <= cArray.getSize() )
  increaseSize( (1024 * 16) );

cArray.setC( last, toSet );
last++;
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



void CharBuf::appendCharArray(
                       const CharArray& toAdd,
                       const Int32 howMany )
{
if( ( Casting::i32ToU64( cArray.getSize() ) +
      Casting::i32ToU64( howMany ) ) >=
      0x7FFFFFFF )
 throw "CharBuf.appendCharArray too big.";

if( (last + howMany + 2) >= cArray.getSize() )
  increaseSize( howMany + (1024 * 1) );

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
  cArray.setC( last, charBuf.valAt( count ));
  last++;
  }
}



void CharBuf::appendStr( const Str& in )
{
const Int32 howMany = in.getSize();
if( ((last + 2) + howMany) >= cArray.getSize() )
  increaseSize( howMany + (1024 * 16) );

for( Int32 count = 0; count < howMany; count++ )
  {
  cArray.setC( last, in.charAt( count ));
  last++;
  }
}
