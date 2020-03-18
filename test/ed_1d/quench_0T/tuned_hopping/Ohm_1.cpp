// /std_bhm/test/ed_1d/quench_0T/tuned_hopping/Ohm_1.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the classes defined in the 
// .cpp file 'std_bhm/test/ed_1d/quench_0T/tuned_hopping/Ohm_1.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/tuned_hopping/Ohm_1.h"
#include "ed_1d/quench_0T/tuned_hopping/main_alg_params.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/local_params.h"
#include "ed_1d/step_params.h"
#include "hopping/quench/linear/amplitude.h"
#include "hopping/quench/linear/quench_params.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::ed_1d::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA4 = std_bhm::hopping::quench::linear;

int main(int argc, char** argv)
{
    const auto main_params = ::NSA3::main_alg_params();

    const auto& l_params = main_params.get_local_params();
    const auto& fb_params = main_params.get_fock_basis_params();
    const auto& q_params = main_params.get_quench_params();
    const auto& dt_and_Nt = main_params.get_step_params();

    const auto basis = ::NSA2::fock_basis(fb_params);
    const auto J = ::NSA4::amplitude(q_params);
    auto dt = dt_and_Nt.get_dt();

    auto Ohm = ::NSA3::Ohm_1(basis, J, l_params, dt);

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    auto t = ::NSA1::to_value<double>();
    auto mat_rep = Ohm.eval(t);
    mat_rep.raw_print(std::cout);

    t += 2.0;
    dt /= 2.0;
    Ohm.set_timestep(dt);
    mat_rep = Ohm.eval(t);
    mat_rep.raw_print(std::cout);
    
    return 0;
}

