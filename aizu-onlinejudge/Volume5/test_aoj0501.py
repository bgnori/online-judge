
from StringIO import StringIO
from aoj0501 import run

input = StringIO("""\
3
A a
0 5
5 4
10
A  
B  
C  
0  
1  
4  
5  
a  
b  
A
3  
A a
0 5
5 4
10 
A  
B  
C  
0  
1  
4  
5  
a  
b
A
0
""")

output = StringIO()
expected = """\
aBC5144aba
aBC5144aba
"""

run(input, output)

assert output.getvalue() == expected

