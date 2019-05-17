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
	vector <int> *Adj; // adjacency matrix
    bool cyclic =0;//means the graph is cyclic if cyclic == 1 
    bool *visited;
    bool *under_exploration;
    vector <int> topologically_sorted_order;

	Graph(int v){
		this->v = v;
		Adj = new vector<int>[v];
		visited = new bool[v];
		under_exploration = new bool[v];
	}
	
	void cycle(){
		if(cyclic == 0){
			printf("The graph is non cyclic\n");
		}
		else{
			printf("The graph is cyclic\n");
		}
	}
	void Add_edge(int v, int w){
		Adj[v].pb(w);
	}

    void DFS_visit(int start){
		
		visited[start] = 1;
		under_exploration[start] = 1;
		for(int i=0;i<Adj[start].size();i++){
			if(visited[Adj[start][i]]==0){
                DFS_visit(Adj[start][i]);
			}
			else if(under_exploration[Adj[start][i]] == 1){
                cyclic = 1;
			}
		}
		under_exploration[start] = 0;
		topologically_sorted_order.pb(start);
	}

	vector<int> DFS(){
		topologically_sorted_order.clear();
		for(int i=0;i<v;i++){ visited[i] = 0; }
		
		for(int i=0;i<v;i++){
            if(visited[i]==0){
                DFS_visit(i);
            }
		}
 
        reverse(topologically_sorted_order.begin(), topologically_sorted_order.end());
        return topologically_sorted_order;
	}
    
	

};

int main(){
	Graph graph_1(9);
    
	graph_1.Add_edge(0, 1);
	graph_1.Add_edge(1, 2);
	graph_1.Add_edge(2, 5);
	graph_1.Add_edge(3, 1);
	graph_1.Add_edge(3, 4);
	graph_1.Add_edge(4, 5);
	graph_1.Add_edge(0, 7);
	graph_1.Add_edge(6, 7);
    
	vector<int> sorted_order;
	sorted_order = graph_1.DFS();
    
    graph_1.cycle();

    printf("Topologically sorted order of graph:\n");
	for(int i=0;i<sorted_order.size()-1;i++){
		printf("%d->", sorted_order[i]);
	}
	cout << sorted_order[sorted_order.size()-1] << endl;
}
