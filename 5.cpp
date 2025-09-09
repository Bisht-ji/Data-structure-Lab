#include<iostream>
using namespace std;

struct distance{
    int km;
    int meter;
};

int main() {
    struct distance T1 = {10, 5};
    struct distance T2 = {12, 9};
    struct distance T3;

    T3.meter = T1.meter + T2.meter;
    T3.km = T1.km + T2.km + (T3.meter / 1000);
    T3.meter = T3.meter % 1000;

    cout << T3.km << ", " << T3.meter;
    return 0;
}

