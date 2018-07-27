#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/ed_1d/quench_0T/ground_state'
#
#---------------------------------------------------------------------------

# Set fixed parameters
total_number_of_particles="4"
number_of_lattice_sites="4"

J="0.5"

U="0.3"
mu="0.42"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/ground_state

time "$exe_path" <<EOF
${total_number_of_particles}
${number_of_lattice_sites}
${J}
${U}
${mu}
EOF
