readme.md

Authors: Hannah Tippin, Leonardo Garcia, Brandon Steege

COSC 4010

May 12, 2020


The development of this program took place in the Community Edition of Visual Studio 2019. To run this program, the user will need to first clone the repository in Visual Studio 2019. No external libraries were used. The program must be ran with the standard debugger in Visual Studio 2019. 

If the repository is cloned correctly, then the Default.txt file should be located in the source files directory of the project folders. Defaults.txt must always be in that directory, or the program will not function correctly as the code searches for the file in that specific directory.

When the program is initially ran, the console will prompt the user to either change the default local variables or not. If the user inputs y or Y, then a few predetermined variables will be changed. The program will detect this, and reset them based on the internally stored default values. 

Defaults.txt stores all of the predetermined default values of the game variables. The encoded locally stored default values are written to the file. These values are used to generate a string that can be used to determine whether or not the values in the file have changed. The program reads in the data in Defaults.txt as a string. This string is compared to the aforementioned string. If these two strings are not equivalent to one another, then the program recognizes that the Defaults.txt file has been tampered with and will write the original default values to the file. 
