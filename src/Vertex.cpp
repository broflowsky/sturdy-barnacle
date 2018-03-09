/*
 * Vertex.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "Vertex.h"

int Vertex::counter = 0;
Vertex::Vertex(int value){
	this->value=value;
	this->id=++counter;

}

Vertex::~Vertex() {
	// NOTE Auto-generated destructor stub
}
void Vertex::setId(int id){
	this->id =id;
}
void Vertex::setValue(int value){
	this->value =value;
}
int Vertex::getId()const{
	return id;
}
int Vertex::getValue()const{
	return value;
}

void Vertex::add( Edge&e){
	listEdge.push_back(e);
}
void Vertex::remove( Edge&e){
	listEdge.remove(e);
}
bool Vertex::operator ==(const Vertex& v){

	return(id == v.getId());
}
const Vertex& Vertex::operator=(const Vertex&v){
	this->id = v.id;
	this->listEdge = v.listEdge;
	this->value = v.value;
	return *this;
}
