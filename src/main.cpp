/*
 * main.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: vpuyf
 */

#include "GraphException.h"
#include <iostream>
#include <list>
#include <exception>
#include "GraphDirected.h"
using namespace std;

int main(){

	GraphDirected g;

	for (size_t i = 0; i < 9; i++)
	{
		g.add(*new Vertex(i+1));
	}


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
	//Exceptions/////////////
	catch(char* str){
		cerr<<str;
	}
	catch(GraphException &e){
		cerr<<e.what();
	}
	catch(...){
		cerr<<"Unhandled error occured...Bad.";
	}
	//end//////
	cin.get();

return 0;
}
















