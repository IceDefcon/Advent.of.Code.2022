import codecs

file = open("data.h", "r")

lines = file.readlines() 
file.close()

i = 0
prio = 0

for line in lines:

	count = 0
	for c in line:
	    count = count + 1

	# minus carry return
	count = count - 1 

	# integer division
	half  = count//2

	first  = line[0:half]
	second = line[half:-1]
	asci_one = [0 for i in range(half)]
	asci_two = [0 for i in range(half)]
	print(first)
	print(second)

	i = 0
	for c in line:
		if i < half: asci_one[i] = c
		elif i < count: asci_two[i - half] = c
		i = i + 1

	print(asci_one)
	print(asci_two)

	int_one = [0 for i in range(half)]
	int_two = [0 for i in range(half)]

	length = len(int_one)

	x = 0
	for x in range(length):
		if asci_one[x].isupper() == True: 
			int_one[x] = ord(asci_one[x]) - 38
		else:
			int_one[x] = ord(asci_one[x]) - 96
		if asci_two[x].isupper() == True: 
			int_two[x] = ord(asci_two[x]) - 38
		else:
			int_two[x] = ord(asci_two[x]) - 96

	x = 0
	y = 0
	temp = 0
	
	for x in range(length):
		for y in range(length):
			if int_one[x] == int_two[y]:
				temp = int_one[x]
				print("Plus ---> " + str(int_one[x]))
				print("Breaking 1st")
				break
		if int_one[x] == int_two[y]: 
			print("Breaking 2nd")
			break

	prio = prio + temp

	print(int_one)
	print(int_two)
	print(line)


print(prio)