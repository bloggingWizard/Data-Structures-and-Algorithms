#include<bits/stdc++.h>
using namespace std ;

// now we will make a generic unweighted bidirectional graph ;


// the distance calculated by the level order traversal is the shortest distance of node from the source in the case of unweighted graphs 
// The very first time a node is discovered , tat will be the shortest path of that node from the source 

template <typename T> 

class Graph
{
// kept private as we don't want user to know about the underhood implementation 
map<T, list<T>> l ;

public:

void addEdge(T x, T y)
{

    l[x].push_back(y) ;
    l[y].push_back(x) ;
}

void bfs(T src)
{

    queue<T> q ;

    unordered_map<T, int>dist;

for (auto node_pair: l)
{

    T node= node_pair.first;
    dist[node]= INT_MAX ;
}
 dist[src]= 0 ;
    q.push(src) ;
   

    while(q.size()!=0)
    {
        T node= q.front() ;
        q.pop() ;


        for (int nbr:l[node])
        {

          if (dist[nbr]==INT_MAX)
          {
          q.push(nbr) ; 
          dist[nbr]= dist[node]+1 ;
          } 
        }
    }



    for (auto node_pair:l)
    {
        T node= node_pair.first ;

        cout << "node " << node <<" " <<"dist from the src  " << dist[node] << endl;
    } 
}

} ;

int main()
{

Graph <int>g ;
    g.addEdge(0,1) ;
     g.addEdge(1,2) ;
     g.addEdge(2,3) ;
     g.addEdge(3,4) ;
     g.addEdge(4,5) ;
     g.addEdge(0,3) ;
     g.bfs(0) ;


    return 0 ; 
}
