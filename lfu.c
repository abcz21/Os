#include <stdio.h>

int findLFU(int freq[], int frames[], int f) {
    int min = freq[0], pos = 0;
    for(int i = 1; i < f; i++) {
        if(freq[i] < min) {
            min = freq[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[100], frames[10], freq[10];
    int n, f, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(int i = 0; i < f; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            int empty = -1;
            for(int j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frames[empty] = pages[i];
                freq[empty] = 1;
            } else {
                int pos = findLFU(freq, frames, f);
                frames[pos] = pages[i];
                freq[pos] = 1;
            }
            faults++;
        }

        // Print current frame status
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
