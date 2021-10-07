
#include<bits/stdc++.h>
using namespace std ;

class Graph
{

int v ;

list<int> * l;

public:

// constructor ;

Graph(int v)
{

    this->v= v ;
    l= new list<int>[v] ;
    }

// l is a pointer to an array of list 

void addEdge(int x, int y)
{
    l[x].push_back(y) ;
    l[y].push_back(x) ;   // considering bidirectional graph 


}

bool isTree()
{

bool * visited= new bool [v] ;

int* parent= new int[v] ;

for (int i=0; i<v; i++)
{
    visited[i]= false ;
    parent[i]= i ;
}

queue<int>q ;

int src=0;
visited[src]= true ;
q.push(src) ;

while(q.size()!=0)
{
    int node= q.front() ;
    q.pop() ;

    for (int nbr:l[node])
    {
        if (visited[nbr]==true and parent[node]!=nbr)
        {
            return false ;
        }

        else if (visited[nbr]==false)
        {
         visited[nbr]= true ;
         parent[nbr]= node ;
         q.push(nbr) ;   
        }
    }
}


return true ;
}

} ;

int main()
{

Graph g(4) ;

g.addEdge(0,1) ;
g.addEdge(0,2) ;
g.addEdge(2,3) ;
//g.addEdge(1,2) ;


if(g.isTree())
{
    cout <<"true" << endl ;
}

else{
    cout <<"false"  ;
}

}
