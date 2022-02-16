# TerminalPlatformer

## Plan
One buffer will store map ascii data and another buffer of the same size
will store an int value for each of those ascii data's and those ints will
decide what the ascii data will do (solid, air, etc).
To move a player throughout the world a further part of the array will be
printed (the whole array will not be printed to show the world). To Display
the world we will use a for loop, using an integer i to print certain array 
data. 1 char of the array will be printed at each time that char being
A: (if a pressed, left) int i = currentpos; i < MAP_DATA_PRINT_SIZE; i++
and a seperate integer (to print a certain char in the array) will be 
decremented
B: (if d pressed, right) int i = currentpos; i < MAP_DATA_PRINT_SIZE; i++
i will also be used to print the index in the array
The currentpos will be the array index in the bottom left corner (that is
displayed on the screen).
