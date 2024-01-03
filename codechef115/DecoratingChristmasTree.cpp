#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int leaves = y / 3;
        int x_left, leaves1;

        if (x >= leaves) {
            x_left = x - leaves;
            leaves1 = leaves;
        } else {
            x_left = 0;
            leaves1 = x;
        }

        int leaves2 = x_left / 2;

        if (leaves2 + leaves1 >= n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;

}
