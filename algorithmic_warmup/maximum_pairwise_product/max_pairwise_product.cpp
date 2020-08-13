#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//Calculate max_pairwise_product as the product of the two max numbers in array
long long max_pairwise_product(const std::vector<long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    long max = INT_MIN;

    int max_index_1 = -1, max_index_2 = -1;

    for (int first = 0; first < n; ++first) {
        if(numbers[first] > max) {
            max = numbers[first];
            max_index_1 = first;
        }        
    }

    max = INT_MIN;

    for (int first = 0; first < n; ++first) {
        if(numbers[first] >= max && first != max_index_1) {
            max = numbers[first];
            max_index_2 = first;
        }        
    }

    // cout << "Max Indices: " << max_index_1 << " " << max_index_2 << endl;

    max_product = (long long)( numbers[max_index_1] * numbers[max_index_2]);
    return max_product;
}

int main() {
    int n;
    cin >> n; // input length of vector(array)
    vector<long> numbers(n);
    for (int i = 0; i < n; ++i) { 
        cin >> numbers[i]; // input vector(array) elements
    }

    cout << max_pairwise_product(numbers) << "\n";
    
    return 0;
}
