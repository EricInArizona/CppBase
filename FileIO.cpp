// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html




#include "FileIO.h"
#include <iostream>
#include <fstream>
#include "StIO.h"
#include "Casting.h"



FileIO::FileIO( void )
{
}


FileIO::FileIO( const FileIO &in )
{
// Make the compiler think in is being used.
if( in.testForCopy == 7 )
  return;

// Don't copy a giant buffer.
const char* showS = "The FileIO copy constructor"
         " should not be getting called.\n";
throw showS;
}



FileIO::~FileIO( void )
{
}


void FileIO::writeAll( const char* fileName )
{
Int32 howMany = cBuf.getLast();
const char* buffer = cBuf.getBufPoint();

std::ofstream outFile( fileName,
                       std::ofstream::binary );

outFile.write( buffer, howMany );
outFile.close();
}



void FileIO::readAll( const char* fileName )
{
std::ifstream inFile( fileName,
                      std::ifstream::binary );

inFile.seekg( 0, inFile.end );
Int64 howMany = inFile.tellg();
// Error returns -1.
if( howMany < 0 )
  throw "FileIO.readAll() tellg() returned < 0.";

// Don't read files that are this big in to RAM.
if( howMany > 4000000000LL )
  throw "Infile tellg() returned > 4000000000.";

inFile.seekg( 0 );

char* buffer = new char[Casting::i64ToU64(
                                     howMany )];
inFile.read( buffer, howMany );

cBuf.appendCharArray( buffer, Casting::i64ToI32(
                                   howMany ));

delete[] buffer;
inFile.close();
}



bool FileIO::exists( const char* fileName )
{
std::ifstream inFile( fileName,
                      std::ifstream::binary );

return inFile.good();
}



void FileIO::appendStr( const Str& in )
{
cBuf.appendStr( in );
}




void FileIO::appendCharPt( const char* pStr )
{
cBuf.appendCharPt( pStr );
}


void FileIO::appendCharBuf( const CharBuf& buf )
{
const Int32 last = buf.getLast();
for( Int32 count = 0; count < last; count++ )
  cBuf.appendChar( buf.valAt( count ));

}
