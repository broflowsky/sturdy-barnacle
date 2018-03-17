/*
 * GraphDirected.cpp
 *
 *  Created on: Mar 8, 2018
 *      Author: vpuyf
 */

#include "GraphDirected.h"

#include "GraphException.h"

#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

using std::cout;
using std::string;
using std::list;

GraphDirected::GraphDirected(Vertex* v){
	std::cout<<"\nDirected graph created.\n";
	base = v;

}
GraphDirected::~GraphDirected() {

}
bool GraphDirected::add(Vertex &v){
	try{
		if(base == nullptr)
			base = &v;
		listVertex.push_back(v);
		return true;//fixme
	}
	catch(...){
		cerr<<"\nVertex could not be added.\n";
		return false;
	}
}
bool GraphDirected::remove(Vertex &v){
	try{
		listVertex.remove(v);
		return true;//FIXme
	}
	catch(...){
		std::cerr<<"\nVertex could not be removed.\n";
		return false;
	}
}
bool GraphDirected::add(Edge &e){
	try{
		listEdge.push_back(e);
		return true; //fixme
	}
	catch(...){
		std::cerr<<"\nEdge could not be added.\n";
		return false;
	}
}
bool GraphDirected::remove(Edge &e){
	try{
		listEdge.remove(e);
		return true;
	}
	catch(...){
		cerr<<"Edge could not be removed.";
		return false;
	}
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
	throw GraphException();//NOTE exception
}
Edge* GraphDirected::searchEdge(int weight){
	for(list<Edge>::iterator it = listEdge.begin(); it != listEdge.end();++it)
		if(it->getWeight() == weight)
			return &*it;
	throw GraphException();
}
bool GraphDirected::search(int weight, Edge& e){
	for(list<Edge>::iterator it = listEdge.begin(); it != listEdge.end();++it)
		if(it->getId() == weight){
			 e = *it;
			return true;
		}
	return false;
}
void GraphDirected::display(Vertex& v)const{
	//finds the shortest path to vertex

	vector<Vertex> path;
	findPath(v,path);
	cout<<'\n';
	for(vector<Vertex>::iterator it = path.begin(); it != path.end();++it)
		cout<<it->getId()<<'\0';

}
void GraphDirected::findPath(Vertex& v, vector<Vertex>& buffer)const{
	//The path is written from the destination Vertex, going in reverse direction
	//
	v.setVisited(true);
	if(v == *base)
		buffer.push_back(*base);
	else
	{
		for(list<Edge>::iterator it = v.getListEdge().begin(); it != v.getListEdge().end(); ++it)
		{//iterating through all edges of vertex v
			if(*(it->getEnd()) == v && it->getStart()->isVisited() == false)
			{//testing if iterator is directed toward Vertex v

				//add vertex to path
				buffer.push_back(v);

				//recursive call
				//testing if the vertex on the other hand of iterator is part of path
				findPath(*it->getStart(),buffer);
			}
		}
		if(buffer.back() != *base)
			buffer.pop_back();

	}
	v.setVisited(false);

}

void GraphDirected::display()const{




}
void GraphDirected::display(Edge& e)const{
	//TODO
}
string GraphDirected::toString()const{
	return "fuck";
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






















