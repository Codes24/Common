mul = 2**1000
r = 0;
while mul//10 != 0:
	r = r + mul%10
	mul = mul//10
r = r + mul
print(r)