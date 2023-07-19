#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
    /* code */

    int n,m;
    // cin >> n >> m;

    n = 3; m = 4;


    vector<long long>a = {5,1,3};
    vector<long long>b = {8,5,4,9};

    long long sumA = 0;
    long long sumB = 0;

    // for(int i=0;i<n;i++){
    //     cin >> a[i];
    //     sumA += a[i];
    // }

    // for(int i=0;i<m;i++){
    //     cin >> b[i];
    //     sumB += b[i];
    // }

    sort(b.begin(),b.end(),greater<long long>());

    for(int num:b){
        cout << num << " "; 
    }
    cout << endl;

    // int jumlah;
    // jumlah = count(b.begin(),b.end(),10);

    //cout << jumlah << endl;

    long long nA = n;
    long long nB = m;

    long long rA = sumA * nB;
    long long rB = sumB * nA;

    int index = 0;

    long long sumTotal = 0;
    long long sumTemp = 0;

    int total = 0;

    while(((b.size()>0)&&(rA <= rB))){
        // long long temp = b[index];
        // sumTemp = 0;

        // int jumlah = count(b.begin(),b.end(),temp);
        // index += jumlah;
        // nA += jumlah;
        // nB -= jumlah;

        // sumTemp = temp * jumlah;
        // sumTotal += sumTemp;


        // sumA += sumTemp;
        // sumB -= sumTemp;

        // rA = sumA * nB;
        // rB = sumB * nA;

        long long temp = b[0];
        int jumlah = 1;

        for(int i=1;i<b.size();i++){
            if (b[i] == temp)
            {
                /* code */
                jumlah++;
            } else {
                break;
            }
        }

        for (int i = 0; i < jumlah; i++)
        {
            /* code */
            a.push_back(temp);
        }

        total += (temp * jumlah);

        b.erase(remove(b.begin(),b.end(),temp),b.end());

        

        rA = accumulate(a.begin(),a.end(),0.0) * b.size();
        rB = accumulate(b.begin(),b.end(),0.0) * a.size();
    }

    if(b.size()==0){
        cout << -1 << endl;
    } else {
        cout << sumTotal << endl;
    }



    return 0;
}
