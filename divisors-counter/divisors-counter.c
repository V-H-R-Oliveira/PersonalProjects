#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void sieveEratosthenes(unsigned long n, bool array[])
{
    long double limit = sqrtl((long double)n);
    
    for(unsigned long i = 2; i <= n; ++i)
        array[i] = true;
    
    for(unsigned long i = 2; i <= (unsigned long)limit; ++i)
    {
        if(array[i])
        {
            for(unsigned long j = i * i; j <= n; j+=i)
                array[j] = false;
        }
    }
}

unsigned long countDivisors(unsigned long n)
{
    if(n < 2)
        exit(EXIT_FAILURE);
    
    bool primes[n - 1];
    unsigned long counter = 0, ans = 1;

    sieveEratosthenes(n, primes);
    
    for(unsigned long i = 2; i <= n; ++i)
    {
        if(primes[i])
        {
            while(true)
            {
                if(n % i != 0)
                    break;
                counter++;
                n /= i;
            }

            ans *= (counter + 1);
            counter = 0;
        }
    }
    
    return ans;
} 

int main(int argc, char **argv)
{
    unsigned long number;

    if(argc == 2)
    {
        number = strtoul(argv[1], NULL, 10);
        printf("Divisors: %lu\n", countDivisors(number));
    }else
    {
        fprintf(stderr, "Usage %s <number>\n", *argv);
        return 1;
    }

    return 0;
}