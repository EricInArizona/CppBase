// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#pragma once


#include "BasicTypes.h"
#include "CharArray.h"
#include "Str.h"



class FileIO
  {
  private:

  public:
  static bool exists( const Str& fileName );
  static void writeCharBuf( const Str& fileName,
                        const CharBuf& cBuf );
  static bool readAll( const Str& fileName,
                       CharBuf& cBuf );

  };
