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
	GraphDirected g2;
	GraphDirected g3;



	try{

		for (int i = 0; i < 9; ++i)// 9 Vertices added to g, id 1 to 9
			g.add(*new Vertex(i));//argument is value

		for(int i =0; i<9;++i) // 9 Vertices added to g2, id 10 to 18
			g2.add(*new Vertex(i));
		//Adding Edges to g
		g.add(g.link(g.searchVertex(1),g.searchVertex(2)));
		g.add(g.link(g.searchVertex(3),g.searchVertex(2)));
		g.add(g.link(g.searchVertex(2),g.searchVertex(4)));
		g.add(g.link(g.searchVertex(4),g.searchVertex(3)));
		g.add(g.link(g.searchVertex(2),g.searchVertex(6)));
		g.add(g.link(g.searchVertex(6),g.searchVertex(8)));
		g.add(g.link(g.searchVertex(4),g.searchVertex(5)));
		g.add(g.link(g.searchVertex(5),g.searchVertex(8)));
		g.add(g.link(g.searchVertex(5),g.searchVertex(9)));
		g.add(g.link(g.searchVertex(7),g.searchVertex(7)));//link to itself -> no path leading to it


		//Adding Edges to g2
		g2.add(g2.link(g2.searchVertex(12),g2.searchVertex(10)));
		g2.add(g2.link(g2.searchVertex(10),g2.searchVertex(13)));
		g2.add(g2.link(g2.searchVertex(11),g2.searchVertex(10)));
		g2.add(g2.link(g2.searchVertex(11),g2.searchVertex(17)));
		g2.add(g2.link(g2.searchVertex(11),g2.searchVertex(16)));
		g2.add(g2.link(g2.searchVertex(13),g2.searchVertex(14)));
		g2.add(g2.link(g2.searchVertex(14),g2.searchVertex(12)));
		g2.add(g2.link(g2.searchVertex(12),g2.searchVertex(15)));
		g2.add(g2.link(g2.searchVertex(15),g2.searchVertex(18)));
		g2.add(g2.link(g2.searchVertex(18),g2.searchVertex(16)));


		g3 = g + g2;//since a graph can only have one base, and that a path has to start from the base
					//there is no path to the vertices from g2, however they exist in g3.listVertex



		for(unsigned int i = 1; i<g.getListVertexSize()+1;++i){
			cout<<"\nPaths leading to Vertex "<<i;
			g.display(g.searchVertex(i));
		}

		cout<<"\n\n\n"<<g<<"\n\n\n"<<g2<<"\n\n\n"<<g3;

		g.displayEdgeInfo();
		cout<<"\n\n\n";
		g++;
		g.displayEdgeInfo();
		++g;
		cout<<"\n\n\n";
		g.displayEdgeInfo();

		if(++g > ++g2)
			cout<<"\n\ng is greater than g2";
		else cout<<"\n\ng2 is greater than g";

	}
	//Exceptions/////////////
	catch(GraphException &e){
			cerr<<e.what();
	}
	catch(char* str){
		cerr<<str;
	}
	catch(exception&e){
		cerr<<e.what();
	}
	//end//////
	//cin.get();

return 0;
}
















