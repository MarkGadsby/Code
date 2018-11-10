from tkinter import *
from tkinter import ttk
import serial
import struct

root = Tk()
root.title("Cube Snake Control")
container_Frame = ttk.Frame(root, padding = 5)

# define out control variables
XPos = IntVar(0)
YPos = IntVar(0)
ZPos = IntVar(0)

# define global position variables
X = 3
Y = 3
Z = 3
arduino = serial.Serial('/dev/ttyACM0')

# define our button traps
def UpButtonPress(*args):
	global Z,X,Y
	if (IsHorizontalAxle()):
		Y += 1	
	elif (Z == 0 and Y < 3):
		Y += 1
	elif (Y == 3 and Z < 3):
		Z += 1
	elif (Z == 3 and Y > 0):
		Y -= 1
	elif (Y == 0 and Z > 0):
		Z -= 1
	SetDisplayVaribles()
	container_Frame.focus_set()

def DownButtonPress(*args):
	global Z,X,Y
	if (IsHorizontalAxle()):
		Y -= 1	
	elif (Y == 0 and Z < 3):
		Z += 1
	elif (Z == 3 and Y < 3):
		Y += 1
	elif (Y == 3 and Z > 0):
		Z -= 1
	elif (Z == 0 and Y > 0):
		Y -= 1
	SetDisplayVaribles()
	container_Frame.focus_set()

def LeftButtonPress(*args):
	global Z,X,Y
	if (IsVerticalAxle()):
		X += 1
	elif (X == 0 and Z < 3):
		Z += 1
	elif (Z == 3 and X < 3):
		X += 1
	elif (X == 3 and Z > 0):
		Z -= 1
	elif (Z == 0 and X > 0):
		X -= 1
	SetDisplayVaribles()
	container_Frame.focus_set()

def RightButtonPress(*args):
	global Z,X,Y
	if (IsVerticalAxle()):
		X -= 1
	elif (Z == 0 and X < 3):
		X += 1
	elif (X == 3 and Z < 3):
		Z += 1
	elif (Z == 3 and X > 0):
		X -= 1
	elif (X == 0 and Z > 0):
		Z -= 1
	SetDisplayVaribles()
	container_Frame.focus_set()

def SetDisplayVaribles():
	XPos.set(X)
	YPos.set(Y)
	ZPos.set(Z)
	SendToArduino()

def SendToArduino():
        global arduino
        print(arduino.name)
        valueToSend = ((Z * 16) + (Y * 4) + X)
        print(valueToSend)
        arduino.write(chr(valueToSend).encode())
	
def IsVerticalAxle():
	if ((Y == 0 or Y == 3) and
		(Z > 0 and Z < 3) and	
		(X > 0 and X < 3)):
		return True
	else:
		return False	

def IsHorizontalAxle():
	if ((X == 0 or X == 3) and
		(Z > 0 and Z < 3) and	
		(Y > 0 and Y < 3)):
		return True
	else:
		return False	

# Create our controls
XPos_Name_Lable = ttk.Label(container_Frame, text = "X Position", width = 10, anchor = "center")
YPos_Name_Lable = ttk.Label(container_Frame, text = "Y Position", width = 10, anchor = "center")
ZPos_Name_Lable = ttk.Label(container_Frame, text = "Z Position", width = 10, anchor = "center")

XPos_Lable = ttk.Label(container_Frame, textvariable = XPos, width = 5, relief = SUNKEN, anchor = "center")
YPos_Lable = ttk.Label(container_Frame, textvariable = YPos, width = 5, relief = SUNKEN, anchor = "center")
ZPos_Lable = ttk.Label(container_Frame, textvariable = ZPos, width = 5, relief = SUNKEN, anchor = "center")

UpButton = ttk.Button(container_Frame, text = "Up", command = UpButtonPress)
DownButton = ttk.Button(container_Frame, text = "Down", command = DownButtonPress)
LeftButton = ttk.Button(container_Frame, text = "Left", command = LeftButtonPress)
RightButton = ttk.Button(container_Frame, text = "Right", command = RightButtonPress)

# Lay the controls out 
container_Frame.grid(column = 0, row = 0, sticky = (N, S, E, W))

XPos_Name_Lable.grid(column = 0, row = 0, pady = 5)
YPos_Name_Lable.grid(column = 1, row = 0)
ZPos_Name_Lable.grid(column = 2, row = 0)

XPos_Lable.grid(column = 0, row = 1, pady = 5)
YPos_Lable.grid(column = 1, row = 1)
ZPos_Lable.grid(column = 2, row = 1)

LeftButton.grid(column = 0, row = 2, rowspan = 2, pady = 5, padx = 5)
UpButton.grid(column = 1, row = 2, pady = 5, padx = 5)
DownButton.grid(column = 1, row = 3, pady = 5, padx = 5)
RightButton.grid(column = 2, row = 2, rowspan = 2, pady = 5, padx = 5)

# bind in the key presses
container_Frame.bind('<Up>', UpButtonPress)
container_Frame.bind('<Down>', DownButtonPress)
container_Frame.bind('<Left>', LeftButtonPress)
container_Frame.bind('<Right>', RightButtonPress)
container_Frame.focus_set()

# Tell Tk to enter its event loop, which is needed to make everything run.
root.mainloop()
arduino.close()

