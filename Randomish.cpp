// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Randomish.h"
#include <random>
#include "Casting.h"



void Randomish::makeRandomBytes(
                            Uint16Array& uArray,
                            const Int32 howMany )
{
std::random_device rd;

// rd.entropy()
// rd.min()
// rd.max()

// std::mersenne_twister_engine
// std::mt19937_64

std::mt19937 gen( rd() );

// Make a uniform distribution:
//std::uniform_int_distribution<> dist( 1,
//                               0xFFFFFFFF );

Int32 where = 0;
for( Int32 count = 0; count < 100000; count++ )
  {
  // dist( gen())

  // Truncate the unsigned int to an 8 bit byte.
  Uint16 c = Casting::
                U64ToU16ByteTruncate( gen());

  // Use non zero bytes.
  if( c == 0 )
    continue;

  uArray.setVal( where, c );
  where++;
  if( where >= howMany )
    return;

  }
}
