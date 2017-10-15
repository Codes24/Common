# 9 + 90x2 + 900x3 + 9000x4 + 90000x5 + 900000x6 = 5.888.889
def genarator():
	fraction = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	i = 10
	while i < 200000:
		n = i
		num = []
		while n >= 10:
			num.append(n%10)
			n = int(n/10)
		num.append(n)
		index = len(num)-1
		while index >= 0:
			fraction.append(num[index])
			index -= 1
		i += 1
	return fraction

r = genarator()
print(r[0] * r[9] * r[99] * r[999] * r[9999] * r[99999] * r[999999])