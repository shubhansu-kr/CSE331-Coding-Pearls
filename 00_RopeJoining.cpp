// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution1
{
    // Solution Using Max Heap: If we have to use max heap, we can negate all the elements of the given input array.
    // [3, 4, 5] -> [-3, -4, -5];
    // Now in max heap -3 would be on top and we can negate after popping.
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Max Heap
        priority_queue<long long> pq;

        long long cost = 0;
        for(long long i = 0; i < n; ++i) {
            pq.push((arr[i]) * (-1));
        }
        while(pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            cost += (first + second) * (-1);
            pq.push((first+second));
        }

        return cost;
    }
};

class Solution
//  Solution using Min Heap: 
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // MinHeap: 
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        long long cost = 0;
        for(long long i = 0; i < n; ++i) {
            pq.push(arr[i]);
        }
        while(pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            cost += (first + second);
            pq.push((first+second));
        }

        return cost;
    }
};


//{ Driver Code Starts.

long long main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends