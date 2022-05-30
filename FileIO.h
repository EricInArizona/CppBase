// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#pragma once


#include "BasicTypes.h"
#include "CharBuf.h"



class FileIO
  {
  private:

  public:
  static bool exists( const char* fileName );
  static void writeCharBuf( const char* fileName,
                            const CharBuf& cBuf );
  static void readAll( const char* fileName,
                       CharBuf& cBuf );

  };
