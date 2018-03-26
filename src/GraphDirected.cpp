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
	base = v;
}
GraphDirected::GraphDirected(const GraphDirected& g){
	base = g.base;
	try{
		listVertex.insert(listVertex.end(), g.listVertex.begin(), g.listVertex.end());
		listEdge.insert(listEdge.end(), g.listEdge.begin(),g.listEdge.end());
	}
	catch(exception &e){
		cerr<<"Copy constructor: "<<e.what();
	}
}
GraphDirected::~GraphDirected() {

}
bool GraphDirected::add(Vertex &v){
	try{
		if(base == nullptr)
			base = &v;

		listVertex.push_back(v);

	}
	catch(std::bad_alloc& ba){
		cerr<<"Caught bad alloc: "<< ba.what();
		return false;
	}
	catch(exception& e){
		cerr<<"add(Vertex&) "<<e.what();
		return false;
	}
	return true;
}
bool GraphDirected::remove(Vertex &v){
	try{
		listVertex.remove(v);
	}
	catch(exception& e){
		cerr<<"remove(Vertex&) "<<e.what();
		return false;
	}
	return true;
}
bool GraphDirected::add(Edge &e){
	try{
		listEdge.push_back(e);
	}
	catch(exception& e){
		cerr<<e.what();
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
	return true;
}
bool GraphDirected::remove(Edge &e){
	try{
		listEdge.remove(e);
		return true;
	}
	catch(exception& e){
		cerr<<e.what();
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
			if(it->getId() == id  ){
				 v = *it;
				return true;
			}
		return false;
}
Vertex& GraphDirected::searchVertex(int id){
	for(list<Vertex>::iterator it = listVertex.begin(); it != listVertex.end();++it)
		if(it->getId() == id )
			return *it;
	throw GraphException("Vertex not found.");
	//NOTE exception
}
Edge* GraphDirected::searchEdge(int id){
	for(list<Edge>::iterator it = listEdge.begin(); it != listEdge.end();++it)
		if(it->getId() == id)
			return &*it;
	throw GraphException("Edge not found.");
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
	bool* visited = nullptr;
	do{
		try{
			visited = new bool[listVertex.size()];
		}
		catch(exception&e){
			cerr<<e.what();
			cerr<<listVertex.size();
		}
	}while(visited == nullptr);

	for(unsigned int i = 0; i < listVertex.size();++i )
		visited[i] = false;

	vector<Vertex> path;
	path.clear();

	findPath(v,path,visited);

	if(path.empty())
		cout<<"\nNo path leading to vertex "<<v.getId()<<".";
	else{
		cout<<'\n';
		for(vector<Vertex>::reverse_iterator it = path.rbegin(); it != path.rend();++it)
			cout<<it->getId()<<(it->getId()==v.getId()?';':'-');
	}
}
void GraphDirected::findPath(const Vertex& v, vector<Vertex>& buffer, bool* visited)const{

	//The path is written from the destination Vertex, going in reverse direction
	try{
		if(base == nullptr)
			throw GraphException("invalid base vertex!");
	}catch(exception&e){
		cerr<<e.what();
		throw e;
	}

	if(v == *base)//checking if we reached base
		buffer.push_back(*base);//add base to path

	else if(!visited[v.getId() - base->getId()])//checking if we ve been here before
	{
		visited[v.getId() - base->getId()]=true;//setting the vertex as visited

		for(list<Edge>::const_iterator it = v.getListEdge().begin(); it != v.getListEdge().end(); ++it)
		{//iterating through all edges of vertex v

			if( *(it->getEnd()) == v && !visited[ (it->getStart()->getId()) - base->getId()])
			{//testing if iterator is directed toward Vertex v
				//add vertex to path
				buffer.push_back(v);

				//recursive call
				//testing if the vertex on the other hand of iterator is part of path
				findPath(*it->getStart(),buffer,visited);
			}
		}
		if(!buffer.empty())//means path does not lead back to base
			if(buffer.back() != *base)
				buffer.pop_back();
	}
	visited[v.getId() - base->getId()] = false;//freeing vertex



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
	cout<<toString();
}
void GraphDirected::displayEdgeInfo()const{
	for(const Edge& e : listEdge)
		cout<<'\n'<<e;
}
void GraphDirected::displayVertexInfo()const{
	if(base != nullptr)
		cout<<"\nBase vertex:\n"<<*base<<'\n';
	for(const Vertex& v : listVertex)
	{
		cout<<"\n##################"<<v;
		for(const Edge& e : v.getListEdge())
			cout<<"\n"<<e;
		cout<<"\n##################";
	}
}
string GraphDirected::toString()const{
	try{
		stringstream buffer;

		buffer <<"\nAll Graph Paths\n\nFormat:\tBase Vertex ID - intermediate vertices IDs - Destination Vertex ID;\n\n\t";

		if(listVertex.empty())
			throw GraphException("listVertex is empty!");

		for(list<Vertex>::const_iterator it = listVertex.begin(); it !=listVertex.end();++it)
		{
			bool* visited;

			//try-catch new operator///
			try{
				visited = new bool[listVertex.size()];
			}
			catch(GraphException& e){
				throw GraphException("bool array could not be allocated!!");
			}
			///////////////////////////

			for(unsigned int i = 0; i < listVertex.size();++i )
				visited[i] = false;

			vector<Vertex> path;
			path.clear();

			try{
				findPath(*it,path,visited);
			}
			catch(exception& e){
				cerr<<"\nerror in findPath\n"<<flush;
				throw e;
			}
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
		}

		string s = buffer.str();
		return s;
	}
	catch(exception& e){
		cerr<<"error in toString()\n"<<flush;
		throw e;
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
		catch(exception &e){
			cerr<<e.what();
			return false;
		}
}

GraphDirected& GraphDirected::operator=(GraphDirected g)
{
	if(*this!= g)
	{
		clean();
		listVertex.assign(g.listVertex.begin(),g.listVertex.end());
		listEdge.assign(g.listEdge.begin(),g.listEdge.end());
		if(base == nullptr)
			base = &*(listVertex.begin());

		if(base == nullptr)
			cerr<<"still nullptr";
	}
	return *this;
}

bool GraphDirected::operator==(const GraphDirected & g)const
{

	if(base == g.base)
	{
		if(listVertex.size() != g.listVertex.size() || listEdge.size() != g.listEdge.size()){


			return false;
		}

		else if(!listVertex.empty() && !listEdge.empty())
		{

			list<Vertex>::const_iterator v1 = listVertex.begin(), v2 = g.listVertex.begin();
			list<Edge>::const_iterator e1 = listEdge.begin(), e2 = g.listEdge.begin();

			do
				if(*v1 != *v2){

					return false;
				}
			while(v1++ != listVertex.end() && v2++ != g.listVertex.end());

			do
				if(*e1 != *e2){

					return false;
				}
			while(e1++ != listEdge.end() && e2++ != g.listEdge.end());
		}
	}
	else return false;


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

	return GraphDirected(++(*this));

}
GraphDirected GraphDirected::operator+(GraphDirected& g){

	GraphDirected temp = *this;
	for( Vertex& v: g.listVertex)
		temp.add(v);
	for( Edge& e: g.listEdge)
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



















