// /std_bhm/include/ed_1d/quench_0T/ground_state.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_QUENCH_0T_GROUND_STATE_H
#define STD_BHM_ED_1D_QUENCH_0T_GROUND_STATE_H

/* Include standard libraries */

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{



namespace bhm_params_detail
{
class bhm_params; // forward declaration
}



namespace quench_0T
{



namespace fock_basis_detail
{
class fock_basis; // forward declaration
}



namespace ground_state_detail
{

namespace NSA1 = std_bhm::ed_1d::bhm_params_detail;
namespace NSA2 = std_bhm::ed_1d::quench_0T::fock_basis_detail;

void ground_state(arma::dvec& ground_state_vec,
		  const NSA2::fock_basis& basis,
		  const NSA1::bhm_params& model_params);

void ground_state(double& ground_state_energy,
		  const NSA2::fock_basis& basis,
		  const NSA1::bhm_params& model_params);

void ground_state(double& ground_state_energy,
		  arma::dvec& ground_state_vec,
		  const NSA2::fock_basis& basis,
		  const NSA1::bhm_params& model_params);

} // end of ground_state_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::quench_0T::ground_state_detail::ground_state;



} // end of quench_0T namespace
} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
