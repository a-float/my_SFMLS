#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//using topological sort with DFS
//graph is represented by a heap allocated array
//filled with vectors containing neighbours
bool DNF(int c, vector<int> packs[], 
				vector<int> prevs,
				vector<int> &stack,
				bool visited[]){

	for(int i = 0; i < prevs.size(); i++){
		if(prevs[i] == c)return false;
	}
	if(visited[c])return true;
	visited[c] = true;
	
	prevs.push_back(c);
	for(int i = 0; i < packs[c].size(); i++){	
		if(DNF(packs[c][i], packs, prevs, stack, visited)==false){
			return false;
		}
	}
	stack.push_back(c);
	return true;
}

int main(){
	int N, K;
	cin>>N>>K;
	vector<int> packets[N];
	bool visited[N];
	for(int i = 0; i < N; i++)visited[i] = false;

	for(int i = 0; i < K; i++){
		int a,b;
		cin>>a>>b;
		packets[a].push_back(b);
	}

	bool has_cycle = false;
	vector<int> stack;
	vector<int> vec;

	for(int i = 0; i < N; i++){
		if(!DNF(i, packets, vec, stack, visited)){
			has_cycle = true;
			break;
		}
	}
	if(!has_cycle){
		cout<<"OK"<<endl;
		for(int i = stack.size()-1; i>= 0; i--){
			cout<<stack[i]<<" ";
		}
		cout<<endl;
	}
	else cout<<"CYCLE"<<endl;
	return 0;
}