/*
 * Vertex.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "Vertex.h"
#include <iostream>
using std::ostream;

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
const std::list<Edge>& Vertex::getListEdge()const{
	return listEdge;
}
void Vertex::add( Edge&e){
	listEdge.push_back(e);
}
void Vertex::remove( Edge&e){
	listEdge.remove(e);
}
bool Vertex::operator ==(const Vertex& v)const{

	return(id == v.getId());
}
bool Vertex::operator !=(const Vertex& v)const{

	return!(Vertex::operator ==(v));
}
const Vertex& Vertex::operator=(const Vertex&v){
	this->id = v.id;
	this->listEdge.clear();
	this->listEdge = v.listEdge;
	this->value = v.value;
	return *this;
}
ostream& operator<<(ostream& out, const Vertex& v){

	out << "\nEdge id: " << v.id
		<< "\nEdge weight: "<< v.value;

	return out;
}






















