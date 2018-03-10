/*
 * GraphDirected.cpp
 *
 *  Created on: Mar 8, 2018
 *      Author: vpuyf
 */

#include "GraphDirected.h"
#include <iostream>
#include <list>
using namespace std;

GraphDirected::GraphDirected(){
	std::cout<<"Directed graph created";

}
GraphDirected::~GraphDirected() {

}
bool GraphDirected::add(Vertex &v){
	listVertex.push_back(v);
	return true;//fixme
}
bool GraphDirected::remove(Vertex &v){
	listVertex.remove(v);
	return true;//FIXme
}
bool GraphDirected::add(Edge &e){

	listEdge.push_back(e);
	return true; //fixme
}
bool GraphDirected::remove(Edge &e){
	listEdge.remove(e);
	return true;
}
bool GraphDirected::search( Vertex& v){
	for(list<Vertex>::iterator it = listVertex.begin(); it != listVertex.end();++it)
		if(*it == v)
			return true;
	return false;

}
bool GraphDirected::search( Edge& e){
	for(list<Edge>::iterator it = listEdge.begin(); it != listEdge.end();++it)
		if(*it == e)
			return true;
	return false;
}
bool GraphDirected::search(int id, Vertex&v){
	for(list<Vertex>::iterator it = listVertex.begin(); it != listVertex.end();++it)
			if(it->getId() == id){
				 v = *it;
				return true;
			}
		return false;
}
Vertex* GraphDirected::searchVertex(int value){
	for(list<Vertex>::iterator it = listVertex.begin(); it != listVertex.end();++it)
		if(it->getValue() == value)
			return &*it;
	return nullptr;
}
Edge* GraphDirected::searchEdge(int weight){
	for(list<Edge>::iterator it = listEdge.begin(); it != listEdge.end();++it)
		if(it->getWeight() == weight)
			return &*it;
	return nullptr;
}
bool GraphDirected::search(int weight, Edge&){
	//TODO
}
void GraphDirected::display(Vertex& v)const{
//TODO
}
void GraphDirected::display(Edge& e)const{
	//TODO
}
void GraphDirected::display()const{
	//TODO
}
string GraphDirected::toString()const{
	//TODO
}
Edge& GraphDirected::link(Vertex& start,Vertex& end){
	Edge* newEdge = new Edge(0,&start,&end);
	newEdge->setStart(&start);
	newEdge->setEnd(&end);

	start.add(*newEdge);
	end.add(*newEdge);
	return *newEdge;

}
bool GraphDirected::clean(){
return false;
}






















