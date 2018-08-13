// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Y/base.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/base.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/epsilon_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/array_gen_params.h"

#include "hopping/quench/linear/amplitude.h"
#include "hopping/quench/linear/quench_params.h" 
#include "hopping/fourier_transform_of_connectivity.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

using dbl_vec = std::vector<double>;

struct NSA3::base::impl
{
    impl(const ::NSA3::params& y_params);

    const dbl_vec array_rep;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

namespace NSA4 = std_bhm::hopping;
namespace NSA5 = NSA4::quench::linear;

using dbl_vec = std::vector<double>;

namespace unnamed
{
namespace
{

const dbl_vec gen_array(const ::NSA3::params& y_params);

const double calc_neg_F_CM(const ::NSA3::params& y_params);
const NSA5::amplitude gen_hop_amp_obj(const ::NSA3::params& y_params);
const double calc_two_u1_n0(const ::NSA3::params& y_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// base constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

NSA3::base::base(const ::NSA3::params& y_params)
    : pimpl{ spimpl::make_impl<impl>(y_params) }
{}



// base::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

NSA3::base::impl::impl(const ::NSA3::params& y_params)
    : array_rep( ::unnamed::gen_array(y_params) )
{}



// Generate array representation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

namespace unnamed
{
namespace
{

const dbl_vec gen_array(const ::NSA3::params& y_params)
{
    const auto neg_F_CM = ::unnamed::calc_neg_F_CM(y_params);
    const auto hop_amp = ::unnamed::gen_hop_amp_obj(y_params);
    const auto two_u1_n0 = ::unnamed::calc_two_u1_n0(y_params);

    const auto& ag_params = y_params.get_array_gen_params();
    const auto step_offset = ag_params.get_step_offset();
    const auto ds = ag_params.get_ds();
    const auto s_offset = step_offset * ds;
    
    const auto Ns = ag_params.get_Ns();
    auto array_rep = dbl_vec(Ns);

    for(auto l=decltype(Ns){0}; l<Ns; l++)
    {
	double s = l * ds + s_offset;
	array_rep[l] = hop_amp.eval(s) * neg_F_CM - two_u1_n0;
    }

    return array_rep;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate -1 x fourier transform of the connectivity matrix.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

namespace NSA4 = std_bhm::hopping;

namespace unnamed
{
namespace
{

const double calc_neg_F_CM(const ::NSA3::params& y_params)
{
    const auto& e_params = y_params.get_epsilon_params();
    const auto& k_vec = e_params.get_k_vector();
    const auto F_CM = ::NSA4::fourier_transform_of_connectivity(k_vec);
    
    return -F_CM;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate hopping amplitude object.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

namespace NSA4 = std_bhm::hopping;
namespace NSA5 = NSA4::quench::linear;

namespace unnamed
{
namespace
{

const NSA5::amplitude gen_hop_amp_obj(const ::NSA3::params& y_params)
{
    const auto& e_params = y_params.get_epsilon_params();
    const auto& q_params = e_params.get_quench_params();
    const auto hop_amp = ::NSA5::amplitude(q_params);
    
    return hop_amp;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate 2 * u1 * n0.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

namespace NSA6 = NSA1::finite_temperature;
namespace NSA7 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

namespace unnamed
{
namespace
{

const double calc_two_u1_n0(const ::NSA3::params& y_params)
{
    const auto& l_params = y_params.get_local_params();
    
    const auto u1 = ::NSA6::u1(l_params);
    
    const auto G0_K12 = ::NSA7::kinetic_propagator(l_params);
    const auto G0_K12_s0 = G0_K12.eval(0);
    const auto n0 = -0.5 * std::imag(G0_K12_s0) - 0.5;
    
    return 2.0 * u1 * n0;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Evaluate Y.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

double NSA3::base::eval(int l1, int l2) const
{
    const auto index = calc_array_index(l1, l2);
    return pimpl->array_rep[index];
}



// base destructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb::Y;

NSA3::base::~base() {}
