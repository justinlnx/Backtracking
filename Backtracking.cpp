#include "Backtracking.h"

int steps = 0;

Backtracking::Backtracking()
{
	colorList.clear();
	colorList.push_back("Red");
	colorList.push_back("Blue");
	colorList.push_back("Green");
	colorList.push_back("Yellow");
}

Backtracking::Backtracking(int numberOfColors)
{
	colorList.clear();
	for (int i = 0; i < numberOfColors; i++)
	{
		if (i == 0) colorList.push_back("Red");
		else if (i == 1) colorList.push_back("Blue");
		else if (i == 2) colorList.push_back("Green");
		else if (i == 3) colorList.push_back("Yellow");
		else colorList.push_back("color_" + i);
	}
}

bool Backtracking::ReadInputs(std::string readLine)
{
	// Separate the line into a vector of string, and each represents a vertex
	std::vector<std::string> vertexList;
	std::string buf = "";
	int i = 0;
	while (i < readLine.length())
	{
		if (readLine[i] != '(' && readLine[i] != ' ' && readLine[i] != ')')
			buf += readLine[i];
		else if (buf.length() > 0)
		{
			vertexList.push_back(buf);
			buf = "";
		}
		i++;
	}

	// Set the current vertex, if exists, skip, if not, appends
	std::string vertexName = vertexList[0];
	int vertexIndex = FindVertexIndex(vertexName);
	if (vertexIndex < 0)
	{
		Vertex ver(vertexName);
		vertices.push_back(ver);
		vertexIndex = vertices.size() - 1;
	}

	// Set the current vertex's neighbours
	// If neighbour exists, update the neighbour, if not, append the neighbour
	std::string neighbourName;
	int neighbourIndex;
	for (int j = 1; j < vertexList.size(); j++)
	{
		neighbourName = vertexList[j];
		neighbourIndex = FindVertexIndex(neighbourName);
		if (neighbourIndex < 0)
		{
			Vertex ver_n(neighbourName);
			vertices.push_back(ver_n);
			neighbourIndex = vertices.size() - 1;
		}
		vertices[vertexIndex].SetNeighbor(vertices[neighbourIndex]);
	}
	return true;
}

int Backtracking::Recursive_backtracking(int assignments)
{
	if (assignments == vertices.size())
		return 1; // assignment is completed

	int variable = SelectMRV();
	for (int i = 0; i < colorList.size(); i++)
	{
		std::string currentColor = colorList[i];
		if (!HasConstraint(variable, currentColor))
		{
			vertices[variable].SetColor(currentColor);
			UpdateNeighbours(variable, false, currentColor);
			assignments++;
			steps++;

			if (ForwardChecking(variable))
			{
				int result = Recursive_backtracking(assignments);
				if (result == 1) return result;
			}
			vertices[variable].SetToNotColored();
			UpdateNeighbours(variable, true, currentColor);
			assignments--;
		}
	}
	return 0;
}

int Backtracking::SelectMRV()
{
	// Choose the vertex with minimum remaining values
	int mrv = colorList.size() + 1;
	int var = 0;
	for (int i = 0; i < vertices.size(); i++)
	{
		// select unassigned variable
		if (!vertices[i].IsColored())
		{
			// Current vertex is not colored yet
			// Find the variable with minimum legal values, ie minimum colors
			int possibleColors = vertices[i].GetPossibleColors();
			if (possibleColors < mrv)
			{
				var = i;
				mrv = possibleColors;
			}
			else if (possibleColors == mrv)
			{
				// When the degree is the same as mrv
				// Choose the vertex with largest number of neighbours
				int constraintsV = GetNumberOfConstraints(var);
				int constraintsI = GetNumberOfConstraints(i);
				if (constraintsI > constraintsV)
				{
					var = i;
					mrv = vertices[i].GetPossibleColors();
				}
			}
		}
	}
	return var;
}

int Backtracking::GetNumberOfConstraints(int vertexIndex)
{
	int counter = 0;
	std::vector<Vertex> neighbours = vertices[vertexIndex].GetNeighbours();
	for (int i = 0; i < neighbours.size(); i++)
	{
		Vertex currentNeighbour = neighbours[i];
		int neighbourVertexIndex = FindVertexIndex(currentNeighbour.GetName());
		if (!vertices[neighbourVertexIndex].IsColored()) counter++;
	}
	return counter;
}

int Backtracking::FindVertexIndex(std::string vertexName)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].GetName() == vertexName) return i;
	}
	return -1;
}

bool Backtracking::HasConstraint(int variable, std::string colorName)
{
	std::vector<Vertex> neighbours = vertices[variable].GetNeighbours();
	for (int i = 0; i < neighbours.size(); i++)
	{
		Vertex currentNeighbour = neighbours[i];
		int neighbourVertexIndex = FindVertexIndex(currentNeighbour.GetName());
		if (vertices[neighbourVertexIndex].GetColor() == colorName)
		{
			return true;
		}
	}
	return false;
}

void Backtracking::UpdateNeighbours(int index, bool colorAvailable, std::string colorName)
{
	std::vector<Vertex> neighbours = vertices[index].GetNeighbours();
	for (int i = 0; i < neighbours.size(); i++)
	{
		Vertex currentNeighbour = neighbours[i];
		int neighbourVertexIndex = FindVertexIndex(currentNeighbour.GetName());
		vertices[neighbourVertexIndex].UpdateAvailbleColors(colorAvailable, colorName);
	}
}

bool Backtracking::ForwardChecking(int index)
{
	std::vector<Vertex> neighbours = vertices[index].GetNeighbours();
	for (int i = 0; i < neighbours.size(); i++)
	{
		Vertex currentNeighbour = neighbours[i];
		int neighbourVertexIndex = FindVertexIndex(currentNeighbour.GetName());
		if (vertices[neighbourVertexIndex].GetPossibleColors() == 0)
			return false;
	}
	return true;
}
