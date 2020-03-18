#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /g/rho'
#
#---------------------------------------------------------------------------

# Set fixed parameters
beta="1000.0"
mu="0.40"
max_band_index="100"

jf="0.035"
tc="5.0"
tau_Q="0.1"

L="30"
k_ints="5 2"

n_block_steps="2000"
ds="0.05"

l1="34"
l2="43"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/rho

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
${l1}
${l2}
EOF
