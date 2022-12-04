file = open("data.h", "r")

lines = file.readlines() 
file.close()

line = 0
line_count = 0

for line in lines:
    if line != "\n":
        line_count += 1

one_one = [0 for i in range(line_count)]
one_two = [0 for i in range(line_count)]
two_one = [0 for i in range(line_count)]
two_two = [0 for i in range(line_count)]

x = 0
contained = 0

for line in lines:

	coma = 0
	for c in line:
		if line[coma:coma + 1] == ',':
			string_one = line[0:coma]
			string_two = line[coma + 1:-1]
			break
		coma += 1

	minus = 0
	length_one = len(string_one)

	for c in string_one:
		if string_one[minus:minus + 1] == '-':
			one_one[x] = int(string_one[0:minus])
			one_two[x] = int(string_one[minus + 1:length_one])
			break
		minus += 1

	minus = 0
	length_two = len(string_two)

	for c in string_two:
		if string_two[minus:minus + 1] == '-':
			two_one[x] = int(string_two[0:minus])
			two_two[x] = int(string_two[minus + 1:length_two])
			break
		minus += 1

	if one_one[x] <= two_one[x] and one_two[x] >= two_two[x]: 
		contained += 1
	elif two_one[x] <= one_one[x] and two_two[x] >= one_two[x]: 
		contained += 1
	else:
		continue

	x += 1

print("Contained pairs ---> " + str(contained))

