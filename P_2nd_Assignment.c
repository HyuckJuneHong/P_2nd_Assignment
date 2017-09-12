#include <stdio.h>
#include <math.h>								//Á¦°ö pow
int checkPrime_between(int n);
int checkArmstrongNumber(int n);
int checkPrimeNumber(int n);
int main()
{
	int select, n;
	printf("1.Display Prime Numbers Between Intervals Using Function.\n");
	printf("2.Check Prime or Armstrong Number Using User-defined Function.\n");
	printf("3.Check Whether a Number can be Expressed as Sum of Two Prime Numbers.\n");
	printf("4.Ending is 0\n");
	while(1)
	{
		printf("select the number\n");
		scanf("%d", &select);
		if(select == 1)
		{
			int n, n1, n2;
			printf("Enter two number:");
			scanf("%d %d",&n1, &n2);
			for(n=n1; n<=n2; n++)
				checkPrime_between(n);
			printf("\n");
		}
		else if(select == 2)
		{
			int n, flag;
			printf("Enter a number:");
			scanf("%d", &n);
			flag = checkPrimeNumber(n);
			if(flag == 1)
				printf("%d is a prime number.\n", n);
			else
				printf("%d is not a prime number.\n", n);
			flag = checkArmstrongNumber(n);
			if(flag == 1)
				printf("%d is an armstrong number.\n", n);
			else
				printf("%d is not a armstrong number.\n", n);
			printf("\n");
		}
		else if(select==3)
		{
			int n, i, flag=0;
			printf("Enter a number:");
			scanf("%d", &n);
			for(i = 2; i <= n/2; ++i)
			{
				if(checkPrimeNumber(i)==1)
				{
					if(checkPrimeNumber(n-i)==1)
					{
						printf("%d = %d + %d\n", n, i, n-i);
						flag=1;
						printf("\n");
					}
				}
			}
		}
		else if(select==0)
		{
			printf("Exit the program.\n");
			break;
		}
	}
	return 0;
}
int checkPrime_between(int n)
{
	int i;
	for(i=2; i<=n; i++)
	{
		if(n%i==0)
			break;
	}
	if(n==i)
		printf("%d ", n);
}
int checkArmstrongNumber(int n)
{
	int OriginalNumber, remainder, result=0, number=0, flag;
	OriginalNumber=n;
	while(OriginalNumber!=0)
	{
		OriginalNumber/=10;
		++number;
	}
	OriginalNumber=n;
	while(OriginalNumber!=0)
	{
		remainder=OriginalNumber%10;
		result+=pow(remainder, number);
		OriginalNumber/=10;
	}
	if(result==n)
		flag=1;
	else
		flag=0;
	return flag;
}
int checkPrimeNumber(int n)
{
	int i, flag=0;
	for(i=1; i<=n; i++)
	{
		if(n%i==0)
			flag++;
	}
	return(flag==2);
}