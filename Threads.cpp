// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "Threads.h"

#include <thread>
#include <chrono>


void Threads::sleep( Int32 milli )
{
std::this_thread::sleep_for(
                      std::chrono::milliseconds(
                      milli ));

}



/*

// Pass 123 to the function written in C.
// std::thread aThread( aCFunction, 123 );



Put a C function in a cpp file.


extern "C" {

// Declare it extern, then define it.
// extern volatile Int32 ForTest;
// volatile Int32 ForTest;



// Declare it, then define it.
void aCFunction( Int32 something );


void aCFunction( Int32 something )
{
// Do something in a thread.
// forTest = someResult;

}



} // extern "C"

*/
