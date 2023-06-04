//Library Management System (Mini Project)

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>

void white()   {printf("\033[0;37m");} //changes colour of console to WHITE
void red()     {printf("\033[1;31m");} //changes colour of console to RED
void yellow()  {printf("\033[1;33m");} //changes colour of console to YELLOW
void green()   {printf("\033[0;32m");} //changes colour of console to GREEN
void blue()    {printf("\033[0;34m");} //changes colour of console to BLUE
void cyan()    {printf("\033[0;36m");} //changes colour of console to CYAN
void purple()  {printf("\033[0;35m");} //changes colour of console to PURPLE
void black()   {printf("\033[0;30m");} //changes colour of console to BLACK
void resetcolor() {printf("\033[0m");} //changes colour of console to DEFAULT

//Structure to store the details of books available in the library
struct book
{
char name[20], author[50], subject[20];
int copies,id;
}s[100];

//Structure to store the details of books issued by the students
struct issue
{
char stdname[30],dept[20];
int stdid,bkid;
}j[100];

//Function to display header on each page
void head()
{
time_t T=time(NULL); //To generate current date, time and day
printf("\t\t\t\t\t\t       %s",ctime(&T));  //To display current date time and day
yellow();
printf("--------------------------------------------------------------------------------");
printf("\t\t\t  LIBRARY MANAGEMENT SYSTEM\n");
printf("--------------------------------------------------------------------------------");
resetcolor();
}

//Function for the Welcome page
int homePage(int a)
{
int x=0;
clrscr();
head();
if(a==0)
{
	purple();
	printf("=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=+");
	resetcolor();
	white();
	printf("\t\t\t\t   WELCOME\n");
	resetcolor();
	purple();
	printf("=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=++=+");
	resetcolor();
}
if(a>0&&a<5)
{
	red();
	printf("\n\n%d of 5 failed login attempts.",a);
	resetcolor();
}
printf("\n\n1. Login\n2. Quit application\n");
cyan();
printf("\nEnter Choice:");
scanf("%d",&x);
resetcolor();
return x;
}

