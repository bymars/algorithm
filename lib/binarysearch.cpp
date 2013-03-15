#include <iostream>
#include "binarysearch.h"

using namespace std;

int binary_search(int* A, unsigned low, unsigned high, int target) {
	while (low < high) {
		unsigned mid = low + (high - low) / 2;
		if (A[mid] == target) return mid;
		target < A[mid] ? high = mid : low = mid + 1;
	}
	return -1;
}

int upper_bound(int *A, unsigned low, unsigned high, int target) {
	while (low < high) {
		unsigned mid = low + (high - low) / 2;
		if (A[mid] <= target) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

int lower_bound(int *A, unsigned low, unsigned high, int target) {
	while (low < high) {
		unsigned mid = low + (high - low) / 2;
		if (A[mid] >= target) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}
