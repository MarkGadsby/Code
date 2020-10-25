

def encrpyt():
    def code(message, shift):
        message = message.lower()
        codedMessage = ""
        for x in message:
            if x in "abcdefghijklmnopqrstuvwxyz":
                num = ord(x)
                num += shift
                if num > ord("z"):    
                    num -= 26
                codedMessage = codedMessage + chr(num)
            else:
                codedMessage = codedMessage + x
        return codedMessage

    num1 = 0
    num2 = 1
    while num1 < num2:
        msg = input("Enter your message: ")
        shift = int(input("input the number of shifts you want from message: "))
        msg.lower()
        if shift > 36:
            print("You cant shift that far!")
            num1 += 1
            num2 += 1
        else:
            codedMessage = code(msg,shift)
            print("The encoded message is:", codedMessage)
