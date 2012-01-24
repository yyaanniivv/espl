#! /src/bin/python
from dirwatch import Dirwatch
import sys, subprocess


if __name__ == '__main__':
    def f (changed_files, removed_files):
        print len(changed_files)
        print 'Removed', len(removed_files)
        for cfile in changed_files:
	  subprocess.call(sys.argv[1]+" "+ cfile, shell=True)

    dirs = sys.argv[2:]
    if not dirs:
        dirs = ["."]

    
    Dirwatch(dirs, f, 1).watch()