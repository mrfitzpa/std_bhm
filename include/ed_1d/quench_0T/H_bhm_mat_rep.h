// /std_bhm/include/ed_1d/quench_0T/H_bhm_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_QUENCH_0T_H_BHM_MAT_REP_H
#define STD_BHM_ED_1D_QUENCH_0T_H_BHM_MAT_REP_H

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



namespace H_bhm_mat_rep_detail
{

namespace NSA1 = std_bhm::ed_1d::bhm_params_detail;
namespace NSA2 = std_bhm::ed_1d::quench_0T::fock_basis_detail;

arma::sp_mat H_bhm_mat_rep(const NSA2::fock_basis& basis,
			   const NSA1::bhm_params& model_params);

} // end of H_bhm_mat_rep_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::quench_0T::H_bhm_mat_rep_detail::H_bhm_mat_rep;



} // end of quench_0T namespace
} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
