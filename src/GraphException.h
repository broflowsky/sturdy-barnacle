/*
 * GraphException.h
 *
 *  Created on: Mar 10, 2018
 *      Author: vpuyf
 */

#ifndef GRAPHEXCEPTION_H_
#define GRAPHEXCEPTION_H_


#include <exception>
#include <string>
using namespace std;

class GraphException : public exception{
public:
	GraphException();
	string what();




};


#endif /* GRAPHEXCEPTION_H_ */
