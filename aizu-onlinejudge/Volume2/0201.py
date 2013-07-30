#!/usr/bin/python
#

import sys

class Alchemey(object):
    def __init__(self):
        self.prices = {}
        self.recipes = {}

    def add_to_price_list(self, line):
        name, price = line.split()
        self.prices[name] = int(price)

    def add_to_recipe_list(self, line):
        xs = line.split()
        dst = xs[0]
        n = int(xs[1])
        srcs = xs[2:]
        self.recipes[dst] = srcs

    def plan(self, name):
        if name not in self.recipes:
            return self.prices[name]
        return sum([self.plan(n) for n in self.recipes[name]])

al = Alchemey()


'PRICE'
'RECIPE'
'REQUEST'

state = None
offset = 0
price_to_read = 0
recipe_to_read = 0
for i, line in enumerate(sys.stdin):
    i = i - offset
    if state is None:
        price_to_read = int(line)
        state = 'PRICE'
        continue
    elif state == 'PRICE' and price_to_read == 0:
        recipe_to_read = int(line)
        state = 'RECIPE'
        continue
    elif state == 'RECIPE' and recipe_to_read == 0:
        state = 'REQUEST'
        pass
    if price_to_read > 0:
        assert state == 'PRICE'
        al.add_to_price_list(line)
        price_to_read -= 1
    elif recipe_to_read > 0:
        assert state == 'RECIPE'
        al.add_to_recipe_list(line)
        recipe_to_read -= 1
    else:
        assert state == 'REQUEST'
        assert recipe_to_read == 0 and price_to_read == 0
        request = line.split()[0]
        offset +=i
        print al.plan(request)
        state = None
