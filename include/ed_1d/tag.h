// /std_bhm/include/ed_1d/tag.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_TAG_H
#define STD_BHM_ED_1D_TAG_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{
namespace tag_detail
{

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

double gen_fock_state_tag(const int_vec& vec);
dbl_vec gen_fock_state_tags(const int_vec_2d& vec_set);

} // end of tag_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::tag_detail::gen_fock_state_tag;
using std_bhm::ed_1d::tag_detail::gen_fock_state_tags;



} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
