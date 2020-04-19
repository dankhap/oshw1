import subprocess
import os
from os import path

def load_test_list():
    mypath = '.'
    res = []
    inputs = [path.basename(f) for f in os.listdir(mypath) if path.isfile(path.join(mypath, f)) and f.endswith('.in')]
    for input in inputs:
        output = '.'.join((input.split('.')[:-1]+['out']))
        res.append((input,output))
    return res

def run_test(input, output_file):
    ps = subprocess.Popen(('cat', input), stdout=subprocess.PIPE)
    output = subprocess.check_output(('../smash'), stdin=ps.stdout)
    output = output.decode("utf-8")
    with open(output_file+'.o', 'w+') as f:
        f.write(output)

    with open(output_file, 'r') as out:
        out = out.read()
    return out == output

if __name__ == "__main__":
    tests = load_test_list()
    for test in tests:
        print(f'Running test: {test}...')
        res = run_test(*test)
        label = "PASSED!" if res else "FAILED!"
        print(f"test {label}")

