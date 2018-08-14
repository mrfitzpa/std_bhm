#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /X/type_1'
#
#---------------------------------------------------------------------------

# Set fixed parameters
Ns="4001"
ds="0.05"
step_offset="0.0"

l1="101"
l2="49"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/type_1

time "$exe_path" <<EOF
${Ns}
${ds}
${step_offset}
${l1}
${l2}
EOF
