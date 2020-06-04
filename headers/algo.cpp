#include "algo.h"
#include "util.h"
#include <iostream>

using namespace std;

void comb_sort(vector<int>& vec)
{
    int comp = 0, perm = 0, pass = 0;
    int size = vec.end() - vec.begin();
    int gap = size; 
    double shrink = 1.2473309;
    bool sorted = false;

    while (sorted == false) {
        gap /= shrink;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for (int i = 0; i < size - gap; i++) {
            if (vec[i] > vec[i + gap]) {
                swap(vec[i], vec[i + gap]);
                sorted = false;
                ++perm;
            }
            ++comp;
        }
        ++pass;
    }
    //cout << "\npasses: " << pass << endl;
    //cout << "compares: " << comp << endl;
    //cout << "permutations: " << perm << "\n" << endl;
}

void comb_sort(int* arr, size_t size)
{
    int comp = 0, perm = 0, pass = 0;
    int gap = size;
    double shrink = 1.2473309;
    bool sorted = false;

    while (sorted == false) {
        gap /= shrink;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                sorted = false;
                ++perm;
            }
            ++comp;
        }
        ++pass;
    }
    cout << "\npasses: " << pass << endl;
    cout << "compares: " << comp << endl;
    cout << "permutations: " << perm << "\n" << endl;
}

vector<int> make_delta_uni(int n) {
    vector<int> delta;
    int power = 1;
    int i = 0;
    do {
        int half = power;
        power <<= 1;
        delta.push_back((n + half) / power);
    } while (delta[i++] != 0);
    return delta;
}

vector<int> make_delta_shar(int k) {
    vector<int> delta;
    int power = pow(2, k);
    do {
        power >>= 1;
        delta.push_back(power);
    } while (power != 1);
    delta.push_back(1);
    delta.push_back(0);

    return delta;
}

int uniform_bsearch(vector<int> a, int key, vector<int> delta, bool asc) {
    int comp = 0, get = 0;
    int size = a.end() - a.begin();
    /*if (key < a[0] || key > a[size - 1]) {
        ++comp; ++get;
        return -1;
    }*/
    int i = delta[0] - 1;
    if (!asc) i = size - 1 - i;
    int d = 0;

    while (1) {
        if (key == a[i]) {
            ++comp; ++get;
            cout << "\ngets: " << get << endl;
            cout << "compares: " << comp << "\n" << endl;
            return i;
        }
        else if (delta[d] == 0) {
            ++comp;
            cout << "\ngets: " << get << endl;
            cout << "compares: " << comp << "\n" << endl;
            return -1;
        }
        else {
            if (key < a[i])
                i -= delta[++d];
            else
                i += delta[++d];
            ++comp; ++get;
        }
    }
}

int shar_search(vector<int> a, int key) {
    int comp = 0, get = 0;
    int size = a.end() - a.begin();
    if (key < a[0] || key > a[size - 1]) {
        ++comp; ++get;
        return -1;
    }
    int k = log2(size);
    int i = pow(2, k);
    int n = 1;
    bool asc = true;
    
    if (key < a[i]) {
        ++comp; ++get;
        n = k;
    }
    else if (key > a[i]) {
        ++comp; ++get;
        int l = log2(size - pow(2, k) + 1);
        i = size + 1 - pow(2, l);
        if (key > a[i]) {
            ++comp; ++get;
            n = l;
        }
        else if (key < a[i]) {
            ++comp; ++get;
            n = k;
        }
        else
            return i;
        asc = false;
    }
    else {
        return i;
    }
    cout << "\ngets: " << get << endl;
    cout << "compares: " << comp << "\n" << endl;
    vector<int> delta = make_delta_shar(n);
    return uniform_bsearch(a, key, delta, asc);
}

int shar_search_nodelta(vector<int> a, int key) {
    int size = a.end() - a.begin();
    if (key < a[0] || key > a[size - 1])
        return -1;
    int k = log2(size);
    int i = pow(2, k);
    int n = 1;

    if (key < a[i]) {
        n = k;
    }
    else if (key > a[i]) {
        int l = log2(size - pow(2, k) + 1);
        i = size + 1 - pow(2, l);
        if (key > a[i])
            n = l;
        else if (key < a[i])
            n = k;
        else
            return i;
    }
    else if (key == a[i]) {
        return i;
    }

    int power = pow(2, --n);
    int j = power - 1;
    bool inc = false;

    while (1) {
        if (key == a[j])
            return j;
        else if (power == 0)
            return -1;
        else {
            if (!inc && power == 1)
                inc = true;
            else
                power >>= 1;

            if (key < a[j])
                j -= power;
            else
                j += power;
        }
    }
}

