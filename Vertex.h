#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <vector>
#include <map>

class Vertex
{
public:
	Vertex(); // Default constructor
	explicit Vertex(std::string name); // Constructor that only sets the name of the vertex

	bool IsColored() const;
	// Determine if the current vertex is colored or not

	int GetPossibleColors();
	// Get the possible colors for this current vertex

	std::vector<Vertex> GetNeighbours() const;
	// Getter function returns Neighbour member variable

	std::string GetName() const;
	// Getter function returns Name member variable

	std::string GetColor() const;
	// Getter function returns Color member variable

	void SetColor(std::string colorName);
	// Setter function sets the current vertex color

	void UpdateAvailbleColors(bool colorAvailable, std::string colorName);
	// Alter value of the given vertex's available colors

	void SetToNotColored();
	// Set the current vertex's color to be NotColored

	void SetNeighbor(Vertex vertex);
	// Set the current vertex to have a neighbour of vertex

private:
	std::string Name;
	std::string Color;
	std::vector<Vertex> Neighbours; // list of the neighbour vertices
	std::map<std::string, bool> AvailbleColors; // minimum remaining values 
};

#endif
