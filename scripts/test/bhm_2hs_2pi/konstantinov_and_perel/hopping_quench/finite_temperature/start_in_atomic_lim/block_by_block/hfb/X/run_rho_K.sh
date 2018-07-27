#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /X/rho_K'
#
#---------------------------------------------------------------------------

# Set fixed parameters
beta="10.0"
mu="0.42"
max_band_index="100"

ds="0.05"
Ns="4001"

l1="49"
l2="101"
l3="45"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/rho_K

time "$exe_path" <<EOF
${beta}
${mu}
${max_band_index}
${ds}
${Ns}
${l1}
${l2}
${l3}
EOF
