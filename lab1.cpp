#include "util.h"
#include "algo.h"
#include <iostream>

using namespace std;

int main1()
{
	vector<int> vec;
	bool RANDOM = true, ASC = false;
	string mes = "random";

	vec = generate_vector(10, RANDOM, ASC);
	cout << "10 " + mes << endl;
	display(vec);
	comb_sort(vec);
	display(vec);

	/*vec = generate_vector(1000, RANDOM, ASC);
	cout << "1000 " + mes << "\n" << endl;
	display(vec);
	comb_sort(vec);
	display(vec);

	vec = generate_vector(1000, RANDOM, ASC);
	cout << "1000 " + mes << endl;
	comb_sort(vec);

	vec = generate_vector(5000, RANDOM, ASC);
	cout << "5000 " + mes << endl;
	comb_sort(vec);

	vec = generate_vector(10000, RANDOM, ASC);
	cout << "10000 " + mes << endl;
	comb_sort(vec);

	vec = generate_vector(20000, RANDOM, ASC);
	cout << "20000 " + mes << endl;
	comb_sort(vec);

	vec = generate_vector(50000, RANDOM, ASC);
	cout << "50000 " + mes << endl;
	comb_sort(vec);*/

	return 0;
}