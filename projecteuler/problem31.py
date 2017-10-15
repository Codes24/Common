# 	a : 1 pound
#	b : 2 pound
#	c : 5 pound
#	d : 10 pound
# 	e : 20 pound
#	f : 50 pound
#	g : 100 pound
#	h : 200 pound
#	a + 2b + 5c + 10d + 20e + 50f + 100g + 200h = 200
def carry_out(left_list, right_sum):
	if len(left_list) == 1:
		if right_sum % left_list[0] == 0:
			return 1
		else:
			return 0
	else:
		temp_list = []
		i = 0
		while i < (len(left_list) - 1):
			temp_list.append(left_list[i])
			i += 1
		result = 0
		x = 0
		while (x * left_list[len(left_list) - 1]) <= right_sum:
			result += carry_out(temp_list, right_sum - (x * left_list[len(left_list) - 1]))
			x += 1
		return result

index = [1, 2, 5, 10, 20, 50, 100, 200]
print(carry_out(index, 200))