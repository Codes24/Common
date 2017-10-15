def count_letter(letter):
	letter_list = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	i = 0
	while i < 26:
		if letter == letter_list[i]:
			return i + 1
		i = i + 1

def count_name(name):
	i = 0
	for each_letter in name:
		i += count_letter(each_letter)
	return i

def carry_out(file):

	f = open(file, "r")
	w = open("name.txt", "w")
	t = f.readline(46447);
	
	child_list = []
	parent_list = []
	sorted_list = []
	
	for each_letter in t:
		if each_letter != ',':
			if each_letter != '"':
				child_list.append(each_letter)
		else: 
		 	parent_list.append(child_list)
		 	child_list = []
	
	
	for each in parent_list:
		each = ''.join(each)
		sorted_list.append(each)
	
	sorted_list.sort()
	total = 0
	position = 1
	for each_name in sorted_list:
		total += (position * count_name(each_name)) 
		w.write(str(position) + "    " + each_name + "      " + str(count_name(each_name)) + "   " + str((position * count_name(each_name))) + "\n")
		position += 1
	print(total)
	# for each_name in sorted_list:
		# print(each_name)


carry_out("problem22.txt")
