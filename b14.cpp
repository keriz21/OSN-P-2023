#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long total = 0;

double rata_rata(const vector<long long>& arr) {
    return static_cast<double>(accumulate(arr.begin(), arr.end(), 0LL)) / arr.size();
}

bool ratarata(const vector<long long>& a, const vector<long long>& b) {
    double rata_a = rata_rata(a);
    double rata_b = rata_rata(b);

    return (rata_a * b.size()) > (rata_b * a.size());
}

void dibandingkan(vector<long long>& vA, vector<long long>& vB) {
    sort(vB.begin(), vB.end(), greater<int>());

    while (!vB.empty()) {
        if(ratarata(vA,vB)){
            break;
        }
        int temp = vB[0];
        int jumlah = count(vB.begin(), vB.end(), temp);

        for (int j = 0; j < jumlah; j++) {
            vA.push_back(temp);
        }

        total += (temp * jumlah);

        vB.erase(remove(vB.begin(), vB.end(), temp), vB.end());
    }

    // if (vB.empty()) {
    //     total = -1;
    // }
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> A(n);
    vector<long long> B(m);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    dibandingkan(A, B);
    cout << total << endl;
    return 0;
}
