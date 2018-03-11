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

using std::cout;
using std::string;
using std::list;

GraphDirected::GraphDirected(){
	std::cout<<"Directed graph created";

}
GraphDirected::~GraphDirected() {

}
bool GraphDirected::add(Vertex &v){
	try{
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

	string buffer = ";";
	string output = "";
	findPath(v,buffer);
	//NOTE i wanted to make my own streambuf buffer, but...

	//reversing the order of the path and formatting for output
	for(unsigned int i = 1; i < buffer.size();++i)
	{
		if(buffer.at(i) == ';')
		{
			for(unsigned int j = i-1; buffer.at(j) != ';'; --j)
			{//reversing the paths
			output+= buffer.at(j);
			}
			if(output.at(i-2) != v.getValue()+'0' ){
				output += '-';
				output += v.getValue() + '0';
				output += ';';
			}
			else output+= ";";
		}
	}
	if(!output.size())
		cout<<"\nThere is no path that leads to vertex " << v.getValue()<<'.';
	else cout<<endl<<output;
}
void GraphDirected::findPath(Vertex& v, string& buffer)const{
	//The path is written from the origin Vertex, going in reverse direction
	//
	for(list<Edge>::iterator it = v.getListEdge().begin(); it != v.getListEdge().end(); ++it)
	{//iterating through all edges of vertex v
		if(*(it->getEnd()) == v)
		{//testing if iterator is directed toward Vertex v

			//add vertex to path
			buffer += (v.getValue() + '0');
			buffer += '-';

			//recursive call
			//testing if the vertex on the other hand of iterator is part of path
			findPath(*it->getStart(),buffer);

			//adding missing ';'
			if(buffer.at(buffer.size()-1) != ';')
				buffer += ';';
		}
	}
	//adding missing Vertex v in buffer
	if(buffer.at(buffer.size()-1) != ';')
		buffer += v.getValue() + '0';
}
void GraphDirected::display(Edge& e)const{
	//TODO
}
void GraphDirected::display()const{

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






















