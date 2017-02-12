#include<stdio.h>
#include<stdlib.h>

struct node
{
	int number;
	int count;
	struct node *next;
};

typedef struct node mostandmax_sum;
int sigma(int inPut);
void linked_list(mostandmax_sum **startLoc, int sum);
void find_max(mostandmax_sum **startLoc);

int main()
{
	int inPut, start, sum = 0;
	mostandmax_sum *startLoc = NULL;
	
	printf("input: ");
	scanf("%d", &inPut);
	
	for(start = 0; start <= inPut; start++)
	{
		sum = sigma(start);
		printf("\nNumber %d : Digit: %d", start, sum);
		linked_list(&startLoc, sum);
	}
	
	find_max(&startLoc);
	if(startLoc != NULL)
		printf("\nThe most digit sum is %d The number of occurrences is %d", startLoc->number, startLoc->count);
	else
		printf("\nThere are not most digit sum, It is all equal!");
	Sleep(10000);
	return 0;
}

int sigma(int inPut)
{
	int tem = 0;
	
	do
	{
		tem += inPut % 10;
		inPut = inPut / 10;
	}
	while(inPut > 0);
	return tem;
}

void linked_list(mostandmax_sum **startLoc, int sum)
{
	if(*startLoc == NULL)
	{
		*startLoc = (mostandmax_sum*)malloc(sizeof(mostandmax_sum));
		(*startLoc)->number = sum;
		(*startLoc)->next = NULL;
		(*startLoc)->count = 1;
	}
	else
	{
		if(sum != (*startLoc)->number)
			linked_list(&((*startLoc)->next), sum);
		else
			((*startLoc)->count)++;
	}
}

void find_max(mostandmax_sum **startLoc)
{
	mostandmax_sum *max_Loc = NULL;
	int counting = 1;
	while(*startLoc != NULL)
	{
		if((*startLoc)->count > counting)
		{
			max_Loc = *startLoc;
			counting = (*startLoc)->count;
		}
		*startLoc = (*startLoc)->next;
	}
	*startLoc = max_Loc;
}
