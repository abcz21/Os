#include <stdio.h>

int main() {
    int p, r, i, j, k;
    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int finish[10] = {0}, safeSeq[10], count = 0;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &p, &r);

    printf("Enter Allocation matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Calculate Need matrix
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Find Safe Sequence
    while (count < p) {
        int found = 0;
        for (i = 0; i < p; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (k = 0; k < r; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < p; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
