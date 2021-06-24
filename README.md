# DataSort
k Timestamps were provided with n Number of lines. Objective of this project was to sort the Timestamps with lowest Time and Space Complexity,


The goal is to make an application that takes multiple input files, and produces a single, UTC timestamp-ordered, output
file that only has events of the specified event types.  If multiple events from
different files occur at the same UTC timestamp, they should be ordered in the
same order the input files were specified.  If multiple events in the same file
occur at the same UTC timestamp, they should maintain their ordering from the
original file.

This application is designed assuming the input data is too large to fit
in memory.

    To achieve this, I used a minHeap to store each of the timestamps along with
    it's file # and line #, which avoids having to store everything else in the memory as
    we can just access it using the file # and line #. The space complexity would be O(k) where
    k is the # of files.
    
    I also wanted to keep as low runtime as possible, and worse cause scenario this runtime is
    O( n * k * log k) roughly, where k is the # of files and n is the amount of lines. 

Instructions to run: 
	1. Please have the g++ Compiler downloaded
	2. Please open the project folder
	3. type 'make' to run the makefile
	4. please type 'gpath' followed by the names of the input files you wish to open.
		ex:
			./gpath g1.txt g2.txt
	
	This will write the sorted timestamps into a file called output.txt
