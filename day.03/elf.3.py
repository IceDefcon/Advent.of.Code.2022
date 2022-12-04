import codecs

file = open("data.h", "r")

lines = file.readlines() 
file.close()

i = 0

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
	one = [0 for i in range(half)]
	two = [0 for i in range(half)]
	print(first)
	print(second)
	
	i = 0
	for c in line:
		if i < half: one[i] = c
		elif i < count: two[i - half] = c
		i = i + 1

	print(one)
	print(two)
	print(line)


symbol = codecs.encode(b"a", "hex")

prio = int(symbol) - 60

print(prio)