/*
 * Vertex.h
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include<list>
#include "Edge.h"

class Vertex {
	int value;
	int id;
	std::list<Edge> listEdge;
	//static int id;
public:
	Vertex(int = 0, int = 0);
	virtual ~Vertex();

	void setId(int);
	void setValue(int);

	int getValue()const;
	int getId()const;

	bool operator==(const Vertex&);
};

#endif /* VERTEX_H_ */
