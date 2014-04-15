#include "dijkstra.h"



int main()
{
	Read_Map();
	Read_Routes();
}

string read_line(std ::ifstream &file)
{
	string line;
	getline(file,line);
	while (line== "")
	{
		getline(file,line);
	}
	return line;
}

ld Distance(point from,point to)
{
	return sqrt(pow((from.x-to.x),2)+pow((to.y-from.y),2));
}

void Read_Map()
{
	ifstream myfile ("Map.txt");
	int node,X,Y,from,to;
	string line ;
	if (myfile.is_open())
	{
		line =read_line(myfile);
		istringstream iss(line); 
		iss >> num_of_vertices >> num_of_edges;	
		vertices_coords = new point [num_of_vertices];
		Graph.resize(num_of_vertices);
		For(i,0,num_of_vertices)
		{
			line = read_line(myfile);
			istringstream iss(line); 
			iss>>node >>X>>Y;
			vertices_coords[node]=point(X,Y);
		}
		For(i,0,num_of_edges)
		{
			line=read_line(myfile);
			istringstream iss(line); 
			iss>>from>>to;
			Graph[from].pb(mp(to,Distance(vertices_coords[from],vertices_coords[to])));
			Graph[to].pb(mp(from,Distance(vertices_coords[from],vertices_coords[to])));
		}
		myfile.close();
	}
}
void Read_Routes()
{
	ifstream myfile ("Routes.txt");
	string line;
	int N,From,To;
	if (myfile.is_open())
	{
		line =read_line(myfile);
		istringstream iss(line); 
		iss >> N;
		For(i,0,N)
		{
			line=read_line(myfile);
			istringstream iss(line); 
			iss >> From >> To;
			clock_t start,end;

			/*start=clock();
			naive_dijkstra(From,To);
			end=clock();
			print_path(From,To);
			cout << "            ***** Naive solution results *****\n";
			cout <<"\nTime elapsed to get the shortest path is :  "<<(ld)(end-start)/CLOCKS_PER_SEC <<" seconds.\n\n";

			/*start =clock();
			dijkstra_with_heap(From,To);
			end=clock();
			cout << "            ***** Binary Heap results *****\n";
			cout <<"\nTime elapsed to get the shortest path is :  "<<(ld)(end-start)/CLOCKS_PER_SEC <<" seconds.\n\n";*/

			/*start=clock();
			fib_dijkstra(From,To);
			end=clock();
			cout << "            ***** Fibonacci Heap results *****\n";
			cout <<"\nTime elapsed to get the shortest path is :  "<<(ld)(end-start)/CLOCKS_PER_SEC <<" seconds.\n\n";
			*/
			start=clock();
			A_Star(From,To);
			end=clock();
			//print_path(From,To);
			cout << "            ***** A* results *****\n";
			cout <<"\nTime elapsed to get the shortest path is :  " << (ld)(end-start)/CLOCKS_PER_SEC <<" seconds.\n\n";

			cout<<"________________________________________________________________________________\n";
		}
		myfile.close();
	}
}