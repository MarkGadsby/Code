import random 

for i in range(100):
    print(random.randint(1,6))


numberplate = "ZX19CSV"
starting_index = 2

yearString = numberplate[starting_index:starting_index + 4]

print(yearString)