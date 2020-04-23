#include<iostream>
#include<vector>
using namespace std;

struct Station{
	int len;
	vector<int> cons;
};

void delete_edge(Station& stat, int other){
	int count = stat.cons.size();
	for(int i = 0; i < count; i++){
		if(stat.cons[i] == other){
			stat.cons[i] = -1;
			stat.len--;
			break;
		}
	}
}

void print_vector(vector<int>& vec){
	cout<<vec.size()<<" ";
	for(int i = 0; i < vec.size(); i++){
		cout<<vec[i]+1<<" ";
	}
	cout<<endl;
}

void DNF_priv(int c, Station* stats, vector<int>& out, bool is_euler){
	if(!is_euler){
		// cout<<"not euler pushing "<<c+1<<endl;
		out.push_back(c);
	}
	// cout<<"visiting "<<c+1<<endl;
	int count = stats[c].cons.size();
	for (int i = 0; i < count; i++){
		// cout<<"checking "<<stats[c].cons[i]+1<<endl;
		if(stats[c].cons[i] != -1){	
			int other = stats[c].cons[i];
			delete_edge(stats[c], other);
			delete_edge(stats[other], c);
			DNF_priv(other, stats, out, is_euler);
			if(!is_euler)return;
		}
	}
	if(is_euler){
		// cout<<"euler pushing "<<c+1<<endl;
		out.push_back(c);
	}

}
vector<int> DNF(int c, Station* stats, bool is_euler){
	vector<int> res;
	DNF_priv(c, stats, res, is_euler);
	return res;
}

int main(){
	int Z, N, K;
	cin>>Z;
	for(int z = 0; z < Z; z++){
		cin>>N>>K;
		Station stations[N];
		for (int i = 0; i < K; i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			stations[a].cons.push_back(b);
			stations[b].cons.push_back(a);
		}
		int odd_count = 0;
		for (int i = 0; i < N; i++){
			stations[i].len = stations[i].cons.size();
			if(stations[i].len % 2 == 1)odd_count++;
			// cout<<i+1<<" len = "<<stations[i].len<<endl;
			// print_vector(stations[i].cons);
		}

		bool is_euler = odd_count == 0 || odd_count == 2;
		vector< vector<int> > results;
		int to_do; // -1 means no vertex has any edges left
				  // -2 means that a vertex with an odd number of
	   		     //edges has already been searched this iteration 
		do{
			to_do = -1;
			for (int i = 0; i < N; i++){
				if(stations[i].len > 0)to_do = i;
				if(stations[i].len > 0 && stations[i].len%2==1){
					to_do = -2;	
					// cout<<endl<<"starting from coz len odd "<<i+1<<endl;
					results.push_back(DNF(i, stations, is_euler));
					// cout<<"result:"<<endl;
					// print_vector(results.back());
					break;
				}
			}
			if(to_do != -1 && to_do != -2){
				// cout<<endl<<"starting from coz len even "<<to_do+1<<endl;
				results.push_back(DNF(to_do, stations, is_euler));
				// cout<<"result:"<<endl;;
				// print_vector(results.back());
			}
		}while(to_do != -1);
		
		cout<<results.size()<<endl;
		for(int i = 0; i < results.size(); i++){
			print_vector(results[i]);
		}

	}
	return 0;
}