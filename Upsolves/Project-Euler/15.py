ans, N = 1, 40
for i in range(N, N // 2, -1):
	ans *= i
for i in range(1, N // 2 + 1, 1):
	ans //= i
print(ans)