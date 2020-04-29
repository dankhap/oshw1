from subprocess import Popen, check_output, PIPE
import os
import signal
from os import path
from time import sleep
import select
import sys
import re


builtins = [
"pwd",
"cd",
"history",
"showpid",
"cp",
"diff",
"jobs",
"kill",
"fg",
"bg",
"quit"]
prompt = 'smash > '


def load_test_list():
    mypath = '.'
    res = []
    inputs = [path.basename(f) for f in os.listdir(mypath) if path.isfile(path.join(mypath, f)) and f.endswith('.in')]
    for input in inputs:
        output = '.'.join((input.split('.')[:-1]+['out']))
        res.append((input,output))
    return res

def timed_line_read(stream, tries):
    had_error = False
    time_limit = tries
    line = ""
    poll_obj = select.poll()
    poll_obj.register(stream, select.POLLIN)   
    while not had_error and time_limit > 0:
        poll_result = poll_obj.poll(0)
        if poll_result:
            line = stream.readline()
            had_error = True
        sleep(0.1)
        time_limit -= 1
    return line


def read_built_in(ps, is_blocked):
    output_lines = []
    err_line = timed_line_read(ps.stderr, 2)
    if not err_line:
        output_lines.append(timed_line_read(ps.stdout, 1))
        if is_blocked:
            return [x for x in output_lines if x]   
        next = ps.stdout.read(len(prompt))
        while next != prompt:
            next += ps.stdout.readline()
            output_lines.append(next)
            next = ps.stdout.read(len(prompt))
    else:
        output_lines.append(err_line)
    output_lines = [x for x in output_lines if x]  
    if is_blocked:
        sleep(0.1)  
    return output_lines


def compare_outputs(expected, output):
    if len(expected) != len(output):
        return False

    lines = zip(expected, output)
    num_placeholder = ' # '
    for i, (expect, present) in enumerate(lines):
        if num_placeholder in expect:
            present = re.sub(" -*\d+", " #", present)
        if expect != present:
            print(f"missmatch at output line {i}")
            return False
    
    return True


def run_test(input, output_file):
    with open(input, 'r') as input_file:
        test_commands = input_file.readlines()
    ps = Popen(('../smash'),  stderr=PIPE, stdout=PIPE, stdin=PIPE, text=True)
    ps.stdout.read(len(prompt))
    output_lines = []
    for command in test_commands:
        if command.startswith('@wait'):
            sleep(int(command[5:]))
            command = ''
        elif command.startswith('@z'):
            ps.send_signal(signal.SIGTSTP)
            command = ''
        elif command.startswith('@c'):
            ps.send_signal(signal.SIGINT)
            command = ''
        
        print('in cmd:' + command)
        
        if not command or command == 'quit\n':
            ps.stdin.write(command)
            continue

        ps.stdin.write(command)
        ps.stdin.flush()
        cmd = command.split()[0]
        blocking =  cmd not in builtins or cmd == 'fg'
        cmd_out = read_built_in(ps, blocking)
        output_lines += cmd_out

    output_lines = [x.replace(prompt, '') for x in output_lines]

    with open(output_file+'.o', 'w+') as f:
        f.writelines(output_lines)

    with open(output_file, 'r') as out:
        out = out.readlines()
    return compare_outputs(out, output_lines)

if __name__ == "__main__":
    # sys.argv.append('test_fg.in')
    if len(sys.argv) > 1:
        test_name = sys.argv[1].split('.')[0]
        tests = [(test_name + ".in", test_name + ".out")]
    else:
        tests = load_test_list()
    for test in tests:
        print(f'Running test: {test}...')
        res = run_test(*test)
        label = "PASSED!" if res else "FAILED!"
        print(f"test {label}")

