/*
 * main.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "GraphException.h"
#include <iostream>
#include <list>
<<<<<<< HEAD
#include <exception>

#include "GraphDirected.h"
=======

>>>>>>> branch 'master' of https://github.com/broflowsky/sturdy-barnacle.git
using namespace std;

int main(){
<<<<<<< HEAD
	GraphDirected g;
=======
	
	GraphDirected *gd = new GraphDirected();
>>>>>>> branch 'master' of https://github.com/broflowsky/sturdy-barnacle.git

<<<<<<< HEAD


	g.add(*new Vertex(1));
	g.add(*new Vertex(2));
	g.add(*new Vertex(3));
	g.add(*new Vertex(4));
	g.add(*new Vertex(5));
	g.add(*new Vertex(6));
	g.add(*new Vertex(7));
	g.add(*new Vertex(8));
	g.add(*new Vertex(9));
	for(int i =0; i<10;++i)
		g.add(*new Vertex(i));
	cout<<"\n\n\n";
	try{
		g.add(g.link(*g.searchVertex(1),*g.searchVertex(2)));
		g.add(g.link(*g.searchVertex(3),*g.searchVertex(2)));
		g.add(g.link(*g.searchVertex(2),*g.searchVertex(4)));
		g.add(g.link(*g.searchVertex(4),*g.searchVertex(3)));
		g.add(g.link(*g.searchVertex(2),*g.searchVertex(6)));
		g.add(g.link(*g.searchVertex(6),*g.searchVertex(8)));
		g.add(g.link(*g.searchVertex(4),*g.searchVertex(5)));
		g.add(g.link(*g.searchVertex(5),*g.searchVertex(8)));
		g.add(g.link(*g.searchVertex(9),*g.searchVertex(5)));
		g.add(g.link(*g.searchVertex(7),*g.searchVertex(7)));


		cout<<"\nDisplaying all path that contains a Vertex:\n";
		for(size_t i = 1; i <= g.getListVertexSize();++i )
		{
			cout<<"\nDisplaying path that leads to vertex " <<i<<".";
			g.display(*g.searchVertex(i));
			cout<<'\n';
		}


		cout<<"\n\n\nDisplaying all path that contains an Edge\n";

		for(size_t i = 1; i <= g.getListEdgeSize();++i )
		{
			cout<<"\nDisplaying path that contains the Edge " <<i<<".";
			g.display(*g.searchEdge(i));
			cout<<'\n';
		}

		cout<<g.toString();

	}
	catch(char* str){
		cerr<<str;
	}
	catch(GraphException &e){
		cerr<<e.what();
	}
	catch(...){
		cerr<<"Unhandled error occured...Bad.";
	}


=======
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
>>>>>>> branch 'master' of https://github.com/broflowsky/sturdy-barnacle.git
return 0;
}
















