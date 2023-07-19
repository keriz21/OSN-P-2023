#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;

int total = 0;

bool ratarata(vector<long long> a, vector<long long> b){
    long long hasila;
    long long hasilb;

    hasila = accumulate(a.begin(),a.end(),0.0) * b.size();
    hasilb = accumulate(b.begin(),b.end(),0.0) * a.size();

    bool hasil = hasila > hasilb;

    return hasil;
}


void dibandingkan(vector<long long> vA, vector<long long>vB){


    if(vB.size() == 0){
        total = -1;
        return;
    }

    // long long rasioA = accumulate(vA.begin(),vA.end(),0) * vB.size();
    // long long rasioB = accumulate(vB.begin(),vB.end(),0) * vA.size();

    // bool banding = rasioA > rasioB;
    bool banding = ratarata(vA,vB);
    if(banding){
        return;
    }
    int temp = vB[0];
    int jumlah = 1;
    for(int i=1;i< vB.size();i++){
        if(vB[i] == temp){
            jumlah++;
        } else {
            break;
        }
    }

    for(int i=0;i<jumlah;i++){
        vA.push_back(temp);
    }

    total += (temp * jumlah);

    vB.erase(remove(vB.begin(),vB.end(),temp),vB.end());
    
    return dibandingkan(vA,vB);
    
}

int main(int argc, char const *argv[])
{
    /* code */
    long long n,m;
    // cin >> n;
    // cin >> m;

    n = 3; m = 4;

    vector<long long> A = {5,1,3};
    vector<long long> B = {8,5,4,9};

    // for(int i=0;i<n;i++){
    //    long long temp;
    //    cin >> temp;
    //    A.push_back(temp);
    // }

    // for(int i=0;i<m;i++){
    //     long long temp;
    //    cin >> temp;
    //    B.push_back(temp);
    // }

    sort(B.begin(),B.end(),greater<int>());
    dibandingkan(A,B);
    cout << total << endl;
    return 0;
}
