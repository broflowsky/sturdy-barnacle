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
	bool visited;
	int value;
	int id;
	std::list<Edge> listEdge;
public:
	Vertex(int = 0);
	virtual ~Vertex();

	void setId(int);
	void setValue(int);
	void setVisited(bool);

	int getValue()const;
	int getId()const;
	bool isVisited() const {
		return visited;
	}

	void add( Edge&);
	void remove( Edge&);

	std::list<Edge>& getListEdge();

	bool operator==(const Vertex&);
	bool operator!=(const Vertex&);
	const Vertex& operator=(const Vertex&);


};

#endif /* VERTEX_H_ */
