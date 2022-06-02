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
if( in.testForCopy == 789 )
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
last = 0;
cArray.setSize( howBig );
}


void CharBuf::increaseSize( const Int32 howMuch )
{
cArray.increaseSize( howMuch );
}



void CharBuf::appendChar( const char toSet )
{
// It's good if you can set the size ahead
// of time.
if( (last + 1) <= cArray.getSize() )
  increaseSize( appendIncrease );

cArray.setC( last, toSet );
last++;
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
  cArray.setC( last, charBuf.getC( count ));
  last++;
  }
}



void CharBuf::copy( const CharBuf& toCopy )
{
last = toCopy.last;
appendIncrease = toCopy.appendIncrease;

cArray.copy( toCopy.cArray );
}



void CharBuf::copyToCharArray( CharArray& copyTo )
{
const Int32 max = getLast();
copyTo.setSize( max );
for( Int32 count = 0; count < max; count++ )
  copyTo.setC( count, cArray.getC( count ));

}
