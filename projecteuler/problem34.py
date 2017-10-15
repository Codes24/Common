def fac(n):
	if n == 1:
		return 1
	if n == 2:
		return 2
	if n == 0:
		return 1
	return fac(n-1) * n

def array_fac():
	i = 0
	facs = []
	while i < 10:
		facs.append(fac(i))
		i += 1
	return facs

def sum_fac_digit(n):
	digits = []
	facs = array_fac()
	while n//10 != 0:
		digits.append(n%10)
		n = n // 10
	digits.append(n)
	s_fac = 0
	for digit in digits:
		s_fac += fac(digit)
	return s_fac

def carry_out():
	i = 10
	resutl = 0
	while i < 2540161:
		if i == sum_fac_digit(i):
			resutl += i
			print(i)
		i += 1
	return resutl

print(carry_out())