#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for(int i = 1; i < n; i++) {
        if(time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[100], frames[10], time[10];
    int n, f, faults = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        int hit = 0;
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                hit = 1;
                break;
            }
        }

        if(!hit) {
            int empty = -1;
            for(int j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            counter++;
            faults++;

            if(empty != -1) {
                frames[empty] = pages[i];
                time[empty] = counter;
            } else {
                int pos = findLRU(time, f);
                frames[pos] = pages[i];
                time[pos] = counter;
            }
        }

        printf("Page %d → ", pages[i]);
        for(int j = 0; j < f; j++) {
            if(frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
