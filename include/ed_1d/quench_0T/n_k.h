// /std_bhm/include/ed_1d/quench_0T/n_k.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_QUENCH_0T_N_K_H
#define STD_BHM_ED_1D_QUENCH_0T_N_K_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"
#include <armadillo>

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{
namespace quench_0T
{



namespace fock_basis_detail
{
class fock_basis; // forward declaration
}



namespace n_k_detail
{

namespace NSA1 = std_bhm::ed_1d::quench_0T::fock_basis_detail;

class n_k
{
public:
    n_k(const NSA1::fock_basis& basis);

    double expectation_value(int k, const arma::cx_dvec& state_vec) const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of n_k_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::quench_0T::n_k_detail::n_k;



} // end of quench_0T namespace
} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
