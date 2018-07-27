#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/ed_1d/quench_0T/
# unit_strength_interaction_mat_rep'
#
#---------------------------------------------------------------------------

# Set fixed parameters
total_number_of_particles="3"
number_of_lattice_sites="3"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/unit_strength_interaction_mat_rep

time "$exe_path" <<EOF
${total_number_of_particles}
${number_of_lattice_sites}
EOF
