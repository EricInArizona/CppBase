// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



// This is supposed to be cryptographically
// random, but this is not.  It is random enough
// to test an algorithm.
// I'm not writing a long and in-depth book
// on randomness just yet.  I'll do that when
// I have a few years to set aside for that
// task.
// The more complex something is, the more
// random it looks.  Is the Universe just a
// series of meaningless random events?
// Or is it complex?
// I won't be answering that question any
// time soon.


#include "BasicTypes.h"
#include "Uint16Buf.h"


class Randomish
  {
  private:

  public:
  static void makeRandomBytes( Uint16Buf& uBuf,
                           const Int32 howMany );

  };
