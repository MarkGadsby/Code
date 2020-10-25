# Module imported to use the sleep function for delays in output
import time

class CaesarCipher:

    def __init__(self):
        self.message = "" # Stores the message that the user will input
        self.encrypted_message = "" # Stores encrypted message if this mode is chosen
        self.decrypted_message = "" # Stores decrypted message if this mode is chosen
        self.shift = 0 # Integer storing the number of characters to shift left (decryption) or right (encryption) by
        self.mode = "" # Either stores 'e' for encryption or 'd' for decryption
    
    # Function to display title
    def title(self):
        print("\n-------------")
        print("CAESAR CIPHER")
        print("-------------")
    
    # Function to display the main menu
    def main_menu(self):
        time.sleep(1)
        print("\nENCRYPT MESSAGE -  E")
        print("DECRYPT MESSAGE -  D")
        print("INSTRUCTIONS    -  I")
        print("QUIT            -  Q")
    
    # Function to check the user's input to the main menu screen and, if valid, returns their choice
    def get_main_menu_input(self):
        while True:
            choice = input("Enter E, D, I or Q: ").lower().strip()
            if len(choice) != 1 or choice not in "ediq":
                print("Invalid input!")
            else:
                return choice

    # Function to display the instructions and the user exits these by pressing the enter key    
    def instructions(self):
        print("\n------------")
        print("INSTRUCTIONS")
        print("------------")
        print("Enter the message you would like to encrypt or decrypt when prompted")
        print("Enter an integer for the amount that the characters in your message shift by when prompted")
        
        input("\nPress Enter to start using this program")
    
    # Function that quits the program
    def quit_program(self):
        print("\nThanks for using the program!")
        quit()
    
    # Function that handles the program loop
    def program_loop(self):
        # Displays the title
        self.title()
        
        # Loop to ensure user can encrypt, decrypt, see instructions or quit
        while True:
            # Displays the main menu
            self.main_menu()
            # Gets the user input for the main menu
            choice = self.get_main_menu_input()

            # If the user types something beginning with 'q'
            if choice == "q":
                #  The quit function of this class is called
                self.quit_program()
            # Otherwise, if the user types something starting with 'i'
            elif choice == "i":
                # The instructions function of this class is called
                self.instructions()
            # Otherwise the user inputted either 'e' or 'd'
            else:
                # The mode is set to 'e' or 'd' depending on user input
                self.mode = choice
                # Function called so that the encryption/decryption can begin
                self.get_message_and_shift()
    
    # Asks the user to enter the message and shift and then encrypts or decrypts based on user input from main menu
    def get_message_and_shift(self):
        self.message = input("\nEnter message: ")
        
        # Keeps asking the user to enter the shift until it is a valid integer (be it positive or negative)
        while True:
            try:
                self.shift = int(input("\nEnter shift: "))
                break
            except:
                print("You must enter a whole number!")
        
        if self.mode.startswith("e"):
            self.encrypt_message() # Function in this class to encrypt message
        else:
            self.decrypt_message() # Function in this class to decrypt message
    
    # Function to encrypt the message and print out the result
    def encrypt_message(self):
        
        # The encrypted message needs to be an empty string to ensure only the message recently typed in by the user is encrypted and stored
        self.encrypted_message = ""
        
        # Adding a bit of suspense...
        print("Encrypting...")
        time.sleep(1)

        # Loops through all the characters in the message
        for char in self.message:
            # Checks if the character is a capital letter
            if ord(char) >= 65 and ord(char) <= 90:
                # Formula to find the new index of the letter (65 is the ASCII value for 'A')
                new_index = (ord(char) + self.shift - 65) % 26 + 65
                # Converts the new index into character form
                char = chr(new_index)
            # Checks if the character is a lower-case letter
            elif ord(char) >= 97 and ord(char) <= 122:
                # Formula to find the new index of the letter (97 is the ASCII value for 'a')
                new_index = (ord(char) + self.shift - 97) % 26 + 97
                # Converts the new index into character form
                char = chr(new_index)

            # Will either add the shifted letters or the non-alphabetic characters to the "encrypted_message" attribute
            self.encrypted_message += char
        
        # Prints out the encrypted message
        print("\nEncrypted message:", self.encrypted_message)
    
    # Function to decrypt the message and print out the result
    def decrypt_message(self):
        
        # The decrypted message needs to be an empty string to ensure only the message recently typed in by the user is decrypted and stored
        self.decrypted_message = ""

        # Adding a bit of suspense...
        print("Decrypting...")
        time.sleep(1)

        # Loops through all the characters in the message
        for char in self.message:
            # Checks if the character is a capital letter
            if ord(char) >= 65 and ord(char) <= 90:
                new_index = (ord(char) - self.shift - 65) % 26 + 65
                char = chr(new_index)
            # Checks if the character is a lower-case letter
            elif ord(char) >= 97 and ord(char) <= 122:
                new_index = (ord(char) - self.shift - 97) % 26 + 97
                char = chr(new_index)
            
            # Will either add the shifted letters or the non-alphabetic characters to the "decrypted_message" attribute
            self.decrypted_message += char
        
        print("\nDecrypted message:", self.decrypted_message)

# Creates an instance of the "CaesarCipher" class
c = CaesarCipher()
# program_loop function from the "CaesarCipher" class is called through the object in previous line
c.program_loop()