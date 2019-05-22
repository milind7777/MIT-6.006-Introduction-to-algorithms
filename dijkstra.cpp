#include <bits/stdc++.h>
#define mod 1000000000+7
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair 
#define pii pair <int, int>
#define infi 2000000000
using namespace std;

class Graph{
public: 
	int v; // number of vertices
	vector <pair<int, int>> *Adj; // adjacency matrix with weights as the second element 
    bool *visited;
    
    int source;
    vector <int> shortest_path;
    int *parent; 
 
	Graph(int v){
		this->v = v;
		Adj     = new vector<pair<int, int>>[v];
		visited = new bool[v];
        parent  = new int[v];

		shortest_path.clear();
		for(int i=0;i<v;i++){ shortest_path.pb(infi); }
	}
	
	void Add_edge(int u, int w, int weight){
		Adj[u].pb({w, weight});
		Adj[w].pb({u, weight});
	}

	int minimum(vector<int> arr){
		int min = infi + 1;
		int index;
		for(int i=0;i<v;i++){
			if(visited[i]==0){
				if(arr[i]<min){
					min = arr[i];
					index = i;
				}
			}
		}

		return index;
	}
    
	vector <int> dijkstra(int source){
        for(int i=0;i<this->v;i++){ 
        	visited[i] = 0;
        	shortest_path[i] = infi; 
        }

	    int v, u, min_distance;
	    vector <int> sorted;
	    vector <int> queue;
	    queue = shortest_path;
	    queue[source] = 0;

	    for(int j=0;j<this->v;j++){
	    	u = minimum(queue); // O(V) complexity
	    	min_distance = queue[u];
	    	shortest_path[u] = min_distance;
	    	sorted.pb(u);

	    	for(int i=0;i<Adj[u].size();i++){
	    		v = Adj[u][i].first; 
	    		if( visited[v]==0 ){
                    if(queue[v] > queue[u] + (Adj[u][i]).second){
                    	queue[v] = queue[u] + (Adj[u][i]).second;  // O(1) constant time
                    	parent[v] = u;
                    }
	    		}
	    	}
	    	visited[u] = 1;
	    	
	    }

	    return sorted;
	}

};

int main(){

	Graph graph_1(5);
	graph_1.Add_edge(0, 1, 19);
	graph_1.Add_edge(0, 3, 7);
	graph_1.Add_edge(3, 4, 5);
	graph_1.Add_edge(4, 2, 13);
	graph_1.Add_edge(2, 1, 4);
	graph_1.Add_edge(1, 3, 11);
	graph_1.Add_edge(3, 2, 15);
    
 	vector <int> sorted;

	sorted = graph_1.dijkstra(0);
    
	for(int i=0;i<sorted.size();i++){
		printf("the distance to %d node is %d\n",sorted[i], graph_1.shortest_path[sorted[i]] );
	}
	printf("\n");

	sorted = graph_1.dijkstra(2);
    
	for(int i=0;i<sorted.size();i++){
		printf("the distance to %d node is %d\n",sorted[i], graph_1.shortest_path[sorted[i]] );
	}
}
