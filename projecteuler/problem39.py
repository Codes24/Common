# If p is the perimeter of a right angle triangle with integral length sides,
# {a,b,c}, there are exactly three solutions for p = 120.

# {20,48,52}, {24,45,51}, {30,40,50}

# For which value of p ≤ 1000, is the number of solutions maximised?
def check_triangle(a, b, c):
	if (a+b > c) & (a+c > b) & (b+c > a):
		return 1
	return 0

def check_right_triangle(a, b, c):
	if check_triangle(a, b, c) == 0:
		return 0
	if ((a**2) + (b**2) == (c**2)) | ((a**2) + (c**2) == (b**2)) |((b**2) + (c**2) == (a**2)):
		return 1
	return 0

def work():
	maximum = 0
	result = 120
	p = 120
	while p <= 1000:
		count = 0
		a = 1
		while a < p//2:
			b = 1
			while b < p//2:
				c = p - a - b
				if check_right_triangle(a, b, c) == 1:
					count += 1
				b += 1
			a += 1
		if count > maximum:
			maximum = count
			result = p
		p += 1
	return result

print(work())