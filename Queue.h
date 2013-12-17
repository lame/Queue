#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
namespace cop4530{

template <typename T>
class Queue{

public:
	Queue();				//Default constructor
	~Queue();				//default destructor
	Queue(const Queue &rhs);		//copy constructor
	Queue& operator=(const Queue &rhs);	//copy assignment operator
	Queue& operator[](int index);		//copy assignment operator
	T& back();				//return a reference to the last element in the queue
	const T& back() const;			//
	bool empty() const;			//return true if there is no element in the queue
	T& front();				//return a reference to the first term
	const T& front() const;			//
	void pop();				//remove the first element in the queue and discard it
	void push(const T& val);		//add a new element val into the queue
	int size();				//return the number of elements in the queue
private:
	std::deque <T> array;			//dynamic array to store the elements
		
};						//end of Queue class

#include "Queue.hpp"
}						//end of namespace cop4530
#endif









	
