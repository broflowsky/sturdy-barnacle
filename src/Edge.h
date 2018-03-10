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
	static int counter;
	int id;
	int weight;
	Vertex *vertexStart;
	Vertex *vertexEnd;
public:
	Edge(int = 0, Vertex *start = nullptr, Vertex *end = nullptr);
	virtual ~Edge();

	void setWeight(int);
	void setId(int);
	void setStart(Vertex*);
	void setEnd(Vertex*);

	int getWeight()const;
	int getId()const;
	Vertex* getStart()const;
	Vertex* getEnd()const;



	bool operator==(const Edge&)const;
	const Edge& operator=(const Edge&);
};

#endif /* EDGE_H_ */

