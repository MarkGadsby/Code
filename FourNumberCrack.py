combination = [3,3,3,3]

def spinFourth():
    for x in range(4):
        if all(elem in combination for elem in [1,2,3,0]):
            print (combination)
        combination[3] -= 1
    combination[3] = 3

def spinThird():
    for x in range(4):
        spinFourth()
        combination[2] -= 1
    combination[2] = 3

def spinSecond():
    for x in range(4):
        spinThird()
        combination[1] -= 1
    combination[1] = 3
    
def spinFirst():
    for x in range(4):
        spinSecond()
        combination[0] -= 1
    combination[0] = 3

spinFirst()
