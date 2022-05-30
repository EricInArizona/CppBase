// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



/*

#pragma once




#include "BasicTypes.h"
// #include "Str.h"
#include "RangeC.h"
#include "CharArray.h"




class CircleBuf
  {
  private:
  Int32 testForCopy = 123;
  CharArray cArray;
  Int32 first = 0;
  Int32 last = 0;


  public:
  CircleBuf( void );
  CircleBuf( const CircleBuf &in );
  ~CircleBuf( void );

  void setSize( const Int32 howBig );

  inline Int32 getFirst( void ) const
    {
    return first;
    }

  inline Int32 getLast( void ) const
    {
    return last;
    }

  inline void clear( void )
    {
    first = 0;
    last = 0;
    }

  bool appendChar( const char toSet );
  bool appendCharPt( const char* pStr );


====
Don't be giving out pointers.
Do a send buffer like
static char SocketSendBuf[SocketBufSize] =

copy the CharArray.
  inline const char* getBufPoint( void ) const
    {
    return cArray.getBufPoint( first );
    }

  inline const Int32 getBiggestBuf( void ) const
    {
    if( first > last )
      return arraySize - first;
    else
      return last - first;
=====
    }



  inline char getC( const Int32 where ) const
    {

between first ane last or what?
    return cArray.getC( where );
    }


  };

*/


