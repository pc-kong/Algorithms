def prefix(s):
	if len(s) == 1:
		return [0];
	array = [0]*len(s)
	i = 0
	j = 1
	while(j<len(s)):
		if s[i] == s[j]:
			array[j] = i+1
			i+=1
			j+=1
		else:
			if i != 0:
				i = array[i-1]
			else: 
				j+=1
	return array

def KMP(text, pattern):
	array = prefix(pattern)
	i = 0
	j = 0
	app = 0
	s = ""
	lt = len(text)
	lp = len(pattern)
	while(j<lt):
		if text[j] == pattern[i]:
			i+=1
			j+=1
		if i == lp:
			s = s + " " + str(j-i+1)
			i = array[i-1]
			app += 1
		elif j<lt and text[j] != pattern[i]:
			if i != 0:
				i = array[i-1]
			else:
				j+=1
	if app == 0:
		print("Not Found")
	else:
		print(app)
		print(s.strip())

n = int(input())
words = []
for i in range(n):
	text, patt = input().split()
	words.append((text,patt))
for k in range(len(words)):
	if k == len(words)-1:
		KMP(words[k][0],words[k][1])
	else:
		KMP(words[k][0],words[k][1])
		print("")
"""
s1 = input()
s2 = input()
print(KMP(s1,s2))
#print(prefix(s2))"""



