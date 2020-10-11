#include<stdio.h>
#include<conio.h>
int main()
{
	int row, c, n;
	printf("Enter the number of rows you want to print in pyramid : ");
	scanf("%d", &n);
	printf("\n");	
	for (int i=1; i<=n; i++)
	{
		for (c=1; c<=n-i; c++)
			printf(" ");
		for (c=1; c<=2*i-1; c++)
			printf("*");
    	printf("\n");
	}
	getch();
	return 0;
}
