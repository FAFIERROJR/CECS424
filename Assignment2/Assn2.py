import re
import sys

pattern = "\\$\\^*(0|([123456789]|[123456789]\\d|[123456789]\\d\\d)(,\\d\\d\\d)*)((\\.\\d\\d)|$)"

if(len(sys.argv) < 2):
    print("Usage: python Assn2.py [filename]")
    exit(0)

print(str(sys.argv[1]))
file = open(str(sys.argv[1]), 'r')

curLine = file.readline();
while curLine != "":
    if curLine[-1] == "\n":
        curLine = curLine[0:-2]
    if re.match(pattern, curLine):
        print curLine + " is a financial quantity"
    else:
        print curLine + " is not a financial quantity"
    curLine = file.readline()
