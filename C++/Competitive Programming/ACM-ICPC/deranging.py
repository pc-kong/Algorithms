inp = list(input())

array = []

for a in range(len(inp)):
	array.append((inp[a],a))

inp.sort()

ans = []

def encuentra(e):
	for i in range(len(array)):
		if array[i][0] == e:
			return array[i]

for i in range(len(inp)):
	t = encuentra(inp[i])
	if i < t[1]:
		ans.append((t[1],i))
	array.remove(t)

for i in range(len(ans)-1, -1, -1):
	print(str(ans[i][0]+1) + " " + str(ans[i][1]+1))



