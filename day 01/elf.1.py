


file = open("data.h", "r")

lines = file.readlines() 
file.close()



i = 0
for line in lines:

	if line.strip():
		continue
	else:
		i = i + 1;

elves = i
elf = [0 for i in range(elves)]
print("number of elfves = " + str(elves))

sum = 0;

i = 0
for line in lines:

	if line.strip():
		data = int(line)
		sum = sum + data
	else:
		elf[i] = sum
		i = i + 1;
		sum = 0;

elf.sort()
print(elf[-1])
print(elf[-2])
print(elf[-3])

print(elf[-1]+elf[-2]+elf[-3])