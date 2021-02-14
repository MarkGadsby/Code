file_data = open("bts.txt", "r")

all_data = file_data.read()

print(all_data)

file_data.close()

file_data = open("bts.txt", "a")

new_name = input()

file_data.append(new_name)

file_data.close()