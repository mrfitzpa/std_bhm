// std_bhm/include/atomic_lim/local/params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ATOMIC_LIM_LOCAL_PARAMS_H
#define STD_BHM_ATOMIC_LIM_LOCAL_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace atomic_lim
{
namespace local
{

class params
{
public:
    params(double beta, double mu, int max_band_index);

    double get_beta() const;
    double get_mu() const;
    int get_max_band_index() const;
    
private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of local namespace
} // end of atomic_lim namespace
} // end of std_bhm namespace


#endif
 
