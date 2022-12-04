file = open("data.h", "r")

lines = file.readlines() 
file.close()

def xyz_switch(arg): 
    switch = { 
        "X": 1, 
        "Y": 2,
        "Z": 3,
    } 
    return switch.get(arg) 

def abc_switch(arg): 
    switch = { 
        "A": 1, 
        "B": 2,
        "C": 3,
    } 
    return switch.get(arg) 

def loose_switch(arg): 
    loose = { 
        "A": "Z", 
        "B": "X",
        "C": "Y",
    } 
    return loose.get(arg) 

def draw_switch(arg): 
    draw = { 
        "A": "X", 
        "B": "Y",
   		     "C": "Z",
    } 
    return draw.get(arg) 

def win_switch(arg): 
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

	abc 		= abc_switch(oponent)
	xyz 		= xyz_switch(me)

	if xyz == 1:
		me 		= loose_switch(oponent)
		xyz 	= xyz_switch(me)
	elif xyz == 2:
		me 		= draw_switch(oponent)
		xyz 	= xyz_switch(me)
	else:
		me 		= win_switch(oponent)
		xyz 	= xyz_switch(me)

	result  = abc^xyz

	if result == 0: 
		points = points + 3 + xyz
	elif abc != 3:
		if (xyz - 1) == abc:
			points = points + 6 + xyz
		else:
			points = points + 0 + xyz
	elif (abc - 2) == xyz:
		points = points + 6 + xyz
	else:
		points = points + 0 + xyz

print("Total points ---> " + str(points))