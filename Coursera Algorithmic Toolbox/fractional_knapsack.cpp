#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using std::vector;

double get_optimal_value(int items, int capacity, vector<vector<int>> sorted) {
    double value = 0.0;

    for (int j=0; j < items; j++){
        if (capacity == 0){
            return value;
        }
        int a = min(capacity, sorted[j][1]);
        value += static_cast< double >(a) * (static_cast< double >(sorted[j][0])/static_cast< double >(sorted[j][1]));
        capacity -= a;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    vector<vector<int>> sorted;

    for (int i=0; i < n; i++){
        vector<int> item;
        item.push_back(values[i]);
        item.push_back(weights[i]);
        sorted.push_back(item);
    }

    sort(sorted.begin(), sorted.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return (static_cast< double >(a[0])/static_cast< double >(a[1])) > (static_cast< double >(b[0])/static_cast< double >(b[1]));
         });

    double optimal_value = get_optimal_value(n, capacity, sorted);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}

