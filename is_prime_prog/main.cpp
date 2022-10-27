#include<iostream>
using namespace std;

long long square_root(long long n){
    long long i = 0;
    while(i * i < n)
        i++;
    return i; 
}

bool isPrime(unsigned long int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
	    return false;
    long long racine = square_root(n);
    for (unsigned long int i = 3; i <= racine; i += 1)
        if (n % i == 0)
            return false;
    return true;
}


int main()
{
    unsigned long int n;
    while(cin >> n)
    {
        if(isPrime(n))
            std::cout << n << " is a prime: True" << std::endl;
        else
            std::cout << n << " is a prime: False" << std::endl;
    }
    return EXIT_SUCCESS; 
}
