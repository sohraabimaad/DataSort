We have a bunch of log files with event data in them.  The format of the files
is that each line has an event, each event is of the format:

<event type (str with no whitespace)> <UTC timestamp (int)> <type-specific data>

Each individual file is already sorted by the UTC timestamp.

Our goal is to make an application that takes multiple input files, optionally
filters by event type(s), and produces a single, UTC timestamp-ordered, output
file that only has events of the specified event types.  If multiple events from
different files occur at the same UTC timestamp, they should be ordered in the
same order the input files were specified.  If multiple events in the same file
occur at the same UTC timestamp, they should maintain their ordering from the
original file.

This application should be designed assuming the input data is too large to fit
in memory.

Example input files are provided in example-input/

An example output file is in example-output/ (this is from running the example
inputs file1.log and file2.log with no filtering).

You can choose the language you want to use.  Be sure to provide instructions on
how to run it (e.g. command line argument ordering), and if using a compiled
language, include instructions or files for how to compile it (e.g. Makefile for
C++).
