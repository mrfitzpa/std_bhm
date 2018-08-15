#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /X/type_5'
#
#---------------------------------------------------------------------------

# Set fixed parameters
n_block_steps="2000"
ds="0.05"

l1="101"
l2="73"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/type_5

time "$exe_path" <<EOF
${n_block_steps}
${ds}
${l1}
${l2}
EOF
