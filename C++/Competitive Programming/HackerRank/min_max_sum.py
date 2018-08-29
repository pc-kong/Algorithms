numbers = list(map(int, input().strip().split()))

numbers.sort()
print(str(numbers[0]+numbers[1]+numbers[2]+numbers[3]) + " " + str(numbers[1]+numbers[2]+numbers[3]+numbers[4]))