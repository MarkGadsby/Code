def DisplayName(planet_string):
    index_of_comma = planet_string.find(',')
    print(index_of_comma)

file_handle = open("Planetary_data.csv", "r")

string_list = file_handle.readlines()

for i in range(1,len(string_list)):
    DisplayName(string_list[i])

file_handle.close()