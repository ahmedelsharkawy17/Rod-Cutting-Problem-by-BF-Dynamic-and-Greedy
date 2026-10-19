#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

int rodCutting(int prices[], int n) {
    int* dp = new int[n + 1];
    dp[0] = 0;


    for (int i = 1; i <= n; ++i) {
        int maxVal = -1;

        for (int j = 1; j <= i; ++j) {
            maxVal = max(maxVal, prices[j - 1] + dp[i - j]);
        }

        dp[i] = maxVal;
    }

    int result = dp[n];
    delete[] dp;
    return result;
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int* prices = new int[n];
    cout << "Enter the prices for each rod length (1 to " << n << "): ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    auto start = high_resolution_clock::now();

    int maxProfit = rodCutting(prices, n);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Maximum obtainable value: " << maxProfit << endl;
    cout << "Time taken by the algorithm: " << duration.count() << " microseconds" << endl;
    delete[] prices;
    return 0;
}
