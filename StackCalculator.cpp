#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top;
int num[MAX];
void Push(int);
int Pop();
int Test_Full();
int Test_Empty();
void print();
/* This main function read data in file
And traslate string line to operand and operator
Also calculate this string.
This result values will write new file
Fianally printf this new file data
Switch library function controls operation using stack(pop and push)*/
void main()
{
	int data;
	int tmp1, tmp2;
	char *token;
	char delimit[] = " \n";
	char line[255];
	char *tmp;
	int button;
	FILE *fp;
	FILE *FP;
	fp = fopen("lab2-1.txt", "r");
	FP = fopen("result.txt", "w");
	if (fp == NULL)
	{
		printf("File read failed.\n");
		exit(1);
	}

	top = -1;
	button = 1;
	while (fgets(line, 255, fp))
	{
		token = strtok(line, delimit);
		while (token != NULL)
		{
			printf("%s ", token);
			fprintf(FP, "%s ", token);

			switch (*token)
			{
			case '*':
				tmp1 = Pop();
				tmp2 = Pop();
				Push(tmp1*tmp2);
				break;
			case '+':
				tmp1 = Pop();
				tmp2 = Pop();
				Push(tmp1 + tmp2);
				break;
			case '-':
				tmp1 = Pop();
				tmp2 = Pop();
				Push(tmp2 - tmp1);
				break;
			default:
				data = atoi(token);
				Push(data);
				break;
			}
			token = strtok(NULL, delimit);
		}
		printf(" = %d \n", num[top]);
		fprintf(FP, "%d \n", num[top]);
		top = -1;
	}

	fclose(fp);
	fclose(FP);
}
//This push function is used to insert new data.
//Input: New Data from main function 
//Output: None.
void Push(int DATA)
{
	top++;
	num[top] = DATA;
}
//This pop function is used to delete data(The last inserted data).
//Input: None
//Output: deleted data.
int Pop()
{
	int tmp;
	tmp = top;
	top--;
	return num[tmp];
}
//This Test Full function checks data storage is full.
//Input: None
//Output: return false or true (stack is full or not full)
int Test_Full()
{
	if (top == MAX - 1)
		return -1;
	else
		return 1;
}
//This Test Empty function checks data storage is Empty.
//Input: None
//Output: return false or true (stack is empty or not empty)
int Test_Empty()
{
	if (top == -1)
		return -1;
	else
		return 1;
}