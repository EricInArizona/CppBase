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
  CharBuf cBuf;
  Int32 testForCopy = 123;
  public:
  FileIO( void );
  FileIO( const FileIO &in );
  ~FileIO( void );
  void readAll( const char* fileName );
  void writeAll( const char* fileName );
  void appendStr( const Str& in );
  void appendCharPt( const char* pStr );
  static bool exists( const char* fileName );
  void appendCharBuf( const CharBuf& buf );

  };
