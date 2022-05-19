// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "BasicTypes.h"
#include "../CppBase/CharBuf.h"



class StIO
  {
  private:

  public:
  static void printF( const char* toWrite );
  // putS adds a newline to the end.
  static void putS( const char* toWrite );
  static void printFD( const Int32 d );
  static void putChar( const int c );
  static void putCharBuf( const CharBuf& charBuf );
  bool checkKey( void );

  };
