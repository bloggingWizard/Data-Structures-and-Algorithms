#include<bits/stdc++.h>
using namespace std ;

// in this algorithm we will use the concept of visited vertices , and add the edges if it is betwwen the MST set(visited) 
// and the normal set i.e. unvisited 

// we will make graphs using adjacency list as we need to discover the edges for a particular node as optimally as possible 


class Graph
{
vector<pair<int,int>> * l ;
int V ;

public:

Graph(int V)
{
 this->V= V ;
l= new vector<pair<int,int>>[V] ;
}


void addEdge(int x, int y, int w)
{
    l[x].push_back({y,w}) ;
    l[y].push_back({x,w}) ;
}

// most important part of the algorithm 

int prims()
{

// unvisit all the nodes 

bool* visited= new bool[V] ;
for (int i=0; i<V; i++)
{
    visited[i]= false ;
}

int ans=0 ;
// make a min heap to get the minimum value optimally

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 

//priority_queue<pair<int,int>, vector<pair<int,int>, greater<pair<int,int>>> pq ;

pq.push({0,0}) ;   // weight, node 

while(pq.size()!=0)
{

    auto best= pq.top() ;
    pq.pop() ;

    int to= best.second ;
    int weight= best.first ;

    if (visited[to]==true)
    {
        continue ;
    }


    ans+= weight ;
 visited[to]= true ;
    for (auto nbr: l[to])
    {

   if (visited[nbr.first]==false)
   {
       pq.push({nbr.second, nbr.first}) ;
   }

    }

}


return ans ;
}

};


int main()
{

int v, e ;
cin >> v>> e ;

Graph g(v) ;

for (int i=0; i< e; i++)
{
    int x, y, wt ;

    cin >> x>> y >> wt ;


    g.addEdge(x,y,wt) ;
}


cout << g.prims() << endl;
return 0 ;

}
