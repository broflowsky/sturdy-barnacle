/*
 * Edge.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "Edge.h"
#include "Vertex.h"
#include <iostream>
using std::ostream;

int Edge::counter=0;

Edge::Edge(int weight, Vertex *vertexStart, Vertex *vertexEnd){
	this->weight = weight;
	this->id=++counter;
	this->vertexStart = vertexStart;
	this->vertexEnd = vertexEnd;

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
void Edge::setStart(Vertex *start){
	if(!start)
		vertexStart = start;
	else ;//improve
}
void Edge::setEnd(Vertex *end){
	if(!end)
		vertexEnd = end;
	else ;//improve
}


int Edge::getWeight()const{
	return weight;
}
int Edge::getId()const{
	return id;
}
Vertex* Edge::getStart()const{
	return vertexStart;
}
Vertex* Edge::getEnd()const{
	return vertexEnd;
}
bool Edge::operator==(const Edge& e )const{
	return this->id == e.id;
}
Edge& Edge::operator ++(){
	++weight;
	return *this;
}
const Edge& Edge::operator=(const Edge& e){
	//NOTE
	this->id = e.id;
	this->weight = e.weight;

	delete vertexStart;
	delete vertexEnd;
	this->vertexStart = &*(e.vertexStart);
	this->vertexEnd = &*(e.vertexEnd);

	return *this;
}
ostream& operator<<(ostream& out, const Edge& e){

	out << "\nEdge id: " << e.id
		<< "\nEdge weight: "<< e.weight;


	return out;
}























