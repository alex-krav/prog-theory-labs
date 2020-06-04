#include "util.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

void read_map_from_file(string in, map<int, std::string>* mapping) {
    ifstream input(in);
    if (input.is_open())
    {
        vector<string> pair;
        int n, size; 
        string line, word, name = "";
        input >> n; getline(input, line);

        for (int j = 0; j < n; ++j) {
            getline(input, line);
            istringstream iss(line);
            while (iss >> word)
                pair.push_back(word);
            size = pair.end() - pair.begin();
            for (int i = 1; i < size; ++i) {
                name += pair[i];
                if (i != size - 1)
                    name += " ";
            }
            (*mapping)[stoi(pair[0])] = name;
            name = ""; pair.clear();
        }
        input.close();
    }
    else cout << "Unable to open input file: " << in << endl;
}

void read_vec_from_file(string in, vector<int>* vec) {
    ifstream input(in);
    if (input.is_open())
    {
        int n;
        input >> n;
        double elem;

        for (int j = 0; j < n; ++j) {
            input >> elem;
            vec->push_back(elem);
        }
        input.close();
    }
    else cout << "Unable to open input file: " << in << endl;
}

void read_vec_from_file(string in, vector<vector<int>>* vec) {
    ifstream input(in);
    if (input.is_open())
    {
        int n, m;
        input >> n >> m;
        double elem;

        for (int i = 0; i < n; ++i) {
            vector<int> row;
            for (int j = 0; j < m; ++j) {
                input >> elem;
                row.push_back(elem);
            }
            vec->push_back(row);
        }

        input.close();
    }
    else cout << "Unable to open input file: " << in << endl;
}

void display(vector<vector<int>> vec) {
    int size = vec.end() - vec.begin();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%6d ", vec[i][j]);
        cout << endl;
    }
    cout << endl;
}

void display(vector<int> vec) {
    int size = vec.end() - vec.begin();

    if (size > 100) {
        int n = 20;
        for (int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << "... ";
        for (int i = size - n; i < size; i++)
            cout << vec[i] << " ";
    }
    else {
        for (int i = 0; i < size; i++)
            printf("%6d ", vec[i]);
    }
    cout << endl;
}

void display(int* arr, size_t size) {

    if (size > 100) {
        int n = 20;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "... ";
        for (int i = size - n; i < size; i++)
            cout << arr[i] << " ";
    }
    else {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}

/*vector<int> generate_vector(int size, bool random, bool asc)
{
    vector<int> vec(size);

    if (random) {
        for (int i = 0; i < size; ++i) {
            vec[i] = rand() % INT16_MAX + 1;
        }
    }
    else {
        int max = size;
        for (int i = 0; i < size; ++i) {
            if (asc)
                vec[i] = i + 1;
            else
                vec[i] = max--;
        }
    }

    return vec;
}*/

vector<int> generate_vector(int size, bool random, bool asc)
{
    vector<int> vec(size);

    if (random) {
        vec = generate_rand_vector(size, 1, INT16_MAX);
    }
    else {
        int max = size;
        for (int i = 0; i < size; ++i) {
            if (asc)
                vec[i] = i + 1;
            else
                vec[i] = max--;
        }
    }

    return vec;
}

vector<int> generate_rand_vector(int size, int min_val, int max_val) {
    vector<int> vec(size);

    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine{ rnd_device() };  // Generates random integers
    uniform_int_distribution<int> dist{ min_val, max_val };

    function<int()> gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    generate(begin(vec), end(vec), gen);

    return vec;
}

/*vector<int> generate_rand_vector(int size, int min_val, int max_val) {
    vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = rand() % (max_val - min_val + 1) + min_val;
    }
    return vec;
}*/

/*int* generate_array(int size, bool random, bool asc)
{
    vector<int> vec = generate_vector(size, random, asc);

    int* arr = new int[size];
    copy(vec.begin(), vec.end(), arr);
    return arr;
}*/

vector<vector<int>> copy_vec(vector<vector<int>> vec) {
    vector<vector<int>> copy;

    for (vector< vector<int> >::iterator row = vec.begin(); row != vec.end(); ++row) {
        vector<int> copyRow;
        for (vector<int>::iterator col = row->begin(); col != row->end(); ++col) {
            copyRow.push_back(*col);
        }
        copy.push_back(copyRow);
    }

    return copy;
}

vector<int> copy_vec(vector<int> vec) {
    vector<int> copy;

    for (vector<int>::iterator col = vec.begin(); col != vec.end(); ++col) {
        copy.push_back(*col);
    }

    return copy;
}