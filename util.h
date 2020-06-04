#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <string>
#include <map>

using namespace std;

void read_vec_from_file(string, vector<int>*);
void read_vec_from_file(string, vector<vector<int>>*);
void read_map_from_file(string, map<int, string>*);

void display(vector<vector<int>>);
void display(vector<int>);
void display(int*, size_t);

vector<int> generate_vector(int, bool, bool);
vector<int> generate_rand_vector(int, int, int);
//int* generate_array(int, bool, bool);

vector<vector<int>> copy_vec(vector<vector<int>>);
vector<int> copy_vec(vector<int>);

#endif