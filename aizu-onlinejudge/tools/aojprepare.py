#!/usr/bin/python
# -*- coding=utf8 -*-

import sys
import codecs

from urlparse import urlunparse
from urllib import urlencode, urlopen
from lxml import etree

sys.stdout = codecs.getwriter('utf_8')(sys.stdout)




def get(problem_id):
  q = urlencode({"id":problem_id})
  parts = ("http", "judge.u-aizu.ac.jp", "onlinejudge/description.jsp", "", q, "")
  url = urlunparse(parts)

  print 'getting:', url

  h = urlopen(url)
  g = codecs.getreader('shift_jis')(h)
  return g.read()

def parse_and_save(problem_id, got):
  t = etree.HTML(got)
  find_h2= etree.XPath('''//div[@class="description"]/h2''')
  for h2 in find_h2(t):
    if h2.text == "Sample Input":
      "<H2>Sample Input</H2>"
      candi = h2.getnext()
      if candi.tag == 'pre':
        with open(problem_id+".input", 'w') as f:
          f.write(candi.text.lstrip())
          print 'wrote %s.input'%(problem_id,)

    if h2.text == "Output for the Sample Input":
      "<H2>Output for the Sample Input</H2>"
      candi = h2.getnext()
      if candi.tag == 'pre':
        with open(problem_id+".output", 'w') as f:
          f.write(candi.text.lstrip())
          print 'wrote %s.output'%(problem_id,)


if __name__ == "__main__":
  if not len(sys.argv) == 2:
    print "please specify problem id"
    sys.exit(0)
  x = int(sys.argv[1])
  problem_id = "%04d"%(x,)
  print 'working on "%s"'%(problem_id,)
  got = get(problem_id)
  print "received", len(got), "bytes"
  parse_and_save(problem_id, got)
