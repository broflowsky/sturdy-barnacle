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
#include <iostream>

class Vertex {
	static int counter;
	//bool visited;
	//NOTE using an array of bool in findPath instead of a bool data member, so we can keep the toString() and display() constant!
	int value;
	int id;
	std::list<Edge> listEdge;
public:
	Vertex(int = 0);
	Vertex(const Vertex&);
	virtual ~Vertex();

	void setId(int);
	void setValue(int);
	void setVisited(bool);

	int getValue()const;
	int getId()const;
	void add( Edge&);
	void remove( Edge&);

	const std::list<Edge>& getListEdge()const;

	bool operator==(const Vertex&)const;
	bool operator!=(const Vertex&)const;
	const Vertex& operator=(const Vertex&);
	friend std::ostream& operator<<(std::ostream&, const Vertex&);


};

#endif /* VERTEX_H_ */
