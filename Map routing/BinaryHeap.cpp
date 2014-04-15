#include "BinaryHeap.h"

template <class T>
void BinaryHeap<T>::Insert(const T& value)
{
	_heap.push_back(value);
	_shiftUp(_heap.size()-1);
}

template <class T>
T BinaryHeap<T>::PopMax()
{
	T result = _heap.front();
	_heap.front() = _heap.back();
	_heap.pop_back();
	_shiftDown(0);
	return result;
}


template <class T>
void BinaryHeap<T>::_shiftDown(_heap_size_t node)
{
	_heap_size_t left_child = node*2+1;
	_heap_size_t right_child = node*2+2;

	_heap_size_t replace = node;
	if (right_child < _heap.size())
	{
		bool left = _heap[right_child] < _heap[left_child];
		if (left && _heap[node] < _heap[left_child])
			replace = left_child;
		else if (!left && _heap[node] < _heap[right_child])
			replace = right_child;
	}
	else if (left_child < _heap.size())
	{
		if (_heap[node] < _heap[left_child])
			replace = left_child;
	}

	if (replace == node)
		return;
	std::swap(_heap[node], _heap[replace]);
	_shiftDown(replace);
}

template <class T>
void BinaryHeap<T>::_shiftUp(_heap_size_t node)
{
	if (node == 0)
		return;

	_heap_size_t parent = (unsigned int ) std::floor((node-1)/2);

	if (_heap[node] < _heap[parent])
		return;
	std::swap(_heap[node], _heap[parent]);
	_shiftUp(parent);
}
