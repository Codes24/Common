# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
# For example, 2143 is a 4-digit pandigital and is also prime.

# What is the largest n-digit pandigital prime that exists?

#	my algorithm
# abc % 3 == 0 	<==>	(a+b+c) % 3 == 0
# 1+2+3+4+5+6+7+8+9 = 45
# 1+2+3+4+5+6+7+8	= 36
# 1+2+3+4+5+6+7		= 28
# 1+2+3+4+5+6		= 21
# 1+2+3+4+5			= 15
# 1+2+3+4			= 10
# 1+2+3				= 6
# 1+2				= 3
#	==>	result is a with |	abcdefg in (1,2,3,4,5,6,7) and abcd in (1,2,3,4)
import math
def is_Prime(n):
	if n == 0 | n == 1:
		return 0
	i = 2
	while i <= math.sqrt(n):
		if n % i == 0:
			return 0
		i += 1
	return 1

def is_pandigital(number):
	check = [1,2,3,4,5,6,7]
	digits = []
	while number//10 != 0:
		digits.append(number%10)
		number = number//10
	digits.append(number)
	for digit in check:
		if digit not in digits:
			return 0
	return 1
def next_Prime(n):
	while 1:
		if is_Prime(n-1) == 1:
			return n-1
		n = n - 1
def not_zero(number):
	digits = []
	while number//10 != 0:
		digits.append(number%10)
		number = number // 10
	digits.append(number)
	for digit in digits:
		if digit == 0:
			return 0
	return 1
def work():
	prime = 7654322
	while prime > 4320:
		if is_Prime(prime) == 1 & is_pandigital(prime) == 1 & not_zero(prime) == 1:
			return prime
		prime = next_Prime(prime)
	return 0

print(work())