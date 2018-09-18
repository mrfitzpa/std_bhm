// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/sim/alg_1.cpp

// -----------------------------------------------------------------------

// This algorithm simulates light-cone-like spreading of single-particle
// correlations after a hopping quench in the strong-coupling regime.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>
#include <string>
#include <vector>
#include <limits>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/alg_1.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/alg_1_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/n_array_tracker.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/epsilon_params.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/k_eqn/alg.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/sim/gen_abs_filename_for_output_file.h"

#include "hopping/spatial_params.h"
#include "hopping/quench/linear/quench_params.h"

#include "atomic_lim/local/params.h"

#include "k_map/gen_minimal_k_vec_set.h"
#include "k_map/gen_minimal_k_ints_set.h"
#include "k_map/calc_n_duplicates.h"

#include "density_matrix/single_particle/calc_from_n_k_data.h"

#include "output/write_time_series_to_file.h"
#include "output/vector_to_string.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = NSA3::k_eqn;

using k_eqn_alg_set = std::vector<::NSA5::alg>;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

::NSA3::n_array_tracker gen_n_array_tracker(
                            const ::NSA4::alg_1_params& sim_params);
k_eqn_alg_set gen_k_eqn_alg_set(const ::NSA4::alg_1_params& sim_params,
				const ::NSA3::n_array_tracker& n_tracker);

void exe_outermost_loop(::NSA3::n_array_tracker& n_tracker,
			k_eqn_alg_set& k_alg_set,
			const ::NSA4::alg_1_params& sim_params);

int_vec gen_n_duplicates_map(const ::NSA4::alg_1_params& sim_params);

void step_evolve(::NSA3::n_array_tracker& n_tracker,
		 k_eqn_alg_set& k_alg_set,
		 const ::NSA4::alg_1_params& sim_params,
		 const int_vec& n_duplicates_map);
void reiterate_until_convergence(::NSA3::n_array_tracker& n_tracker,
				 k_eqn_alg_set& k_alg_set,
				 const ::NSA4::alg_1_params& sim_params,
				 const int_vec& n_duplicates_map);

int calc_n_sites(const ::NSA4::alg_1_params& sim_params);

void print_final_n_estimate(int index,
			    const ::NSA4::alg_1_params& sim_params,
			    const ::NSA3::n_array_tracker& n_tracker);

dbl_vec_2d gen_n_k_array_set(const k_eqn_alg_set& k_alg_set);

void write_n_k_data_to_file(const ::NSA4::alg_1_params& sim_params,
			    const dbl_vec_2d& n_k_arrays);
void write_single_particle_density_matrix_to_file(
         const ::NSA4::alg_1_params& sim_params,
	 const dbl_vec_2d& density_matrix);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Execute simulation algorithm.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA6 = std_bhm::k_map;
namespace NSA7 = std_bhm::density_matrix::single_particle;

void NSA4::alg_1()
{
    const auto sim_params = ::NSA4::alg_1_params();

    auto n_tracker = ::unnamed::gen_n_array_tracker(sim_params);
    auto k_alg_set = ::unnamed::gen_k_eqn_alg_set(sim_params, n_tracker);

    ::unnamed::exe_outermost_loop(n_tracker, k_alg_set, sim_params);

    const auto n_k_arrays = ::unnamed::gen_n_k_array_set(k_alg_set);
    const auto sp_params = sim_params.get_spatial_params();
    const auto density_matrix = ::NSA7::calc_from_n_k_data(sp_params,
							   n_k_arrays);

    ::unnamed::write_n_k_data_to_file(sim_params, n_k_arrays);
    ::unnamed::write_single_particle_density_matrix_to_file(sim_params,
							    density_matrix);
}



