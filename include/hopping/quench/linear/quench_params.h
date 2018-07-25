// /std_bhm/include/hopping/quench/linear/quench_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_HOPPING_QUENCH_LINEAR_QUENCH_PARAMS_H
#define STD_BHM_HOPPING_QUENCH_LINEAR_QUENCH_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace hopping
{
namespace quench
{
namespace linear
{

class quench_params
{
public:
    quench_params(double ji, double jf, double tc, double tau_Q);

    double get_ji() const;
    double get_jf() const;
    double get_tc() const;
    double get_tau_Q() const;
    
private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of linear namespace
} // end of quench namespace
} // end of hopping namespace
} // end of std_bhm namespace


#endif
 
