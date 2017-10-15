# problem at https://projecteuler.net/problem=44
# slove by me, on 31 January,2017
import math

def is_pentagonal(number):
	n = (math.sqrt(24*number + 1) + 1) / 6
	return n == int(n)

def check():
	i = 2
	while(1):
		P = int((i * (3*i - 1)) / 2)
		j = i - 1
		while(j >= 1):
			Q = int((j * (3*j - 1)) / 2)
			if is_pentagonal(P-Q) == True & is_pentagonal(P+Q) == True:
				print(P)
				print(Q)
				print(P-Q)
				return
			else:
				j = j - 1
		i = i + 1

check()
