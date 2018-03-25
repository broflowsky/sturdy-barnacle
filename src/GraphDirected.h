/*
 * GraphDirected.h
 *
 *  Created on: Mar 8, 2018
 *      Author: vpuyf
 */

#ifndef GRAPHDIRECTED_H_
#define GRAPHDIRECTED_H_

#include "Graph.h"
#include <vector>
#include <iostream>
using std::cout;

class GraphDirected: public Graph {
public:

	//if no arg provided, first Vertex added becomes the base
	GraphDirected(Vertex* = nullptr);
	GraphDirected(const GraphDirected&); //

	virtual ~GraphDirected();



	//
	virtual Edge& link( Vertex& start,  Vertex& end);

	//adds one vertex; returns bool if added successfully.
	virtual bool add(Vertex& v);

	//adds an edge; returns true if the edge is added successfully.
	virtual bool add(Edge& e);

	//Bonus question: adds in a set of vertices; returns bool if added
	 //successfully
	virtual bool add(Vertex* vArray, int size);

	//Bonus question: removes a set of edges; as a result, some nodes may remain
	//as orphan.
	virtual bool add(Edge* eArray,int size);


	//removes a vertex; the edges that have connection with this vertex need to
	 //be removed;
	virtual bool remove(Vertex& v);

	// remove the edge
	virtual bool remove(Edge& e);
	// returns bool if a vertex exists in a graph.


	virtual bool search(Vertex& v);
	// returns bool if an Edge exists in a graph.
	virtual bool search(Edge& e);



	virtual bool search(int value,Vertex&);
	virtual bool search(int weight,Edge&);

	virtual Vertex& searchVertex(int value); // cannot be made const
	virtual Edge* searchEdge(int weight);	// cannot be made const


	void findPath(const Vertex&,vector<Vertex>&,bool*)const;
	// displays the path that contains the vertex.


	void displayEdgeInfo()const;
	void displayVertexInfo()const;
	virtual void display(Vertex& v) const;

	// displays the path that contains the edge.
	virtual void display(Edge& e) const;

	// displays the whole graph with your own defined format
	virtual void display() const;
	 // converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path
	 // is separated by ';'
	virtual string toString()const;
	//remove all the vertices and edges;
	virtual bool clean();

	//Operators
	//=
	GraphDirected& operator=(GraphDirected g); //cannot be made const
	//==
	bool operator==(const GraphDirected &graph)const;
	//!=
	bool operator!=(const GraphDirected&)const;
	//++g
	GraphDirected& operator++();
	//g++
	GraphDirected operator++(int);
	//+
	GraphDirected operator+(GraphDirected&);
	//>
	bool operator>(const GraphDirected &g)const;
	//<<
	friend ostream& operator<<(ostream&, const GraphDirected&);

};

#endif /* GRAPHDIRECTED_H_ */
