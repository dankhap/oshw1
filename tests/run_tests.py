from subprocess import Popen, check_output, PIPE
import os
from os import path
from time import sleep


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
    ps = Popen(('../smash'), stdout=PIPE, stdin=PIPE, text=True)
    output_lines = []
    for command in test_commands:
        if command.startswith('@wait'):
            sleep(int(command[5:]))
            command = ''
        elif command.startswith('@sig'):
            ps.send_signal(int(command[4:]))
            command = ''
        output_lines.append(ps.communicate(command)[0])
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

