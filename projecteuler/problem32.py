# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; 
# for example, the 5-digit number, 15234, is 1 through 5 pandigital.

# The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

# Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

# HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

""" 
	x1x2	*	x3x4x5	=	x6x7x8x9
or	x1x2x3	*	x3x4 	= 	x6x7x8x9 
"""

def Not_In(small_n, big_n):
	small_number = []
	while  small_n//10 != 0:
		small_number.append(small_n%10)
		small_n = small_n//10
	small_number.append(small_n)

	big_number = []
	while big_n//10 != 0:
		big_number.append(big_n%10)
		big_n = big_n // 10
	big_number.append(big_n)

	result_list = []
	i = 0
	for each_number in small_number:
		i = 0
		for number in big_number:
			if each_number == number:
				result_list.append(1)
				i = 1
				break
		if i == 0:
			result_list.append(0)
	for each in result_list:
		if each == 1:
			return 1
	return 0

def is_pandigital(number):
	digits = []
	while number//10 != 0:
		digits.append(number%10)
		number = number//10
	digits.append(number)
	for digit in digits:
		i = digits.index(digit) + 1
		while i < len(digits):
			if digit == digits[i]:
				return 0
			i += 1
	return 1
def next_product(product):
	if (is_pandigital(product - 1) == 1) & (not_zero(product - 1) == 1):
		return product - 1
	else:
		return next_product(product - 1)
def next_multiplicand(multiplicand):
	if (is_pandigital(multiplicand + 1) == 1) & (not_zero(multiplicand + 1) == 1):
		return multiplicand + 1
	else:
		return next_multiplicand(multiplicand + 1) 
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
def carry_out():
	result = 0
	product = 9876
	while product > 1233:
		multiplicand = 1
		while multiplicand < 100:
			if multiplicand < 10:
				if Not_In(multiplicand, product) == 0:
					if product%multiplicand == 0:
						multiplier = product // multiplicand
						if (multiplier > 1000) & (multiplier != multiplicand):
							if (is_pandigital(multiplier) == 1) & (Not_In(multiplier, multiplicand) == 0) & (Not_In(multiplier, product) == 0) & (not_zero(multiplier) == 1):
								result += product
								break
			else:
				if Not_In(multiplicand, product) == 0:
					if product%multiplicand == 0:
						multiplier = product // multiplicand
						if (multiplier > 100) & (multiplier != multiplicand):
							if (is_pandigital(multiplier) == 1) & (Not_In(multiplier, multiplicand) == 0) & (Not_In(multiplier, product) == 0) & (not_zero(multiplier) == 1):
								result += product
								break
			multiplicand = next_multiplicand(multiplicand)
		product = next_product(product)
	return result

print(carry_out())