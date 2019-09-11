denominations = [1,2,5,10,20,50]

amount = float(input("Please the amount of money to be divided: "))
pounds = int(amount)
pence = round((amount - pounds) * 100)

index = len(denominations)

pounds_and_pence = [pounds,pence]

for i in range(len(pounds_and_pence)):
   
    index = len(denominations)
    
    if (i):
        print("\nPence p:")
    else: 
        print("\nPounds £:")
  
    while (index):
        index -= 1
        whole_nums = int(pounds_and_pence[i] / denominations[index])
    
        if (whole_nums):
            print(whole_nums, ' x ', denominations[index])
        
        pounds_and_pence[i] %= denominations[index]