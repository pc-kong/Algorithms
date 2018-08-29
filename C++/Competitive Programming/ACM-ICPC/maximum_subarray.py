""" Maximum Subarray """

array = [-1, 2, -1, 2, 3, 4, -5]

def get_sum_array(array):
	sum_array = []
	count = 0
	for i in range(len(array)):
		count += array[i]
		sum_array.append((count, i))
	return sum_array


sum_array = get_sum_array(array)
sum_array.sort()

print(sum_array)