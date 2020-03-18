// std_bhm/include/hopping/quench/amplitude.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_HOPPING_QUENCH_AMPLITUDE_H
#define STD_BHM_HOPPING_QUENCH_AMPLITUDE_H

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace hopping
{
namespace quench
{

class amplitude
{
public:
    double eval(double t) const { return do_eval(t); };

    virtual ~amplitude();

private:
    virtual double do_eval(double t) const = 0;
};

} // end of quench namespace
} // end of hopping namespace
} // end of std_bhm namespace


#endif
 













