#include<iostream>
using namespace std;
struct height{
    int feet;
    int inch;
};
int main()
{
    height T1 = {10,5};
    height T2 = {12,9};
    height T3;
    T3.inch = T1.inch+T2.inch;
    T3.feet = T1.feet+T2.feet+T3.inch/12;
    T3.inch = T3.inch%12;
    cout<<T3.feet<<", "<<T3.inch;
    return 0;
}