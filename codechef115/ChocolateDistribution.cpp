#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test_cases;
    cin >> test_cases;

    while(test_cases--) {
        int number;
        cin >> number;

        if(number % 2 == 0) {
            cout << number / 2 << ' ' << number << endl;
        } else {
            cout << number / 2 + 1 << ' ' << number <<endl;
        }
    }

    return 0;

}
