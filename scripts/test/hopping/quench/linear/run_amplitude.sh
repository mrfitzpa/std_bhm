#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/hopping/quench/linear/amplitude'
#
#---------------------------------------------------------------------------

# Set fixed parameters
ji="0.00"
jf="0.035"
tc="25.0"
tau_Q="5.0"
s="0"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/amplitude

time "$exe_path" <<EOF
${ji}
${jf}
${tc}
${tau_Q}
${s}
EOF
