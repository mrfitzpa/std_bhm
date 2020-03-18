// /std_bhm/include/ed_1d/quench_0T/tuned_hopping/Ohm_1.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_QUENCH_0T_TUNED_HOPPING_OHM_1_H
#define STD_BHM_ED_1D_QUENCH_0T_TUNED_HOPPING_OHM_1_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"
#include <armadillo>

/* Include user-defined header files */



namespace std_bhm
{



namespace hopping
{
namespace quench
{
class amplitude; // forward declaration
}
}



namespace ed_1d
{



class local_params;



namespace quench_0T
{



namespace fock_basis_detail
{
class fock_basis; // forward declaration
}



namespace tuned_hopping
{
namespace Ohm_1_detail
{

namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::fock_basis_detail;
namespace NSA3 = std_bhm::hopping::quench;

class Ohm_1
{
public:
    Ohm_1(const NSA2::fock_basis& basis,
	  const NSA3::amplitude& J,
	  const NSA1::local_params& l_params,
	  double dt);

    void set_timestep(double dt);
    
    arma::sp_mat eval(double t) const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of Ohm_1_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::quench_0T::tuned_hopping::Ohm_1_detail::Ohm_1;



} // end of tuned_hopping namespace
} // end of quench_0T namespace
} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
