#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /sim/alg_1'
#
#---------------------------------------------------------------------------

# Set number of threads to run in parallel
export OMP_NUM_THREADS=4

# Set fixed parameters
beta="1000"
mu="0.4136"
max_band_index="100"

L="6"
d="1"

jf="0.05"
tc="5"
tau_Q="0.1"

n_block_steps="2200"
ds="0.05"
window_index="2200"

tol="1.0e-12"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/main_alg

time "$exe_path" <<EOF
${beta}
${mu}
${max_band_index}
${L}
${d}
${jf}
${tc}
${tau_Q}
${n_block_steps}
${ds}
${window_index}
${tol}
EOF
