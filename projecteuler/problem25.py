def count_digit(number):
	digit = 0
	while number//10 != 0:
		digit += 1
		number = number//10
	return digit+1

def count_term(number_of_digit):
	term = 0
	a = 1
	b = 1
	index = 1
	while count_digit(term) != number_of_digit:
		term = a + b
		a = b
		b = term
		index += 1
	return index+1


print(count_term(1000))