#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'k_map/gen_minimal_k_vec_set'
#
#---------------------------------------------------------------------------

# Set fixed parameters
L="30"
d="2"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/gen_minimal_k_vec_set

time "$exe_path" <<EOF
${L}
${d}
EOF
