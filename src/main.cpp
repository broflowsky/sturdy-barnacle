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





	try{

		GraphDirected graph1;
		GraphDirected graph2;
		GraphDirected graph3;
		GraphDirected graph4;


		for (int i = 0; i < 9; ++i)// 9 Vertices added to g, id 1 to 9
			graph1.add(*new Vertex(i));//argument is value

		for(int i =0; i<9;++i) // 9 Vertices added to graph2, id 10 to 18
			graph2.add(*new Vertex(i));
		//Adding Edges to g   -> 10 Edges added id 1 o 10
		graph1.add(graph1.link(graph1.searchVertex(1),graph1.searchVertex(2)));
		graph1.add(graph1.link(graph1.searchVertex(3),graph1.searchVertex(2)));
		graph1.add(graph1.link(graph1.searchVertex(2),graph1.searchVertex(4)));
		graph1.add(graph1.link(graph1.searchVertex(4),graph1.searchVertex(3)));
		graph1.add(graph1.link(graph1.searchVertex(2),graph1.searchVertex(6)));
		graph1.add(graph1.link(graph1.searchVertex(6),graph1.searchVertex(8)));
		graph1.add(graph1.link(graph1.searchVertex(4),graph1.searchVertex(5)));
		graph1.add(graph1.link(graph1.searchVertex(5),graph1.searchVertex(8)));
		graph1.add(graph1.link(graph1.searchVertex(5),graph1.searchVertex(9)));
		graph1.add(graph1.link(graph1.searchVertex(7),graph1.searchVertex(7)));//link to itself -> no path leading to it


		//Adding Edges to graph2  -> 10 Edges added, id 11 to 20
		graph2.add(graph2.link(graph2.searchVertex(12),graph2.searchVertex(10)));
		graph2.add(graph2.link(graph2.searchVertex(10),graph2.searchVertex(13)));
		graph2.add(graph2.link(graph2.searchVertex(10),graph2.searchVertex(11)));
		graph2.add(graph2.link(graph2.searchVertex(11),graph2.searchVertex(17)));
		graph2.add(graph2.link(graph2.searchVertex(11),graph2.searchVertex(16)));
		graph2.add(graph2.link(graph2.searchVertex(13),graph2.searchVertex(14)));
		graph2.add(graph2.link(graph2.searchVertex(14),graph2.searchVertex(12)));
		graph2.add(graph2.link(graph2.searchVertex(12),graph2.searchVertex(15)));
		graph2.add(graph2.link(graph2.searchVertex(15),graph2.searchVertex(18)));
		graph2.add(graph2.link(graph2.searchVertex(18),graph2.searchVertex(16)));



		graph3 = graph1 + graph2;//since a graph can only have one base, and that a path has to start from the base
								//there is no path to the vertices from graph2, however they exist in graph3.listVertex
		graph4 = graph2;


		cout << "\n\n\n" <<"graph1\n"
			 <<graph1
			 <<"\n\n\n"<<"graph2\n"
			 <<graph2
			 <<"\n\n\n"<<"graph3\n"
			 <<graph3
			 <<"\n\n\n"
		     <<"graph4\n"
		     <<graph4;

		for(unsigned int i = 1; i<graph1.getListEdgeSize();++i){
			cout<<"\nPaths that contains Edge "<<i<<" in  Graph g.";
			graph1.display(*graph1.searchEdge(i));
		}
		cout<<"\n\n\n\n";

		for(unsigned int i = 10; i<19;++i){
			cout<<"\nPaths that contains Edge "<<i<<" in  Graph graph2.";
			graph2.display(graph2.searchVertex(i));
		}

		cout<<"\n\nEdges info in graph1\n";
		graph1.displayEdgeInfo();
		cout<<"\n\n\n";

		graph1++;
		cout<<"\n\nEdges info in graph1 AFTER graph1++(increased weights)\n";
		graph1.displayEdgeInfo();
		cout<<"\n\n\n";

		++graph1;
		cout<<"\n\nEdges info in ggraph1 AFTER ++graph1(increased weights)\n";
		graph1.displayEdgeInfo();

		cout<<"\n\nTesting operator> :";
		if(++graph1 > ++graph2)
			cout<<"\n\ngraph1 is greater than graph2";
		else cout<<"\n\ngraph2 is greater than graph1";

		cout<<"\n\n\nTesting operator== :";
		cout<<"\n\ngraph2 and graph4 are"<<(graph2==graph4?" the same.":" NOT the same.");
	}
	//Exceptions/////////////
	catch(GraphException &e){
		cerr<<e.what();
	}
	catch(char* str){
		cerr<<str;
	}
	catch(exception&e){
		cerr<<"main "<<e.what();
	}
	//end//////
	//cin.get();

return 0;
}
















