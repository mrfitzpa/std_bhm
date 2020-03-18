// /std_bhm/include/ed_1d/bhm_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_BHM_PARAMS_H
#define STD_BHM_ED_1D_BHM_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{

class local_params; // forward declaration

namespace bhm_params_detail
{

namespace NSA1 = std_bhm::ed_1d;

class bhm_params
{
public:
    bhm_params(double J, const NSA1::local_params& l_params);

    double get_J() const;
    NSA1::local_params get_local_params() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of bhm_params_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::bhm_params_detail::bhm_params;



} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
