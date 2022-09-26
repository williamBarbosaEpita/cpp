#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 0)
        return false;
    if((n == 1) || (n == 2))
        return true;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}


int main()
{
    int n;
    while(cin >> n)
    {
        if(isPrime(n))
            cout << n << "is a prime: True\n";
        else
            cout << n << "is a prime: False\n";
    }
    return 0;
}
