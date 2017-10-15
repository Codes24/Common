def letter_number(letter):
	letters = ['\"','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	return letters.index(letter)
def word_number(word):
	number = 0
	for letter in word:
		number += letter_number(letter)
	return number
def readfile(filename):
	f = open(filename, "r")
	words = f.read().split(',')
	words = [word.strip('\"') for word in words]
	return words
def genarate_triangle():
	i = 1
	triangle = []
	while 1:
		n = int((i*(i+1)) / 2)
		if (n > 676):
			break
		triangle.append(n)
		i += 1
	return triangle
def work():
	count = 0
	triangle = genarate_triangle()
	words = readfile("problem42.txt")
	for word in words:
		if word_number(word) in triangle:
			count += 1
	return count
print(work())
