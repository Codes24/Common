# The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

# Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

# (Please note that the palindromic number, in either base, may not include leading zeros.)

def get_binary(number):
	digits = []
	while number//2 != 0:
		digits.insert(0, number%2)
		number = number//2
	digits.insert(0, number%2)
	return digits
def get_rever_number(number):
	digits = []
	while number//10 != 0:
		digits.append(number%10)
		number = number // 10
	digits.append(number)
	return digits
def get_number(digits):
	number = 0
	i = 1
	for digit in digits:
		number += digit * (10**(len(digits) - i))
		i += 1
	return number
def get_rever_binary(number):
	digits = []
	while number//2 != 0:
		digits.append(number%2)
		number = number//2
	digits.append(number%2)
	return digits
def compare_two_binary(number):
	binary1 = get_binary(number)
	binary2 = get_rever_binary(number)
	i = 0
	for digit in binary1:
		if digit != binary2[i]:
			return 0
		i += 1
	return 1

def my_main():
	result = 0
	i = 1
	while i < 1000000:
		if i != get_number(get_rever_number(i)):
			i += 1
		else:
			if compare_two_binary(i) == 1:
				result += i
			i += 1
	return result

print(my_main())