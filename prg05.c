#include <stdio.h>
int main()
{
	int A[100][5]; 			
	int i, j, n, wt=0, tat=0, index, temp;
	float avg_wt, avg_tat;

	printf("Enter number of process: ");
	scanf("%d", &n);

	printf("Enter Burst Time:\n");	
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}

	printf("Enter Priority:\n");	
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][4]);
	}


	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][4] < A[index][4])
				index = j;
		
			temp = A[i][1];
			A[i][1] = A[index][1];
			A[index][1] = temp;

			temp = A[i][0];
			A[i][0] = A[index][0];
			A[index][0] = temp;

			temp = A[i][4];
			A[i][4] = A[index][4];
			A[index][4] = temp;


	}

	A[0][2] = 0;
	A[0][3] = A[0][1];
	for (i = 1; i < n; i++) {
		A[i][2] = A[i-1][3];
		A[i][3] = A[i][1] + A[i][2];
		wt += A[i][2];
		tat += A[i][3];
	}

	printf("P	 Priority	 BT	 WT	 TAT\n");
	for (i = 0; i < n; i++)
		printf("P%d	 %d\t	 %d	 %d	 %d\n", A[i][0],A[i][4],A[i][1], A[i][2], A[i][3]);

	avg_wt = (float)wt / n;
	avg_tat = (float)tat / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
	
	return 0;
}
