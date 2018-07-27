#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'n_k/load_n_k_data_arrays'
#
#---------------------------------------------------------------------------

# Set fixed parameters

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/load_n_k_data_arrays

time "$exe_path" <<EOF
EOF
