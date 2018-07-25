// std_bhm/src/ed_1d/tag.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "ed_1d/tag.h"



// Generate a tag for a given fock state.
namespace NSA1 = std_bhm::ed_1d::tag_detail;

using int_vec = std::vector<int>;

double NSA1::gen_fock_state_tag(const int_vec& fock_state)
{
    auto tag = 0.0;

    const auto M = fock_state.size();

    for(auto i=decltype(M){0}; i<M; i++)
    {
	const auto p_i = 100.0 * (i + 1) + 3.0;
	tag += sqrt(p_i) * fock_state[i];
    }

    return tag;
}



// Generate a tag array given a set of fock states.
namespace NSA1 = std_bhm::ed_1d::tag_detail;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

dbl_vec NSA1::gen_fock_state_tags(const int_vec_2d& fock_states)
{
    const auto size = fock_states.size();
    auto tag_array = dbl_vec(size);

    for(auto v=decltype(size){0}; v<size; v++)
    {
	const auto vec = fock_states[v];
	const auto tag = ::NSA1::gen_fock_state_tag(vec);
	tag_array[v] = tag;
    }

    return tag_array;
}
