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
	
	list<Edge*> listGraph;
	list<Edge*> subset;

	Edge *e0 = new Edge(0);
	Edge *e1 = new Edge(1);
	Edge *e2 = new Edge(2);
	Edge *e3 = new Edge(3);
	Edge *e4 = new Edge(4);

	listGraph.push_back(e0);
	listGraph.push_back(e1);
	listGraph.push_back(e2);
	listGraph.push_back(e3);
	listGraph.push_back(e4);

	//subset.push_back(*e0);
	subset.push_back(e1);
	subset.push_back(e2);
	subset.push_back(e3);
	//subset.push_back(*e4);

	for(list<Edge*>::iterator it = listGraph.begin(); it != listGraph.end();++it){
	cout<<(*it)->getWeiht()<<'\n';
	}
	cout<<'\n';
	for(list<Edge*>::iterator it = subset.begin(); it != subset.end();++it){
		cout<<(*it)->getWeiht()<<'\n';
	}
	list<Edge*>::iterator it = subset.begin();

	++it++;
	delete e2;
	cout<<"\n\n\n";
	for(list<Edge*>::iterator it = listGraph.begin(); it != listGraph.end();++it){
		cout<<(*it)->getWeiht()<<'\n';
		}
		cout<<'\n';
	for(list<Edge*>::iterator it = subset.begin(); it != subset.end();++it){
			cout<<(*it)->getWeiht()<<'\n';
		}
	cout<<"all good";
return 0;
}
