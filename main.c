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
	int voterid,age,pincode,gender;
	temp = (struct node *)malloc(sizeof(struct node));
	voter:
		printf("\nEnter the voter details \n");
		printf("\nVoter id(int), Voter age(int), pincode(int),and gender(0 for male and 1 for female) :");
		scanf("%d %d %d %d", &voterid,&age,&pincode,&gender);
	if(age<18)
	{
		printf("\nAge is %d\n",age);
		printf("\nIneligible\n");
		printf("\nHow did you get your VoterID???\n");
		goto voter;
	}
	else if(age>100)
	{
		printf("\nAge is %d\n",age);
		printf("\n So Old are you alive\n");
		goto voter;
	}
	else
	{
		temp->voterid = voterid;
		temp->age = age;
		temp->pincode = pincode;
		temp->gender = gender;
	}
	printf("\nEnter the Candidate: \n 1:Murthy \n 2:Ramprasad \n 3:GuruPrasad \n 4:Modi \n 5:Rahul Gandhi\n NOTA is any other number \n");
	scanf("%d",&temp->candidate);
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
	temp->candidate=singlerand(1, 6);
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


void individualStats()
{	
	char candidates[5][20]={"Murthy","Ramprasad","GuruPrasad","Modi","Rahul Gandhi"};
	int candidate1=0,candidate2=0,candidate3=0,candidate4=0,candidate5=0;
	if (first == NULL)
	{
		printf("\n list is empty\n");
		return;
	}
	//do individual candidate stats here
	//1:Murthy \n 2:Ramprasad \n 3:GuruPrasad \n 4:Modi \n 5:Rahul Gandhi
	temp = first;
	int vcount=0;
  	while(temp!= NULL)
	{
		if(temp->candidate >= 1 && temp->candidate <= 5)
			vcount++;
		switch(temp->candidate)
		{
			case 1:
				candidate1++;
				break;
			case 2:
				candidate2++;
				break;
			case 3:
				candidate3++;
				break;
			case 4:
				candidate4++;
				break;
			case 5:
				candidate5++;
				break;
		}
		temp=temp->next;
	}
	printf("\nThere are %d voter(s) \n",count);
	printf("\nTotal Votes issued for candidates (votes - nota): %d\n",vcount);
	printf("\n Candidate 1 (%s)       got %d votes",candidates[0],candidate1);
	printf("\n Candidate 2 (%s)    got %d votes",candidates[1],candidate2);
	printf("\n Candidate 3 (%s)   got %d votes",candidates[2],candidate3);
	printf("\n Candidate 4 (%s)         got %d votes",candidates[3],candidate4);
	printf("\n Candidate 5 (%s) got %d votes\n",candidates[4],candidate5);
	printf("\n---|THE WINNER OF THE ELECTION BY AQUIREING MAXIMUM VOTES|---");

}


void calculatestats()
{
	if (first == NULL)
	{
		printf("\n list is empty\n");
		return;
	}
	// TODO WORK ON WHY PINCODE DOES NOT WORK
	int vcount = 0;
	int less25 = 0;
	int less50 = 0;
	int less100 = 0;
	int mvoter = 0;
	int fvoter = 0;
	
	int pin_arr[]={0};
	int pincodes[10]={560098,560072,560004,560062,560085,560090,560070,560066,560050,560008};
	temp = first;
  	while(temp!= NULL)
	{
		if(temp->candidate >= 1 && temp->candidate <= 5)
			vcount++;
		if(temp->age <= 25)
			less25++;
		if(temp->age > 25 && temp->age <=50)
			less50++;
		if(temp->age > 50 && temp->age <= 100)
			less100++;
		if(temp->gender == 0)
			mvoter++;
		if(temp->gender == 1)
			fvoter++;
		/* pin_arr[temp->pincode]++; */
		temp=temp->next;
	}
	printf("\nThere are %d voter(s) \n",count);
	printf("\nTotal Votes issued for candidates (votes - nota): %d\n",vcount);
	printf("Total NOTA votes: %d\n",count-vcount);
	printf("\nNumber of voters in age group(18-25):%d\n",less25);
	printf("Number of voters in age group(25-50):%d\n",less50);
	printf("Number of voters in age group(50-100):%d\n",less100);
	printf("\nNumber of male voters : %d\n",mvoter);
	printf("Number of female voters : %d\n",fvoter);
	/* for(int i=0;i<10;i++)
	{	
		int current_pin= pincodes[i];
		printf("No of votes in pincode %d is :%d \n",current_pin,pin_arr[current_pin]);
	} */
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
		//calculatestats();
		printf("\nThere are %d voter(s) \n",count);
		printf("The voter is \n");
		printf("VoterID |  Age  |\tPincode | gender \t | Voted Candidate \n");
		while (temp != NULL)
		{
			char gender1[20];
			if(temp->gender== male)
				strcpy(gender1,"Male    ");
			else
				strcpy(gender1,"Female ");
			char candidate[20];
			//1:Murthy \n 2:Ramprasad \n 3:GuruPrasad \n 4:Modi \n 5:Rahul Gandhi
			switch(temp->candidate)
			{
				case 1:
					strcpy(candidate,"Murthy");
					break;
				case 2:
					strcpy(candidate,"Ramprasad");
					break;
				case 3:
					strcpy(candidate,"GuruPrasad");
					break;
				case 4:
					strcpy(candidate,"Modi");
					break;
				case 5:
					strcpy(candidate,"Rahul Gandhi");
					break;
				default:
					strcpy(candidate,"NOTA");
			}
			printf("%d\t\t %d\t \t%d\t %s \t %s\n", temp->voterid,temp->age,temp->pincode,gender1,candidate);
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
		typewriter("\n1.Insert n details of voters ",35);
		typewriter("\n2.Insert at beginning",35);
		typewriter("\n3.Random Generate n voters",35);
		typewriter("\n4.Display Calulated stats(classification based stats)",35);
		typewriter("\n5.Display Individual Candidate stats(classification based candidate)",35);
		typewriter("\n6.Display",35);
		typewriter("\n7.Exit",35);
		typewriter("\nEneter your choice : ",35);
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				printf("\nEnter the value of n: ");
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
			case 4:
				calculatestats();
				break;			
			case 5:
				individualStats();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(1);
			default:
				printf("\n Invalid Input, try again");
		}
	}
 	return 0;
}