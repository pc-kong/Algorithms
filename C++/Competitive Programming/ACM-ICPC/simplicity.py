s = input()

letters = [0]*26

for i in range(len(s)):
	letters[ord(s[i])-97] += 1
letters.sort()
borra = 0
for i in range(len(letters)-2):
	borra+=letters[i]

print(borra)