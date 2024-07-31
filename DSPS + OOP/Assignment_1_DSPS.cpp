#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search and return the index of the target
int linearSearch(const vector<int>& A, int target) {
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to count the number of occurrences of the target in the array
int countOccurrences(const vector<int>& A, int target) {
    int count = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == target) {
            ++count;
        }
    }
    return count;
}

// Function to find the first and last occurrence of the target in the array
pair<int, int> findFirstAndLastOccurrence(const vector<int>& A, int target) {
    int first = -1, last = -1;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == target) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    return make_pair(first, last);
}

int main() {
    vector<int> A = {1, 2, 2, 3, 4, 4, 4, 5, 6};
    int target = 4;

    int index = linearSearch(A, target);
    cout << "Index of target: " << index << endl;

    int occurrences = countOccurrences(A, target);
    cout << "Number of occurrences of target: " << occurrences << endl;

    pair<int, int> firstLast = findFirstAndLastOccurrence(A, target);
    cout << "First occurrence of target: " << firstLast.first << endl;
    cout << "Last occurrence of target: " << firstLast.second << endl;

    return 0;
}
