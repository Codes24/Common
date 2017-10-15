def search_in_list(s_list, s_object):
	for each_object in s_list:
		if each_object == s_object:
			return 1
	return 0

def carry_out(n):
	a = 2
	b = 2
	main_list = []
	while a <= 100:
		while b <= 100:
			number = a**b;
			if search_in_list(main_list, number) == 0:
				main_list.append(number)
			b += 1
		a += 1
		b = 2
	count = 0
	for each_number in main_list:
		count += 1
	return count

print(carry_out(100))