#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int total = 0;

bool ratarata(const vector<long long>& a, const vector<long long>& b) {
    long long hasila = accumulate(a.begin(), a.end(), 0LL) * b.size();
    long long hasilb = accumulate(b.begin(), b.end(), 0LL) * a.size();

    bool hasil = hasila > hasilb;

    return hasil;
}

void dibandingkan(vector<long long>& vA, vector<long long>& vB) {
    if (vB.size() == 0) {
        total = -1;
        return;
    }

    bool banding = ratarata(vA, vB);
    if (banding) {
        return;
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
    /* code */
    long long n,m;
    cin >> n;
    cin >> m;

    vector<long long> A;
    vector<long long> B;

    for(int i=0;i<n;i++){
       long long temp;
       cin >> temp;
       A.push_back(temp);
    }

    for(int i=0;i<m;i++){
        long long temp;
       cin >> temp;
       B.push_back(temp);
    }

    sort(B.begin(), B.end(), greater<int>());
    dibandingkan(A, B);
    cout << total << endl;
    return 0;
}
