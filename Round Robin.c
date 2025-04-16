#include <stdio.h>

struct Process {
    int id;
    int bt;
    int rt; // Remaining time
    int wt;
    int tat;
};

int main() {
    int n, tq, time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                done = 0;

                if (p[i].rt > tq) {
                    time += tq;
                    p[i].rt -= tq;
                } else {
                    time += p[i].rt;
                    p[i].wt = time - p[i].bt;
                    p[i].rt = 0;
                }
            }
        }
    } while (!done);

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
    }

    // Print result
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
