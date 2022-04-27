// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


// Range checking.



#include "BasicTypes.h"


class RangeC
  {
  private:

  public:

  inline static void testEmpty( void )
    {
    // This is marked as an inline function.
    // An empty inlined function ought to
    // be optimized away completely.
    }

  inline static void test2( Int64 toTest,
                           Int64 min, Int64 max,
                           const char* showIt )
    {
    if( toTest < min )
      throw showIt;

    if( toTest > max )
      throw showIt;

    }

  };
