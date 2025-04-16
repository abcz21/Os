#include <stdio.h>
#include <string.h>
struct Process {
    char name[10];
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    int total_wt = 0, total_tat = 0;
    for (i = 0; i < n; i++) {
        printf("Enter the process name %d: ", i);
        scanf("%s", p[i].name);
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &p[i].burst_time);
    }
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nTotal Waiting Time: %d", total_wt);
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nTotal Turnaround Time: %d", total_tat);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++) {
        printf("  %s  |", p[i].name);
    }
    printf("\n0");
    int time = 0;
    for (i = 0; i < n; i++) {
        time += p[i].burst_time;
        printf("     %d", time);
    }
    printf("\n");
    return 0;
}
