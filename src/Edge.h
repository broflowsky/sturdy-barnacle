/*
 * Edge.h
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Vertex.h"
class Edge {

	int weight;
	Vertex *vertexStart;
	Vertex *vertexEnd;
public:
	Edge(int = 0, Vertex *start = nullptr, Vertex *end = nullptr);
	virtual ~Edge();
};

#endif /* EDGE_H_ */
/*NOTE functions that we will need
	 * link(const Vertex&)
	 *
	 * */
