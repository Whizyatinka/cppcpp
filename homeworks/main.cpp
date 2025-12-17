#include <iostream>
#include <set>
using namespace std;

int main() {
    const int SIZE = 5;
    int A[SIZE], B[SIZE];
    int t;

    cout << "--- Working with arrays ---" << endl;

    cout << "Enter elements of array A (" << SIZE << " elements): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> A[i];
    }

    cout << "Enter elements of array B (" << SIZE << " elements): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> B[i];
    }

    cout << "Enter value t: ";
    cin >> t;

    int countA = 0, countB = 0;
    for (int i = 0; i < SIZE; i++) {
        if (A[i] < t) {
            countA++;
        }
        if (B[i] < t) {
            countB++;
        }
    }

    cout << "Number of elements less than " << t << " in array A: " << countA << endl;
    cout << "Number of elements less than " << t << " in array B: " << countB << endl;

    if (countA <= countB) {
        cout << "Array A: ";
        for (int i = 0; i < SIZE; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        cout << "Array B: ";
        for (int i = 0; i < SIZE; i++) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Array B: ";
        for (int i = 0; i < SIZE; i++) {
            cout << B[i] << " ";
        }
        cout << endl;

        cout << "Array A: ";
        for (int i = 0; i < SIZE; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    cout << "\n--- Working with sets ---" << endl;
    set<int> setA, setB, symDiff;
    int n, elem;

    cout << "count A: ";
    cin >> n;
    cout << "elements A:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        setA.insert(elem);
    }

    cout << "count B: ";
    cin >> n;
    cout << "elements B:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        setB.insert(elem);
    }

    for (int elem : setA) {
        if (setB.find(elem) == setB.end()) {
            symDiff.insert(elem);
        }
    }

    for (int elem : setB) {
        if (setA.find(elem) == setA.end()) {
            symDiff.insert(elem);
        }
    }

    cout << "Symmetric difference of sets: ";
    if (symDiff.empty()) {
        cout << "empty set";
    }
    else {
        for (int elem : symDiff) {
            cout << elem << " ";
        }
    }
    cout << endl;

    if (!symDiff.empty()) {
        int sum = 0;
        int count = 0;
        for (int elem : symDiff) {
            sum += elem;
            count++;
        }
        double mathExpectation = (double)sum / count;
        cout << "Mathematical expectation: " << mathExpectation << endl;
    }
    else {
        cout << "Mathematical expectation is undefined (empty set)" << endl;
    }

    return 0;
}