

from aoj0500 import run

from StringIO import StringIO

input = StringIO("""3
9 1
5 4
0 8
3
9 1
5 4
1 0
3
9 1
5 5
1 8
0""")

output = StringIO()

expected = ("""19 8
20 0
15 14
""")

run(input, output)
v = output.getvalue()
assert v == expected

