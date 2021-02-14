def isitprime(num):
    answer = True
    
    for count in range (2,num):
        remainder = num % count
        if remainder == 0:
            answer = False
    if answer == True:
        print((num),("is a prime number!\n"))
        
        
    
            
    

loopnumber = 0
while loopnumber <= 144:
    

    isitprime(loopnumber)
    
    loopnumber = loopnumber + 1
    
