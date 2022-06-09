// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL), version 2.  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "BasicTypes.h"
#include "RangeC.h"


class BoolArray
  {
  private:
  bool testForCopy = false;
  Int32 arraySize = 1;
  bool* bArray;

  public:
  BoolArray( void );
  BoolArray( const BoolArray& in );
  ~BoolArray( void );
  void setSize( const Int32 howBig );
  inline Int32 getSize( void ) const
    {
    return arraySize;
    }

  inline bool getVal( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
           "BoolArray.getVal() where range." );

    return bArray[where];
    }

  inline void setVal( const Int32 where,
                      const bool toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
             "BoolArray.setVal() where range." );

    bArray[where] = toSet;
    }


  };
