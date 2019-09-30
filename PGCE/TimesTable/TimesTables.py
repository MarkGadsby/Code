import random

for i in range(10):
    a = random.randint(1,12)
    b = random.randint(1,12)

    qu = 'What is ' + str(a) + ' X ' + str(b) + ' ? '
    an = int(input(qu))
    
    if an == a * b:        
        print("Well Done!")
    else:
        print("No, the answer is", a * b)
    