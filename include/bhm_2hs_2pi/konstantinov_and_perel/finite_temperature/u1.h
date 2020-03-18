// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_FINITE_TEMPERATURE_U1_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_FINITE_TEMPERATURE_U1_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{



namespace atomic_lim
{
namespace local
{
class params; // forward declaration
}
}



namespace bhm_2hs_2pi
{
namespace konstantinov_and_perel
{
namespace finite_temperature
{
namespace u1_detail
{

using local_params = std_bhm::atomic_lim::local::params;

double u1(const local_params& l_params);

} // end of u1_detail namespace



using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::finite_temperature::\
u1_detail::u1;



} // end of finite_temperature namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
