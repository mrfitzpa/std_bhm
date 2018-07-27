#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/atomic_lim/equilibrium/finite_
# temperature/local/kinetic_propagator'
#
#---------------------------------------------------------------------------

# Set fixed parameters
beta="1000.0"
mu="0.42"
max_band_index="100"
s="0.0"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/kinetic_propagator

time "$exe_path" <<EOF
${beta}
${mu}
${max_band_index}
${s}
EOF
