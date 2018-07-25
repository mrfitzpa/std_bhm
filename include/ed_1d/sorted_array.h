// /std_bhm/include/ed_1d/sorted_array.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_SORTED_ARRAY_H
#define STD_BHM_ED_1D_SORTED_ARRAY_H

/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{
namespace sorted_array_detail
{

using dbl_vec = std::vector<double>;

class sorted_array
{
public:
    sorted_array(const dbl_vec& data);

    int where_in_unsorted(double elem, double tol = 1.0e-10) const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of sorted_array_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::sorted_array_detail::sorted_array;



} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
