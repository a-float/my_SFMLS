#include<iostream>
using namespace std;

int main(){
	int T,N,Q, s, t;
	cin>>T>>N>>Q;
	int** dists = new int*[T];
	for(int i = 0; i < T; i++)dists[i] = new int[T];

	for(int i = 0; i < T; ++i){
		for(int j = 0; j < T; j++){
			dists[i][j] = -1;
		}
	}

	for(int i = 0; i < T; ++i){
		dists[i][i] = 0;
	}

	for(int i = 0; i < N; i++){
		int K,a,b,c;
		cin>>K>>a;
		for(int j = 0; j < K-1; j++){
			cin>>c>>b;
			if(dists[a][b] == -1){
				dists[a][b] = c;
				dists[b][a] = c;
			}
			else{
				dists[a][b] = min(dists[a][b], c);
				dists[b][a] = min(dists[b][a], c);
			}
			a = b;
		}
	}

	// for(int i = 0; i < T; ++i){
	// 	for(int j = 0; j < T; j++){
	// 		cout<<" "<<dists[i][j];
	// 	}
	// 	cout<<endl;
	// }

	for (int k = 0; k < T; k++){
		for (int i = 0; i < T; i++){
			for (int j = 0; j < T; j++){
				if(dists[i][k]==-1 || dists[k][j] == -1)continue;
				else if(dists[i][j] == -1){
					dists[i][j] = dists[i][k] + dists[k][j];
				}
				else if(dists[i][j] > dists[i][k] + dists[k][j]){
					dists[i][j] = dists[i][k] + dists[k][j];
				}
			}	
		}	
	}
	// cout<<endl;
	// for(int i = 0; i < T; ++i){
	// 	for(int j = 0; j < T; j++){
	// 		cout<<" "<<dists[i][j];
	// 	}
	// 	cout<<endl;
	// }

	int p,q;
	for (int i = 0; i < Q; ++i){
		cin>>p>>q;
		cout<<dists[p][q]<<endl;
	}
	
	for(int i = 0; i < T; i++)delete [] dists[i];
	delete [] dists;
	return 0;
}