#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int tank, vector<int> stops) {
    int refills = 0;
    int current = 0;

    while (current <= (stops.size()-2)){
        int last = current;
        while((current <= (stops.size()-2)) && ((stops[current + 1] - stops[last]) <= tank)){
            current++;
        }

        if (current == last){
            return -1;
        }

        if (current <= (stops.size()-2)){
            refills++;
        }
    }

    return refills;

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);

    stops.at(0) = 0;

    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);

    stops.at(n+1)=d;

    cout << compute_min_refills(m, stops) << "\n";

    return 0;
}
