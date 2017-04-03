# Backtracking
SFU CMPT 310 Introduction to Artificial Intelligence Assignment Two: Backtracking Algorithm

Backtracking algorithm of map colouring 

- Input file name: input.txt

- Output file name: output.txt

Modify the input data in the input file and then run the executable file.
The specific format is required for the input data.
i.e, the data must be in the format given as the test data. 
Any other format of the input file may lead to failure to the program.

Expected output:
You should be looking at an output file with all vertices colored.
Each vertex is printed on one line with color next to it.

Failure output:
If the given color is to less to color entire map
i.e, using the same test data given but change the colors to 3.
It will fail, and all the vertices will print except they are all NotColored.

Running Environment:
This program is working on Windows Visual Studio 2013 X64. Any environment that is higher than this should work.

# Sample Input File
```
(10 4
(1 2 3 4 6 7 10)
(2 1 3 4 5 6)
(3 1 2)
(4 1 2)
(5 2 6)
(6 1 2 5 7 8)
(7 1 6 8 9 10)
(8 6 7 9)
(9 7 8 10)
(10 1 7 9)
)
```
