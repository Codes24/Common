def fac(n):
	if(n == 1):
		return 1
	else:
		return n * fac(n - 1)

a = fac(100)

s = 0
while(a//10 != 0):
	s = s + a%10
	a = a//10
s = s + a

print(s)