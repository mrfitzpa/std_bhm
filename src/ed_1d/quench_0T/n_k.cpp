// /std_bhm/src/ed_1d/quench_0T/n_k.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>
#include <complex>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/n_k.h"
#include "ed_1d/quench_0T/n_k_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using sp_cx_mat_set = std::vector<arma::sp_cx_mat>;

struct NSA1::n_k::impl
{
    impl(const ::NSA1::fock_basis& basis);

    const sp_cx_mat_set mat_rep;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using sp_cx_mat_set = std::vector<arma::sp_cx_mat>;

namespace unnamed
{
namespace
{

sp_cx_mat_set calc_mat_rep(const ::NSA1::fock_basis& basis);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// n_k constructor.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

NSA1::n_k::n_k(const ::NSA1::fock_basis& basis)
    : pimpl{ spimpl::make_impl<impl>(basis) }
{}



// n_k::impl constructor.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

NSA1::n_k::impl::impl(const ::NSA1::fock_basis& basis)
    : mat_rep( ::unnamed::calc_mat_rep(basis) )
{}



// Calculate the matrix representation.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

using sp_cx_mat_set = std::vector<arma::sp_cx_mat>;

namespace unnamed
{
namespace
{

sp_cx_mat_set calc_mat_rep(const ::NSA1::fock_basis& basis)
{
    const auto D = basis.get_hilbert_space_dimension();
    const auto M = basis.get_number_of_lattice_sites();

    auto mat_rep = sp_cx_mat_set( M, arma::sp_cx_mat(D, D) );

    for(auto k=decltype(M){0}; k<M; k++)
	mat_rep[k].set_real( ::NSA1::n_k_mat_rep(k, basis) );

    return mat_rep;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the expectation value.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

double NSA1::n_k::expectation_value(int k, const arma::cx_dvec& state_vec) const
{
    const auto temp_vec = arma::cx_dvec(pimpl->mat_rep[k] * state_vec);
    return std::real( arma::cdot(state_vec, temp_vec) );
}
