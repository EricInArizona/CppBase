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

  // I want to be able to comment out the range
  // checking without it warning me that I have
  // unused parameters.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"

  inline static void test2( Int64 toTest,
                           Int64 min, Int64 max,
                           const char* showIt )
    {
    // This is marked as an inline function.
    // An empty inlined function ought to
    // be optimized away completely if there
    // is nothing in it.

    if( toTest < min )
      throw showIt;

    if( toTest > max )
      throw showIt;

    }

#pragma clang diagnostic pop

  };


