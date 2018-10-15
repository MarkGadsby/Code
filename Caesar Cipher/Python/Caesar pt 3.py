# Import module support
import CodebreakingToolbox

messageText = input("Enter your text:\n")
shift = int(input("Enter how many places to shift:\n"))

messageText = CodebreakingToolbox.ApplyCaesarShift(messageText, shift)
print("Encoded Message: " + messageText)

messageText = CodebreakingToolbox.ApplyCaesarShift(messageText, -shift)
print("Decoded Message: " + messageText)
