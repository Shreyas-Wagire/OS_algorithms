#include <stdio.h>

void firstFit(int memorySize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (memorySize[j] >= processSize[i])
            {
                allocation[i] = j;
                memorySize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\n---------- First Fit -----------\n\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int memorySize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (memorySize[j] >= processSize[i])
            {
                if (bestIdx == -1 || memorySize[j] < memorySize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            memorySize[bestIdx] -= processSize[i];
        }
    }

    printf("\n---------- Best Fit -----------\n\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int memorySize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (memorySize[j] >= processSize[i])
            {
                if (worstIdx == -1 || memorySize[j] > memorySize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            memorySize[worstIdx] -= processSize[i];
        }
    }

    printf("\n---------- Worst Fit -----------\n\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int memorySize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(memorySize) / sizeof(memorySize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    firstFit(memorySize, m, processSize, n);
    bestFit(memorySize, m, processSize, n);
    worstFit(memorySize, m, processSize, n);
    return 0;
}
