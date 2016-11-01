#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Backtracking.h"
using namespace std;

int main()
{
	int numOfVerices = 0;
	int numOfColors = 0;
	ifstream inf("input.txt", ifstream::in);
	ofstream ouf("output.txt", ofstream::out);

	if (!inf)
	{
		ouf << "Input error! Unable to read the input file. Terminating program!" << endl;
		return 0;
	}

	// Get the first line info, numOfVertices, numOfColors
	string info;
	getline(inf, info);
	int separator = info.find(" "); 
	int vLength = separator - 1;
	int cLength = info.size() - separator;
	string v = info.substr(1, vLength);
	string c = info.substr(separator + 1, cLength);

	istringstream convert_v(v);
	convert_v >> numOfVerices;
	istringstream convert_c(c);
	convert_c >> numOfColors;

	// Initialize Backtracking algorithm number of colors given in context
	Backtracking backtracking;
	if (numOfColors != 4)
	{
		backtracking = Backtracking(numOfColors);
	}
	else
	{
		backtracking = Backtracking();
	}

	// Initialize Backtracking algorithm vertices given in the context
	string vertexInfo;
	while (getline(inf, vertexInfo))
	{
		if (vertexInfo == ")") break;
		if (!backtracking.ReadInputs(vertexInfo))
		{
			ouf << "Error occurred in input file! Make sure your input file is correct and try again. Terminating program" << endl;
			return 0;
		}
	}

	// Check for edge conditions
	if (numOfVerices != backtracking.vertices.size())
	{
		ouf << "Number of vertices specified in the first and the actual number of vertices are not equal. Terminating program" << endl;
		return 0;
	}

	backtracking.Recursive_backtracking(0);

	for (int i = 0; i < backtracking.vertices.size(); i++)
	{
		string vName = backtracking.vertices[i].GetName();
		string vColor = backtracking.vertices[i].GetColor();
		ouf << vName << ": " << vColor << ".\n";
	}

	inf.close();
	ouf.close();
	return 0;
}
