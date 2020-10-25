phrase = "Be quiet Noah"
finished = ""

for i in range(0, len(phrase)):
    if i % 2 == 0:
        finished = finished + phrase[i] 
    else:
        finished = finished + chr(ord(phrase[i]) - 32)

print(finished) 