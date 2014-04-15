#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <ctime>
#include <string>
#include "FibonacciHeap.h"
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "FibonacciHeap.cpp"
using namespace std;

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define mem(a, s) memset(a, s, sizeof (a))
#define sz(c) ((int)(c).size())
#define pb push_back
#define MAX 90000
#define infinity (ld)1e18
#define mp make_pair
#define vi vector<int>
typedef long double ld;


struct point{
	int x,y;
	point(){}
	point(int _x,int _y): x(_x),y(_y){
	}
};

void print_path(int,int);
void fib_dijkstra(int,int);
void naive_dijkstra(int , int ) ;
void dijkstra_with_heap(int , int ) ;
void A_Star(int,int);
void Read_Map();
void Read_Routes();
string read_line(ifstream &);
ld Distance(point ,point );


extern int num_of_vertices,num_of_edges;
extern vector<vector<pair<int, ld > > > Graph;
extern point *vertices_coords;

#endif 