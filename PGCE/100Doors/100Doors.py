doors = [False for i in range(100)]
open_close_count = [0 for i in range(100)]

step = 1

while step <= 100:
    for i in range(1, 101):
        if i % step == 0:
            doors[i-1] = not doors[i-1]
            open_close_count[i-1] += 1
    step = step + 1

for i in range(1, 101):
    if doors[i-1] == True:
        print(str(i) + " = " + str(doors[i-1]),open_close_count[i-1])

import matplotlib.pyplot as plt

x_axis = []
bar_cols = []

for i in range(1,101):
    x_axis.append(str(i))
    
    if doors[i-1] == True:
        bar_cols.append('r')
    elif open_close_count[i-1] == 2:
        bar_cols.append('c')
    else:        
        bar_cols.append('b')        
            
plt.rc('xtick',labelsize = 7)
plt.bar(x_axis, open_close_count, color = bar_cols)

plt.ylabel('Number of door state changes')
plt.title('100 Doors Problem')
plt.show()