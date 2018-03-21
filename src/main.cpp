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

	//Vertex *v[5];
	for (size_t i = 0; i < 5; i++)
	{
		gd->add(*new Vertex(i));
	}

	gd->add(gd->link(*gd->searchVertex(0), *gd->searchVertex(1)));
	gd->add(gd->link(*gd->searchVertex(0), *gd->searchVertex(2)));
	gd->add(gd->link(*gd->searchVertex(0), *gd->searchVertex(3)));
	gd->add(gd->link(*gd->searchVertex(3), *gd->searchVertex(4)));
	gd->add(gd->link(*gd->searchVertex(3), *gd->searchVertex(5)));
	gd->add(gd->link(*gd->searchVertex(2), *gd->searchVertex(6)));

	gd->display();
	cout << "\n\n\n";

	gd->display(*gd->searchEdge(3));
	cin.get();
return 0;
}
