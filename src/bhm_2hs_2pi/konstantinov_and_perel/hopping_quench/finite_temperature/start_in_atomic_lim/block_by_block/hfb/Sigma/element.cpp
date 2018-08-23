// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma/element.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

struct NSA4::element::impl
{
    impl(const ::NSA4::element_ctor_args& s_element_ctor_args);

    const NSA5::element& Y_element;
    const NSA6::element& Z_element;
    const double two_u1;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

namespace unnamed
{
namespace
{

const double calc_two_u1(const ::NSA4::element_ctor_args& s_element_ctor_args);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// element constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

NSA4::element::element(const ::NSA4::element_ctor_args& s_element_ctor_args)
    : pimpl{ spimpl::make_impl<impl>(s_element_ctor_args) }
{}



// element::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

NSA4::element::impl::impl(const ::NSA4::element_ctor_args& s_element_ctor_args)
    : Y_element{ s_element_ctor_args.get_Y_element() },
      Z_element{ s_element_ctor_args.get_Z_element() },
      two_u1{ ::unnamed::calc_two_u1(s_element_ctor_args) }
{}



// Calculate 2 * u1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA7 = NSA1::finite_temperature;

namespace unnamed
{
namespace
{

const double calc_two_u1(const ::NSA4::element_ctor_args& s_element_ctor_args)
{
    const auto& l_params = s_element_ctor_args.get_local_params();    
    const auto u1 = ::NSA7::u1(l_params);
    
    return 2.0 * u1;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Evaluate Sigma.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA2 = NSA1::hopping_quench::finite_temperature::start_in_atomic_lim;
namespace NSA3 = NSA2::block_by_block::hfb;
namespace NSA4 = NSA3::Sigma;

double NSA4::element::eval(int l1, int l2) const
{
    const auto Y = pimpl->Y_element.eval(l1, l2);
    const auto Z = pimpl->Z_element.eval(l1, l2);
    
    return Y + pimpl->two_u1 * Z;
}
