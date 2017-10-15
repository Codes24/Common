"""
--	n^2 + an + b la so nguyen to
--	khi n = 0
--		=>	b la so nguyen to  trong doan [2,999] (1)
--	khi n = 1
--		=>	a + b + 1 la so nguyen to va a + b + 1 > 2 <=>	a + b > 1 (2)
--		va de a + b + 1 la so nguyen to thi a + 1 phai la so le, => a la so chan (3)
--	voi 3 dieu kien tren, ta co the thu hep cac cap so (a,b)
"""
import math

def isPrime(number):
	i = 2
	if number <= 1:
	 	return 0
	while i <= math.sqrt(number):
		if number%i == 0:
			return 0
		i += 1
	return 1

def count_n(a, b):
	count = 0
	n = 0
	while isPrime(n**2 + a*n + b) == 1:
		count += 1
		n += 1
	return count

def find_b():
	b = []
	i = 999
	while i >= 2:
		if isPrime(i) == 1:
			b.append(i)
		i -= 1
	return b

def find_a(b):
	index_a = -999
	a = []
	while index_a < 1000:
		if (index_a + b) > 1:
			a.append(index_a)
		index_a += 1
	return a

def carry_out():
	b = find_b()
	afinal = 0
	bfinal = 0
	n_max = 0
	for each_prime in b:
		a = find_a(each_prime)
		for each_num in a:
			count = count_n(each_num, each_prime)
			if count > n_max:
				n_max = count
				afinal = each_num
				bfinal = each_prime
	print(afinal * bfinal)

carry_out()
