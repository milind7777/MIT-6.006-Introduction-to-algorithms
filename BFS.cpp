#include <bits/stdc++.h>
#define mod 1000000000+7
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair 
#define pii pair <int, int>
using namespace std;

class Graph{
public:
	int v; // number of vertices
	vector <int> *Adj; // the adjacency matirx for the graph

	Graph(int v){
		this->v = v;
		Adj = new vector<int>[v];
	}

	void Add_edge(int v, int w){
		Adj[v].pb(w);
		Adj[w].pb(v); // for undirected graphs
	}

	vector <pair<int,int>> BFS(int start){
		bool visited[v] = {0};
        int level=1;
        
        vector <pair<int,int>> next;
        vector <pair<int,int>> queue;
        queue.pb({start, 0});
        
        visited[start] = 1;

		for(int i=0;i<queue.size();i++){
            for(int j=0;j<Adj[queue[i].first].size();j++){
            	if(visited[Adj[queue[i].first][j]] == 0){
            		visited[Adj[queue[i].first][j]] = 1;
            		next.pb({Adj[queue[i].first][j], level});
            	}
            }
            if(i==queue.size()-1){
            	queue.insert(queue.end(), next.begin(), next.end());
            	level++;
            	next.clear();
            }
		}
		return queue;
	}
};


int main(){
	Graph graph(8);
	graph.Add_edge(0, 4);
	graph.Add_edge(0, 1);
	graph.Add_edge(1, 5);
	graph.Add_edge(5, 2);
	graph.Add_edge(5, 6);
	graph.Add_edge(2, 6);
	graph.Add_edge(2, 3);
	graph.Add_edge(6, 3);
	graph.Add_edge(6, 7);
	graph.Add_edge(3, 7);
    
    vector <pair<int, int>> queue;

    queue = graph.BFS(1);
    
    for(int i=0;i<queue.size();i++){
    	printf("vertex %d is at level %d\n",queue[i].first, queue[i].second );
    }
	
}
