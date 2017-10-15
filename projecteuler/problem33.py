def gcd(a, b):
	if b == 0:
		return a;
	else:
		return gcd(b, a%b)

def main():
	num = 1
	deno = 1
	i = 1
	a = 1
	b = 1
	while i < 10:
		b = 1
		while b < i:
			a = 1
			while a < b:
				if (b*(10*a+i) == (a*(10*i+b))):
					num *= a
					deno *= b
				a += 1
			b += 1
		i += 1
	return deno/gcd(deno, num)

print(main())