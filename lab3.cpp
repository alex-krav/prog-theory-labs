#include "algo.h"
#include "util.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string in_matrix = "lab3_matrix.txt", in_cities = "lab3_cities.txt", in_heuristic = "lab3_heuristic.txt";
	int size = 15;
	vector<vector<int>> matrix, heuristic;
	map<int, string> cities;

	read_vec_from_file(in_matrix, &matrix);
	read_vec_from_file(in_heuristic, &heuristic);
	read_map_from_file(in_cities, &cities);

	for (int i = 0; i < size; ++i)
		greedy_search(matrix, heuristic, i, cities, astar);

	return 0;
}