#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int n, ud, pd, neg = 0, norg, cd = 0, cdp = 1; 
    printf("Informe um número: ");
    scanf(" %d", &n);

    // Flag in case of n beign negative.
    if(n < 0){
        neg = 1;
        n *= -1;
    }
    // Saving the original value of n
    norg = n;
    // Storing the last digit of n.
    ud = n % 10;

    // Getting the first digit of n and counting the number of digits.
    while (n > 0){
        pd = n % 10;
        n /= 10;
        cd++;
    }
    // Using the counter to make 10^(number of digits).
    for(int i = cd; i > 1; i--){
        cdp *= 10;
    }
    // Digit exchange process.
    int ud2 = ud * cdp;
    int pd2 = pd * cdp;
    norg = (norg - pd2) - ud;
    norg = norg + ud2 + pd;

    // Calling the flag and checking if it was activated. 
    if(neg == 1){
        norg *= -1;
    }
    printf("> %d\n", norg);
    return 0;
}