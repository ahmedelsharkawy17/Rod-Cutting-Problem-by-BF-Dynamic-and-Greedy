#include <iostream>
#include <climits> 
#include <chrono>  

using namespace std;
using namespace chrono;
int greedyRodCutting(int prices[], int n) {
    int maxValue = 0;
    int remainingLength = n;


    while (remainingLength > 0) {
        int maxPrice = INT_MIN;
        int bestCut = 0;

        for (int i = 1; i <= remainingLength; ++i) {
            if (prices[i - 1] > maxPrice) {
                maxPrice = prices[i - 1];
                bestCut = i;
            }
        }


        remainingLength -= bestCut;
        maxValue += maxPrice;
    }

    return maxValue;
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
    int maxProfit = greedyRodCutting(prices, n);

    auto end = high_resolution_clock::now();


    auto duration = duration_cast<microseconds>(end - start);


    cout << "Maximum obtainable value (Greedy): " << maxProfit << endl;

    cout << "Time taken by the algorithm: " << duration.count() << " microseconds" << endl;


    delete[] prices;
    return 0;
}
