#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>

template <class T>
class BinaryHeap {
	std::vector<T> _heap;

public:
	BinaryHeap() {}
	
	void Insert(const T&);
	T PopMax();
	const T& Max() const { return _heap.front(); }
	unsigned Count() const { return _heap.size(); }

private:
	typedef typename std::vector<T>::size_type _heap_size_t;

	void _shiftDown(_heap_size_t node);
	void _shiftUp(_heap_size_t node);
};

#endif