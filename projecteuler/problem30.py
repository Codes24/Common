def is_power_digit(digit, n):
	temp_digit = digit
	digit_list = []
	count_digit = n
	while digit//10 != 0:
		digit_list.append(digit%10)
		digit = digit//10
	digit_list.append(digit)
	total = 0
	for each_num in digit_list:
		total += each_num**count_digit
	if total == temp_digit:
		return 1
	return 0

def carry_out(n):
	total = 0
	i = 1000
	limit = n * (9**n)
	print(limit)
	while i < limit:
		if is_power_digit(i, n) == 1:
			print(i)
			total += i
		i += 1
	return total

print(carry_out(5))