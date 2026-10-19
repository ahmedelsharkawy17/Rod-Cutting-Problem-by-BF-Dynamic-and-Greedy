#include <iostream>
#include <climits>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int* prices = new int[n];
    cout << "Enter the prices for each rod length (1 to " << n << "): ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int* dp = new int[n + 1];
    dp[0] = 0;

    auto start = high_resolution_clock::now();
    for (int length = 1; length <= n; ++length) {
        int maxValue = INT_MIN;
        for (int cut = 1; cut <= length; ++cut) {

            maxValue = max(maxValue, prices[cut - 1] + dp[length - cut]);
        }
        dp[length] = maxValue;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Maximum obtainable value: " << dp[n] << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    delete[] prices;
    delete[] dp;
    return 0;
}
