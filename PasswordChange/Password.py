fileHandle = open("Passwords.txt", "r")

linesRead = []

lineRead = fileHandle.readline()

fileHandle.endOfFile();

while lineRead != "":
    linesRead.append(lineRead)
    lineRead = fileHandle.readline()
    
print(linesRead)    

fileHandle.close() 