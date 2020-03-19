# [T1086 The First Number](https://acm.ecnu.edu.cn/contest/195/problem/1086/)

### Thoughts Jornal

The key insight 1 is almost jump to the mind instantly.





### Key Insights

1. Guess: We can use the logarithmic calculation to remove the influence of the latter digits. E.G.
   $$
   \log(256) = \log(2.56) + \log(100) = \log(2.56) + 2, \qquad\text{where  0 < log(2.56) < 1}
   $$
   Here we've drived the first integer of $256$ in the log expression $\log(2.56)$. The only thing we have to do next is the exponentiation calculation (reverse of logarithmic) and the `floor`.





### Language Specific Technique

1. The function `double log(double)` function in C or Python both represent natural logarithm! The solution of common is function `double log10(double)` for C and appended parameter like `log(n, 10)` for Python.





### Codes Comment

```c
#include <iostream>
#include <cmath>

int get_first_digit_of_power(int n){
    double r = n*log10(n);
    double frac = r - (int)r;
    return (int)pow(10, frac);
}

int main(int argc, const char * argv[]) {
    int n;
    while(true){
        std::cin >> n; if(!n) break;
        std::cout << get_first_digit_of_power(n) << std::endl;
    }
    return 0;
}
```





### Further Investigation

By remove the first digit and repeat the operation we can get the first $n$ digit of any large number.





### Tag Field

#math