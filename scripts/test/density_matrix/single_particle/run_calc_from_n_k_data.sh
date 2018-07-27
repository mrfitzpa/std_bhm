#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'density_matrix/single_particle
# /calc_from_n_k_data'
#
#---------------------------------------------------------------------------

# Set fixed parameters
index="0"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/calc_from_n_k_data

time "$exe_path" <<EOF
${index}
EOF
