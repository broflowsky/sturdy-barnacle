/*
 * GraphException.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: vpuyf
 */


#include "GraphException.h"
#include <exception>
using namespace std;

GraphException::GraphException(string error) : exception(){
	this->error = error;
}
string GraphException::what(){
	return error;
}
