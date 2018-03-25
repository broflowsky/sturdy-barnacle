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
#include <sstream>
#include <string>

using std::cout;
using std::string;
using std::list;

GraphDirected::GraphDirected(Vertex* v){
	std::cout<<"\nDirected graph created.\n";
	base = v;

}
GraphDirected::GraphDirected(const GraphDirected& g){
	clean();
	base = g.base;
	listVertex.insert(listVertex.end(), g.listVertex.begin(), g.listVertex.end());
	listEdge.insert(listEdge.end(), g.listEdge.begin(),g.listEdge.end());
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
		return false;
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
		return false;
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

	stringstream buffer;

	buffer <<"\nAll Graph Paths\n\nFormat:\tBase Vertex ID - intermediate vertices IDs - Destination Vertex ID;\n\n\t";

	for(list<Vertex>::const_iterator it = listVertex.begin(); it !=listVertex.end();++it)
	{
		bool* visited = new bool[listVertex.size()+1];
		for(unsigned int i = 0; i < listVertex.size()+1;++i )
			visited[i] = false;

		vector<Vertex> path;

		findPath(*it,path,visited);

		if(!path.empty())
			for(vector<Vertex>::reverse_iterator r_it = path.rbegin(); r_it != path.rend();++r_it){
				buffer << r_it->getId();
				if(r_it->getId() == it->getId()){
					buffer << ';';
					buffer << '\n';
					buffer << '\t';
				}
				else buffer << '-';
			}
		delete visited;
		visited = nullptr;
	}
	try{
		string s = buffer.str();
		cout<<"\n\nhere\n\n"<<flush;
		return s;
	}
	catch(...){
		cerr<<"Error with stringstream";
		return "Error with stringstream";
	}
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
			delete base;
			base = nullptr;
			return true;
		}
		catch(...){
			cerr<<"Graph could not be cleaned.";
			return false;
		}
}

GraphDirected& GraphDirected::operator=(GraphDirected & graph)
{
	if(*this!= graph)
	{
		this->clean();
		for (list<Vertex>::iterator itr = graph.listVertex.begin(); itr != graph.listVertex.end(); itr++)
			this->add(*itr);
		for (list<Edge>::iterator itr = graph.listEdge.begin(); itr != graph.listEdge.end(); itr++)
			this->add(*itr);
	}
	return *this;
}

bool GraphDirected::operator==(const GraphDirected & g)const
{
	if(&g != this)
	{
		if(base == g.base)
		{
			if(listVertex.size() != g.listVertex.size() || listEdge.size() != g.listEdge.size())

				return false;

			else if(!listVertex.empty() && !listEdge.empty())
			{

				list<Vertex>::const_iterator v1 = listVertex.begin(), v2 = g.listVertex.begin();
				list<Edge>::const_iterator e1 = listEdge.begin(), e2 = g.listEdge.begin();

				do
					if(v1->getValue() != v2->getValue())
						return false;
				while(v1++ != listVertex.end() && v2++ != g.listVertex.end());

				do
					if(e1->getStart() != e2->getStart() || e1->getEnd() != e2->getEnd())
						return false;
				while(e1++ != listEdge.end() && e2++ != g.listEdge.end());
			}
		}
		else return false;
	}
	return true;
}
bool GraphDirected::operator !=(const GraphDirected& g)const{
	return !(*this==g);
}
GraphDirected& GraphDirected::operator++(){
	if(!listEdge.empty())
		for(Edge& e : listEdge)
			++e;
	return *this;
}
GraphDirected GraphDirected::operator++(int value){

	GraphDirected temp = *this;
	if(!temp.listEdge.empty())
		for(Edge& e : temp.listEdge)
			++e;
	return temp;


}
GraphDirected GraphDirected::operator+(const GraphDirected& g)const{

	GraphDirected temp = *this;
	for(Vertex& v: temp.listVertex)
		temp.add(v);
	for(Edge& e: temp.listEdge)
		temp.add(e);
	return temp;
}
bool GraphDirected::operator >(const GraphDirected& g)const{
	int sumThis, sum2 = sumThis = 0;
	for(const Edge& e : listEdge)
		sumThis += e.getWeight();
	for(const Edge& e : g.listEdge)
		sum2 += e.getWeight();
	return sumThis>sum2;
}
ostream& operator<<(ostream& out, const GraphDirected& g){
	out << "\n##############################################"
	    << "\nGraph contains "<< g.listVertex.size() <<" vertices and " << g.listEdge.size() << " edges."
		<< g.toString()
		<< "\n##############################################";

	return out;
}



















