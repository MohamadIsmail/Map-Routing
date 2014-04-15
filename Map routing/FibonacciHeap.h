#ifndef _FIBONACCI_HEAP_H_
#define _FIBONACCI_HEAP_H_

#include <vector> 

template <class V> class FibonacciHeap;

template <class V> struct node {
private :
	node<V>* prev;
	node<V>* next;
	node<V>* child;
	node<V>* parent;
	V value;
	int degree;
public :
	friend class FibonacciHeap<V>;
};


template <class V> class FibonacciHeap {
protected :
	node<V>* heap;
public :

	FibonacciHeap() ;

	node<V>* insert(V value) ;

	bool isEmpty() ;

	V getMinimum() ;

	V removeMinimum() ;

private:

	node<V>* _initialize_node(V value) ;

	node<V>* _merge(node<V>* a,node<V>* b) ;

	void _addChild(node<V>* parent,node<V>* child) ;

	void _unMarkAndUnParentAll(node<V>* n) ;

	node<V>* _removeMinimum(node<V>* n) ;

};

#endif