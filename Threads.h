// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


// I might never be using threads like this:
// std::thread aThread( AFunctionInC );
// But see the bottom of the Threads.cpp file for
// notes on that.


#include "BasicTypes.h"


class Threads
  {
  private:

  public:
  static void sleep( Int32 milli );

  };
