# Take the number 192 and multiply it by each of 1, 2, and 3:

# 192 × 1 = 192
# 192 × 2 = 384
# 192 × 3 = 576
# By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

# The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, 
# which is the concatenated product of 9 and (1,2,3,4,5).

# What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

def get_digits(n):
	digits = []
	while n//10 != 0:
		digits.append(n%10)
		n = n//10
	digits.append(n)
	return digits
def get_number(digits):
	number = 0
	i = 0
	while i < len(digits):
		number += digits[i] * (10**i)
		i += 1
	return number
def is_pandigital(n):
	digits = get_digits(n)
	if len(digits) != 9:
		return 0
	i = [1,2,3,4,5,6,7,8,9]
	for digit in i:
		if digit not in digits:
			return 0
	return 1

def cat_number(n, m):
	n_digits = get_digits(n)
	m_digits = get_digits(m)
	main_digits = []
	for digit in m_digits:
		main_digits.append(digit)
	for digit in n_digits:
		main_digits.append(digit)
	n_m = get_number(main_digits)
	return n_m

i = 9387
while i >= 9284:
	result = cat_number(i, i*2)
	if is_pandigital(result) == 1:
		print(result)
		break
	i -= 1


