# The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

# There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

# How many circular primes are there below one million?
import math
def is_prime(number):
	i = 2
	while i <= math.sqrt(number):
		if number%i == 0:
			return 0
		i += 1
	return 1
def get_digits(number):
	digits = []
	while number//10 != 0:
		digits.insert(0, number%10)
		number = number // 10
	digits.insert(0, number)
	return digits

def rotation(number):
	digits = get_digits(number)
	new_digits = []
	i = 1
	while i < len(digits):
		new_digits.append(digits[i])
		i += 1
	new_digits.append(digits[0])
	return new_digits
def get_number(digits):
	number = 0
	i = 1
	for digit in digits:
		number += digit * (10**(len(digits) - i))
		i += 1
	return number
def is_possible(number):
	i = 1
	while i <= len(get_digits(number)):
		if is_prime(number) == 0:
			return 0
		number = get_number(rotation(number))
		i += 1
	return 1
def not_zero(number):
	digits = get_digits(number)
	for digit in digits:
		if digit == 0:
			return 0
	return 1
def my_main():
	result = 13
	i = 101
	while i < 1000000:
		if is_possible(i) == 1 & not_zero(i) == 1:
			print(i)
			result += 1
		i += 1
	return result

print(my_main())