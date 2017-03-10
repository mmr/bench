Simple Benchmark
===

What is the easiest way to calculate the order of magnitude
of a number?

And what is the fastest?

ie.:
```
1 = 1
10 = 2
100 = 3
```
and so forth


The easiest is to use `log10`... what about the fastest?

This project runs a simple benchmark with the two implementations
just for kicks

How to run it:
```
1) generate test mass:
  ./gen.py 100000000 > num.txt

2) compile it:
  make

3) run it:
  ./bench-o1
  ./bench-o2
  ./bench-o3
```

Results for 100 million numbers:
```
./bench-o1
t1 = 1489119506.393334 / 1489119506.426231 = 0.032897
t2 = 1489119506.426254 / 1489119515.598740 = 9.172486

./bench-o2
t1 = 1489119536.650835 / 1489119536.650835 = 0.000000
t2 = 1489119536.650854 / 1489119536.726511 = 0.075657

./bench-o3
t1 = 1489119557.969913 / 1489119557.969913 = 0.000000
t2 = 1489119557.969936 / 1489119558.045725 = 0.075789
```


Test env:
```
- MacBook Pro 2015, i5 2.7GHz, 8GB RAM
- ubuntu 16.04
- gcc 5.4.0
```
