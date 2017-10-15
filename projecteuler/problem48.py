def find():
	i = 1
	s = 0
	while i <= 1000:
		s = s + i**i
		i += 1
	return s

print(find())