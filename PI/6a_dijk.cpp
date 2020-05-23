#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge{
	int w;
	int n;
	Edge(int _n, int _w):w(_w),n(_n){}
};
struct Node{
	vector<Edge>cons;
	int d;
	bool visited;
	Node():d(-1), visited(false){} //-1 = +inifinity
};
struct myComparator 
{  
    bool operator() (const Edge& e1, const Edge& e2) 
    { 
        return e1.w > e2.w; 
    } 
};

void relax(Node &s, Node &t, int w){
	if(t.d == -1)t.d = s.d + w;
	else t.d = min(t.d, s.d + w);
	// cout<<"t.d is now = "<<t.d<<endl;
}

int main(){
	int N, K, s, t;
	cin>>N>>K>>s>>t;
	Node cities[N];
	for(int i = 0; i < K; i++){
		int a,b,c;
		cin>>a>>b>>c;
		cities[a].cons.push_back(Edge(b,c));
		cities[b].cons.push_back(Edge(a,c));
	}
	priority_queue <Edge, vector<Edge>, myComparator > pq;

	cities[s].d = 0;
	pq.push(Edge(s,0));
	while (pq.empty() == false) 
    {
        // cout << "poping " << pq.top().n <<" "<<pq.top().w<<endl; 
    	int c = pq.top().n;
    	pq.pop();
        // cout<<"Queue length is "<<pq.size()<<endl;

    	if(cities[c].visited)continue;
    	cities[c].visited = true;
    	if(c == t)break;

        for(int i = 0; i < cities[c].cons.size(); i++){
        	Edge e = cities[c].cons[i];
        	// cout<<"the edge is ("<<e.n<<" "<<e.w<<")"<<endl;

	        if(cities[e.n].visited == false){
	        	// cout<<"relaxing "<<c<<" "<<e.n<<" "<<e.w<<endl;
	        	relax(cities[c], cities[e.n], e.w);

	    		// cout<<"pushing new edge"<<endl;
	    		pq.push(Edge(e.n, cities[e.n].d));
	    	}
        } 
    }
    // cout<<"end of the queue"<<endl;
    // for (int i = 0; i < N; i++)
    // {
    	// cout<<"city "<<i<<" is "<<cities[i].d<<" aways"<<endl;
    // }
    cout<<cities[t].d<<endl;
	return 0;
}