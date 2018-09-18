#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/ed_1d/quench_0T/tuned_hopping/
# main_alg'
#
#---------------------------------------------------------------------------

# Set number of threads to run in parallel
export OMP_NUM_THREADS=1

# Set fixed parameters
mu="0.4116"

total_number_of_particles="8"
number_of_lattice_sites="8"

ji="0.000"
jf="0.035"
tc="5.0"
tau_Q="0.1"

Nt="1202"
dt="0.05"

d_K="2500"
convergence_tolerance="1.0e-14"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/main_alg

time "$exe_path" <<EOF
${mu}
${total_number_of_particles}
${number_of_lattice_sites}
${ji}
${jf}
${tc}
${tau_Q}
${Nt}
${dt}
${d_K}
${convergence_tolerance}
EOF













