/*
 * main.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "GraphDirected.h"
#include <iostream>
#include <list>

using namespace std;

int main(){
	
	GraphDirected *gd = new GraphDirected();

	Vertex *v[5];
	for (size_t i = 0; i < 5; i++)
	{
		v[i] = new Vertex(1);
	}
	
	for (size_t i = 0; i < 5; i++)
	{
		gd->add(*v[i]);
	}
	
	//gd->display();
	Edge *e[6];
	/*Invard
	e[0] = new Edge(2, v[1], v[0]);
	e[1] = new Edge(2, v[2], v[0]);
	e[2] = new Edge(2, v[3], v[0]);
	e[3] = new Edge(2, v[4], v[3]);
	e[4] = new Edge(2, v[5], v[3]);
	e[5] = new Edge(2, v[6], v[2]);*/
	/*Outward*/
	e[0] = new Edge(2, v[0], v[1]);
	e[1] = new Edge(2, v[0], v[2]);
	e[2] = new Edge(2, v[0], v[3]);
	e[3] = new Edge(2, v[3], v[4]);
	e[4] = new Edge(2, v[3], v[5]);
	e[5] = new Edge(2, v[2], v[6]);
	gd->add(*e, 6);
	gd->display();
	cout << "\n\n\n";
	gd->display(*e[4]);
	cin.get();
return 0;
}
