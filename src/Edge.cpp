/*
 * Edge.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "Edge.h"
#include "Vertex.h"

Edge::Edge(int weight, Vertex *vertexStart, Vertex *vertexEnd){
	this->weight = weight;
	this->vertexStart = vertexStart;
	this->vertexEnd=vertexEnd;

}

Edge::~Edge() {
	// NOTE Auto-generated destructor stub
}

