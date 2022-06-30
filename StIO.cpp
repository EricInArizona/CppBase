// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "StIO.h"


// Always put these last.
#include <stdio.h>
#include <wchar.h>

// #include <time.h>
// #include <select.h>



// extern "C" {


/*
d or i Signed decimal integer 392
u Unsigned decimal integer 7235
o Unsigned octal 610
x Unsigned hexadecimal integer 7fa
X Unsigned hexadecimal integer (uppercase)
 7FA
f Decimal floating point, lowercase
        392.65
F Decimal floating point, uppercase
 392.65
e Scientific notation (mantissa/exponent),
        lowercase 3.9265e+2
E Scientific notation (mantissa/exponent),
        uppercase 3.9265E+2
g Use the shortest representation: %e or %f
 392.65
G Use the shortest representation: %E or %F
 392.65
a Hexadecimal floating point, lowercase
 -0xc.90fep-2
A Hexadecimal floating point, uppercase
 -0XC.90FEP-2
c Character a
s String of characters sample
p Pointer address b8000000
n Nothing printed.

hh signed char unsigned char
 signed char*
h short int unsigned short int
 short int*
l long int unsigned long int
 wint_t wchar_t*  long int*
ll long long int unsigned long long int
 long long int*
j intmax_t uintmax_t
 intmax_t*
z size_t size_t
        size_t*
t ptrdiff_t ptrdiff_t
 ptrdiff_t*
 long double

*/




void StIO::printF( const char* toWrite )
{
if( toWrite == nullptr )
  return;

// printf( "Testing.\n" );

printf( "%s", toWrite );
}



void StIO::putS( const char* toWrite )
{
if( toWrite == nullptr )
  return;

// This adds a newline character to the end
// of the string.

// puts( "Testing." );

puts( toWrite );

// extern int puts (const char *__s);
}


void StIO::printFD( const Int64 x )
{
printf( "%lld", x );
}


void StIO::printFUD( const Uint64 x )
{
printf( "%llu", x );
}


void StIO::putChar( const int c )
{
// int putchar( int c );
putchar( c );
}


void StIO::putLF( void )
{
// int putchar( int c );
putchar( '\n' );
}



// putwchar won't work on Windows?

// wchar_t is the type for a wide character.
// putwchar() is in wchar.h
void StIO::putWChar( const Uint16 c )
{
putwchar( c );
}



void StIO::putCharBuf( const CharBuf& charBuf )
{
const Int32 max = charBuf.getLast();
for( Int32 count = 0; count < max; count++ )
  putchar( charBuf.getC( count ));

}




/*
In Windows:
#include <windows.h>
winuser.h
And link to what dll?
SHORT GetKeyState( [in] int nVirtKey );

*/

/*
This might work in Linux.
Non blocking see if a key was pressed.
bool StIO::checkKey( void )
{
// In winsock2.h
typedef struct timeval {
    long tv_sec;
    long tv_usec;
} timeval;


struct timeval tv;
fd_set readfds;

tv.tv_sec = 0;
tv.tv_usec = 1; // 500000; // microseconds.

FD_ZERO( &readfds );
FD_SET( 0, &readfds );

select( // Casting::U64ToI32( STDIN_FILENO + 1 ),
        0,
         &readfds, nullptr,
                 nullptr, &tv );

if( FD_ISSET( STDIN_FILENO, &readfds ))
  {
  putS( "A key was pressed." );
  return true;
  }

return false;
}
*/
