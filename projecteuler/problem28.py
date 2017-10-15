def clock_matrix(n):
	i = 0
	matrix = [[0 for x in range(n)] for y in range(n)] 
	k = n*n
	while i<n:
		j = n-i-1
		while j >= i:
			matrix[i][j] = k
			k -= 1
			j -= 1
		j = i+1
		while j < n-i-1:
			matrix[j][i] = k
			k -= 1
			j += 1
		j = i
		while j < n-i-1:
			matrix[n-i-1][j] = k
			k -= 1
			j += 1
		j = n-i-1
		while j > i:
			matrix[j][n-i-1] = k
			k -= 1
			j -= 1
		i += 1
	return matrix

def calculate(matrix, n):
	total = 0
	i = 0
	j = 0
	while (i < n) & (j < n):
		total += matrix[i][j]
		i += 1
		j += 1
	i = 0
	j = n - 1
	while (i < n) & (j >= 0):
		total += matrix[i][j]
		i += 1
		j -= 1
	return total - 1

n = 1001
matrix = clock_matrix(n)
print(calculate(matrix, n))
