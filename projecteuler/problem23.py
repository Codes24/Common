# A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
# For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
# A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
# the smallest number that can be written as the sum of two abundant numbers is 24. 
# By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. 
# However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot 
# be expressed as the sum of two abundant numbers is less than this limit.
# Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

def is_abundant(number):
	i = 1
	num_list = []
	while(i < number):
		if number%i == 0:
			num_list.append(i)
		i+=1
	if sum_list(num_list) > number:
		return True
	return False

def sum_list(num_list):
	s = 0
	for num in num_list:
		s += num
	return s
def get_abundant():
	i = 1
	abundant = []
	while(i <= 28123):
		if (is_abundant(i)):
			abundant.append(i)
		i += 1
	return abundant.sort()
def get_2abundant():
	abundant = get_abundant()
	two_abundant = []
	for num in abundant:
		for other_num in abundant:
			two_abundant.append(num + other_num)
	return two_abundant
def MAIN():
	return get_2abundant()
print(MAIN())