// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/M/set.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set_ctor_args.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/X/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set_ctor_args.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

struct NSA4::set::impl
{
    impl(const ::NSA4::set_ctor_args& m_set_ctor_args);

    const ::NSA5::set X_set;
    const ::NSA6::set Sigma_set;
    
    const ::NSA4::element M_rho_rho_1;
    const ::NSA4::element M_rho_rho_2;
    const ::NSA4::element M_rho_rho_3;

    const ::NSA4::element M_rho_K_4;
    const ::NSA4::element M_rho_K_5;
    const ::NSA4::element M_rho_K_6;

    const ::NSA4::element M_K_rho_1;
    const ::NSA4::element M_K_rho_2;
    const ::NSA4::element M_K_rho_3;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_rho_1(const ::NSA5::set& X_set,
				const ::NSA6::set& Sigma_set);
::NSA4::element gen_M_rho_rho_2(const ::NSA5::set& X_set,
				const ::NSA6::set& Sigma_set);
::NSA4::element gen_M_rho_rho_3(const ::NSA5::set& X_set,
				const ::NSA6::set& Sigma_set);

::NSA4::element gen_M_rho_K_4(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set);
::NSA4::element gen_M_rho_K_5(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set);
::NSA4::element gen_M_rho_K_6(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set);

::NSA4::element gen_M_K_rho_1(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set);
::NSA4::element gen_M_K_rho_2(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set);
::NSA4::element gen_M_K_rho_3(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

NSA4::set::set(const ::NSA4::set_ctor_args& m_set_ctor_args)
    : pimpl{ spimpl::make_impl<impl>(m_set_ctor_args) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

NSA4::set::impl::impl(const ::NSA4::set_ctor_args& m_set_ctor_args)
    : X_set{ m_set_ctor_args.get_X_set_params() },
      Sigma_set{ m_set_ctor_args.get_Sigma_set_ctor_args() },
      M_rho_rho_1{ ::unnamed::gen_M_rho_rho_1(X_set, Sigma_set) },
      M_rho_rho_2{ ::unnamed::gen_M_rho_rho_2(X_set, Sigma_set) },
      M_rho_rho_3{ ::unnamed::gen_M_rho_rho_3(X_set, Sigma_set) },
      M_rho_K_4{ ::unnamed::gen_M_rho_K_4(X_set, Sigma_set) },
      M_rho_K_5{ ::unnamed::gen_M_rho_K_5(X_set, Sigma_set) },
      M_rho_K_6{ ::unnamed::gen_M_rho_K_6(X_set, Sigma_set) },
      M_K_rho_1{ ::unnamed::gen_M_K_rho_1(X_set, Sigma_set) },
      M_K_rho_2{ ::unnamed::gen_M_K_rho_2(X_set, Sigma_set) },
      M_K_rho_3{ ::unnamed::gen_M_K_rho_3(X_set, Sigma_set) }
{}



// Generate M_rho_rho_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_rho_1(const ::NSA5::set& X_set,
				const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_rho_rho_A();
    const auto& Sigma_element = Sigma_set.get_rho_rho_1();

    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_rho_rho_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_rho_2(const ::NSA5::set& X_set,
				const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_rho_rho_B();
    const auto& Sigma_element = Sigma_set.get_rho_rho_2();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_rho_rho_3.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_rho_3(const ::NSA5::set& X_set,
				const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_rho_rho_B();
    const auto& Sigma_element = Sigma_set.get_rho_rho_3();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_rho_K_4.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_K_4(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_rho_K_A();
    const auto& Sigma_element = Sigma_set.get_rho_K_4();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_rho_K_5.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_K_5(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_rho_K_B();
    const auto& Sigma_element = Sigma_set.get_rho_K_5();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_rho_K_6.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_rho_K_6(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_rho_K_B();
    const auto& Sigma_element = Sigma_set.get_rho_K_6();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_K_rho_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_K_rho_1(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_K_rho_A();
    const auto& Sigma_element = Sigma_set.get_K_rho_1();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_K_rho_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_K_rho_2(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_K_rho_B();
    const auto& Sigma_element = Sigma_set.get_K_rho_2();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate M_K_rho_3.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

namespace NSA5 = NSA3::X;
namespace NSA6 = NSA3::Sigma;

namespace unnamed
{
namespace
{

::NSA4::element gen_M_K_rho_3(const ::NSA5::set& X_set,
			      const ::NSA6::set& Sigma_set)
{
    const auto& X_element = X_set.get_K_rho_B();
    const auto& Sigma_element = Sigma_set.get_K_rho_3();
    
    const auto m_element_ctor_args = ::NSA4::element_ctor_args(X_element,
							       Sigma_element);

    return ::NSA4::element(m_element_ctor_args);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get M_rho_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_rho_1() const
{
    return pimpl->M_rho_rho_1;
}



// Get M_rho_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_rho_2() const
{
    return pimpl->M_rho_rho_2;
}



// Get M_rho_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_rho_3() const
{
    return pimpl->M_rho_rho_3;
}



// Get M_rho_K_4 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_K_4() const
{
    return pimpl->M_rho_K_4;
}



// Get M_rho_K_5 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_K_5() const
{
    return pimpl->M_rho_K_5;
}



// Get M_rho_K_6 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_rho_K_6() const
{
    return pimpl->M_rho_K_6;
}



// Get M_K_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_K_rho_1() const
{
    return pimpl->M_K_rho_1;
}



// Get M_K_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_K_rho_2() const
{
    return pimpl->M_K_rho_2;
}



// Get M_K_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::M;

const NSA4::element& NSA4::set::get_K_rho_3() const
{
    return pimpl->M_K_rho_3;
}
