#include "../headers/util.h"
#include "../headers/algo.h"
#include <iostream>

using namespace std;

int main2()
{
	//int n = 10;
	//vector<int> vec = { 1,3,5,6,7,9,14,15,17,19 };
	//
	//for (int i = 0; i <= 20; ++i)
	//	printf("%d is at index %d\n", i, shar_search(vec, i));

	//int counter = 0;
	//for (int j = 0; j < 100; ++j) {
	//	vector<int> vec_10_rand = generate_vector(100, true, true);
	//	int key = vec_10_rand[0];
	//	comb_sort(vec_10_rand);
	//	int i = shar_search(vec_10_rand, key);
	//	if (i == -1) {
	//		++counter;
	//	}
	//}
	//cout << counter << " out of 100 not found" << endl;

	vector<int> vec_10_rand = generate_vector(20000, true, true);
	int key = vec_10_rand[0];
	cout << "100 random" << endl;
	display(vec_10_rand);
	comb_sort(vec_10_rand);
	cout << "sorted" << endl;
	display(vec_10_rand);
	int i = shar_search(vec_10_rand, key);
	cout << "key: " << key << " is at " << i << " index" << endl;

	//string in = "lab2_input2.txt";
	//int key = 25404;
	//vector<int> vec_100_asc;
	//read_vec_from_file(in, &vec_100_asc);
	//int i = shar_search(vec_100_asc, key);
	//cout << "key: " << key << " is at " << i << " index" << endl;

	return 0;
}