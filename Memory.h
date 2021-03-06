// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html

// In the cpp file:
// #include <string.h>
// memset()
// strlen() finds the length of a C string.

// memcpy( void* dest, const void * source, howmany )



// If I need to use Shared Memory Files then
// this would be just an #include to one for
// Windows and one for Linux.  And it would
// be a different class called SharedMem.



#pragma once


#include "BasicTypes.h"


class Memory
  {
  private:

  public:
  static inline void copyMemory( void* dest,
                            const void* source,
                            Int32 howMany )
    {
    // In strings.h:
    // memcpy( void* dest, const void * source, howmany )
    }


  static inline Int32 strLength(
                      const char* pStr )
{
// string.h has strlen().

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

  };
