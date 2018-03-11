balls = int(input())

colors = []
for i in range(balls):
	colors.append(input().strip())

def getMax(c):
		if "black" in c:
			c.remove("black")
			return 7
		if "pink" in c:
			c.remove("pink")
			return 6
		if "blue" in c:
			c.remove("blue")
			return 5
		if "brown" in c:
			c.remove("brown")
			return 4
		if "green" in c:
			c.remove("green")
			return 3
		if "yellow" in c:
			c.remove("yellow")
			return 2

def ans(c):
	reds = c.count("red")
	if reds == len(c):
		return 1
	for i in range(reds):
		c.remove("red")
	mc = getMax(c)
	total = (reds+1)*mc
	l = len(c)
	for i in range(l):
		total += getMax(c)
	return total+reds

print(ans(colors))