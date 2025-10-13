// Implement the coin changing problem using the greedy method.  
#include <stdio.h>
int main() {
    int n,i,amt;
    printf("Enter number of coins: ");
    scanf("%d",&n);
    int c[n];
    printf("Enter coin denominations: ");
    for(i=0;i<n;i++) scanf("%d",&c[i]);
    printf("Enter amount: ");
    scanf("%d",&amt);
    printf("Coins used: ");
    for(i=0;i<n;i++) {
        while(amt>=c[i]) {
            amt-=c[i];
            printf("%d ",c[i]);
        }
    }
    return 0;
}
