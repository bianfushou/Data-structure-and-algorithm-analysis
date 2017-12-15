#include<iostream>
#include <ctime>
#include<vector>
#include"quick_sort.h"
using namespace std;

#define N 1000
int main() {

	srand((unsigned)time(0));
	vector<int> vec(N);
	for (int i = 0; i<N; i++) {
		vec[i] = rand() % N;
		//cout << vec[i] << " ";
	}
	cout << endl;
	clock_t start = clock();
	quickSort(vec);
	clock_t ends = clock();
	cout << "quick Running Time : " << ends - start << endl;

	cout << endl;
	int i;

	cin >> i;
}
