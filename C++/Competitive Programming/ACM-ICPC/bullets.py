n, m = map(int, input().split())

if m < n:
	print('Impossible')

pos = []
for i in range(m):
	iz, de = map(int, input().split())
	pos.append((iz,de))

pos.sort()








