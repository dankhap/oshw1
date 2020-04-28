from subprocess import Popen, check_output, PIPE
import os
from os import path
from time import sleep
import select

def load_test_list():
    mypath = '.'
    res = []
    inputs = [path.basename(f) for f in os.listdir(mypath) if path.isfile(path.join(mypath, f)) and f.endswith('.in')]
    for input in inputs:
        output = '.'.join((input.split('.')[:-1]+['out']))
        res.append((input,output))
    return res

def run_test(input, output_file):
    with open(input, 'r') as input_file:
        test_commands = input_file.readlines()
    ps = Popen(('../smash'),  stderr=PIPE, stdout=PIPE, stdin=PIPE, text=True)
    output_lines = []

    for command in test_commands:
        had_error = False
        time_limit = 3
        if command.startswith('@wait'):
            sleep(int(command[5:]))
            command = ''
        elif command.startswith('@sig'):
            ps.send_signal(int(command[4:]))
            command = ''
        ps.stdin.write(command)
        ps.stdin.flush()

        poll_obj = select.poll()
        poll_obj.register(ps.stderr, select.POLLIN)   
        while not had_error and time_limit > 0:
            poll_result = poll_obj.poll(0)
            if poll_result:
                line = ps.stderr.readline()
                output_lines.append(line)
                had_error = True
            sleep(0.2)
            time_limit -= 1

        if not had_error:
            output_lines.append(ps.stdout.readline())
        
    with open(output_file+'.o', 'w+') as f:
        f.writelines(output_lines)

    with open(output_file, 'r') as out:
        out = out.readlines()
    return out == output_lines

if __name__ == "__main__":
    tests = load_test_list()
    for test in tests:
        print(f'Running test: {test}...')
        res = run_test(*test)
        label = "PASSED!" if res else "FAILED!"
        print(f"test {label}")

