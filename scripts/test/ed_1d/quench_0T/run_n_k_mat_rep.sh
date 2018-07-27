#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/ed_1d/quench_0T/
# n_k_mat_rep'
#
#---------------------------------------------------------------------------

# Set fixed parameters
total_number_of_particles="4"
number_of_lattice_sites="4"

k="3"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/n_k_mat_rep

time "$exe_path" <<EOF
${total_number_of_particles}
${number_of_lattice_sites}
${k}
EOF
