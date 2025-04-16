#include <stdio.h>

struct Process {
    int id;
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

void sortByBurstTime(struct Process p[], int n) {
    struct Process temp;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].bt > p[j+1].bt) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    
    // Input burst times
    for(int i=0; i<n; i++) {
        p[i].id = i+1;
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].bt);
    }

    // Sort by burst time (SJF)
    sortByBurstTime(p, n);

    // Calculating Waiting Time and Turnaround Time
    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for(int i=1; i<n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Printing results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int total_wt = 0, total_tat = 0;
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat/n);

    return 0;
}
