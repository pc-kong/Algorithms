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
	lt = len(text)
	lp = len(pattern)
	patterns = []
	while(j<lt):
		if text[j] == pattern[i]:
			i+=1
			j+=1
		else:
			if i != 0:
				i = array[i-1]
			else:
				j+=1
		if i == lp:
			patterns.append(j-i)
			i = array[i-1]
	return patterns


s1 = input()
s2 = input()
print(KMP(s1,s2))
print(prefix(s2))



