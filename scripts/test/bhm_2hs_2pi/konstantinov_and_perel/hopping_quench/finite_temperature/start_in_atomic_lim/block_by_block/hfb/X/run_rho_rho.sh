#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /X/rho_rho'
#
#---------------------------------------------------------------------------

# Set fixed parameters
beta="10.0"
mu="0.42"
max_band_index="100"

jf="0.03"
tc="5.0"
tau_Q="0.1"

L="50"
k_ints="5 2 1"

n_block_steps="2000"
ds="0.05"

step_offset="0.5"

l1="49"
l2="101"
l3="45"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/rho_rho

time "$exe_path" <<EOF
${beta}
${mu}
${max_band_index}
${jf}
${tc}
${tau_Q}
${L}
${k_ints}
${n_block_steps}
${ds}
${step_offset}
${l1}
${l2}
${l3}
EOF
