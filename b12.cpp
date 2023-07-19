#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

double ratarata(vector<int> data) {
    double hasil;
    hasil = accumulate(data.begin(), data.end(), 0.0) / data.size();
    return hasil;
}

int dibandingkan(vector<int> vA, vector<int> vB) {
    int total;
    if (vB.empty()) {
        total = -1;
        return total;
    }

    if (ratarata(vA) > ratarata(vB)) {
        return total;
    }

    int temp = vB[0];
    int jumlah = 1;

    for (int i = 1; i < vB.size(); i++) {
        if (vB[i] == temp) {
            jumlah++;
        } else {
            break;
        }
    }

    for (int i = 0; i < jumlah; i++) {
        vA.push_back(temp);
    }

    total += (temp * jumlah);

    vB.erase(remove(vB.begin(), vB.end(), temp), vB.end());
    dibandingkan(vA, vB);
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> A;
    vector<int> B;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }

    sort(B.begin(), B.end(), greater<int>());
    int hasil = dibandingkan(A, B);
    cout << hasil << endl;

    return 0;
}
