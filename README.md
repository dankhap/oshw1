# oshw1
os hw 1

# Tests usage:
test script is in tests/run_tests.py
if run_tests.py is run without arguments, all files with extension '.in' are paired with a file with the same name with extension '.out'. 
For each '.in' file, an instance of smash executable (from /smash) is started and input from '.in' is entered.
output from each command is read sequentialy and written into same name file with extension '.out.o' and compared to '.out' file.
run_tests.py can be run with one arguemnt, which is the filename of an '.in' test file. 
In this way you run only this specific test. 
Otherwise all '.in' files in the same directory are run squentialy.

## Sepcial input
ctrl+c and ctrl+z can be simulated in the '.in' file using @z and @c in a new line.
Waiting is done by @wait<number> where <number> is in seconds.

When expecting some unknown number in the output, you can enter # in the '.out' file (example in test_fg.out)

# Knwon bugs
when starting an application in the background (using &) the tester looses output stream so this cannot be tested, but you can always run normally and then @z in a new line, and then bg.
