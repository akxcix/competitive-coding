#include<iostream>
using namespace std;

int main()
{
    long sum = 0;
    long max = 0;
    long min = 5000000001;
    long int array[5];
    for(int i =0; i <5; i++)
    {
        cin>>array[i];
        sum += array[i];
    }
    for(int i =0; i <5; i++)
    {
        if(sum - array[i]> max)
        {
            max = sum - array[i];
        }
        if(sum - array[i]< min)
        {
            min = sum - array[i];
        }
    }
    cout<<min<<' '<<max;
    return 0;
}
