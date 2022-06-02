// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "FileIO.h"
#include "StIO.h"
#include "Casting.h"

// Put these standard files last so that macros
// get defined as late as possible.

#include <iostream>
#include <fstream>


void FileIO::writeCharAr( const char* fileName,
                       const CharArray& cArray )
{
const Int32 howMany = cArray.getSize();

char* buffer = new char[Casting::i64ToU64(
                                  howMany)];

for( Int32 count = 0; count < howMany; count++ )
  buffer[count] = cArray.getC( count );

std::ofstream outFile( fileName,
                       std::ofstream::binary );

outFile.write( buffer,
               howMany );

// good() returns true if none of the error
// bits get set.
// End of file flag?

// outFile.good();

outFile.close();
delete[] buffer;
}


void FileIO::readAll( const char* fileName,
                      CharArray& cArray )
{
std::ifstream inFile( fileName,
                        std::ifstream::binary );

inFile.seekg( 0, inFile.end );
Int64 howMany = inFile.tellg();
// Error returns -1.
if( howMany < 0 )
  throw "FileIO.readAll() tellg() returned < 0.";

// Don't read files that are this big in to RAM.
if( howMany > 1000000000LL )
  throw "Infile tellg() returned > 1000000000.";

inFile.seekg( 0 );

char* buffer = new char[Casting::i64ToU64(
                                     howMany )];
inFile.read( buffer, howMany );

cArray.setSize( Casting::i64ToI32( howMany ));
for( Int32 count = 0; count < howMany; count++ )
  cArray.setC( count, buffer[count] );

inFile.close();
delete[] buffer;
}



bool FileIO::exists( const char* fileName )
{
std::ifstream inFile( fileName,
                      std::ifstream::binary );

return inFile.good();
}