vector<vector<int>> floyd_warshal(vector<vector<int>> vec) {
    vector<vector<int>> result = copy_vec(vec);
    int size = vec.end() - vec.begin();

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (result[i][k] + result[k][j] < result[i][j])
                    result[i][j] = result[i][k] + result[k][j];
    }

    return result;
}

int dijkstra_heuristic(int i, int j, vector<vector<int>> cost, vector<vector<int>> heuristic) {
    return cost[i][j];
}

int greedy_best_first_heuristic(int i, int j, vector<vector<int>> cost, vector<vector<int>> heuristic) {
    return heuristic[i][j];
}

int astar_heuristic(int i, int j, vector<vector<int>> cost, vector<vector<int>> heuristic) {
    return cost[i][j] + heuristic[i][j];
}

void greedy_search(vector<vector<int>> vec, vector<vector<int>> h, int startnode, map<int,string> cities,
    int (*func)(int, int, vector<vector<int>>, vector<vector<int>>)) {
    int n = vec.end() - vec.begin();
    vector<vector<int>> cost;
    vector<int> distance, path, visited;
    int i, j, count, mindistance, nextnode, INF = 10000;

    // init values
    for (i = 0; i < n; ++i) {
        vector<int> row;
        for (j = 0; j < n; ++j) {
            if (vec[i][j] == 0)
                row.push_back(INF);
            else
                row.push_back(vec[i][j]);
        }
        cost.push_back(row);
    }      

    for (i = 0; i < n; ++i) {
        distance.push_back(cost[startnode][i]);
        path.push_back(startnode);
        visited.push_back(0);
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        // step with minimal weight
        mindistance = INF;
        for (i = 0; i < n; ++i)
            if (!visited[i] && (distance[i] < mindistance)) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1; 
        // find path to node with minimal weight
        for (i = 0; i < n; ++i)
            if (!visited[i])
                if (mindistance + func(nextnode,i,cost,h) < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    path[i] = nextnode;
                }

        count++;
    }

    // output results
    output_path(distance, path, startnode, cities);
}

void dijkstra_search(vector<vector<int>> vec, int startnode, map<int,string> cities) {
    int n = vec.end() - vec.begin();
    vector<vector<int>> cost;
    vector<int> distance, path, visited;
    int i, j, count, mindistance, nextnode, INF = 10000;

    // init values
    for (i = 0; i < n; ++i) {
        vector<int> row;
        for (j = 0; j < n; ++j) {
            if (vec[i][j] == 0)
                row.push_back(INF);
            else
                row.push_back(vec[i][j]);
        }
        cost.push_back(row);
    }      

    for (i = 0; i < n; ++i) {
        distance.push_back(cost[startnode][i]);
        path.push_back(startnode);
        visited.push_back(0);
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        // step with minimal weight
        mindistance = INF;
        for (i = 0; i < n; ++i)
            if (!visited[i] && (distance[i] < mindistance)) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1; 
        // find path to node with minimal weight
        for (i = 0; i < n; ++i)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    path[i] = nextnode;
                }

        count++;
    }

    // output results
    output_path(distance, path, startnode, cities);
}

void output_path(vector<int> distance, vector<int> path, int startnode, map<int, string> cities) {
    int n = distance.end() - distance.begin();
    int i, j;

    for (i = 0; i < n; ++i) {
        if (i != startnode) {
            cout << cities[startnode] << " - " << cities[i] << ". Distance: " << distance[i] << " km. Path: ";
              
            vector<int> output;
            output.push_back(i);
            j = i;
            do {
                j = path[j];
                output.push_back(j);
            } while (j != startnode);

            reverse(output.begin(), output.end());
            int size = output.end() - output.begin();

            for (j = 0; j < size; ++j) {
                cout << cities[output[j]];
                if (j != size - 1)
                    cout << " -> ";
            }
            cout << endl;
        }
    }
    cout << endl;
}