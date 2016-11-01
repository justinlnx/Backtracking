#include "Vertex.h"
#include <vector>
#define NOT_COLORED "NotColored"

Vertex::Vertex()
{
}

Vertex::Vertex(std::string name)
{
	Name = name;
	Color = NOT_COLORED;
	AvailbleColors["Red"] = true;
	AvailbleColors["Blue"] = true;
	AvailbleColors["Green"] = true;
	AvailbleColors["Yellow"] = true;
}

bool Vertex::IsColored() const
{
	return Color != NOT_COLORED;
}

int Vertex::GetPossibleColors()
{
	int counter = 0;
	for (std::map<std::string, bool>::iterator i = AvailbleColors.begin(); i != AvailbleColors.end(); i++)
	{
		if (i->second) counter++;
	}
	return counter;
}

std::vector<Vertex> Vertex::GetNeighbours() const
{
	return Neighbours;
}

std::string Vertex::GetName() const
{
	return Name;
}

std::string Vertex::GetColor() const
{
	return Color;
}

void Vertex::SetColor(std::string colorName)
{
	Color = colorName;
}

void Vertex::UpdateAvailbleColors(bool colorAvailable, std::string colorName)
{
	AvailbleColors[colorName] = colorAvailable;
}

void Vertex::SetToNotColored()
{
	Color = NOT_COLORED;
}

void Vertex::SetNeighbor(Vertex vertex)
{
	Neighbours.push_back(vertex);
}
