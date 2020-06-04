#include "../headers/algo.h"
#include "../headers/util.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string in_matrix = "input/lab3_matrix.txt", in_cities = "input/lab3_cities.txt", in_heuristic = "input/lab3_heuristic.txt";
	int size = 15;
	vector<vector<int>> matrix, heuristic;
	map<int, string> cities;

	read_vec_from_file(in_matrix, &matrix);
	read_vec_from_file(in_heuristic, &heuristic);
	read_map_from_file(in_cities, &cities);

	for (int i = 0; i < size; ++i) {
		cout << "Greedy Best-First" << endl;
		search(matrix, heuristic, i, cities, greedy_best_first_heuristic);
		cout << "A-star" << endl;
		search(matrix, heuristic, i, cities, astar_heuristic);
	}

	return 0;
}