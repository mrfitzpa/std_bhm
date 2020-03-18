// /std_bhm/include/ed_1d/step_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_STEP_PARAMS_H
#define STD_BHM_ED_1D_STEP_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{

class step_params
{
public:
    step_params(int Nt, double dt);

    int get_Nt() const;
    double get_dt() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
