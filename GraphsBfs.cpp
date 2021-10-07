#include<bits/stdc++.h>
using namespace std ;

// now we will make a generic unweighted bidirectional graph ;


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

    unordered_map<T, bool>visited ;


    q.push(src) ;
    visited[src]= true ;

    while(q.size()!=0)
    {
        T node= q.front() ;
        q.pop() ;

cout << node <<" "  ;
        for (int nbr:l[node])
        {

       if (!visited[nbr])
       {
          q.push(nbr) ; 
          visited[nbr]= true ;
        } 
        }
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

     g.bfs(0) ;


    return 0 ; 
}
