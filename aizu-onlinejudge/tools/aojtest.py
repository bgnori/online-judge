


import sys
import subprocess
from StringIO import StringIO


problem_id = "0035"



input = open(problem_id+".input", "rb")
output = open(problem_id+".log", "wb")


p = subprocess.Popen("./"+problem_id, stdin=input, stdout=output)#subprocess.PIPE)
input.close()
output.close()

output = open(problem_id+".log", "r")

output.seek(0)
for line in output:
  print line


