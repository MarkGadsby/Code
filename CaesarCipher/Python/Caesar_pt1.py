plainText = input("Enter your text:\n")
shift = int(input("Enter how many places to shift:\n"))

cipherText = ""

for char in plainText:
    asciiDec = ord(char)
    
    if 48 <= asciiDec <= 57: # 48 to 56 are ascii numbers
        zeroedPos = asciiDec - 48
        zeroedPosShifted = zeroedPos + shift
        modPos = zeroedPosShifted % 10;
        asciiDec = modPos + 48
    elif 65 <= asciiDec <= 90: # an ascii upper case letter
        asciiDec = (asciiDec - 65 + shift) % 26 + 65
    elif 97 <= asciiDec <= 122: # an ascii lower case letter
        asciiDec = (asciiDec - 97 + shift) % 26 + 97
    else:
        asciiDec = asciiDec

    cipherText += chr(asciiDec)

print("Coded Message:")
print(cipherText)