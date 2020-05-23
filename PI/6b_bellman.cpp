#include<iostream>
using namespace std;

struct Edge{
	int w;
	int s;
	int e;
	Edge(){}
	Edge(int a, int b, int c):s(a),e(b),w(c){}
};

int main(){
	int N, K, s, t;
	cin>>N>>K>>s>>t;
	int *dists = new int[N];
	bool *visited = new bool[N];
	Edge *edges = new Edge[K]; 

	for (int i = 0; i < N; ++i){
		visited[i] = false;
	}
	for(int i = 0; i < K; i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges[i] = Edge(a,b,c);
	}

	dists[s] = 0;
	visited[s] = true;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			Edge e = edges[j];
			if(visited[e.s]){
				if(visited[e.e] == false){
					visited[e.e] = true;
					dists[e.e] = dists[e.s] + e.w;
				}
				else{
					if(dists[e.e] > dists[e.s] + e.w){
						dists[e.e] = dists[e.s] + e.w;
					}
				}
			}
			//end of relaxation
		}
	}
	//verification
	int res = 0; // 0 is good, 1 is cycle 2 is no route
	for (int i = 0; i < K; i++){
		Edge e = edges[i];
		if(dists[e.e] > dists[e.s] + e.w){
			//cout<<e.s<<" "<<e.e<<" "<<e.w<<endl;
			res = 1;
			break;
		}
	}
	if(visited[t] == false)res = 2;

	if(res == 1)cout<<"CYCLE"<<endl;
	else if(res == 2)cout<<"NO"<<endl;
	else if(res == 0)cout<<dists[t]<<endl;

	// for (int i = 0; i < N; ++i)
	// {
	// 	cout<<"bank "<<i<<" is "<<dists[i]<<endl;
	// }
	
	delete [] edges;
	delete [] dists;
	delete [] visited;
	return 0;
}