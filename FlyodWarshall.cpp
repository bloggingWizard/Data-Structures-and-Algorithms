#include <bits/stdc++.h>
using namespace std;

void floyd(vector<vector<int>> &graph, int v)
{

    vector<vector<int>> dist(graph);

    for (int k = 0; k < v; k++)
    {

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {

                if (i != j)
                {

                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        //	cout <<"X" ;

                        if (dist[i][j] > dist[i][k] + dist[k][j])
                        {
                            //	cout <<"X" ;

                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{

    int m, n;
    cin >> m >> n;

    vector<vector<int>> graph(m, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;

        graph[a][b] = wt;
        graph[a][a] = 0;
        graph[b][b] = 0;
    }

    floyd(graph, m);
}
