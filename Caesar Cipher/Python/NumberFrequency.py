read_book = "../../Code_Block_Projects/TextFiles/HarryPotter.txt"

read_file = open(read_book)
read_data = read_file.read()
read_file.close()

alphabit_countList = [0 for i in range(26)]

for letter in read_data:
    letter = letter.lower()
    zero_based_letter = ord(letter) - 97
    if 0 <= zero_based_letter <= 25:
        alphabit_countList[zero_based_letter] += 1
 
print("Charactor frequency analysis:\n")

for i in range(len(alphabit_countList)):
  print(chr(i + 97), "=", alphabit_countList[i])
      
indexOfMax = alphabit_countList.index(max(alphabit_countList))

print("The most popular letter is '", chr(indexOfMax + 97), "'")
print("At index [", indexOfMax, "]")
