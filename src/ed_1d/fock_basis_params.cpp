// /std_bhm/ed_1d/fock_basis_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/fock_basis_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;

struct NSA1::fock_basis_params::impl
{
    impl(int total_number_of_particles,
	 int number_of_lattice_sites);

    const int total_number_of_particles;
    const int number_of_lattice_sites;
};



// fock_basis_params constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::fock_basis_params::fock_basis_params(int total_number_of_particles,
					   int number_of_lattice_sites)
    : pimpl{ spimpl::make_impl<impl>(total_number_of_particles,
				     number_of_lattice_sites) }
{}



// fock_basis_params::impl constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::fock_basis_params::impl::impl(int total_number_of_particles,
				    int number_of_lattice_sites)
    : total_number_of_particles{total_number_of_particles},
      number_of_lattice_sites{number_of_lattice_sites}
{}



// Get total number of particles.
namespace NSA1 = std_bhm::ed_1d;

int NSA1::fock_basis_params::get_total_number_of_particles() const
{
    return pimpl->total_number_of_particles;
}



// Get number of lattice sites.
namespace NSA1 = std_bhm::ed_1d;

int NSA1::fock_basis_params::get_number_of_lattice_sites() const
{
    return pimpl->number_of_lattice_sites;
}
