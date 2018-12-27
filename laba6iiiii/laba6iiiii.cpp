#include "pch.h" 
#include <iostream> 
#include <time.h> 
using namespace std;

int main()
{
	srand(time(NULL));
	int n, j, p, t = 0, i1 = -1, k1 = 0, l = 0;
	cout << "Enter N to create matrix NxN:\n";
	cin >> n;
	int **a = new int *[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			a[i][k] = rand() % 50 - 10;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (fabs(a[i][k]) > fabs(t)) t = a[i][k];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] == t) {
				if (l == 1) break;
				j = i;
				p = k;
				l = 1;
			}
		}
	}

	cout << "Your matrix N:\n";
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << a[i][k]<< "  ";
		}
		cout << "\n";
	}
	cout << "The greatest number is: " << t << "\n";
	cout << "Row to be deleted: " << j + 1 << "\n";
	cout << "Column to be deleted: " << p + 1 << "\n";

	int **b = new int *[n - 1];
	for (int i = 0; i < n - 1; i++) {
		b[i] = new int[n - 1];
	}

	for (int i = 0; i < n; i++) {
		if (i == j) {
			continue;
		}
		i1 += 1;
		for (int k = 0; k < n; k++) {
			if (k == p) {
				continue;
			}
			b[i1][k1] = a[i][k];
			k1 += 1;
		}
		if (k1 != 0) k1 = 0;
	}

	cout << "Matrix N-1:\n";
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < n - 1; k++) {
			cout << b[i][k] << "  ";
		}
		cout << "\n";
	}
	system ("pause");
}