// /std_bhm/src/ed_1d/quench_0T/tuned_hopping/main_alg_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>
#include <string>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/quench_0T/tuned_hopping/main_alg_params.h"
#include "ed_1d/local_params.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/step_params.h"
#include "ed_1d/lanczos_alg_params.h"
#include "hopping/quench/linear/quench_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;
namespace NSA3 = std_bhm::hopping::quench::linear;

struct NSA2::main_alg_params::impl
{
    impl();

    const ::NSA1::local_params l_params;
    const ::NSA1::fock_basis_params fb_params;
    const ::NSA3::quench_params q_params;
    const ::NSA1::step_params dt_and_Nt;
    const ::NSA1::lanczos_alg_params la_params;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;
namespace NSA3 = std_bhm::hopping::quench::linear;

namespace unnamed
{
namespace
{

::NSA1::local_params get_l_params_from_cin();
::NSA1::fock_basis_params get_fb_params_from_cin();
::NSA3::quench_params get_q_params_from_cin();
::NSA1::step_params get_dt_and_Nt_from_cin();
::NSA1::lanczos_alg_params get_la_params_from_cin();

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// main_alg_params constructor.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;

NSA2::main_alg_params::main_alg_params()
    : pimpl{ spimpl::make_impl<impl>() }
{}



// main_alg_params::impl constructor.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;

NSA2::main_alg_params::impl::impl()
    : l_params{ ::unnamed::get_l_params_from_cin() },
      fb_params{ ::unnamed::get_fb_params_from_cin() },
      q_params{ ::unnamed::get_q_params_from_cin() },
      dt_and_Nt{ ::unnamed::get_dt_and_Nt_from_cin() },
      la_params{ ::unnamed::get_la_params_from_cin() }
{}



// Get local parameters (i.e. 'mu' and 'U') from standard input.
namespace NSA1 = std_bhm::ed_1d;

namespace unnamed
{
namespace
{

::NSA1::local_params get_l_params_from_cin()
{
    auto mu = double();
    const auto U = 1.0;
    
    std::cin >> mu;

    return ::NSA1::local_params(mu, U);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get fock basis parameters from standard input.
namespace NSA1 = std_bhm::ed_1d;

namespace unnamed
{
namespace
{

::NSA1::fock_basis_params get_fb_params_from_cin()
{
    auto total_number_of_particles = int();
    auto number_of_lattice_sites = int();
    
    std::cin >> total_number_of_particles;
    std::cin >> number_of_lattice_sites;

    return ::NSA1::fock_basis_params{total_number_of_particles,
	                             number_of_lattice_sites};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get quench parameters from standard input.
namespace NSA3 = std_bhm::hopping::quench::linear;

namespace unnamed
{
namespace
{

::NSA3::quench_params get_q_params_from_cin()
{
    auto ji = double();
    auto jf = double();
    auto tc = double();
    auto tau_Q = double();
    
    std::cin >> ji;
    std::cin >> jf;
    std::cin >> tc;
    std::cin >> tau_Q;

    return ::NSA3::quench_params{ji, jf, tc, tau_Q};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get step parameters from standard input.
namespace NSA1 = std_bhm::ed_1d;

namespace unnamed
{
namespace
{

::NSA1::step_params get_dt_and_Nt_from_cin()
{
    auto Nt = int();
    auto dt = double();
    
    std::cin >> Nt;
    std::cin >> dt;

    return ::NSA1::step_params{Nt, dt};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get the 'Lanczos algorithm' parameters from standard input.
namespace NSA1 = std_bhm::ed_1d;

namespace unnamed
{
namespace
{

::NSA1::lanczos_alg_params get_la_params_from_cin()
{
    auto krylov_dimension = int();
    auto convergence_tolerance = double();
    auto convergence_tolerance_str = std::string();

    std::cin >> krylov_dimension;
    std::cin >> convergence_tolerance_str;
    convergence_tolerance = std::stod(convergence_tolerance_str);

    return ::NSA1::lanczos_alg_params(krylov_dimension, convergence_tolerance);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get local parameters (i.e. 'mu' and 'U') from class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;

NSA1::local_params NSA2::main_alg_params::get_local_params() const
{
    return pimpl->l_params;
}



// Get spatial parameters from class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;

NSA1::fock_basis_params NSA2::main_alg_params::get_fock_basis_params() const
{
    return pimpl->fb_params;
}



// Get quench parameters from class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;
namespace NSA3 = std_bhm::hopping::quench::linear;

NSA3::quench_params NSA2::main_alg_params::get_quench_params() const
{
    return pimpl->q_params;
}



// Get step parameters from class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;

NSA1::step_params NSA2::main_alg_params::get_step_params() const
{
    return pimpl->dt_and_Nt;
}



// Get Lanczos algorithm parameters from class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T::tuned_hopping;

NSA1::lanczos_alg_params NSA2::main_alg_params::get_lanczos_alg_params() const
{
    return pimpl->la_params;
}
