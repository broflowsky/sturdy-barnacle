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
	static int counter;
	int value;
	int id;
	std::list<Edge> listEdge;
public:
	Vertex(int = 0);
	virtual ~Vertex();

	void setId(int);
	void setValue(int);

	int getValue()const;
	int getId()const;

	void add( Edge&);
	void remove( Edge&);

	bool operator==(const Vertex&);
	const Vertex& operator=(const Vertex&);
};

#endif /* VERTEX_H_ */