// Generate n_array_tracker object from the simulation parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace unnamed
{
namespace
{

::NSA3::n_array_tracker gen_n_array_tracker(
                            const ::NSA4::alg_1_params& sim_params)
{
    const auto s_params = sim_params.get_step_params();
    const auto n_block_steps = s_params.get_n_block_steps();
    
    const auto& l_params = sim_params.get_local_params();
    
    const auto tol = sim_params.get_convergence_tolerance();
    
    return ::NSA3::n_array_tracker(n_block_steps, l_params, tol);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate an array of k_eqn_alg objects from the simulation parameters.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = NSA3::k_eqn;
namespace NSA6 = std_bhm::k_map;

using k_eqn_alg_set = std::vector<::NSA5::alg>;

namespace unnamed
{
namespace
{

k_eqn_alg_set gen_k_eqn_alg_set(const ::NSA4::alg_1_params& sim_params,
				const ::NSA3::n_array_tracker& n_tracker)
{
    const auto& l_params = sim_params.get_local_params();
    const auto& sp_params = sim_params.get_spatial_params();
    const auto& s_params = sim_params.get_step_params();
    const auto& k_vec_set = ::NSA6::gen_minimal_k_vec_set(sp_params);

    const auto& n_array = n_tracker.get_n_array();

    auto k_alg_set = k_eqn_alg_set();
    for(const auto& k_vec : k_vec_set)
    {
	const auto& q_params = sim_params.get_quench_params();
	const auto& e_params = ::NSA3::epsilon_params(q_params, k_vec);
	const auto& k_eqn_params = ::NSA5::params(l_params, e_params, s_params);
	
	k_alg_set.push_back(std::move( ::NSA5::alg(k_eqn_params, n_array) ) );
    }
    
    return k_alg_set;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Execute outer-most loop of simulation.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = NSA3::k_eqn;

using k_eqn_alg_set = std::vector<::NSA5::alg>;

namespace unnamed
{
namespace
{

void exe_outermost_loop(::NSA3::n_array_tracker& n_tracker,
			k_eqn_alg_set& k_alg_set,
			const ::NSA4::alg_1_params& sim_params)
{
    const auto s_params = sim_params.get_step_params();
    const auto n_block_steps = s_params.get_n_block_steps();
    const auto n_duplicates_map = ::unnamed::gen_n_duplicates_map(sim_params);

    auto index = 1;
    
    for(auto m2=decltype(n_block_steps){0}; m2<n_block_steps; m2++)
    {
	for(decltype(2) sub_step_index=0; sub_step_index<2; sub_step_index++)
	{
	    ::unnamed::step_evolve(n_tracker,
				   k_alg_set,
				   sim_params,
				   n_duplicates_map);

	    ::unnamed::reiterate_until_convergence(n_tracker,
						   k_alg_set,
						   sim_params,
						   n_duplicates_map);

	    index++;
	    ::unnamed::print_final_n_estimate(index,
					      sim_params,
					      n_tracker);
	}
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate the duplication map for the our minimal k-vector set.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA6 = std_bhm::k_map;

using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

int_vec gen_n_duplicates_map(const ::NSA4::alg_1_params& sim_params)
{
    const auto& sp_params = sim_params.get_spatial_params();
    const auto& k_vec_set = ::NSA6::gen_minimal_k_vec_set(sp_params);
    auto n_duplicates_map = int_vec();

    for(auto& k_vec : k_vec_set)
    {
	const auto n_duplicates = ::NSA6::calc_n_duplicates(k_vec);
	n_duplicates_map.push_back(n_duplicates);
    }

    return n_duplicates_map;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Step evolve all k-equation algorithms.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = NSA3::k_eqn;

using k_eqn_alg_set = std::vector<::NSA5::alg>;
using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void step_evolve(::NSA3::n_array_tracker& n_tracker,
		 k_eqn_alg_set& k_alg_set,
		 const ::NSA4::alg_1_params& sim_params,
		 const int_vec& n_duplicates_map)
{
    const auto n_sites = ::unnamed::calc_n_sites(sim_params);
    const auto n_k_algs = k_alg_set.size();
    n_tracker.guess_next_step_by_extrapolation();

    auto new_n_estimate = 0.0;

    #pragma omp parallel reduction(+ : new_n_estimate)
    {
	auto mapped_new_n_estimate = 0.0;
    
        #pragma omp for 
	for(auto i=decltype(n_k_algs){0}; i<n_k_algs; i++)
	{
	    auto& k_alg = k_alg_set[i];

	    k_alg.step_evolve();

	    const auto n_duplicates = n_duplicates_map[i];
	    const auto n_k_estimate = k_alg.get_current_step_n_k_estimate();
	    mapped_new_n_estimate += (n_duplicates * n_k_estimate) / n_sites;
	}

	new_n_estimate += mapped_new_n_estimate;
    }

    n_tracker.update_current_step(new_n_estimate);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Reiterate step for all k-equation algorithsm until convergence is reached.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = NSA3::k_eqn;

using k_eqn_alg_set = std::vector<::NSA5::alg>;
using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void reiterate_until_convergence(::NSA3::n_array_tracker& n_tracker,
				 k_eqn_alg_set& k_alg_set,
				 const ::NSA4::alg_1_params& sim_params,
				 const int_vec& n_duplicates_map)
{
    const auto n_sites = ::unnamed::calc_n_sites(sim_params);
    const auto n_k_algs = k_alg_set.size();
    
    auto convergence_reached = false;
    while(!convergence_reached)
    {
	auto new_n_estimate = 0.0;
	
        #pragma omp parallel reduction(+ : new_n_estimate)
	{
	    auto mapped_new_n_estimate = 0.0;

            #pragma omp for 
	    for(auto i=decltype(n_k_algs){0}; i<n_k_algs; i++)
	    {
		auto& k_alg = k_alg_set[i];
		k_alg.reiterate_step();
		const auto n_duplicates = n_duplicates_map[i];
		const auto& n_k_estimate
		    = k_alg.get_current_step_n_k_estimate();
		mapped_new_n_estimate
		    += (n_duplicates * n_k_estimate) / n_sites;
	    }

	    new_n_estimate += mapped_new_n_estimate;
	}
	
	n_tracker.update_current_step(new_n_estimate);
	convergence_reached = n_tracker.get_convergence_status();
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate total # of sites.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace unnamed
{
namespace
{

int calc_n_sites(const ::NSA4::alg_1_params& sim_params)
{
    const auto& sp_params = sim_params.get_spatial_params();
    const auto L = sp_params.get_L();
    const auto d = sp_params.get_d();
    
    return pow(L, d);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Print final n estimates at current block step.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace unnamed
{
namespace
{

void print_final_n_estimate(int index,
			    const ::NSA4::alg_1_params& sim_params,
			    const ::NSA3::n_array_tracker& n_tracker)
{
    const auto& s_params = sim_params.get_step_params();
    const auto ds = s_params.get_ds();
    const auto s = index * ds;

    const auto& n_array = n_tracker.get_n_array();
    const auto num_of_iterations = n_tracker.get_number_of_updates() + 1;

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    std::cout << "n(s=" << s << ") = " << n_array[index]
	      << ",\t# of iterations = " << num_of_iterations << std::endl;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate n_k array set.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA5 = NSA3::k_eqn;

using k_eqn_alg_set = std::vector<::NSA5::alg>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

dbl_vec_2d gen_n_k_array_set(const k_eqn_alg_set& k_alg_set)
{
    const auto set_size = k_alg_set.size();
    auto n_k_arrays = dbl_vec_2d(set_size);

    #pragma omp parallel
    {
	#pragma omp for
	for(auto i=decltype(set_size){0}; i<set_size; i++)
	{
	    const auto& n_k_array = (k_alg_set[i]).get_n_k_array();
	    n_k_arrays[i] = n_k_array;
	}
    }

    return n_k_arrays;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Write quasi-momentum distribution data to a set of files.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA6 = std_bhm::k_map;
namespace NSA8 = std_bhm::output;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void write_n_k_data_to_file(const ::NSA4::alg_1_params& sim_params,
			    const dbl_vec_2d& n_k_arrays)
{
    const auto& sp_params = sim_params.get_spatial_params();
    const auto& k_ints_set = ::NSA6::gen_minimal_k_ints_set(sp_params);
    const auto set_size = k_ints_set.size();

    #pragma omp parallel
    {
	#pragma omp for
	for(auto i=decltype(set_size){0}; i<set_size; i++)
	{
	    const auto& k_ints = k_ints_set[i];
	    const auto& temp_str = "n_k data/k-vector";
	    const auto abs_filename = ::NSA4::gen_abs_filename_for_output_file
		                                  (sim_params,
						   k_ints,
						   temp_str);
	    const auto& s_params = sim_params.get_step_params();
	    const auto ds = s_params.get_ds();
	    const auto& n_k_array = n_k_arrays[i];
	    const auto data_label = "n_k";
	    ::NSA8::write_time_series_to_file(abs_filename,
					      n_k_array,
					      ds,
					      data_label);
	}
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Write single-particle density matrix data to a set of files.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::sim;

namespace NSA6 = std_bhm::k_map;
namespace NSA8 = std_bhm::output;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void write_single_particle_density_matrix_to_file(
         const ::NSA4::alg_1_params& sim_params,
	 const dbl_vec_2d& density_matrix)
{
    const auto& sp_params = sim_params.get_spatial_params();

    // Note that delta_r_ints_set = k_ints_set
    const auto& delta_r_ints_set = ::NSA6::gen_minimal_k_ints_set(sp_params);
    const auto set_size = delta_r_ints_set.size();

    #pragma omp parallel
    {
	#pragma omp for
	for(auto i=decltype(set_size){0}; i<set_size; i++)
	{
	    const auto& delta_r_ints = delta_r_ints_set[i];
	    const auto& temp_str
		= "single-particle density matrix data/r-vector";
	    const auto abs_filename = ::NSA4::gen_abs_filename_for_output_file
		                                  (sim_params,
						   delta_r_ints,
						   temp_str);
	    const auto& s_params = sim_params.get_step_params();
	    const auto ds = s_params.get_ds();
	    const auto& density_matrix_element = density_matrix[i];
	    const auto data_label = "rho_1";
	    ::NSA8::write_time_series_to_file(abs_filename,
					      density_matrix_element,
					      ds,
					      data_label);
	}
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
