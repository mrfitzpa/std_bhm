#!/usr/bin/python

# -----------------------------------------------------------------------

# This script is to be called by a makefile to automatically generate
# .d dependency files and .l link dependency files.
#
# This script is a modified version of that made by Alexander Kl"aser:
# "https://lear.inrialpes.fr/people/klaeser/downloads/genericMakefile
# /dep.py".

# -----------------------------------------------------------------------

# Import some standard modules
import sys
import os
import string
import os.path
import re

# Usage message
HELP_USAGE = """
Usage: dep_tool.py <link-target> <link-file> <d-dep-dir> <build-dir> 
<src-dir> <include-dir> <root-dep-file> ...
"""



# Creating some regular expression objects
reg_suffix = re.compile(r"\.[^.]*$")
reg_src = re.compile(r"^.*\.(c|cc|cpp)$")
reg_dep = re.compile(r"^.*\.d$")
reg_dep_split = re.compile(r"\s*\\*\s*")

# Define possible source file suffixes
suffixes = ['.cpp', '.c', '.cc']



def parse_dep_file(filename):
    # Read in the dependency file
    dep_file = open(filename, 'r')
    dep_file_text = dep_file.read()

    # Discard everything up to the colon
    colon_pos = dep_file_text.find(":")
    dep_file_text = dep_file_text[colon_pos + 1:]

    # Collect all included files
    return reg_dep_split.split(dep_file_text)




def find_source_file(filename, include_dir, src_dir):
    # Substitute header directory with source directory
    mod_filename = re.sub(r"^(" + include_dir + r")", src_dir, filename)
    if filename == mod_filename: # If not a header file
        return None
    
    # Get the basename without extension
    basename = reg_suffix.sub('', mod_filename)
    if not basename:
        return None

    # Iterate over known suffixes
    for suffix in suffixes:
        src_file = basename + suffix

        # Check whether a source file corresponding to the header exists
        if os.path.exists(src_file):
            return src_file

    # No corresponding source file exists
    return None



def main(argv):
    # Check command line parameters
    if len(sys.argv) < 7:
        print(HELP_USAGE)
        return
    
    args = sys.argv
    args.pop(0)
    rule_target = args.pop(0)
    link_file = args.pop(0)
    d_dep_dir = args.pop(0)
    build_dir = args.pop(0)
    src_dir = args.pop(0)
    include_dir = args.pop(0)
    root_dep_file = args.pop(0)

    # Scan all dependency files for files we need to link to,
    # we do this recursively starting at the root dependency file
    link_files = set()
    inc_files = set()
    dep_files_stack = set([root_dep_file])
    dep_files_done = set()

    while dep_files_stack:
        # Get the next dependency file to process from the stack
        dep_file = dep_files_stack.pop()
        if dep_file in dep_files_done:
            continue
        dep_files_done.add(dep_file)

        # Iterate over all source files in the dependency file
        for next_file in parse_dep_file(dep_file):
            new_dep_file = ""

            # If we have a source file, we need to link against it
            if reg_src.match(next_file):
                link_files.add(next_file)
                if next_file[:3] == "src":
                    new_dep_file = (d_dep_dir + "/"
                                    + reg_suffix.sub(".d", next_file[4:]))
                else:
                    new_dep_file = (d_dep_dir + "/"
                                    + reg_suffix.sub(".d", next_file))

            # If we have a header file, check whether there is a corresponding
            # source file
            src_file = find_source_file(next_file, include_dir, src_dir)
            if src_file != None:
                link_files.add(src_file)
                if src_file[:3] == "src":
                    new_dep_file = (d_dep_dir + "/"
                                    + reg_suffix.sub(".d", src_file[4:]))
                else:
                    new_dep_file = (d_dep_dir + "/"
                                    + reg_suffix.sub(".d", src_file))

            # If a corresponding .d file was found, add it to the stack
            if new_dep_file and os.path.exists(new_dep_file):
                dep_files_stack.add(new_dep_file)

    #
    # Generate all necessary rules
    #

    # All includes of dependency files
    for i in link_files:
        i = reg_suffix.sub(".d", i)
        if i[:3] == "src":
            print("-include " + d_dep_dir + "/" + i[4:])
        else:
            print("-include " + d_dep_dir + "/" + i)
    print

    # Dependencies for link file
    print(link_file + ": \\")
    for i in link_files:
        i = reg_suffix.sub(".d", i)
        if i[:3] == "src":
            print("\t" + d_dep_dir + "/" + i[4:] + " \\")
        else:
            print("\t" + d_dep_dir + "/" + i + " \\")
    print

    # Print out all files we need to link against
    print(rule_target + ": " + link_file + " \\")
    for i in link_files:
        i = reg_suffix.sub(".o", i)
        if i[:3] == "src":
            print("\t" + build_dir + "/" + i[4:] + " \\")
        else:
            print("\t" + build_dir + "/" + i + " \\")
    print



if __name__ == "__main__":
    main(sys.argv)
