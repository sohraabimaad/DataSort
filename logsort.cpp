// This file contains the 'main' function. Program execution begins and ends there.

/*
3Red Partners Interview: C++
Name: Imaad Sohraab
Project Selection: Logsort

Instructions to run: 
	1. Please have the g++ Compiler downloaded
	2. Please open the project folder
	3. type 'make' to run the makefile
	4. please type 'gpath' followed by the names of the input files you wish to open.
		ex:
			./gpath g1.txt g2.txt
	
	This will write the sorted timestamps into a file called output.txt
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;

// A pair of pairs, first element is going to
// store value, second element index of array
// and third element index in the array.

// Pair of Pairs:
	// The 1st Element will hold the TimeStamp
	// The 1st Element of the 2nd Element will hold the file number for which the TimeStamp belongs to
	// The 2nd Element of the 2nd Element will hold the line number for which the TimeStamp belongs to
typedef pair<int, pair<int, int> > ppi;



vector<ppi> read_file(int argc, char* argv[]) {

	std::ifstream file;
	string line;


	// Declare return vector
	vector<ppi> output;

	// Create a min heap priority queue with the same amount of heap nodes as our amount of files.
	//  Every heap node has first element of an array
	priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

	// Go through each of the input files provided
	for (int i = 0; i < argc - 1; i++)
	{
		// Open the files
		file.open(argv[i + 1], std::ios::in);

		// Get Next Line
		getline(file, line);

		// Extract Timestamp
		string first_token = line.substr(line.find(" ") + 1);
		auto second_token = first_token.substr(0, 6);

		


		// Push onto PriorityQueue
		pq.push({ (stoi(second_token)), { i, 0}});

		// Close File
		file.close();
	}



	// While the PriorityQueue is not Empty
	while (pq.empty() == false) {

		// Pop the top of the queue and save it in a temporary variable Curr
		ppi curr = pq.top();
		pq.pop();

		// i -> File Number
		// j -> Line Number
		int i = curr.second.first;
		int j = curr.second.second;

		// Push top onto our output vector
		output.push_back(curr);

		// Open the file
		file.open(argv[i + 1], std::ios::in);
		
		// String used to get next line
		string myLine;

		// Keep a count of the amount of lines in the file
		int amountOfLines = 0;

		while (std::getline(file, line))
			amountOfLines++;
		file.close();


		// j has to be where you are at currently in the text
		// so if ur at the first line, j = 0...if ur at the second line, j = 1

		// Go to the j th line in the text file
		file.open(argv[i + 1], std::ios::in);
		for (int p = 0; p < j + 1; p++)
		{
			getline(file, myLine);
		}


		// Print commands
		//cout << "We're in file: " << i << endl;
		//cout << "Count of lines: " << amountOfLines << endl;
		//cout << "The value is: " << myLine << endl;
		//cout << "What j is: " << j << endl;

		// Move onto the next line
		getline(file, myLine);

		// Get Timestamp
		string first_token = myLine.substr(myLine.find(" ") + 1);
		int second_token = stoi(first_token.substr(0, 6));

		// *
		//cout << "Value we will be pushing: " << second_token << endl;
		
		// Close file
		file.close();

		// *
		//cout << endl;

		// If the next element belongs to the same file as current element, push.
		if (j + 1 < amountOfLines)
		{
			pq.push({ second_token, { i, j + 1 } });
		}
	}
	return output;
}

int main(int argc, char* argv[])
{


	// Create output file
	std::ofstream outfile("output.txt");
	outfile.close();

	// Error Checking
	if (argc < 2) {
		std::cout << "usage: cpath <first file> <second file> ... <last file>\n";
		return 0;

	}



	// Call function
	vector<ppi> g = read_file(argc, argv);

	// Variables to read in file
	int m = 0;
	string line;
	std::ifstream file;

	int count = 0;

	cout << "Merged timestap file is: " << endl;


	for (auto x : g) {
		
		// Open file #
		file.open(argv[x.second.first + 1], std::ios::in);

		// Go to line #
		for (m = 0; m < x.second.second + 1; m++)
		{
			getline(file, line);
		}

		// Close file
		file.close();

		// Print Line
		cout << line << endl;


		// Create and open a text file
		std::ofstream outfile("output.txt", std::ofstream::out | std::ofstream::app);
		outfile << line << endl;

		// Close file
		outfile.close();
	}
}