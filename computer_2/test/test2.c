#include <stdio.h>

void func(int array[][4], int m, int N) {
	for (int i = N-1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			array[i][j] *= m;
		}
	}
}

int main(void) {
	int array[][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

	func(array, 2, 4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

