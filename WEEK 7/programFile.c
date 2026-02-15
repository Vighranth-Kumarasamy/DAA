//CH.SC.U4CSE24149 VIGHRANTH SK
#include <stdio.h>
#define MAX 50
struct Job {
    int id;
    int profit;
    int deadline;
};
int main() {
    printf("CH.SC.U4CSE24149 VIGHRANTH \n");
    int n, i, j;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[MAX];
    for(i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("\nEnter profit for Job %d: ", i+1);
        scanf("%d", &jobs[i].profit);
        printf("Enter deadline for Job %d: ", i+1);
        scanf("%d", &jobs[i].deadline);
    }
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(jobs[j].profit < jobs[j+1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
    int maxDeadline = 0;
    for(i = 0; i < n; i++) {
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    int slot[MAX];
    int totalProfit = 0;
    for(i = 0; i <= maxDeadline; i++)
        slot[i] = -1;
    for(i = 0; i < n; i++) {
        for(j = jobs[i].deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("\n\nTime Slot\tJob\n");
    for(i = 1; i <= maxDeadline; i++) {
        if(slot[i] != -1)
            printf("%d\t\tJ%d\n", i, slot[i]);
        else
            printf("%d\t\t--\n", i);
    }
    printf("\nMaximum Profit = %d\n", totalProfit);
    return 0;
}
