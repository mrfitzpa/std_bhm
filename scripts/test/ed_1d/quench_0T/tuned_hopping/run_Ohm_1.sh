#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/ed_1d/quench_0T/tuned_hopping/Ohm_1'
#
#---------------------------------------------------------------------------

# Set fixed parameters
mu="0.42"

total_number_of_particles="3"
number_of_lattice_sites="3"

ji="0.000"
jf="0.035"
tc="100.0"
tau_Q="5.0"

Nt="401"
dt="0.05"

d_K="3"
zero_tolerance="1.0e-14"

t="99.7"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/Ohm_1

time "$exe_path" <<EOF
${mu}
${total_number_of_particles}
${number_of_lattice_sites}
${ji}
${jf}
${tc}
${tau_Q}
${Nt}
${dt}
${d_K}
${zero_tolerance}
${t}
EOF
