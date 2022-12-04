


file = open("elf.h", "r")

lines = file.readlines() 
file.close()

def switch(arg): 
    switch = { 
        "A": 1, 
        "B": 2,
        "C": 3,
    } 
    return switch.get(arg) 

def loose(arg): 
    loose = { 
        "A": "Z", 
        "B": "X",
        "C": "Y",
    } 
    return loose.get(arg) 

def draw(arg): 
    draw = { 
        "A": "X", 
        "B": "Y",
        "C": "Z",
    } 
    return draw.get(arg) 

def win(arg): 
    win = { 
        "A": "Y", 
        "B": "Z",
        "C": "X",
    } 
    return win.get(arg) 

points = 0

for line in lines:

	oponent = line[0:1]
	me  	= line[2:3]

	abc 	= switch(oponent)
	xyz 	= switch(me)
	print("choice ---> " + str(xyz))
	if xyz == 1:
		me = loose(oponent)
		xyz 	= switch(me)
		print(xyz)
	elif xyz == 2:
		me = draw(oponent)
		xyz 	= switch(me)
		print(xyz)
	else:
		me = win(oponent)
		xyz 	= switch(me)
		print(xyz)

	result  = abc^xyz

	print(str(abc) + " xor " + str(xyz))

	if result == 0: 
		points = points + 3 + xyz
		print("Draw  ---> Plus " + str(3 + xyz))
	elif abc != 3:
		if (xyz - 1) == abc:
			points = points + 6 + xyz
			print("Win   ---> Plus " + str(6 + xyz))
		else:
			points = points + 0 + xyz
			print("Loose ---> Plus " + str(0 + xyz))
	elif (abc - 2) == xyz:
		points = points + 6 + xyz
		print("Win   ---> Plus " + str(6 + xyz))
	else:
		points = points + 0 + xyz
		print("Loose ---> Plus " + str(0 + xyz))

print("Total points ---> " + str(points))