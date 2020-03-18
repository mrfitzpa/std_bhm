// /std_bhm/include/ed_1d/quench_0T/tuned_hopping/main_alg_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_QUENCH_0T_TUNED_HOPPING_MAIN_ALG_PARAMS_H
#define STD_BHM_ED_1D_QUENCH_0T_TUNED_HOPPING_MAIN_ALG_PARAMS_H

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

class quench_params; // forward declaration

}
}
}



namespace ed_1d
{



class local_params; // forward declaration
class fock_basis_params; // forward declaration
class step_params; // forward declaration
class lanczos_alg_params; // forward declaration



namespace quench_0T
{
namespace tuned_hopping
{
namespace main_alg_params_detail
{

namespace NSA1 = std_bhm::ed_1d;
namespace NSA3 = std_bhm::hopping::quench::linear;

class main_alg_params
{
public:
    main_alg_params();

    NSA1::local_params get_local_params() const;
    NSA1::fock_basis_params get_fock_basis_params() const;
    NSA3::quench_params get_quench_params() const;
    NSA1::step_params get_step_params() const;
    NSA1::lanczos_alg_params get_lanczos_alg_params() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of main_alg_params_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::quench_0T::tuned_hopping::main_alg_params_detail::\
main_alg_params;



} // end of tuned_hopping namespace
} // end of quench_0T namespace
} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
