#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'bhm_2hs_2pi/konstantinov_and_perel
# /hopping_quench/finite_temperature/start_in_atomic_lim/block_by_block/hfb
# /main_alg_params'
#
#---------------------------------------------------------------------------

# Set fixed parameters
beta="100"
mu="0.42"
max_band_index="100"
L="6"
d="1"
ji="0.00"
jf="0.03"
tc="100"
tau_Q="5"
n_block_steps="200"
ds="0.05"
tol="1.0e-8"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/main_alg_params

time "$exe_path" <<EOF
${beta}
${mu}
${max_band_index}
${L}
${d}
${ji}
${jf}
${tc}
${tau_Q}
${n_block_steps}
${ds}
${tol}
EOF
