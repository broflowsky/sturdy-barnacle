/*
 * GraphDirected.cpp
 *
 *  Created on: Mar 8, 2018
 *      Author: vpuyf
 */

#include "GraphDirected.h"

GraphDirected::GraphDirected(){


}

GraphDirected::~GraphDirected() {

}
bool GraphDirected::addVertex(Vertex &v){
	listVertex.push_back(v);
	return true;
}
bool GraphDirected::removeVertex(Vertex &v){
	listVertex.remove(v);
	return true;
}
bool GraphDirected::addEdge(Edge &v){
	listEdge.push_back(v);
	return true;
}
bool GraphDirected::removeEdge(Edge &v){
	listEdge.remove(v);
	return true;//NOTE idk why that function is returning a bool
}
