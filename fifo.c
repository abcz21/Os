#include <stdio.h>

int main() {
    int pages[100], frames[10], n, f, i, j, k = 0, faults = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in frame
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If not found, replace using FIFO
        if (flag == 0) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
