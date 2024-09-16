#include <stdio.h>

struct processes {
  int pid;
  int bt;
  int tat;
  int ct;
  int wt;
}
p[4], temp;
int main() {
  int n = 4;
  float tat_avg = 0, wt_avg = 0;

  printf("Enter the information in ascending order to the arrival time\n");
  for (int i = 0; i < n; i++) {
    p[i].pid = i + 1;
    printf("Enter the burst time of the process %d --> ", i + 1);
    scanf(" %d", & p[i].bt);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (p[j + 1].bt < p[j].bt) {

        temp.bt = p[j + 1].bt;
        p[j + 1].bt = p[j].bt;
        p[j].bt = temp.bt;

        temp.pid = p[j + 1].pid;
        p[j + 1].pid = p[j].pid;
        p[j].pid = temp.pid;

      }
    }
  }
  p[0].ct = p[0].bt;
  for (int i = 1; i < n; i++) {
    p[i].ct = p[i - 1].ct + p[i].bt;
    p[i].tat = p[i].ct;
    p[i].wt = p[i].tat - p[i].bt;
    tat_avg += p[i].tat;
    wt_avg += p[i].wt;
  }

  tat_avg /= (n);
  wt_avg /= (n);
  printf("The total turn around time is --> %f\n", tat_avg);
  printf("The total waiting time is --> %f\n", wt_avg);
  return 0;
}