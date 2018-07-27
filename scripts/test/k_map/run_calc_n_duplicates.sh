#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'k_map/calc_n_duplicates'
#
#---------------------------------------------------------------------------

# Set fixed parameters
L="100"
d="1"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/calc_n_duplicates

time "$exe_path" <<EOF
${L}
${d}
EOF
