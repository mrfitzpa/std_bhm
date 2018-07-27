#!/bin/bash

#---------------------------------------------------------------------------
#
# This script executes the program 'test/hopping/epsilon'
#
#---------------------------------------------------------------------------

# Set fixed parameters
J="0.03"
kx="0.123"
ky="-0.321"

# Get absolute path of executable/program. This is done by first getting
# the absolute path of this script and then modifying it accordingly.
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exe_dir=${script_dir/\/scripts\//\/bin\/}
exe_path=$exe_dir\/epsilon

time "$exe_path" <<EOF
${J}
${kx}
${ky}
EOF
