import re
import sys

#define reg ex
pattern = "\\$\\^*(0|([1-9]\\d{0,2})(,\\d{3})*)((\\.\\d{2})|$)\\Z"

#print usage and exit if no filename given
if(len(sys.argv) < 2):
    print("Usage: python Assn2.py [filename]")
    exit(0)

#open file
file = open(str(sys.argv[1]), 'r')

#read each line and determine if match
curLine = file.readline();
while curLine != "":
    #discard newline char if present
    if curLine[-1] == "\n":
        curLine = curLine[0:-2]
    if re.match(pattern, curLine):
        print curLine + " is a financial quantity"
    else:
        print curLine + " is not a financial quantity"
    curLine = file.readline()
