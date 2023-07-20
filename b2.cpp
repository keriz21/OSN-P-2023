#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    long long n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> arr;

    for(int i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());

    // for(int num:arr){
    //     cout << num << endl;
    // }

    long long guna = 0;
    int tinggi = m+k;
    for(int i=0;i<n;i++){
        if(arr[i] > tinggi){
            guna++;
            tinggi = arr[i]+k;
        }
    }

    cout << guna << endl;
    return 0;
}
