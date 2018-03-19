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
Vertex* GraphDirected::searchVertex(int id){
	for(list<Vertex>::iterator it = listVertex.begin(); it != listVertex.end();++it)
		if(it->getId() == id)
			return &*it;
	throw GraphException();//NOTE exception
}
Edge* GraphDirected::searchEdge(int id){
	for(list<Edge>::iterator it = listEdge.begin(); it != listEdge.end();++it)
		if(it->getId() == id)
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
	if(path.empty())
		cout<<"\nNo path leading to vertex "<<v.getId()<<".";
	else
		for(vector<Vertex>::reverse_iterator it = path.rbegin(); it != path.rend();++it)
			cout<<it->getId()<<(it->getId()==v.getId()?';':'-');

}
void GraphDirected::findPath(Vertex& v, vector<Vertex>& buffer)const{
	//The path is written from the destination Vertex, going in reverse direction
	//
	if(v == *base)//checking if we reached base
		buffer.push_back(*base);//add base to path
	else if(!v.isVisited())//checking if we ve been here before
	{
		v.setVisited(true);//setting the vertex as visited
		for(list<Edge>::iterator it = v.getListEdge().begin(); it != v.getListEdge().end(); ++it)
		{//iterating through all edges of vertex v
			if(*(it->getEnd()) == v && !it->getStart()->isVisited() )
			{//testing if iterator is directed toward Vertex v

				//add vertex to path
				buffer.push_back(v);

				//recursive call
				//testing if the vertex on the other hand of iterator is part of path
				findPath(*it->getStart(),buffer);
			}
		}
		if(!buffer.empty() && buffer.back() != *base)
			buffer.pop_back();

	}
	v.setVisited(false);

}
void GraphDirected::display(Edge& e)const{
	//output format
	//prints the series of vertices from the base vertex to the vertex that Edge e points to
	vector<Vertex> path;
	findPath(*e.getStart(),path);
		cout<<'\n';
	if(path.empty())
		cout<<"No path contains Edge "<<e.getId()<<".";
	else
		for(vector<Vertex>::reverse_iterator it = path.rbegin(); it != path.rend();++it)
			cout<<it->getId()<<'-';

	if( !path.empty() && path.begin()->getId()== e.getStart()->getId())
		cout<<e.getEnd()->getId()<<';';

}
void GraphDirected::display()const{
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






















