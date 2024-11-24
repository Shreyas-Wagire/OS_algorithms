#include <stdio.h>

void calculateNeed(int need[][10], int max[][10], int allot[][10], int processes, int resources) {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

int isSafe(int processes, int resources, int avail[], int max[][10], int allot[][10]) {
    int need[10][10];
    calculateNeed(need, max, allot, processes, resources);

    int finish[10] = {0};
    int safeSeq[10];
    int work[10];

    for (int i = 0; i < resources; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < processes) {
        int found = 0;
        for (int p = 0; p < processes; p++) {
            if (!finish[p]) {
                int canAllocate = 1;
                for (int j = 0; j < resources; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allot[p][j];
                    }
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }

    printf("The system is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < processes; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    int processes, resources;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    int avail[10], max[10][10], allot[10][10];

    printf("Enter the available resources: ");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &avail[i]);
    }

    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    isSafe(processes, resources, avail, max, allot);

    return 0;
}
