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

	}
	catch(...){
		cerr<<"\nVertex could not be added.\n";
		return false;
	}
	return true;
}
bool GraphDirected::remove(Vertex &v){
	try{
		listVertex.remove(v);
	}
	catch(...){
		std::cerr<<"\nVertex could not be removed.\n";
		return false;
	}
	return true;
}
bool GraphDirected::add(Edge &e){
	try{
		listEdge.push_back(e);
	}
	catch(...){
		std::cerr<<"\nEdge could not be added.\n";
		return false;
	}
	return true;
}
bool GraphDirected::add(Edge *e, int size){
	try{
		if(!size)
			throw invalid_argument("Invalid Size");
		for(int i =0 ; i < size; ++i)
			listEdge.push_back(e[i]);

	}
	catch(exception&e){
		cerr<<e.what();
	}
	catch(...){
		std::cerr<<"\nEdge could not be added.\n";
		return false;
	}
	return true;
}
bool GraphDirected::add(Vertex *v, int size){
	try{
		if(!size)
			throw invalid_argument("Invalid Size");

		for(int i =0 ; i < size; ++i)
			listVertex.push_back(v[i]);

	}
	catch(exception&e){
		cerr<<e.what();
	}
	catch(...){
		std::cerr<<"\nEdge could not be added.\n";
		return false;
	}
	return true;
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
	bool* visited = new bool[this->getListVertexSize()+1];

	for(unsigned int i = 0; i < this->getListVertexSize()+1;++i )
		visited[i] = false;

	vector<Vertex> path;

	findPath(v,path,visited);
	cout<<'\n';

	if(path.empty())
		cout<<"\nNo path leading to vertex "<<v.getId()<<".";
	else
		for(vector<Vertex>::reverse_iterator it = path.rbegin(); it != path.rend();++it)
			cout<<it->getId()<<(it->getId()==v.getId()?';':'-');
}
void GraphDirected::findPath(const Vertex& v, vector<Vertex>& buffer, bool* visited)const{
	//The path is written from the destination Vertex, going in reverse direction

	if(v == *base)//checking if we reached base

		buffer.push_back(*base);//add base to path

	else if(!visited[v.getId()])//checking if we ve been here before
	{
		visited[v.getId()]=true;//setting the vertex as visited

		for(list<Edge>::const_iterator it = v.getListEdge().begin(); it != v.getListEdge().end(); ++it)
		{//iterating through all edges of vertex v

			if(*(it->getEnd()) == v && !visited[it->getStart()->getId()])
			{//testing if iterator is directed toward Vertex v
				//add vertex to path
				buffer.push_back(v);

				//recursive call
				//testing if the vertex on the other hand of iterator is part of path
				findPath(*it->getStart(),buffer,visited);
			}
		}
		if(!buffer.empty() && buffer.back() != *base)

			buffer.pop_back();
	}
	visited[v.getId()]=false;//freeing vertex
}
void GraphDirected::display(Edge& e)const{
	//output format
	//prints the series of vertices from the base vertex to the vertex that Edge e points to
	bool* visited = new bool[this->getListVertexSize()+1];

	for(unsigned int i = 0; i < this->getListVertexSize()+1;++i )
		visited[i] = false;

	vector<Vertex> path;

	findPath(*e.getStart(),path,visited);
	cout<<'\n';

	if(path.empty())
		cout<<"No path contains Edge "<<e.getId()<<".";
	else
		for(vector<Vertex>::reverse_iterator it = path.rbegin(); it != path.rend();++it)
			cout<<it->getId()<<'-';

	if( !path.empty() && path.begin()->getId() == e.getStart()->getId())
		cout<<e.getEnd()->getId()<<';';

}
void GraphDirected::display()const{
	cout<<this->toString();
}
string GraphDirected::toString()const{
	string graph = "\nAll Graph Paths\n\nFormat:\tBase Vertex ID - intermediate vertices IDs - Destination Vertex ID;\n\n\t";

	for(list<Vertex>::const_iterator it = listVertex.begin(); it !=listVertex.end();++it)
	{
		bool* visited = new bool[this->getListVertexSize()+1];
		for(unsigned int i = 0; i < this->getListVertexSize()+1;++i )
			visited[i] = false;

		vector<Vertex> path;

		findPath(*it,path,visited);

		if(!path.empty())
			for(vector<Vertex>::reverse_iterator r_it = path.rbegin(); r_it != path.rend();++r_it){
				graph += r_it->getId() + '0';
				if(r_it->getId()==it->getId()){
					graph += ';';
					graph += '\n';
					graph += '\t';
				}
				else graph+='-';
			}
		delete visited;
	}
	return graph;
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
	try{
			listEdge.clear();
			listVertex.clear();
			return true;
		}
		catch(...){
			cerr<<"Graph could not be cleaned.";
			return false;
		}
}

GraphDirected GraphDirected::operator=(const GraphDirected & graph)
{
	GraphDirected temp;

	
	for (list<Vertex>::iterator itr = listVertex.begin(); itr != listVertex.end(); itr++)
	{
		temp.add(*itr);
	}
	for (list<Edge>::iterator itr = listEdge.begin() = listEdge.begin(); itr != listEdge.end(); itr++)
	{
		temp.add(*itr);
	}

	//return *new GraphDirected(graph);					//is this it? just create new graph with copy constructor
}

bool GraphDirected::operator==(GraphDirected & g)
{
	if (g.getListEdgeSize() != this->getListEdgeSize() && g.getListVertexSize() != this->getListVertexSize())		//Compare sizes of two lists
	{
		return false;
	}
	for (size_t i = 1; i < this->getListEdgeSize(); i++)														//Inspect each element in each list
	{
			
		if (this->searchVertex(i)->getValue() != g.searchVertex(i)->getValue())									//Compare values of verties
			return false;
		else if (this->searchEdge(i)->getEnd() != g.searchEdge(i)->getEnd())									//Compare end vertices in edges
			return false;
		else if (this->searchEdge(i)->getStart() != g.searchEdge(i)->getStart())								//Compare start vertices in edges
			return false;
		else if (this->searchEdge(i)->getWeight() != g.searchEdge(i)->getWeight())								//Compare weight of edges
			return false;

	}
	return true;																								//If no conflicts were found return true
}






















