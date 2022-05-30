// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


/*
#include "CircleBuf.h"
#include "StIO.h"
#include "Casting.h"



CircleBuf::CircleBuf( void )
{
}



CircleBuf::CircleBuf( const CircleBuf& in )
{
if( in.testForCopy == 123 )
  return;

const char* showS = "The CircleBuf copy constructor"
         " should not be getting called.\n";

throw showS;
}



CircleBuf::~CircleBuf( void )
{
}



void CircleBuf::setSize( const Int32 howBig )
{
cArray.setSize( howBig );
}


bool CircleBuf::appendChar( const char toSet )
{
cArray.setC( last, toSet );
last++;
if( last >= cArray.getSize() )
  last = 0;

if( last == first )
  {
  StIO::putS( "CircleBuf overflowed." );
  return false;
  }

return true;
}



bool CircleBuf::appendCharPt( const char* pStr )
{
const char* sizePoint = pStr;
Int32 strSize = 0;
// A regular quoted string would not be
// this long.  10000.
for( Int32 count = 0; count < 10000; count++ )
  {
  char c = *sizePoint;
  if( c == 0 )
    break;

  sizePoint++;
  strSize++;
  }

for( Int32 count = 0; count < strSize; count++ )
  {
  if( !appendChar( *pStr ))
    return false;

  pStr++;
  }

return true;
}

*/
