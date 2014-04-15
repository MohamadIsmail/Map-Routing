#include "FibonacciHeap.h"


template <class V>
FibonacciHeap<V> :: FibonacciHeap() {
	heap=NULL;
}

template <class V>
node<V>* FibonacciHeap<V> ::  insert(V value) {
	node<V>* ret=_initialize_node(value);
	heap=_merge(heap,ret);
	return ret;
}

template <class V>
bool FibonacciHeap<V>:: isEmpty() {
	return heap==NULL;
}

template <class V>
V FibonacciHeap<V>:: getMinimum() {
	return heap->value;
}

template <class V>
V FibonacciHeap<V>:: removeMinimum() {
	node<V>* old=heap;
	heap=_removeMinimum(heap);
	V ret=old->value;
	delete old;
	return ret;
}

template <class V>
node<V>* FibonacciHeap<V>:: _initialize_node(V value) {
	node<V>* n=new node<V>;
	n->value=value;
	n->prev=n->next=n;
	n->degree=0;
	n->child=NULL;
	n->parent=NULL;
	return n;
}

template <class V>
node<V>* FibonacciHeap<V>:: _merge(node<V>* heap,node<V>* ret) {
	if(heap==NULL)return ret;
	if(ret==NULL)return heap;
	if(heap->value>ret->value) 
		swap(heap,ret);
	node<V>* heapNext=heap->next;
	node<V>* retprevious=ret->prev;
	heap->next=ret;
	ret->prev=heap;
	heapNext->prev=retprevious;
	retprevious->next=heapNext;
	return heap;
}

template <class V>
void FibonacciHeap<V>:: _addChild(node<V>* parent,node<V>* child) {
	child->prev=child->next=child;
	child->parent=parent;
	parent->degree++;
	parent->child=_merge(parent->child,child);
}

template <class V>
void FibonacciHeap<V>:: _unMarkAndUnParentAll(node<V>* n) {
	if(n==NULL)return;
	node<V>* temp=n;
	do {
		temp->parent=NULL;
		temp=temp->next;
	}while(temp!=n);
}

template <class V>
node<V>* FibonacciHeap<V>:: _removeMinimum(node<V>* n) {
	_unMarkAndUnParentAll(n->child);
	if(n->next==n) {
		n=n->child;
	} 
	else {
		n->next->prev=n->prev;
		n->prev->next=n->next;
		n=_merge(n->next,n->child);
	}
	if(n==NULL)return n;
	node<V>* trees[100]={NULL};

	while(true) {
		if(trees[n->degree]!=NULL) {
			node<V>* temp =trees[n->degree];
			if(temp ==n)break;
			trees[n->degree]=NULL;
			if(n->value<temp->value) {
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				_addChild(n,temp);
			}
			else {
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				if(n->next==n) {
					temp->next=temp->prev=temp;
					_addChild(temp,n);
					n=temp;
				}
				else {
					n->prev->next=temp;
					n->next->prev=temp;
					temp->next=n->next;
					temp->prev=n->prev;
					_addChild(temp,n);
					n=temp;
				}
			}
			continue;
		} 
		else {
			trees[n->degree]=n;
		}
		n=n->next;
	}
	node<V>* min=n;
	do {
		if(n->value<min->value)min=n;
		n=n->next;
	} while(n!=n);
	return min;
}