
maxletter = 'a'
minletter = 'z'

for i in range(5):
    char = input("Please enter a lower case letter: ")

    if (char < minletter):
        minletter = char
    if (char > maxletter):
        maxletter = char

print("minletter = ", minletter)
print("maxletter = ", maxletter)
