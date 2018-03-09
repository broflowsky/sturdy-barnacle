/*
 * Edge.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "Edge.h"
#include "Vertex.h"

Edge::Edge(int weight,int id, Vertex *vertexStart, Vertex *vertexEnd){
	this->weight = weight;
	this->id=id;
	this->vertexStart = vertexStart;
	this->vertexEnd=vertexEnd;

}

Edge::~Edge() {
	// NOTE Auto-generated destructor stub
}
void Edge::setId(int id){
	this->id=id;
}
void Edge::setWeight(int weight){
	this->weight=weight;
}
int Edge::getWeight()const{
	return weight;
}
int Edge::getId()const{
	return id;
}
bool Edge::operator==(const Edge& e )const{
	return this->id == e.id;

}
