#include <stdio.h>
void allocate(int blocks[], int b, int process[], int p, int type) {
    int alloc[p], i, j;
    for (i = 0; i < p; i++) alloc[i] = -1;
    for (i = 0; i < p; i++) {
        int idx = -1;
        for (j = 0; j < b; j++) {
            if (blocks[j] >= process[i]) {
                if (type == 1) { // First Fit
                    idx = j;
                    break;
                }
                if (type == 2 && (idx == -1 || blocks[j] < blocks[idx])) // Best Fit
                    idx = j;
                if (type == 3 && (idx == -1 || blocks[j] > blocks[idx])) // Worst Fit
                    idx = j;
            }
        }
        if (idx != -1) {
            alloc[i] = idx;
            blocks[idx] -= process[i];
        }
    }
    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < p; i++) {
        printf("%d\t%d\t", i + 1, process[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main() {
    int b, p, i, choice;
    printf("Enter number of blocks: ");
    scanf("%d", &b);
    int blocks[b], original[b];
    printf("Enter block sizes:\n");
    for (i = 0; i < b; i++) {
        scanf("%d", &blocks[i]);
        original[i] = blocks[i]; 
    }
    printf("Enter number of processes: ");
    scanf("%d", &p);
    int process[p];
    printf("Enter process sizes:\n");
    for (i = 0; i < p; i++) scanf("%d", &process[i]);
    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter choice: ");
    scanf("%d", &choice);
    for (i = 0; i < b; i++) blocks[i] = original[i]; 
    if (choice >= 1 && choice <= 3)
        allocate(blocks, b, process, p, choice);
    else
        printf("Invalid choice.\n");
    return 0;
}
