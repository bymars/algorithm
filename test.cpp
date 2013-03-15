#include <iostream>

#include "binarysearch.h"
using namespace std;
int main() {
	int A[20] = {0,1,1,1,1,2,2,2,2,4,4,4,4,5,6,6,6,10, 11, 11};

	cout << "search for 5: " << binary_search(A, 0, 20, 5) << endl;;
	cout << "lower of 6: " << lower_bound(A, 0, 20, 6) << endl;
	cout << "upper of 6: " << upper_bound(A, 0, 20, 6) << endl;
}
