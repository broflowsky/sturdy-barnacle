/*
 * Graph.h
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "Vertex.h"
#include "Edge.h"
#include <list>
#include <string>
using namespace std;

class Graph
{
protected:

	list<Vertex> listVertex;
	list<Edge> listEdge;
	Vertex* base;
	public:
		Graph();
		virtual ~Graph();



		/////////////////////////////////////////
		virtual Edge& link( Vertex& start,  Vertex& end) = 0;


		//adds one vertex; returns bool if added successfully.
		virtual bool add(Vertex& v)=0;
		//Bonus question: adds in a set of vertices; returns bool if added
		 //successfully
		//virtual bool addVertices(Vertex* vArray) = 0;
		//removes a vertex; the edges that have connection with this vertex need to
		 //be removed;
		virtual bool remove(Vertex& v) = 0;
		//adds an edge; returns true if the edge is added successfully.
		virtual bool add(Edge& e) = 0;
		//Bonus question: removes a set of edges; as a result, some nodes may remain
		 //as orphan.
		//virtual bool addEdges(Edge* eArray) = 0;
		// remove the edge
		virtual bool remove(Edge& e) = 0;
		// returns bool if a vertex exists in a graph.
		virtual bool search(Vertex& v) = 0;
		// returns bool if an Edge exists in a graph.
		virtual bool search(Edge& e) = 0;

		//README cannot have two overload with the same parameters
		//here we could not have Vertex search(int) and Edge search(int)
		// so instead we should do has you said, hence those two functions
		virtual bool search(int id,Vertex&) = 0;
		virtual bool search(int weight,Edge&) = 0;



		// displays the path that contains the vertex.
		virtual void display(Vertex& v) const = 0;
		// displays the path that contains the edge.
		virtual void display(Edge& e) const = 0;
		// displays the whole graph with your own defined format
		virtual void display() const = 0;
		 // converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path
		 // is separated by ';'
		virtual string toString()const = 0;
		//remove all the vertices and edges;
		virtual bool clean() = 0;

		unsigned int getListEdgeSize() const;

	unsigned int getListVertexSize() const;
};
#endif /* GRAPH_H_ */
