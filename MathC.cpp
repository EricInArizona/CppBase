// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "MathC.h"
#include "Casting.h"

// Always include system files at the bottom
// under other include files.
#include <cmath>

// https://en.cppreference.com/w/cpp/numeric/math

// abs, sin, cos, sqrt, exp pow, ceil, floor,
// and all that.


double MathC::roundDbl( double x )
{
return std::round( x );
}

Int64 MathC::round64( double x )
{
return std::lround( x );
}

Int32 MathC::round32( double x )
{
return Casting::i64ToI32( std::lround( x ));
}
