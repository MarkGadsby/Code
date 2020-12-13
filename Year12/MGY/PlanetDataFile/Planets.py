def DisplayPlanetName(line):
    index_of_comma = line.find(',')
    name = line[0:index_of_comma]
    print(name)

def DisplayPlanetName_Mass(line):
    index_of_comma = line.find(',')
    index_of_comma_2 = line.find(',', index_of_comma + 1)
    name = line[0 : index_of_comma]
    mass = line[index_of_comma + 1 : index_of_comma_2]
    print(name + '\t\t' + mass)

file_handle = open("Planetary_data.csv")

current_line = file_handle.readline()
print("Name" + '\t\t' + "Mass")
print("====" + '\t\t' + "====")

while current_line:
    current_line = file_handle.readline()
    DisplayPlanetName_Mass(current_line)
file_handle.close()

file_read_handle = open("Neptune.csv", 'r')
file_write_handle = open("Planetary_data.csv", 'a')

neptuneline = file_read_handle.readline()

file_read_handle.close()
file_write_handle.writelines("\n" + neptuneline)
file_write_handle.close()





