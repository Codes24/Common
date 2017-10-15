# problem at https://projecteuler.net/problem=45
# slove by me, on 31 January,2017
import math

def is_triangle(number):
	n = (math.sqrt(8*number + 1) - 1) / 2
	return n == int(n)

def is_pentagonal(number):
	n = (math.sqrt(24*number + 1) + 1) / 6
	return n == int(n)

def is_hexagonal(number):
	n = (math.sqrt(8*number + 1) + 1) / 4
	return n == int(n)

def check():
	i = 286
	while(1):
		n = int((i*(i+1)) / 2)
		if is_pentagonal(n) == True & is_hexagonal(n) == True:
			print(n)
			return
		else:
			i = i+1

check()