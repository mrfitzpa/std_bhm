// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Sigma/set.cpp

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
start_in_atomic_lim/block_by_block/hfb/Sigma/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/set_ctor_args.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Sigma/element_ctor_args.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/set_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Y/element.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/set.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"

#include "atomic_lim/local/params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

struct NSA4::set::impl
{
    impl(const ::NSA4::set_ctor_args& s_set_ctor_args);

    const ::NSA5::set Y_set;
    const ::NSA6::set Z_set;

    const ::NSA4::element Sigma_rho_rho_1;
    const ::NSA4::element Sigma_rho_rho_2;
    const ::NSA4::element Sigma_rho_rho_3;

    const ::NSA4::element Sigma_rho_K_4;
    const ::NSA4::element Sigma_rho_K_5;
    const ::NSA4::element Sigma_rho_K_6;

    const ::NSA4::element Sigma_K_rho_1;
    const ::NSA4::element Sigma_K_rho_2;
    const ::NSA4::element Sigma_K_rho_3;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_rho_1(
                    const ::NSA5::set& Y_set,
		    const ::NSA6::set& Z_set,
		    const ::NSA4::set_ctor_args& s_set_ctor_args);
::NSA4::element gen_Sigma_rho_rho_2(
                    const ::NSA5::set& Y_set,
		    const ::NSA6::set& Z_set,
		    const ::NSA4::set_ctor_args& s_set_ctor_args);
::NSA4::element gen_Sigma_rho_rho_3(
                    const ::NSA5::set& Y_set,
		    const ::NSA6::set& Z_set,
		    const ::NSA4::set_ctor_args& s_set_ctor_args);

::NSA4::element gen_Sigma_rho_K_4(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args);
::NSA4::element gen_Sigma_rho_K_5(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args);
::NSA4::element gen_Sigma_rho_K_6(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args);

::NSA4::element gen_Sigma_K_rho_1(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args);
::NSA4::element gen_Sigma_K_rho_2(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args);
::NSA4::element gen_Sigma_K_rho_3(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// set constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

NSA4::set::set(const ::NSA4::set_ctor_args& s_set_ctor_args)
    : pimpl{ spimpl::make_impl<impl>(s_set_ctor_args) }
{}



// params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

NSA4::set::impl::impl(const ::NSA4::set_ctor_args& s_set_ctor_args)
    : Y_set{ s_set_ctor_args.get_Y_set_params() },
      Z_set{ s_set_ctor_args.get_n_array() },
      Sigma_rho_rho_1{
	  ::unnamed::gen_Sigma_rho_rho_1(Y_set, Z_set, s_set_ctor_args) },
      Sigma_rho_rho_2{
	  ::unnamed::gen_Sigma_rho_rho_2(Y_set, Z_set, s_set_ctor_args) },
      Sigma_rho_rho_3{
	  ::unnamed::gen_Sigma_rho_rho_3(Y_set, Z_set, s_set_ctor_args) },
      Sigma_rho_K_4{
	  ::unnamed::gen_Sigma_rho_K_4(Y_set, Z_set, s_set_ctor_args) },
      Sigma_rho_K_5{
	  ::unnamed::gen_Sigma_rho_K_5(Y_set, Z_set, s_set_ctor_args) },
      Sigma_rho_K_6{
	  ::unnamed::gen_Sigma_rho_K_6(Y_set, Z_set, s_set_ctor_args) },
      Sigma_K_rho_1{
	  ::unnamed::gen_Sigma_K_rho_1(Y_set, Z_set, s_set_ctor_args) },
      Sigma_K_rho_2{
	  ::unnamed::gen_Sigma_K_rho_2(Y_set, Z_set, s_set_ctor_args) },
      Sigma_K_rho_3{
	  ::unnamed::gen_Sigma_K_rho_3(Y_set, Z_set, s_set_ctor_args) }
{}



// Generate Sigma_rho_rho_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_rho_1(
                    const ::NSA5::set& Y_set,
		    const ::NSA6::set& Z_set,
		    const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_rho_rho_A();
    const auto& Z_element = Z_set.get_type_1();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_rho_rho_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_rho_2(
                    const ::NSA5::set& Y_set,
		    const ::NSA6::set& Z_set,
		    const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_rho_rho_B();
    const auto& Z_element = Z_set.get_type_2();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_rho_rho_3.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_rho_3(
                    const ::NSA5::set& Y_set,
		    const ::NSA6::set& Z_set,
		    const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_rho_rho_B();
    const auto& Z_element = Z_set.get_type_3();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_rho_K_4.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_K_4(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_rho_K_A();
    const auto& Z_element = Z_set.get_type_4();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_rho_K_5.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_K_5(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_rho_K_B();
    const auto& Z_element = Z_set.get_type_5();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_rho_K_6.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_rho_K_6(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_rho_K_B();
    const auto& Z_element = Z_set.get_type_6();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_K_rho_1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_K_rho_1(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_K_rho_A();
    const auto& Z_element = Z_set.get_type_1();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_K_rho_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_K_rho_2(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_K_rho_B();
    const auto& Z_element = Z_set.get_type_2();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate Sigma_K_rho_3.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

namespace NSA5 = NSA3::Y;
namespace NSA6 = NSA3::Z;

namespace unnamed
{
namespace
{

::NSA4::element gen_Sigma_K_rho_3(const ::NSA5::set& Y_set,
				  const ::NSA6::set& Z_set,
				  const ::NSA4::set_ctor_args& s_set_ctor_args)
{
    const auto& y_set_params = s_set_ctor_args.get_Y_set_params();
    const auto& l_params = y_set_params.get_local_params();

    const auto& Y_element = Y_set.get_K_rho_B();
    const auto& Z_element = Z_set.get_type_3();

    const auto s_element_ctor_args = ::NSA4::element_ctor_args{Y_element,
							       Z_element,
							       l_params};

    return ::NSA4::element{s_element_ctor_args};
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get Sigma_rho_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_rho_rho_1() const
{
    return pimpl->Sigma_rho_rho_1;
}



// Get Sigma_rho_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_rho_rho_2() const
{
    return pimpl->Sigma_rho_rho_2;
}



// Get Sigma_rho_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_rho_rho_3() const
{
    return pimpl->Sigma_rho_rho_3;
}



// Get Sigma_rho_K_4 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_rho_K_4() const
{
    return pimpl->Sigma_rho_K_4;
}



// Get Sigma_rho_K_5 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_rho_K_5() const
{
    return pimpl->Sigma_rho_K_5;
}



// Get Sigma_rho_K_6 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_rho_K_6() const
{
    return pimpl->Sigma_rho_K_6;
}



// Get Sigma_K_rho_1 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_K_rho_1() const
{
    return pimpl->Sigma_K_rho_1;
}



// Get Sigma_K_rho_2 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_K_rho_2() const
{
    return pimpl->Sigma_K_rho_2;
}



// Get Sigma_K_rho_3 reference.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::Sigma;

const NSA4::element& NSA4::set::get_K_rho_3() const
{
    return pimpl->Sigma_K_rho_3;
}
