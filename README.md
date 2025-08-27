#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int array[10000];
	for (int i = 1; i <= n; i++) {
		array[i] = 1;
	}

	int i = 1;
	int step = 1;
	int count = n;
	while (count!=0) {

		if (array[i] == 1 && step == m) {
			array[i] = 0;
			cout << i << "";
			step = 1;
			count--;
		}
		else if (array[i] == 1 && step != m) {
			step++;
		}
		if (i == n) {
			i = 1;
		}
		else {
			i++;
		}
	}
	return 0;
}
