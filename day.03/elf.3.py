import codecs

file = open("data.h", "r")

lines = file.readlines() 
file.close()

# prio = 0

# for line in lines:

# 	count = 0
# 	for c in line:
# 	    count = count + 1

# 	# minus carry return
# 	count = count - 1 

# 	# integer division
# 	half  = count//2

# 	first  = line[0:half]
# 	second = line[half:-1]
# 	asci_one = [0 for i in range(half)]
# 	asci_two = [0 for i in range(half)]
# 	print(first)
# 	print(second)

# 	i = 0
# 	for c in line:
# 		if i < half: asci_one[i] = c
# 		elif i < count: asci_two[i - half] = c
# 		i = i + 1

# 	print(asci_one)
# 	print(asci_two)

# 	int_one = [0 for i in range(half)]
# 	int_two = [0 for i in range(half)]

# 	length = len(int_one)

# 	x = 0
# 	for x in range(length):
# 		if asci_one[x].isupper() == True: 
# 			int_one[x] = ord(asci_one[x]) - 38
# 		else:
# 			int_one[x] = ord(asci_one[x]) - 96
# 		if asci_two[x].isupper() == True: 
# 			int_two[x] = ord(asci_two[x]) - 38
# 		else:
# 			int_two[x] = ord(asci_two[x]) - 96

# 	x = 0
# 	y = 0
# 	temp = 0
	
# 	for x in range(length):
# 		for y in range(length):
# 			if int_one[x] == int_two[y]:
# 				temp = int_one[x]
# 				print("Plus ---> " + str(int_one[x]))
# 				print("Breaking 1st")
# 				break
# 		if int_one[x] == int_two[y]: 
# 			print("Breaking 2nd")
# 			break

# 	prio = prio + temp

# 	print(int_one)
# 	print(int_two)
# 	print(line)

# print(prio)

prio = 0
trio = 0
count = [0 for i in range(3)]

for line in lines:

	count[trio] = 0
	for c in line:
	    count[trio] = count[trio] + 1

	# minus carry return
	count[trio] = count[trio] - 1 
	print(count[trio])
	if trio == 0:
		i = 0
		asci_one   = [0 for i in range(count[trio])]
		for c in line:
			if i < count[trio]:
				asci_one[i] = c
				i = i + 1
		int_one = [0 for i in range(count[trio])]
		x = 0
		for x in range(count[trio]):
			if asci_one[x].isupper() == True: 
				int_one[x] = ord(asci_one[x]) - 38
			else:
				int_one[x] = ord(asci_one[x]) - 96


	if trio == 1:
		i = 0
		asci_two   = [0 for i in range(count[trio])]
		for c in line:
			if i < count[trio]:
				asci_two[i] = c
				i = i + 1
		int_two = [0 for i in range(count[trio])]
		x = 0
		for x in range(count[trio]):
			if asci_two[x].isupper() == True: 
				int_two[x] = ord(asci_two[x]) - 38
			else:
				int_two[x] = ord(asci_two[x]) - 96

	if trio == 2:
		i = 0
		asci_three   = [0 for i in range(count[trio])]
		for c in line:
			if i < count[trio]:
				asci_three[i] = c
				i = i + 1
		int_three = [0 for i in range(count[trio])]
		x = 0
		for x in range(count[trio]):
			if asci_three[x].isupper() == True: 
				int_three[x] = ord(asci_three[x]) - 38
			else:
				int_three[x] = ord(asci_three[x]) - 96

	trio = trio + 1

	if trio == 3:
		temp = 0;
		flag = 0
		print(asci_one)
		print(asci_two)
		print(asci_three)
		print(int_one)
		print(int_two)
		print(int_three)

		for x in range(count[0]):
			if flag == 1:
				break
			for y in range(count[1]):
				if flag == 1:
					break
				for z in range(count[2]):
					if int_one[x] == int_two[y] and int_one[x] == int_three[z] and int_two[y] == int_three[z]:
						flag = 1
						temp = int_one[x]
						break

		prio = prio + temp

		trio = 0

print(prio)

