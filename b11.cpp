#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;

int total = 0;

double ratarata(vector<int> vector){
    double hasil;

    // if (vector.size() == 0){
    //     return 0;
    // }

    hasil = accumulate(vector.begin(),vector.end(),0.0) / vector.size();

    return hasil;
}

// void compare(vector<int>& vA, vector<int>& vB){

//     bool banding;
//     banding = ratarata(vA) >= ratarata(vB);

//     if(banding){
//         return;
//     }
// }

// void geser(vector<int>& vA, vector<int>& vB){
//     if(vB.size() == 0){
//         total = -1;
//         return;
//     }

//     int temp = vB[0];
//     int jumlah = 1;
//     for(int i=1;i< vB.size();i++){
//         if(vB[i] == temp){
//             jumlah++;
//         } else {
//             break;
//         }
//     }

//     for(int i=0;i<jumlah;i++){
//         vA.push_back(temp);
//     }

//     total += (temp * jumlah);

//     vB.erase(remove(vB.begin(),vB.end(),temp),vB.end());
    
//     return compare(vA,vB);
// }

void dibandingkan(vector<int> vA, vector<int>vB){
    bool banding = ratarata(vA) > ratarata(vB);

    if(banding){
        return;
    }

    if(vB.size() == 0){
        total = -1;
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
    int n,m;
    cin >> n;
    cin >> m;

    vector<int> A;
    vector<int> B;

    for(int i=0;i<n;i++){
       int temp;
       cin >> temp;
       A.push_back(temp);
    }

    for(int i=0;i<m;i++){
        int temp;
       cin >> temp;
       B.push_back(temp);
    }

    sort(B.begin(),B.end(),greater<int>());
    dibandingkan(A,B);
    cout << total << endl;

    // for(int i=0;i<n;i++){
    //     cout << A[i] << " ";
    // }

    // cout << endl;

    // for(int i=0;i<m;i++){
    //     cout << B[i] << " ";
    // }
    // cout << endl;
    // B.erase(remove(B.begin(),B.end(),10),B.end());
    // cout << ratarata(A) << endl;
    // for(int i=0;i<B.size();i++){
    //     cout << B[i] << " ";
    // }
    // cout << endl;
    return 0;
}
