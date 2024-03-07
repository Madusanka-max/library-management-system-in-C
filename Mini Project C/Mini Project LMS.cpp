#include <stdio.h>
#include <stdlib.h>
#include <string.h>				//<-- You need this to use string functions.
#include <conio.h>				//<-- You need this to use getch() function.
#include <windows.h>			//<-- You need this to use gotoxy() function.
#include <time.h>
#include <ctype.h>				//<-- You need this to use toupper() function.

void welcome(); 
void login(); 
void mainmenu(); 
void add_books();
void view_books();
void search_books(); 
void delete_books();
void add_members();
void view_members();
void search_members();
void delete_members();
void loan_books();
void view_overdue_books();
void return_book();

FILE *books, *members, *loans;     //<-- File pointer
time_t now;                        //<-- time
char answer;                     //<-- Submenu Choice
int choice ;                     //<-- Mainmenu Choice
void gotoxy(short x, short y)		//<-- Gotoxy function
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int date_to_timestamp(int year, int month, int date)    //<-- time function
{
	struct tm return_date;
	return_date.tm_year = year - 1900;
	return_date.tm_mon = month - 1;
	return_date.tm_mday = date;
	return_date.tm_hour = 0;
	return_date.tm_min = 0;
	return_date.tm_sec = 0;
	return_date.tm_isdst = 0;
	return mktime(&return_date);
}
struct add_book {                //<-- Book Variable
	char id[150];
	char title[150];
	char author[150];
	char date_added[150];
}book;
struct add_member {              //<-- Member Variable
	char id[150];
	char name[150];
	char date_added[150];
}member;
struct loan_book {               //<-- Loan Book Variable
	char id[150];
	char member_id[150];
	char book_id[150];
	char date_barrow[150];
	int date_to_return;
}loan;
//Main fuction
int main()
{
	welcome();
}
// welcome function
void welcome()
{
	gotoxy(10,5);  printf("  ________________________________________________________");
	gotoxy(10,6);  printf("  ________________________________________________________");
	gotoxy(10,8);  printf("        ---------------------------------------------");
	gotoxy(10,9);  printf("       | ---------------- WELCOME ------------------ |");
	gotoxy(10,10); printf("       | ------------------ TO --------------------- |");
	gotoxy(10,11); printf("       | ---------------- LIBRARY ------------------ |");
	gotoxy(10,12); printf("       | -------------- MANAGEMENT ----------------- |");
	gotoxy(10,13); printf("       | ---------------- SYSTEM ------------------- |");
	gotoxy(10,14); printf("        ---------------------------------------------");
	gotoxy(10,15); printf("                  .--.                   .---.\n");
	gotoxy(10,16); printf("              .---|__|           .-.     |~~~|\n");
	gotoxy(10,17); printf("           .--|===|--|           |_|--.  |~~~|--.\n");
	gotoxy(10,18); printf("           ||||===|  |       .---!~|  |--|   |--|\n");
	gotoxy(10,19); printf("           ||||   |  |       |===| |--|..|   |  |\n");
	gotoxy(10,20); printf("           | ||   |  |       |   | |__|==|   |  |\n");
	gotoxy(10,21); printf("           | ||   |  |       |===| |==|  |   |  |\n");
	gotoxy(10,22); printf("           |  |   |__|       |   |_|__|  |~~~|__|\n");
	gotoxy(10,23); printf("           |--|===|--|       |===|~|--|  |~~~|--|\n");
	gotoxy(10,24); printf("           `--^---'--'       `---^-^--^--^---'--'\n\n\n");
	gotoxy(10,25); printf("       ----------------------------------------------\n\n");
	gotoxy(10,26); printf("                                  - Code Linguists -      ");
	gotoxy(10,27); printf("  ________________________________________________________");
	gotoxy(10,28); printf("  ________________________________________________________");
	gotoxy(15,30); printf(" Enter any key to continue....."); getch(); login();
}
// login function
void login()
{
	system("cls");
	int L=0;
	char a[30], b[30];
	do{
		system("cls");
		gotoxy(15,5);  printf("------------------------\n");
		gotoxy(14,6);  printf("| ---- Login Screen ---- |\n");
		gotoxy(15,7);  printf("------------------------\n");
		gotoxy(20,10); printf("Enter Username and Password");
		gotoxy(22,12); printf("Username: "); scanf("%s" ,a);
		gotoxy(22,14); printf("Password: "); scanf("%s" ,b);	
		if((strcmp(a,"user")==0)&& (strcmp(b,"pass")==0))   // -->Check the password and username
		{
			gotoxy(10,16); printf("-------------------------------------");
			gotoxy(15,17); printf("Logged Into System.");
			gotoxy(15,18); printf("Press any key to go next.....");
			gotoxy(10,19); printf("-------------------------------------"); getch(); mainmenu();
		}else
		{
			gotoxy(10,16); printf("---------------------------------------------------------------");
			gotoxy(15,17); printf("Login Failed Enter Again Username & Password Again.....(%d)",(3-L));
			gotoxy(10,18); printf("---------------------------------------------------------------"); getch();
			L++;
		}
	}while(L<=3);	// --> if password or username is wrong more than 3 time progarm will close
	if(L>3){
		system("cls");
		gotoxy(25,15); printf("Sorry,Unknown User."); getch();
		system("cls");
	}	
}
// mainmenu function
void mainmenu()
	{
		system("cls");
		gotoxy(15,2);  printf("---------------------");
		gotoxy(14,3);  printf("| ---- MAIN MENU ---- |");
		gotoxy(15,4);  printf("---------------------");
		gotoxy(20,7);  printf("1. BOOKS");
		gotoxy(20,9);  printf("2. MEMBERS");
		gotoxy(20,11); printf("3. LOANS");
		gotoxy(20,13); printf("0. Close Application");
		gotoxy(15,18); printf("Please Enter a choice: "); scanf("%i",&choice);
		switch(choice)
			{
				case 1:     //BOOKS menu
					system("cls");
					gotoxy(15,2);  printf("----------------------------------");
					gotoxy(14,3);  printf("|       MAIN MENU >>> BOOKS        |");
					gotoxy(15,4);  printf("----------------------------------");
					gotoxy(20,7);  printf("1. ADD NEW BOOKS");
					gotoxy(20,9);  printf("2. VIEW BOOKS");
					gotoxy(20,11); printf("3. SEARCH BOOKS");
					gotoxy(20,13); printf("4. DELETE BOOKS");
					gotoxy(20,15); printf("0. MAIN MENU");
					gotoxy(20,18); printf("Please Enter a choice: "); scanf("%i",&choice);
						switch(choice)
						{
							case 1:
								add_books();
							case 2:
								view_books();
							case 3:
								search_books();
							case 4:
								delete_books();
							case 0:
								mainmenu();
								break;
							default:
								printf("Wrong Entry!!"); exit(0);
						}
					break;
				case 2:    //MEMBERS menu
					system("cls");
					gotoxy(15,2);  printf("------------------------------------");
					gotoxy(14,3);  printf("|       MAIN MENU >>> MEMBERS        |");
					gotoxy(15,4);  printf("------------------------------------");
					gotoxy(20,7);  printf("1. ADD NEW MEMBER");
					gotoxy(20,9);  printf("2. VIEW MEMBERS");
					gotoxy(20,11); printf("3. SEARCH MEMBERS");
					gotoxy(20,13); printf("4. DELETE MEMBERS");
					gotoxy(20,15); printf("0. MAIN MENU");
					gotoxy(20,18); printf("Please Enter a choice: "); scanf("%i",&choice);
						switch(choice)
						{
							case 1:
								add_members();
							case 2:
								view_members();
							case 3:
								search_members();
							case 4:
								delete_members();
							case 0:
								mainmenu();
								break;
							default:
								printf("Wrong Entry!!"); exit(0);
						}
					break;
				case 3:      //LOANS menu
					system("cls");
					gotoxy(15,2);  printf("----------------------------------");
					gotoxy(14,3);  printf("|       MAIN MENU >>> LOANS        |");
					gotoxy(15,4);  printf("----------------------------------");
					gotoxy(20,7);  printf("1. LOAN BOOK");
					gotoxy(20,9);  printf("2. VIEW OVERDUE BOOKS");
					gotoxy(20,11); printf("3. RETURN BOOK");
					gotoxy(20,13); printf("0. MAIN MENU");
					gotoxy(20,17); printf("Please Enter a choice: "); scanf("%i",&choice);
						switch(choice)
						{
							case 1:
								loan_books();
							case 2:
								view_overdue_books();
							case 3:
								return_book();
							case 0:
								mainmenu();
								break;
							default:
								printf("Wrong Entry!!"); exit(0);
						}
					break;
				case 0:
					exit(0);
					break;
				default:
					printf("Wrong Entry!!"); exit(0);	
			}
}
//addbooks function
void add_books()
{
	system("cls"); time(&now);
	gotoxy(15,2);  printf("--------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> BOOKS >>> ADD NEW BOOK       |");
	gotoxy(15,4);  printf("--------------------------------------------------");
	gotoxy(15,6);  printf("ID: ");     fflush(stdin); scanf("%[^\n]", book.id);
	gotoxy(15,8);  printf("Title: ");  fflush(stdin); scanf("%[^\n]", book.title);
	gotoxy(15,10); printf("Author: "); fflush(stdin); scanf("%[^\n]", book.author);
	gotoxy(8,12);  printf("--------------------------------------------------------------");
	gotoxy(13,13);  printf("ID: %s", &book.id);
	gotoxy(13,14);  printf("Title: %s", &book.title);
	gotoxy(13,15);  printf("Author: %s", &book.author);
	gotoxy(13,16);  printf("Date Added: %s", strcpy(book.date_added, ctime(&now)));
	gotoxy(8,17);  printf("--------------------------------------------------------------");
	gotoxy(10,19);  printf("Are you sure you wish to Add this Record?");
	gotoxy(15,21);  printf("<Y> Yes            <N> No");
	gotoxy(18,23);  printf("Choose an Option: "); scanf("%s",&answer);
 	add_new_book_confirmation_retry:
	switch (toupper(answer)) //<-- Convert the user entry to upper case -->'toupper'
	{
		case 'Y':
			fprintf(books = fopen("Books.txt", "a+"), "%s\n%s\n%s\n%s\n", &book.id, &book.title, &book.author, &book.date_added);
			fclose(books);
			printf("\n\t\t Do you want to add another book?[Y/N]:"); scanf("%s",&answer);
			while(toupper(answer)!='Y'&& toupper(answer)!='N')
			{
				printf("Invalid!\n\tDo you want to add another book?[Y/N]: "); scanf("%s",&answer);
			}
			if(toupper(answer)=='Y')
			{
				add_books();
			}else
			{
				printf("\n\t\tPress any key to go to Main Menu....."); mainmenu();
			}
			break;
		case 'N':
			printf("\n\t\t Do you want to add another book?[Y/N]:"); scanf("%s",&answer);
			while(toupper(answer)!='Y'&& toupper(answer)!='N')
			{
				printf("Invalid!\n\tDo you want to add another book?[Y/N]: "); scanf("%s",&answer);
			}
			if(toupper(answer)=='Y')
			{
				add_books();
			}else
			{
				printf("\n\t\tPress any key to go to Main Menu....."); mainmenu();
			}
			break;
		default:
			goto add_new_book_confirmation_retry;
	}
}
//viwebooks fuction
void view_books()
{
	system("cls"); int counter = 0;
	gotoxy(15,2);  printf("-----------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> BOOKS >>> VIEW BOOK       |");
	gotoxy(15,4);  printf("-----------------------------------------------");
	books = fopen("Books.txt","r");
	gotoxy(0,5);  printf("-----------------------------------------------------------------------\n");
	while(!feof(books)) 
	{
		fscanf(books, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", &book.id, &book.title, &book.author, &book.date_added);
		counter++;
		printf("\tID: %s\n", &book.id);
		printf("\tTitle: %s\n", &book.title);
		printf("\tAuthor: %s\n", &book.author);
		printf("\tDate Added: %s\n\n", &book.date_added);
		printf("-----------------------------------------------------------------------\n");
	}
	printf("\t   %d %s Available\n\n", counter, counter < 2 ? "BOOK" : "BOOKS");
	printf("\t\tPress any Key to Return to the Main Menu");	getch();
	fclose(books);
	mainmenu();
}
//searchbooks function
void search_books()
{
	system("cls");
	gotoxy(15,2);  printf("-------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> BOOKS >>> SEARCH BOOK       |");
	gotoxy(15,4);  printf("-------------------------------------------------");
	books = fopen("Books.txt","r"); 
	char search[20], *id_search, *title_search, *author_search, temp_id[100], temp_title[100], temp_author[100]; int counter = 0;
	fflush(stdin); 
	gotoxy(15,6); printf("Search: ");
	scanf("%[^\n]", search);
	// Convert the user entry to lower case to allow for case insensitive search
	strlwr(search);
	// Move the file pointer back to the start of the file
	// A previous search may have moved the pointer somewhere inside the file so we need to reset it
	fseek(books, 0, SEEK_END);
	rewind(books);
	while (!feof(books))
	{
		fscanf(books, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", &book.id, &book.title, &book.author, &book.date_added);
		// Copy the attribute to a temporary variable, convert it to lower case and compare it with the search term the user entered
		id_search = strstr(strlwr(strcpy(temp_id, book.id)), search);
		title_search = strstr(strlwr(strcpy(temp_title, book.title)), search);
		author_search = strstr(strlwr(strcpy(temp_author, book.author)), search);
		if ((id_search != NULL || title_search != NULL || author_search != NULL )) 
		{
			counter++;
			printf("\n\t--------------------------------------------------------------\n");
			printf("\t\tID: %s\n", &book.id);
			printf("\t\tTitle: %s\n", &book.title);
			printf("\t\tAuthor: %s\n", &book.author);
			printf("\t\tDate Added: %s\n", &book.date_added);
		}
	}
	printf("\t--------------------------------------------------------------\n");
	printf("\n\n\t\t\t%d %s Found for \"%s\"\n\n\n", counter, counter < 2 ? "Result" : "Results", search);
	printf("\t\t<1> Search again <0> Return to Main Menu\n\n\n");
	printf("\tChoose an Option: ");
 	book_search_options_retry:
	switch (getch()) 
	{
		case '1':
			search_books();
			break;	
		case '0':
			fclose(books);
			mainmenu();
			break;
		default:
			goto book_search_options_retry;
	}
}
//deletebooks function
void delete_books()
{
	system("cls"); int found=0;
	gotoxy(15,2);  printf("-------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> BOOKS >>> DELETE BOOK       |");
	gotoxy(15,4);  printf("-------------------------------------------------");
	char search[20], *id_search, temp_id[100];
	FILE *mfile;
	books = fopen("Books.txt","r");
	printf("\n\n\nEnter Book ID  for delete:");
	scanf("%s",&search);
	mfile=fopen("TempBook.txt","w+");
	fseek(books, 0, SEEK_END);
	rewind(books);
	while (!feof(books))
	{
		fscanf(books, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", &book.id, &book.title, &book.author, &book.date_added);
		id_search = strstr(strlwr(strcpy(temp_id, book.id)), search);
		if(id_search == NULL)
		{
			fprintf(mfile,"%s\n%s\n%s\n%s\n",&book.id,&book.title,&book.author,&book.date_added);
		}
		else
		{
			found=1;
		}
	}
	if(!found)
	{
		printf("\n\tRecord not found");
		printf("\n\tPress any key to Main Menu..");
	}
	else
	{
		printf("\n\tRecord deleted successfully.....");
		printf("\n\tPress any key to Main Menu..");
	}
	fclose(mfile); fclose(books);
	remove("Books.txt"); rename("TempBook.txt","Books.txt");
	getch();mainmenu();
}
//addmembers function
void add_members()
{
	system("cls"); time(&now);
	gotoxy(15,2);  printf("-------------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> MEMBERS >>> ADD NEW MEMBERS       |");
	gotoxy(15,4);  printf("-------------------------------------------------------");
	gotoxy(15,6);  printf("ID: ");    fflush(stdin); scanf("%[^\n]", member.id);
	gotoxy(15,8);  printf("Name: ");  fflush(stdin); scanf("%[^\n]", member.name);
	gotoxy(8,10);  printf("--------------------------------------------------------------");
	gotoxy(13,11);  printf("ID: %s\n\n", &member.id);
	gotoxy(13,12);  printf("Name: %s\n\n", &member.name);
	gotoxy(13,13);  printf("Date Added: %s\n\n", strcpy(member.date_added, ctime(&now)));
	gotoxy(8,15);  printf("-----------------------------------------------------------------------------");
	gotoxy(10,17);  printf("Are you sure you wish to Add this Record?");
	gotoxy(15,19);  printf("<Y> Yes            <N> No");
	gotoxy(18,21);  printf("Choose an Option: "); scanf("%s",&answer);
 	add_new_members_options_retry:
	switch (toupper(answer)) //<-- Convert the user entry to upper case -->'toupper'
	{
		case 'Y':
			fprintf(members = fopen("Members.txt", "a+"), "%s\n%s\n%s\n", &member.id, &member.name, &member.date_added);
			fclose(members);
			printf("\n\t\t Do you want to add another member?[Y/N]:"); scanf("%s",&answer);
			while(toupper(answer)!='Y'&& toupper(answer)!='N')
			{
				printf("Invalid!\n\tDo you want to add another member?[Y/N]: "); scanf("%s",&answer);
			}
			if(toupper(answer)=='Y')
			{
				add_members();
			}else
			{
				printf("\n\t\tPress any key to go to Main Menu....."); mainmenu();
			}
			break;
		case 'N':
			printf("\n\t\t Do you want to add another member?[Y/N]:"); scanf("%s",&answer);
			while(toupper(answer)!='Y'&& toupper(answer)!='N')
			{
				printf("Invalid!\n\tDo you want to add another member?[Y/N]: "); scanf("%s",&answer);
			}
			if(toupper(answer)=='Y')
			{
				add_members();
			}else
			{
				printf("\n\t\tPress any key to go to Main Menu....."); mainmenu();
			}
			break;
		default:
		goto add_new_members_options_retry;
	}
}
//viewmembers function
void view_members()
{
	system("cls"); int counter = 0;
	gotoxy(15,2);  printf("----------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> MEMBERS >>> VIEW MEMBERS       |");
	gotoxy(15,4);  printf("----------------------------------------------------");
	members = fopen("Members.txt","r");
	gotoxy(0,5);   printf("-----------------------------------------------------------------------\n");
	while(!feof(members)) 
	{
		fscanf(members, "%[^\n]\n%[^\n]\n%[^\n]\n", &member.id, &member.name, &member.date_added);
		counter++;
		printf("\tID: %s\n", &member.id);
		printf("\tName: %s\n", &member.name);
		printf("\tDate Added: %s\n\n", &member.date_added);
		printf("-----------------------------------------------------------------------\n");
	}
	printf("\t   %d %s Available\n\n", counter, counter < 2 ? "MEMBER" : "MEMBERS");
	printf("\t\tPress any Key to Return to the Main Menu");	getch();
	fclose(members);
	mainmenu();
}
//searchmembers function
void search_members()
{
	system("cls");
	gotoxy(15,2);  printf("------------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> MEMBERS >>> SEARCH MEMBERS       |");
	gotoxy(15,4);  printf("------------------------------------------------------");
	members = fopen("Members.txt","r"); 
	char search[20], *id_search, *name_search, temp_id[100], temp_name[100]; int counter = 0;
	fflush(stdin); 
	gotoxy(15,6); printf("Search: ");
	scanf("%[^\n]", search);
	// Convert the user entry to lower case to allow for case insensitive search
	strlwr(search);
	// Move the file pointer back to the start of the file
	// A previous search may have moved the pointer somewhere inside the file so we need to reset it
	fseek(members, 0, SEEK_END);
	rewind(members);
	while (!feof(members))
	{
		fscanf(members, "%[^\n]\n%[^\n]\n%[^\n]\n", &member.id, &member.name, &member.date_added);
		// Copy the attribute to a temporary variable, convert it to lower case and compare it with the search term the user entered
		id_search = strstr(strlwr(strcpy(temp_id, member.id)), search);
		name_search = strstr(strlwr(strcpy(temp_name, member.name)), search);
		if ((id_search != NULL || name_search != NULL)) 
		{
			counter++;
			printf("\n\t--------------------------------------------------------------\n");
			printf("\tID: %s\n", &member.id);
			printf("\tName: %s\n", &member.name);
			printf("\tDate Added: %s\n", &member.date_added);
		}
	}
	printf("\t--------------------------------------------------------------\n");
	printf("\n\n\t\t\t%d %s Found for \"%s\"\n\n\n", counter, counter < 2 ? "Result" : "Results", search);
	printf("\t\t<1> Search again <0> Return to Main Menu\n\n\n");
	printf("\tChoose an Option: ");
 	book_search_options_retry:
	switch (getch()) 
	{
		case '1':
			search_members();
			break;	
		case '0':
			fclose(members);
			mainmenu();
			break;
		default:
			goto book_search_options_retry;
	}
}
//deletemembers function
void delete_members()
{
	system("cls"); int found=0;
	char search[20], *id_search, temp_id[100];
	gotoxy(15,2);  printf("------------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> MEMBERS >>> DELETE MEMBERS       |");
	gotoxy(15,4);  printf("------------------------------------------------------");
	FILE *mfile;
	members = fopen("Members.txt","r");
	printf("\n\n\n\t\tEnter Member ID  for delete:");
	scanf("%s",&search);
	mfile=fopen("TempBook.txt","w+");
	fseek(members, 0, SEEK_END);
	rewind(members);
	while (!feof(members))
	{
		fscanf(members, "%[^\n]\n%[^\n]\n%[^\n]\n", &member.id, &member.name, &member.date_added);
		id_search = strstr(strupr(strcpy(temp_id, member.id)), search);
		if(id_search == NULL)
		{
			fprintf(mfile,"%s\n%s\n%s\n",&member.id,&member.name,&member.date_added);
		}
		else
		{
			found=1;
		}
	}
	if(!found)
	{
		printf("\n\tRecord not found");
		printf("\n\tPress any key to Main Menu..");
	}
	else
	{
		printf("\n\tRecord deleted successfully.....");
		printf("\n\tPress any key to Main Menu..");
	}
	fclose(mfile); fclose(members);
	remove("Members.txt"); rename("TempBook.txt","Members.txt");
	getch();mainmenu();
}
//loanbooks function
void loan_books()
{
	system("cls"); time(&now);
	gotoxy(15,2);  printf("-----------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> LOANS >>> LOAN BOOK       |");
	gotoxy(15,4);  printf("-----------------------------------------------");
	books = fopen("Books.txt","r");members = fopen("Members.txt","r");loans = fopen("Loans.txt", "r");
	int found_book = 0, found_member = 0, year = 0, month = 0, date = 0;     
	char member_id[150], book_id[150];   
	fflush(stdin);
	printf("\n\t\tMember ID: ");
	scanf("%[^\n]", member_id);
	fseek(members, 0, SEEK_END);
	rewind(members);
	while (!feof(members)) 
	{
		fscanf(members, "%[^\n]\n%[^\n]\n%[^\n]\n", &member.id, &member.name, &member.date_added);
		if (strcmp(member_id, member.id) == 0) 
		{
			printf("\t\t\tName: %s", &member.name);
			found_member = 1;
			strcpy(loan.member_id, member.id);
		}
	}
	if (found_member != 1) 
	{
		printf("\n\n\n                  No student with ID: %s Found\n\n\n\n", member_id);
		printf("           <1> New Loan              <0> Main Menu\n\n\n                 Choose an Option: ");
 		loan_book_student_options_retry:
		switch (getch()) 
		{
			case '1':
				loan_books();
				break;
			case '0':
				mainmenu();
				break;
			default:
				goto loan_book_student_options_retry;
		}
	}
	fflush(stdin);
	printf("\n\n\t\tBook ID: ");
	scanf("%[^\n]", book_id);
	fseek(books, 0, SEEK_END);
	rewind(books);
	while (!feof(books)) 
	{
		fscanf(books, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", &book.id, &book.title, &book.author, &book.date_added);
		if (strcmp(book_id, book.id) == 0) 
		{
			printf("\t\t\tTitle: %s\n\t\t\tAuthor: %s",&book.title, &book.author);
			found_book = 1;
			strcpy(loan.book_id, book.id);
		}
	}
	if (!found_book) 
	{
		printf("\n\n\n                  No Book with ID: %s Found\n\n\n\n", book_id);
		printf("           <1> New Loan              <0> Main Menu\n\n\n                 Choose an Option: ");
 		loan_book_book_options_retry:
		switch (getch()) 
		{
			case '1':
				loan_books();
				break;
			case '0':
				fclose(members);
				fclose(books);
				mainmenu();
				break;
			default:
				goto loan_book_book_options_retry;
		}
	}
	printf("\n\n\t\tDate to Return\n\n");
	printf("\t\t\tYear(YYYY): ");
	scanf("%d", &year);
	printf("\t\t\tMonth(MM): ");
	scanf("%d", &month);
	printf("\t\t\tDate(DD): ");
	scanf("%d", &date);
	loan.date_to_return = date_to_timestamp(year, month, date);
	printf("\t--------------------------------------------------------------\n");
	printf("\t\t\tAre you sure you wish to Add this Record?\n\n");
	printf("\t\t\t\t\t<Y> Yes            <N> No\n\n\n");
	printf("\t\t\tChoose an Option: ");
 	loan_book_confirm_loan_options_retry:
	switch (tolower(getch())) 
	{
		case 'y':
			fprintf(loans = fopen("Loans.txt", "a+"), "%s\n%s\n%s%s\n%s%d\n",
				&loan.member_id, &loan.book_id, &loan.member_id, &loan.book_id, strcpy(loan.date_barrow, ctime(&now)), loan.date_to_return);
			fclose(loans);
			mainmenu();
			break;
		case 'n':
			mainmenu();
			break;
		default:
			goto loan_book_confirm_loan_options_retry;
	}
}
//viewoverduebooks function
void view_overdue_books()
{
	system("cls"); int counter = 0, current_time = time(NULL);
	gotoxy(15,2);  printf("--------------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> LOANS >>> VIEW OVERDUE BOOKS       |");
	gotoxy(15,4);  printf("--------------------------------------------------------");
	books = fopen("Books.txt", "r");members = fopen("Members.txt","r");loans = fopen("Loans.txt", "r");
	printf("\n\t--------------------------------------------------------------\n");
	while (!feof(loans)) 
	{
		fscanf(loans, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%ld\n", &loan.member_id, &loan.book_id, &loan.id, &loan.date_barrow, &loan.date_to_return);
		if (loan.date_to_return < current_time) 
		{
			fseek(members, 0, SEEK_END);
			rewind(members);
			while (!feof(members)) 
			{
				fscanf(members, "%[^\n]\n%[^\n]\n%[^\n]\n", &member.id, &member.name, &member.date_added);
				if (strcmp(loan.member_id, member.id) == 0) 
				{
					printf("\n\t\tMember Id: %s", &member.id);
					printf("\n\t\tMember Name: %s", &member.name);
				}
			}
			fseek(books, 0, SEEK_END);
			rewind(books);	
			while (!feof(books)) 
			{
				fscanf(books, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", &book.id, &book.title, &book.author, &book.date_added);
				if (strcmp(loan.book_id, book.id) == 0) 
				{
					printf("\n\t\tBook Id: %s\n\t\tBook Title: %s\n\t\tBook's Author: %s",&book.id, &book.title, &book.author);
				}
			}
			time_t date_to_return_timestamp = loan.date_to_return;
			printf("\n\t\tDate Loaned: %s", &loan.date_barrow);
			printf("\n\t\tDate to Return: %s", ctime(&date_to_return_timestamp));
			printf("\n\t--------------------------------------------------------------\n");
			counter++;
		}
	}
	printf("\n\t\t\t%d %s Available", counter, counter == 1 ? "Record" : "Records");
	printf("\n\n\t\tPress any Key to Return to the Main Menu");
	fclose(books);fclose(members);fclose(loans);
	getch();
	mainmenu();
}
//returnbook function
void return_book()
{
	system("cls");	int found=0;
	gotoxy(15,2);  printf("-------------------------------------------------");
	gotoxy(14,3);  printf("|       MAIN MENU >>> LOANS >>> RETURN BOOK       |");
	gotoxy(15,4);  printf("-------------------------------------------------");
	char member_id[150], book_id[150], loan_id[150], *id_search, temp_id[100];
	FILE *lfile;
	loans = fopen("Loans.txt","r");
	fflush(stdin);	printf("\n\t\tMember ID: ");	scanf("%s", member_id);
	fflush(stdin);	printf("\n\t\tBook ID: ");	scanf("%s", book_id);
	strcpy(loan_id, member_id);	strcat(loan_id, book_id);	// Concatenate the student ID and book ID to determine the loan ID
	lfile=fopen("TempLoans.txt","w+");
	fseek(loans, 0, SEEK_END);
	rewind(loans);
	while (!feof(loans))
	{
		fscanf(loans, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", &loan.member_id, &loan.book_id, &loan.id, &loan.date_barrow, &loan.date_to_return);
		id_search = strstr(strupr(strcpy(temp_id, loan.id)), loan_id);
		if(id_search == NULL)
		{
			fprintf(lfile, "%s\n%s\n%s\n%s\n%s\n", &loan.member_id, &loan.book_id, &loan.id, &loan.date_barrow, &loan.date_to_return);
		}
		else
		{
			found=1;
		}
	}
	if(!found)
	{
		printf("\n\tRecord not found");
		printf("\n\tPress any key to Main Menu..");
	}
	else
	{
		printf("\n\tBook has successfully Return.....");
		printf("\n\tPress any key to Main Menu..");
	}
	fclose(loans);	fclose(lfile);
	remove("Loans.txt");	
	rename("TempLoans.txt","Loans.txt");
	getch();mainmenu();	
}
