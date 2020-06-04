#ifndef ALGO_H
#define ALGO_H
#include <vector>
#include <map>
#include <string>

using namespace std;

void comb_sort(vector<int>&);
void comb_sort(int*, size_t);	

vector<int> make_delta_uni(int n);
vector<int> make_delta_shar(int n);

int uniform_bsearch(vector<int> a, int key, vector<int> delta, bool asc);
int shar_search(vector<int> a, int key);
int shar_search_nodelta(vector<int> a, int key);

vector<vector<int>> floyd_warshal(vector<vector<int>>);

int dijkstra(int, int, vector<vector<int>>, vector<vector<int>>);
int astar(int, int, vector<vector<int>>, vector<vector<int>>);

void greedy_search(vector<vector<int>>, vector<vector<int>>, int, map<int, string>, 
	int (*func)(int,int, vector<vector<int>>, vector<vector<int>>));
void dijkstra(vector<vector<int>>, int, map<int, string>);
void output_dijkstra(vector<int>, vector<int>, int, map<int, string>);

#endif 