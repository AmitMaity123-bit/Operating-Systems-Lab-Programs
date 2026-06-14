#include <stdio.h>

#define FRAME_SIZE 30

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[FRAME_SIZE], pages[100], time[FRAME_SIZE];
    int total_pages, page_faults = 0, counter = 0;
    int i, j, flag1, flag2, pos;

    printf("Enter total number of pages: ");
    scanf("%d", &total_pages);
    printf("Enter the page reference string: ");
    for(i = 0; i < total_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < FRAME_SIZE; ++i) frames[i] = -1;

    for(i = 0; i < total_pages; ++i) {
        flag1 = flag2 = 0;

        for(j = 0; j < FRAME_SIZE; ++j) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0) {
            for(j = 0; j < FRAME_SIZE; ++j) {
                if(frames[j] == -1) {
                    counter++;
                    page_faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) {
            pos = findLRU(time, FRAME_SIZE);
            counter++;
            page_faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("\n");
        for(j = 0; j < FRAME_SIZE; ++j) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
