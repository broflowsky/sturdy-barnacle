/*
 * GraphDirected.h
 *
 *  Created on: Mar 8, 2018
 *      Author: vpuyf
 */

#ifndef GRAPHDIRECTED_H_
#define GRAPHDIRECTED_H_

#include "Graph.h"

class GraphDirected: public Graph {
public:

	GraphDirected();
	virtual ~GraphDirected();

	//adds one vertex; returns bool if added successfully.
	virtual bool addVertex(Vertex& v);
	//Bonus question: adds in a set of vertices; returns bool if added
	 //successfully
	//virtual bool addVertices(Vertex* vArray) = 0;
	//removes a vertex; the edges that have connection with this vertex need to
	 //be removed;
	virtual bool removeVertex(Vertex& v);
	//adds an edge; returns true if the edge is added successfully.
	virtual bool addEdge(Edge& e);
	//Bonus question: removes a set of edges; as a result, some nodes may remain
	 //as orphan.
	//virtual bool addEdges(Edge* eArray) = 0;
	// remove the edge
	virtual bool removeEdge(Edge& e);
	// returns bool if a vertex exists in a graph.
	virtual bool searchVertex(const Vertex& v);
	// returns bool if an Edge exists in a graph.
	virtual bool searchEdge(const Edge& e);
	// displays the path that contains the vertex.
	virtual void display(Vertex& v) const;
	// displays the path that contains the edge.
	virtual void display(Edge& e) const;
	// displays the whole graph with your own defined format
	virtual void display() const;
	 // converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path
	 // is separated by ';'
	virtual string toString() const;
	//remove all the vertices and edges;
	virtual bool clean();
	/*NOTE functions that we will need
	 * link(const Edge &) links an edge to
	 * link(const Vertex&)
	 *
	 * */
};

#endif /* GRAPHDIRECTED_H_ */
