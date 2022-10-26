#include<iostream>
using namespace std;

bool isPrime(unsigned long int n)
{
    if (n <= 0 || n == 1)
        return false;
    if(n == 2)
        return true;
    if (n%2 == 0)
	return false;
    for (unsigned long int i = 3; i< n/2; i+=2)
    {
        if (n % i == 0)
            return false;
        if (i * i > n)
            break;
    }
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
