#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /n_array_tracker'
#
#---------------------------------------------------------------------------

# Set fixed parameters
beta="10000.0"
mu="0.42"
max_band_index="100"
Ns="4001"
tol="1.0e-8"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/n_array_tracker

time "$exe_path" <<EOF
${beta}
${mu}
${max_band_index}
${Ns}
${tol}
EOF
