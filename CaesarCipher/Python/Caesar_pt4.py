import CodebreakingToolbox

read_book = "The Adventure of the Dancing Men.txt"
write_book = "Encrypted.txt"

read_file = open(read_book)
read_data = read_file.read()
read_file.close()

write_data = CodebreakingToolbox.ApplyCaesarShift(read_data, 5)

write_file = open(write_book, 'w')
write_file.write(write_data)
write_file.close()
