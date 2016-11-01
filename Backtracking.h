#ifndef __BACKTRACKING_H__
#define __BACKTRACKING__

#include <vector>
#include "Vertex.h"

class Backtracking
{
public:
	std::vector<Vertex> vertices;
	std::vector<std::string> colorList;

	Backtracking(); // default constructor contains 4 colors
	Backtracking(int numberOfColors); // constructor with customized number of colors

	int Recursive_backtracking(int assignments);
	// implements the back tracking algorithm to color the vertices

	bool ReadInputs(std::string readLine);
	// parse in and split the string info into vertices details

private:
	int SelectMRV();
	// Selects the vertex with the fewest number of legal colors

	int GetNumberOfConstraints(int variable);
	// Returns the number of constraints to the current vertex

	int FindVertexIndex(std::string vertexName);
	// Use the given vertex name and find the verter index

	bool HasConstraint(int variable, std::string colorName);
	// Determine whether if the current vertex has constraints on color or not

	void UpdateNeighbours(int index, bool colorAvilable, std::string colorName);
	// Reset the available colors for the neighbours

	bool ForwardChecking(int index);
	// Keep track of remaining legal colors for unassigned vertices
};

#endif
