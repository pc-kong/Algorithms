cases = int(input())
notes = list(map(int, input().strip().split()))

sum = 0
for i in range(cases):
	if notes[i] == 0:
		sum += 2
	elif notes[i] == 1:
		sum += 1
	else:
		sum += 1/notes[i]
print(sum)
