#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    long m,n;
    cin >> n >> m;

    vector<int> A;
    vector<int> B;

    long sumA = 0;
    long sumB = 0;

    for(int i=0;i<n;i++){
        long temp;
        cin >> temp;
        sumA += temp;
        A.push_back(temp);
    }

    for(int i=0;i<m;i++){
        long temp;
        cin >> temp;
        sumB += temp;
        B.push_back(temp);
    }

    sort(B.begin(),B.end(),greater<long>());

    // for(int i=0;i<B.size();i++){
    //     cout << B[i] << " ";
    // }
    // cout << endl;

    long rA = sumA * m;
    long rB = sumB * n;

    // cout << sumA << " " << sumB << endl;

    long nA = n;
    long nB = m;

    long total;
    long index = 0;
    long index2 = 0;

    long sumTotal = 0;

    int iterasi = 1;

    while(((nB>0) && (rA <= rB))){
        long base;
        // cout  << "temp sementera " << temp << endl;
        // cout << B[0] << endl;
        long sumTemp = 0;

        while ((nB>0) && (B[base] == B[index]))
        {
            /* code */
            sumTemp += B[index];
            index++;
            nA++;
            nB--; 
            index++;
        }
        
        sumTotal += sumTemp;
        // cout << "total sementara " << sumTotal << endl;

        sumA += sumTemp;
        sumB -= sumTemp;



        rA = sumA * nB;
        rB = sumB * nA;

    }

    cout << sumTotal << endl;
    
    return 0;
}