//Function for the Quit page
void quit()
{
clrscr();
printf("\n\n");
purple();
printf("\n\t    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
resetcolor();
white();
printf("\n\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t       =                   THANK YOU                   =");
printf("\n\t       =                 FOR USING OUR                 =");
printf("\n\t       =               LIBRARY MANAGEMENT              =");
printf("\n\t       =                     SYSTEM                    =");
printf("\n\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
resetcolor();
purple();
printf("\n\n\t    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
resetcolor();
yellow();
printf("\n\n\nProject by:-\nFarin Khan - 60009210140\nSanika Tawate - 60009210161\nNidhi Pabari - 60009210173");
resetcolor();
printf("\n\n\nEnter any key to Exit.");
getch();
exit();
}

//Main function
void main()
{
//declaration of variables
int y,c,bid,sid,i,k,cop,m,p,q,r,days=0,n=0,z=0,found=0,atmp=0;
time_t first,second;   //Time variables
char pass[]="P@ss";    //Storing the default password
char ps[100],cur[100],ch;
recheck:	      //Label 1
y=homePage(atmp);
if(y==1)
{
	//To display login page
	clrscr();
	head();
	white();
	printf("\n\t\t\t\t  LOGIN PAGE\n");
	printf("--------------------------------------------------------------------------------");
	resetcolor();
	if(atmp==4)
	{
		red();
		printf("\n\nLast attempt!\n");
		resetcolor();
	}
	cyan();
	printf("\nEnter Password (end with a /):");
	resetcolor();
	i=0;
	while((ch=getch())!='/')
	{
		ps[i]=ch;
		printf(" *");
		i++;
	}
	if (strcmp(ps,pass)==0)
	{
		again:         //Label 2
		//To display main menu
		clrscr();
		head();
		white();
		printf("\n\t\t\t\t  MAIN MENU\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		printf("1. Add book\n");
		printf("2. Book list\n");
		printf("3. Delete book\n");
		printf("4. Issue book\n");
		printf("5. Return book\n");
		printf("6. List of issues\n");
		printf("7. Update password\n");
		printf("8. Logout\n");
		cyan();
		printf("\nEnter option:");
		resetcolor();
		scanf("%d",&c);
		switch (c)
		{
		//To display Add books page
		case 1:
		clrscr();
		head();
		white();
		printf("\n\t\t\t\t  ADD BOOKS\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nEnter Book ID:");
		resetcolor();
		scanf("%d",&s[n].id);
		//checking if book is present in database
		for(i=0;i<n;i++)
		{
			if(s[i].id==s[n].id)
			{
				found=1;
				break;
			}
		}
		if(found==0)
		{
			cyan();
			printf("\nEnter the book name: ");
			scanf("%s",s[n].name);
			printf("\nEnter the book author: ");
			scanf("%s",s[n].author);
			printf("\nEnter the book subject: ");
			scanf("%s",s[n].subject);
			printf("\nEnter the number of copies: ");
			scanf("%d",&s[n].copies);
			resetcolor();
			n++;
		}
		else
		{
			red();
			printf("\nBook is already present in database.");
			resetcolor();
			cyan();
			printf("\n\nEnter no. of copies to be added:");
			resetcolor();
			scanf("%d",&cop);
			s[i].copies+=cop;
			green();
			printf("\nCopies added successfully!");
			resetcolor();
			found=0;
		}
		printf("\nPress any key to go back to main menu.");
		getch();
		goto again;

		//To display list of books
		case 2:
		clrscr();
		head();
		white();
		printf("\n\t\t\t\t  BOOK LIST\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nSr.No.\tBook ID\t\tName\tAuthor\t\tSubject\t\tCopies\n");
		printf("--------------------------------------------------------------------------------");
		resetcolor();
		white();
		for(i=0; i<n; i++)
			printf("%d\t%d\t\t%s\t%s\t\t%s\t\t%d\n",(i+1),s[i].id, s[i].name, s[i].author, s[i].subject, s[i].copies);
		resetcolor();
		printf("\n\nPress any key to go back to main menu.");
		getch();
		goto again;

		//To display book deletion page
		case 3:
		clrscr();
		head();
		white();
		printf("\n\t\t\t\tBOOK DELETION\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nEnter the book id:");
		resetcolor();
		scanf("%d",&bid);
		//checking if book is present in database
		for(p=0;p<n;p++)
		{
			if(s[p].id==bid)
			{
				found=1;
				break;
			}
		}
		if(found==1)
		{
			for(k=p;k<=n;k++)
				s[k]=s[k+1];
			n--;
			green();
			printf("\nThe book has been deleted successfully!");
			resetcolor();
			found=0;
		}
		else
		{
			red();
			printf("\nBook not found in database.");
			resetcolor();
		}
		printf("\nPress any key to return to main menu.");
		getch();
		goto again;

		//To display Issue books page
		case 4:
		clrscr();
		head();
		white();
		printf("\n\t\t\t\t ISSUE BOOKS\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nEnter the book id:");
		scanf("%d",&j[z].bkid);
		resetcolor();
		//checking if book is present in database
		for(q=0;q<n;q++)
		{
			if((s[q].id==j[z].bkid)&&(s[q].copies>0))
			{
				cyan();
				printf("\nEnter the student's name:");
				scanf("%s",&j[z].stdname);
				printf("\nEnter the student ID:");
				scanf("%d",&j[z].stdid);
				printf("\nEnter the department name:");
				scanf("%s",&j[z].dept);
				resetcolor();
				first=time(NULL);
				s[q].copies--;
				z++;
				green();
				printf("\nBook issued successfully!");
				resetcolor();
				found=1;
				break;
			}
		}
		if(found!=1)
		{
			red();
			printf("\nBook is unavailable.");
			resetcolor();
			found=0;
		}
		printf("\nPress any key to go back to main menu.");
		getch();
		goto again;

		//To display return book page
		case 5:
		clrscr();
		head();
		white();
		printf("\n\t\t\t\t  RETURN BOOK\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nEnter the book id:");
		scanf("%d",&bid);
		printf("\nEnter Student ID:");
		scanf("%d",&sid);
		resetcolor();
		//checking if book was issued
		for(r=0;r<z;r++)
		{
			if((j[r].bkid==bid)&&(j[r].stdid==sid))
			{
				found=1;
				break;
			}
		}
		if(found==1)
		{
			/*calculating amount of fine
			if book is returned late*/
			second=time(NULL);
			days=(int)((difftime(second,first))/86400);
			if(days>7)
			{
				red();
				printf("\nFine to be paid:Rs. %d",(days-7)*10);
				resetcolor();
			}
			s[r].copies++;
			for(k=r;k<=z;k++)
				j[k]=j[k+1];
			z--;
			green();
			printf("\nThe book has been returned successfully!");
			resetcolor();
			found=0;
		}
		else
		{
			red();
			printf("\nBook wasn't issued.");
			resetcolor();
		}
		printf("\nPress any key to return to main menu.");
		getch();
		goto again;

		//To display list of pending issues
		case 6:
		clrscr();
		head();
		white();
		printf("\n\t\t\t\tLIST OF ISSUES\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nSr.no.  Student name  Student ID  Department  Book ID  Issue date\n");
		printf("--------------------------------------------------------------------------------");
		resetcolor();
		white();
		for(i=0; i<z; i++)
			 printf("%d\t%s\t\t%d\t%s\t\t%d\t%s\n",(i+1),j[i].stdname,j[i].stdid,j[i].dept,j[i].bkid,ctime(&first));
		resetcolor();
		printf("\n\nPress any key to go back to main menu.");
		getch();
		goto again;

		//To display passcode updation page
		case 7:
		trys:           //Label 3
		clrscr();
		head();
		white();
		printf("\n\n\t\t\t      PASSCODE UPDATION\n");
		printf("--------------------------------------------------------------------------------\n");
		resetcolor();
		cyan();
		printf("\nEnter current Password(end with a /):");
		resetcolor();
		i=0;
		while((ch=getch())!='/')
		{
			cur[i]=ch;
			printf(" *");
			i++;
		}
		if(strcmp(pass,cur)==0)
		{
			cyan();
			printf("\n\nEnter new Password (end with a /): ");
			resetcolor();
			i=0;
			while((ch=getch())!='/')
			{
				pass[i]=ch;
				printf(" *");
				i++;
			}
			if(strcmp(pass,"P@ss")==0)
			{
				red();
				printf("\nUpdated password is same as new one.");
				resetcolor();
				printf("\nEnter 0 if u want to change the password.");
				printf("\nEnter any other number to continue with the same one.\n");
				scanf("%d",&m);
				if(m==0)
					goto trys;
			}
			green();
			printf("\n\nPasscode updated sucessfully!\n");
			resetcolor();
			printf("Login again after pressing any key.");
			getch();
		}
		else
		{
			red();
			printf("\nIncorrect password entered!");
			resetcolor();
			printf("\nEnter 1 to try again or any other number to logout.\n");
			scanf("%d",&m);
			if(m==1)
				goto trys;
		}
		goto recheck;

		//To logout (Directs to the welcome page)
		case 8:
		clrscr();
		head();
		goto recheck;

		default:
		red();
		printf("\nInvalid option chosen.");
		resetcolor();
		printf("\nPress any key to try again.");
		getch();
		goto again;
		}
	}
	else
	{
		atmp++;
		if(atmp==5)
		quit();
		goto recheck;
	}
}
else if(y==2)
	quit();
else
{
	red();
	printf("\nInvalid option chosen.");
	resetcolor();
	printf("\nPress any key to try again.");
	getch();
	goto recheck;
}
quit();
}