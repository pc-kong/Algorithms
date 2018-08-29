def parte(s):
	if(len(s)%2):
		return s
	else:
		m1 = parte(s[:len(s)//2]) 
		m2 = parte(s[len(s)//2:])
	return m1 + m2 if m1 < m2 else m2 + m1
	
a = input()
b = input()
if(parte(a) == parte(b)):
	print("YES")
else:
	print("NO")

				