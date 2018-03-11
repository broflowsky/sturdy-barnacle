/*
 * GraphException.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: vpuyf
 */


#include "GraphException.h"
#include <exception>
using namespace std;

GraphException::GraphException() : exception(){

}
string GraphException::what(){
	return "\nObject not found. Invalid search input.\n";
}
