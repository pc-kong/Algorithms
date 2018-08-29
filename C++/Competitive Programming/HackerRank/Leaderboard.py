n = int(input().strip())
rank = list(map(int, input().strip().split()))
m = int(input().strip())
scores = list(map(int, input().strip().split()))
for i in range(len(scores)):
	current = 1
	last = rank[0]
	for j in range(len(rank)):
		if rank[j] < last:
			current += 1
			last = rank[j]
		elif rank[j] == last:
			last = rank[j]
		if scores[i] >= rank[j]:
			print(current)
			break
		elif scores[i] <= rank[j] and j == len(rank)-1:
			print(current+1)
			break
