#!/usr/bin/python

import sys

if True:
    from sys import stdin as inputs
else:
    from test_aoj0502 import inputs

class Die:
    def __init__(self, **argv):
        if argv:
            self.faces = dict(argv)
        else:
            self.faces = dict(top=1,
             north=5,
             east=3,
             south=2,
             west=4,
             bottom=6)

    def North(self):
        return Die(
                top=self.faces["south"],
                north=self.faces["top"],
                east=self.faces["east"],
                west=self.faces["west"],
                south=self.faces["bottom"],
                bottom=self.faces["north"])
    def East(self):
        return Die(
                top=self.faces["west"],
                north=self.faces["north"],
                east=self.faces["top"],
                west=self.faces["bottom"],
                south=self.faces["south"],
                bottom=self.faces["east"])
    def South(self):
        return Die(
                top=self.faces["north"],
                north=self.faces["bottom"],
                east=self.faces["east"],
                west=self.faces["west"],
                south=self.faces["top"],
                bottom=self.faces["south"])
    def West(self):
        return Die(
                top=self.faces["east"],
                north=self.faces["north"],
                east=self.faces["bottom"],
                west=self.faces["top"],
                south=self.faces["south"],
                bottom=self.faces["west"])
    def Right(self):
        return Die(
                top=self.faces["top"],
                north=self.faces["west"],
                east=self.faces["north"],
                west=self.faces["south"],
                south=self.faces["east"],
                bottom=self.faces["bottom"])
    def Left(self):
        return Die(
                top=self.faces["top"],
                north=self.faces["east"],
                east=self.faces["south"],
                west=self.faces["north"],
                south=self.faces["west"],
                bottom=self.faces["bottom"])



for line in inputs:
    line = line.strip()
    try:
        n = int(line)
    except:
        n = None
    if n is None:
        count -= 1
        f = getattr(die, line)
        die = f()
        s += die.faces["top"]
        if count == 0:
            print s
    elif n == 0:
        sys.exit()
    else:
        die = Die()
        count = n
        s = 0
        s += die.faces["top"]

