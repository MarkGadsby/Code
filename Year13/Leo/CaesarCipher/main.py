#imports
import caesar_cipher_encrypt as e
import caesar_cipher_decrypt as d
import os
from time import sleep

#title
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
title = os.path.join(THIS_FOLDER, 'title.txt')
title = open(title, "r")
titleData = title.readlines()
for i in range(0,len(titleData)-1):
    print(titleData[i].split("\n")[0])

sleep(3.5)
os. system('cls')

num1 = 0
num2 = 1
while num1 < num2:
    DorE = input("do you want to encrpyt or decrpyt (e or d): ")
    DorE.lower()
    if DorE == "e":
        e.encrpyt()
    if DorE == "d":
        d.decrpyt()
    else: 
        print("that is not e or d")
        num1 += 1
        num2 += 1