#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'n_k/calc_fourier_cos_sum'
#
#---------------------------------------------------------------------------

# Set fixed parameters
L="6"
d="3"

rx="1"
ry="0"
rz="-2"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/calc_fourier_cos_sum

time "$exe_path" <<EOF
${L}
${d}
${rx}
${ry}
${rz}
EOF
