// std_bhm/include/atomic_lim/equilibrium/local/two_pt_func.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_EQUILIBRIUM_LOCAL_TWO_PT_FUNC_H
#define STD_BHM_ATOMIC_LIM_EQUILIBRIUM_LOCAL_TWO_PT_FUNC_H

/* Include standard libraries */
#include <complex>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace atomic_lim
{
namespace equilibrium
{
namespace local
{

class two_pt_func
{
public:
    std::complex<double> eval(double t) const { return do_eval(t); }

    virtual ~two_pt_func();

private:
    virtual std::complex<double> do_eval(double t) const = 0;
};

} // end of local namespace
} // end of equilibrium namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
 
