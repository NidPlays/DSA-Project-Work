#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <string.h>
#include <unistd.h>


int count=0;
//add more pincode then increase range in randrompincodegen
int randrompincode[]={560098,560072,560004,560062,560085,560090,560070,560066,560050,560008};

void typewriter(const char* letter, int rate) {
  for (int i = 0; letter[i] != '\0'; i++) {
    printf("%c", letter[i]);
    fflush(stdout);
    // 1,000,000
    //     1,000 = 1 millisecond
	//added stuff for nid test 1

    usleep(1000 * rate);
  }
}

int singlerand(int lower, int upper) 
{ 
	int i; 
	int num = (rand() % (upper - lower + 1)) + lower; 
	return num;
}

int randrompincodegen()
{
	//i think its done
	int i= singlerand(0, 9);
	return randrompincode[i];
}

struct node
{
	int voterid,age,pincode;
	enum gender{male=0, female=1}gender;
	int candidate;
	struct node * next;
}*first = NULL, *last = NULL, *temp = NULL, *temp1 = NULL;

void create()
{
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the voter details \n");
	printf("\nVoter id(int), Voter age(int), pincode(int),and gender(0 for male and 1 for female) :");
	scanf("%d %d %d %d", &temp->voterid,&temp->age,&temp->pincode,&temp->gender);
	temp->next = NULL;
	count++;
}
void createrandom()
{
	temp = (struct node *)malloc(sizeof(struct node));
	temp->voterid = singlerand(42069, 69420);
	temp->age = singlerand(18, 70);
	temp->pincode= randrompincodegen();
	temp->gender=singlerand(0, 1);
	temp->next = NULL;
	count++;
}

void insertrandomvoters(int n)
{
	for(int i=0;i<n;i++)
	{
		createrandom();
		if (first == NULL)
		{
			first = temp;
			last = first;
		}
		else
		{
			temp->next = first;
			first = temp;
		}
	}
}

void calculatestats()
{
	//todo add calculatestats work
  	//leave it to phanish
  	//one more comment
}

void insertatfirst()
{
	create();
	if (first == NULL)
	{
		first = temp;
		last = first;
	}
	else
	{
		temp->next = first;
		first = temp;
	}
}

void deletefront()
{
	temp = first;
	if (first == NULL)
	{
		printf("\n list is empty\n");
		return;
	}
	if (temp->next == NULL)

	{
		free(temp);
		first = NULL;
	}
	else
	{
		first = temp->next;
		free(temp);
	}
	count--;
}

void display()
{
	if (first == NULL)
	{
		printf("\n list is empty\n");
	}
	else
	{
		temp = first;
		calculatestats();
		printf("\nThere are %d voter(s) \n",count);
		printf("The voter is \n");
		printf("VoterID |  Age  |\tPincode | gender \t \n");
		while (temp != NULL)
		{
			char gender1[20];
			if(temp->gender== male)
				strcpy(gender1,"Male");
			else
				strcpy(gender1,"Female");
			printf("%d\t\t %d\t \t%d\t %s \n", temp->voterid,temp->age,temp->pincode,gender1);
			temp = temp->next;
		}
	}
}

int main(void) 
{
	srand(time(0));
	int ch, i, n; 
	while (1)
	{
		typewriter("\n1.Insert n details of voters ",30);
		typewriter("\n2.Insert at beginning",30);
		typewriter("\n3.Random Generate n voters",30);
		//printf("\n4.todo");
		typewriter("\n5.Display",30);
		typewriter("\n6.Exit",30);
		typewriter("\nEneter your choice : ",30);
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				printf("\nEnter the value of n ");
				scanf("%d", &n);
				for (i = 0; i < n; i++)
					insertatfirst();
				break;
			case 2:
				insertatfirst();
				break;
			case 3:
				printf("\nEnter the value of n ");
				scanf("%d", &n);
				insertrandomvoters(n);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
			default:
				printf("\n Wrong Input, try again");
		}
	}
 	return 0;
}