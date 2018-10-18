from tkinter import *
from tkinter import ttk
from random import randint

root = Tk()
root.title("Dice Game")
container_Frame = ttk.Frame(root, padding = 5)

# initialise required program variables
playerOne_progress_var = DoubleVar()
playerTwo_progress_var = DoubleVar()

playerOne_die1 = IntVar()
playerOne_die2 = IntVar()

playerTwo_die1 = IntVar()
playerTwo_die2 = IntVar()

playerOne_total = IntVar()
playerTwo_total = IntVar()

# define our two dice rolling functions
def PlayerOneDiceRoll():
    # check how many goes used up
    currentPos = playerOne_progress_var.get()
    if currentPos >= 5:
        return
    # update the progress bar
    playerOne_progress_var.set(currentPos + 1)
    # generate the random dice numbers - randint *WILL* seed the random number generator from the time
    playerOne_die1.set(randint(1,6))
    playerOne_die2.set(randint(1,6))
    # increment the total
    currentTotal = playerOne_total.get();
    currentTotal += playerOne_die1.get() + playerOne_die2.get()
    playerOne_total.set(currentTotal)

def PlayerTwoDiceRoll():
    # check how many goes used up
    currentPos = playerTwo_progress_var.get()
    if currentPos >= 5:
        return
    # update the progress bar
    playerTwo_progress_var.set(currentPos + 1)
    # generate the random dice numbers - randint *WILL* seed the random number generator from the time
    playerTwo_die1.set(randint(1,6))
    playerTwo_die2.set(randint(1,6))
    # increment the total
    currentTotal = playerTwo_total.get()
    currentTotal += playerTwo_die1.get() + playerTwo_die2.get()
    playerTwo_total.set(currentTotal)

# Create our controls
playerOne_Lable = ttk.Label(container_Frame, text = "Player One", width = 20, anchor = "center")
playerTwo_Lable = ttk.Label(container_Frame, text = "Player Two", width = 20, anchor = "center")

playerOne_Total = ttk.Label(container_Frame, textvariable = playerOne_total, width = 10, relief = SUNKEN, anchor = "center")
playerTwo_Total = ttk.Label(container_Frame, textvariable = playerTwo_total, width = 10, relief = SUNKEN, anchor = "center")

playerOne_Progress = ttk.Progressbar(container_Frame, orient = HORIZONTAL, length = 160, mode = "determinate", maximum = 5, variable = playerOne_progress_var)
playerTwo_Progress = ttk.Progressbar(container_Frame, orient = HORIZONTAL, length = 160, mode = "determinate", maximum = 5, variable = playerTwo_progress_var)

playerOne_Button = ttk.Button(container_Frame, text = "Roll Dice", command = PlayerOneDiceRoll)
playerTwo_Button = ttk.Button(container_Frame, text = "Roll Dice", command = PlayerTwoDiceRoll)

playerOne_Label_Die_1 = ttk.Label(container_Frame, textvariable = playerOne_die1, width = 5, relief = SUNKEN, anchor = "center")
playerOne_Label_Die_2 = ttk.Label(container_Frame, textvariable = playerOne_die2, width = 5, relief = SUNKEN, anchor = "center")

playerTwo_Label_Die_1 = ttk.Label(container_Frame, textvariable = playerTwo_die1, width = 5, relief = SUNKEN, anchor = "center")
playerTwo_Label_Die_2 = ttk.Label(container_Frame, textvariable = playerTwo_die2, width = 5, relief = SUNKEN, anchor = "center")

# Lay the controls out 
container_Frame.grid(column = 0, row = 0, sticky = (N, S, E, W))

playerOne_Lable.grid(column = 0, row = 0, columnspan = 3)
playerTwo_Lable.grid(column = 3, row = 0, columnspan = 3)

playerOne_Total.grid(column = 0, row = 1, columnspan = 3, pady = 5)
playerTwo_Total.grid(column = 3, row = 1, columnspan = 3, pady = 5)

playerOne_Progress.grid(column = 0, row = 3, columnspan = 3, pady = 5, padx = 5)
playerTwo_Progress.grid(column = 3, row = 3, columnspan = 3, pady = 5, padx = 5)

playerOne_Button.grid(column = 0, row = 2, padx = 5)
playerTwo_Button.grid(column = 3, row = 2, padx = 5)

playerOne_Label_Die_1.grid(column = 1, row = 2, pady = 5, padx = 5)
playerOne_Label_Die_2.grid(column = 2, row = 2, pady = 5, padx = 5)

playerTwo_Label_Die_1.grid(column = 4, row = 2, pady = 5, padx = 5)
playerTwo_Label_Die_2.grid(column = 5, row = 2, pady = 5, padx = 5)

# Tell Tk to enter its event loop, which is needed to make everything run.
root.mainloop()
