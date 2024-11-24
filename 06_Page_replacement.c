#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int frameCount) {
    int frames[frameCount];
    int front = 0; 
    int pageFaults = 0;
    int isFull = 0;


    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("Page Reference\tFrames\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;


        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[front] = page;
            front = (front + 1) % frameCount; 
            pageFaults++;


            if (!isFull && front == 0) {
                isFull = 1;
            }
        }


        printf("%d\t\t", page);
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameCount = 3; 

    fifoPageReplacement(pages, n, frameCount);

    return 0;
}
