/*
 * Vertex.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "Vertex.h"

Vertex::Vertex(int value, int id){
	this->value=value;
	this->id=id;

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
bool Vertex::operator ==(const Vertex& v){

	return(id == v.getId());
}
