#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {7,1,2,3,1,2,3,1,2,4,5,5,4,1};
    vector<int> aux(10, 0);


    for(int i = 0; i < v.size(); i++){
        aux[v[i]]++;
    }
    for(int i = 0;i<aux.size();i++)
        if(aux[i] % 2 == 1){
            cout << i << " appears odd number of times: " << aux[i] << endl;
        }

    return 0;
}
