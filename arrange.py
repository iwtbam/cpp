import os
import glob
import pprint

all_files = glob.glob('oj/lt*.cpp')

for file in all_files:
    problem_id = file.split('\\')[-1].split('.')[0][2:]
    if len(problem_id) == 3:
        nname = 'oj/lt{0:04d}.cpp'.format(int(problem_id))
        os.rename(file,nname)
