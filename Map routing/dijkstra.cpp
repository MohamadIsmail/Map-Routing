#include "dijkstra.h"

ld dist[MAX],f_score[MAX];
int path [MAX];
bool finished[MAX];
vector<vector<pair<int, ld > > > Graph;
point *vertices_coords;
int num_of_vertices,num_of_edges;


void naive_dijkstra(int source,int destination)
{
	fill(dist, dist + sz(Graph), infinity);
	mem(path,-1);
	mem(finished,0);
	dist[source] = 0;
	int currentrent = source,nextIndex=0,neighbour;
	ld  tempDistance,cost;
	vector<pair< int, ld> > arr;
	arr.pb(mp(source,0));
	while(sz(arr))
	{
		finished[currentrent] = true;
		arr.erase(arr.begin()+nextIndex);
		Fors(i,Graph[currentrent])
		{
			neighbour=Graph[currentrent][i].first;
			cost= Graph[currentrent][i].second;
			if(!finished[neighbour] && dist[currentrent] + cost < dist[neighbour])
			{
				dist[neighbour] = dist[currentrent] + cost;
				arr.pb(mp(neighbour,dist[neighbour]));
				path[neighbour]=currentrent;
			}
		}
		tempDistance= infinity,nextIndex=0;
		Fors(i,arr)
		{
			if(!finished[arr[i].first] && arr[i].second < tempDistance){
				nextIndex=i;
				currentrent=arr[i].first;
				tempDistance=arr[i].second;
			}
		}
	}
}


void dijkstra_with_heap(int source , int destination) 
{
	mem(path,-1);
	fill(dist, dist + sz(Graph), infinity);

	dist[source] = 0;
	BinaryHeap<pair<ld ,int> >q;
	int current,neighbour;
	ld cost,tempDistance;
	q.Insert(mp(0, source));
	while (q.Count()) 
	{
		current = q.Max().second;
		cost = -q.Max().first;
		q.PopMax();
		if (cost != dist[current])
			continue;
		if (current == destination){		
			return ;
		}
		Fors(i,Graph[current])
		{
			neighbour = Graph[current][i].first;
			tempDistance = cost + Graph[current][i].second;
			if (dist[neighbour] > tempDistance) 
			{
				dist[neighbour] = tempDistance;
				path[neighbour]=current;
				q.Insert(mp(-tempDistance, neighbour));
			}
		}
	}
}


void A_Star(int source, int destination) 
{
	mem(path,-1);
	fill(dist, dist + sz(Graph), infinity);
	dist[source] = 0;
	f_score[source] = Distance(vertices_coords[source],vertices_coords[destination]);
	FibonacciHeap<pair<ld, int> > q;
	int current,neighbour;
	ld tempDistance;
	q.insert(mp(f_score[source], source));
	while (!q.isEmpty()) 
	{
		pair<ld,int> top=q.removeMinimum();
		current = top.second;
		if (current == destination){
			return ;
		}
		Fors(i,Graph[current])
		{
			neighbour = Graph[current][i].first;
			tempDistance = dist[current] + Graph[current][i].second;
			if (dist[neighbour] > tempDistance) {
				dist[neighbour] = tempDistance;
				path[neighbour] = current;
				f_score[neighbour] = dist[neighbour]+Distance(vertices_coords[neighbour],vertices_coords[destination]);
				q.insert(mp(f_score[neighbour], neighbour));
			}
		}
	}
}

void fib_dijkstra(int source, int destination) 
{
	mem(path,-1);
	fill(dist, dist + sz(Graph), infinity);
	dist[source] = 0;
	FibonacciHeap<pair<ld, int> > q;
	pair<ld,int> top;
	int current,neighbour;
	ld cost,tempDistance;
	q.insert(mp(0, source));
	while (!q.isEmpty()) {
		top=q.removeMinimum();
		current = top.second;
		cost = top.first;
		if (cost != dist[current])
			continue;
		if (current == destination){
			return ;
		}
		Fors(i,Graph[current])
		{
			neighbour = Graph[current][i].first;
			tempDistance = cost + Graph[current][i].second;
			if (dist[neighbour] > tempDistance) 
			{
				dist[neighbour] = tempDistance;
				path[neighbour]=current;
				q.insert(mp(tempDistance, neighbour));
			}
		}
	}
}


void print_path(int start,int End ){
	cout << "Shortest path from Node "<< start << " to Node "<<End<< " is : \n";
	int res= End;
	while (res != -1)
	{
		cout << res ;
		if(path[res]!=-1)
			cout <<"\t "<< "->";
		res=path[res];
	}
	cout << "\nPath cost : " << dist[End]<<endl; 
}