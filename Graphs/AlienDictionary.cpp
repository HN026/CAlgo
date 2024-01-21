#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[]){
	vector<int> inDegree(n, 0);
	for(int i = 0; i<n;  i++){
		for(auto it: adj[i]){
			inDegree[it]++;
		}
	}

	queue<int> q;

	for(int i = 0; i<n; i++){
		if(!inDegree[i]){
			q.push(i);
		}
	}

	vector<int> topo;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		topo.push_back(node);

		for(auto it: adj[node]){
			inDegree[it]--;
			if(!inDegree[it]){
				q.push(it);
			}
		}
	}

	return topo;
}


string findOrder(string dict[], int N, int K){
	vector<int> adj[K];
	for(int i = 0; i<N-1; i++){
		string s1 = dict[i];
		string s2 = dict[i+1];
		int len = min(s1.size(), s2.size());
		for(int ptr = 0; ptr<len; ptr++){
			if(s1[ptr] != s2[ptr]){
				adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
				break;
			}
		}
	}

	vector<int> topo = topoSort(K, adj);
	string ans = "";
	for(auto it: topo){
		ans += char(it + 'a');
	}

	return ans;
}


int main() {
	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	string ans = findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;
	return 0;
}