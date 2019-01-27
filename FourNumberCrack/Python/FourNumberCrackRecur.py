combination = [3,3,3,3]

def SpinWheel(wheel):
    if wheel > 3:
        return
    for x in range(4):
        if wheel == 3 and all(elem in combination for elem in [1,2,3,0]):
            print (combination)
        SpinWheel(wheel + 1)
        combination[wheel] -= 1
    combination[wheel] = 3

SpinWheel(0)
