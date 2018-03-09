/*
 * Edge.h
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#ifndef EDGE_H_
#define EDGE_H_

class Vertex;

class Edge {

	int weight;
	Vertex *vertexStart;
	Vertex *vertexEnd;
public:
	Edge(int = 0, Vertex *start = nullptr, Vertex *end = nullptr);
	virtual ~Edge();
	int getWeiht();
};

#endif /* EDGE_H_ */

