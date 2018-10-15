# define our function here
def ApplyCaesarShift(message, shiftby):
    # Function to apply the shiftby value to each of the charactors in the
    # message string. Returning a new encoded version of the string 
    encoded_return = ""
    
    for char in message:
        pos = ord(char)
    
        if 48 <= pos <= 57:
            newpos = (pos-48 + shiftby) % 10 + 48
        elif 65 <= pos <= 90:
            newpos = (pos-65 + shiftby) % 26 + 65
        elif 97 <= pos <= 122:
            newpos = (pos-97 + shiftby) % 26 + 97
        else:
            newpos = pos
            
        encoded_return += chr(newpos)
    return encoded_return

def get_index_of_most_popular_letter(message):

    alphabit_countList = [0 for i in range(26)]

    for letter in message:
        letter = letter.lower()
        zero_based_letter = ord(letter) - 97
        if 0 <= zero_based_letter <= 25:
            alphabit_countList[zero_based_letter] += 1
 
    print("Charactor frequency analysis:\n")

    for i in range(len(alphabit_countList)):
      print(chr(i + 97), "=", alphabit_countList[i])
      
    return alphabit_countList.index(max(alphabit_countList))

