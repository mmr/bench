#!env python
import sys
import random

for _ in xrange(int(sys.argv[1])):
    print(random.randint(0, 100000000000000000))
