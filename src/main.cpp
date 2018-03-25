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

	for (int i = 0; i < 9; ++i)// 9 Vertices added to g, id 1 to 9
		g.add(*new Vertex(i));//argument here is value*/

	for(int i =0; i<10;++i) // 10 Vertices added to g2, id 10 to 19
		g2.add(*new Vertex(i));


	cout<<"\n\n\n";
	try{
		//Adding Edges to g
		g.add(g.link(*g.searchVertex(1),*g.searchVertex(2)));
		g.add(g.link(*g.searchVertex(3),*g.searchVertex(2)));
		g.add(g.link(*g.searchVertex(2),*g.searchVertex(4)));
		g.add(g.link(*g.searchVertex(4),*g.searchVertex(3)));
		g.add(g.link(*g.searchVertex(2),*g.searchVertex(6)));
		g.add(g.link(*g.searchVertex(6),*g.searchVertex(8)));
		g.add(g.link(*g.searchVertex(4),*g.searchVertex(5)));
		g.add(g.link(*g.searchVertex(5),*g.searchVertex(8)));
		g.add(g.link(*g.searchVertex(5),*g.searchVertex(9)));
		g.add(g.link(*g.searchVertex(7),*g.searchVertex(7)));//link to itself -> no path leading to it

		//Adding Edges to g2
		g2.add(g2.link(*g2.searchVertex(10),*g2.searchVertex(12)));
		g2.add(g2.link(*g2.searchVertex(10),*g2.searchVertex(13)));
		g2.add(g2.link(*g2.searchVertex(11),*g2.searchVertex(10)));
		g2.add(g2.link(*g2.searchVertex(12),*g2.searchVertex(11)));
		g2.add(g2.link(*g2.searchVertex(11),*g2.searchVertex(17)));
		g2.add(g2.link(*g2.searchVertex(11),*g2.searchVertex(16)));
		g2.add(g2.link(*g2.searchVertex(16),*g2.searchVertex(12)));
		g2.add(g2.link(*g2.searchVertex(13),*g2.searchVertex(14)));
		g2.add(g2.link(*g2.searchVertex(13),*g2.searchVertex(19)));
		g2.add(g2.link(*g2.searchVertex(14),*g2.searchVertex(19)));
		g2.add(g2.link(*g2.searchVertex(14),*g2.searchVertex(15)));
		g2.add(g2.link(*g2.searchVertex(12),*g2.searchVertex(15)));
		g2.add(g2.link(*g2.searchVertex(15),*g2.searchVertex(18)));
		g2.add(g2.link(*g2.searchVertex(18),*g2.searchVertex(16)));


		//GraphDirected g3 = g; //program crashes when i do that, and then when i comment it out and try
								//to run the program again, it still crashes !! wtf




		cout<<g<<"\n\n\n"<<g2<<"\n\n\n";




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
	///cin.get();

return 0;
}
















