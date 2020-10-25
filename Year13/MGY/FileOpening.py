file_data = open("example.txt", "r")

data_string = ""

line = file_data.readlines()

print(line[2])

file_data.close()
