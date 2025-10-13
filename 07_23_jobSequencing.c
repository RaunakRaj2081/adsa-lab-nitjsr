// Write a function to implement the job sequencing with deadline problem in which each job has integer 
 // deadline and unit processing time. 

 #include <stdio.h>
#include <string.h>

struct Job {
    char id;
    int dead, profit;
};

int main() {
    int n, i, j;
    scanf("%d", &n);

    struct Job a[n];
    for(i = 0; i < n; i++)
        scanf(" %c %d %d", &a[i].id, &a[i].dead, &a[i].profit);

    // Sort by profit (descending)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(a[i].profit < a[j].profit) {
                struct Job t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    int slot[n];
    memset(slot, -1, sizeof(slot));

    for(i = 0; i < n; i++) {
        for(j = a[i].dead - 1; j >= 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(slot[i] != -1)
            printf("%c ", a[slot[i]].id);
    }

    return 0;
}
