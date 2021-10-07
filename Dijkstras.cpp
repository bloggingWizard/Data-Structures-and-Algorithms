#include<bits/stdc++.h>
using namespace std ;


template<typename T>

class Graph
{


unordered_map<T, list<pair<T,int>>> l ;

public :

void addEdge(T x , T y , int wt)
{
    l[x].push_back(make_pair(y,wt)) ;
    l[y].push_back(make_pair(x,wt)) ;  // considered bidiectional 
}



/*void print()
{

  for (auto itr:l)
   {
    auto city= itr.first ;

    cout << city <<"->"  ;

    for (auto nbr: itr.second)
   {

    cout << nbr.first <<" " << nbr.second <<"  " ;
    }

    cout << endl; 

  }

  return ;
} 

*/



void dijsktras()
{
    unordered_map<T,int>dist ;

    for (auto itr: l)
    {
        dist[itr.first]= INT_MAX ;
    }

     T src= "delhi" ;
    dist[src]= 0 ;

    set<pair<int,T>>s ;

   for (auto itr : dist)
   {

     s.insert(make_pair(itr.second,itr.first)) ;
   }


// initialized the distance map and the set 


// now make the appropraite changes in the set as the nodes are visited ;
//bool* visited= new bool [4]

    while(s.size()!=0)
   {

    auto front= *(s.begin()) ;
    s.erase(s.begin()) ;

    T node= front.second ;
    int node_dist= front.first ;


    for (auto nbr: l[node])
    {
     T dest= nbr.first ;
    if (node_dist+ nbr.second < dist[dest])
    {

    auto f= s.find(make_pair(dist[dest],dest)) ;
    if (f!=s.end())
     {
        s.erase(f) ;
     }

     dist[dest]= node_dist+ nbr.second ;
    s.insert(make_pair(dist[dest], dest)) ;
     }

     }

  }


  for (auto itr: dist)
  {

    cout << "distance of " <<itr.first <<"  from 1 is " << itr.second  << endl;  
  }


}

} ;


int main()
{

   

//g.print() ;
g.dijsktras() ;



}
