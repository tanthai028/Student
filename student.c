#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define maxChar 50
#define COST 120.25
#define HEALTH_FEE 35.00
#define maxNumber 10
#define numberCrnOffered 8

int amtofStudents = 0;
int crnDatabase[] = {4587,4599,8997,9696,1232,9856,8520,8977};
char crnPrefix[12][100] = {"MAT 236","COP 220","GOL 124","COP 100","MAC 531","STA 100","TNV 400","CMP 100"};
int crnHrs[]= {4,3,1,3,2,3,4,3,1,4,3,5};

struct profile
{
  int id;
  char name[maxChar];
  int crn[4];
	int crnAmt;
};

struct profile student[maxNumber];

void options();
void addStudent();
void addDrop();
void search();
void invoice(); 
void displayStudent(); // displays student's courses
void displayCourseList();

void addID();
int checkCrn();
int checkID();
int getID();
int add();
int del();
int checkSameCrn();
int newPrint();

int main() {
	
	options();
  
  return 0;
}

void options(){
	int option;

	printf("\nChoose the following options:\n");
	printf("\t1. Add new student\n");
	printf("\t2. Add/Delete Course\n");
	printf("\t3. Search\n");
	printf("\t4. Invoice\n");
	printf("\t0. Exit\n\n");

	printf("Enter your selection: ");

	do{
		scanf("%d", &option);
		if ( option < 0 || option > 4 ){
			printf("Invalid input. Try again: ");
		}
	} while ( option < 0 || option > 4 );

	switch (option){
		case 1: addStudent(); break;
		case 2: addDrop(); break;
		case 3: search(); break;
		case 4: invoice(); break;
		case 0: exit(0); break;
	}
}

void addID(){
	printf ("Enter the student's id: ");
	scanf("%d", &student[amtofStudents].id);
}

void addStudent(){
	int n;
	int crs;
	int crn = 0;

	addID();

	if ( checkID(student[amtofStudents].id) != 1 ){

		printf ("Enter the student's name: ");
		fgets(student[amtofStudents].name, maxChar, stdin); 
		fgets(student[amtofStudents].name, maxChar, stdin); 
		student[amtofStudents].name[strlen (student[amtofStudents].name) - 1] = '\0'; 

		printf ("Enter how many courses %s is taking (up to 4 courses)? ", student[amtofStudents].name);

		do{
			scanf ("%d", &n);
			if ( n < 0 || n > 4 ){
				printf("Invalid input. Try again: ");
			}
		} while ( n < 0 || n > 4 );
		
		displayCourseList();

		printf("\nEnter the %d course numbers: ", n);
		for (int i = 0; i < n; i++){
			scanf("%d", &crn);

	    while (checkCrn(crn) != 1 ){
      	printf("CRN not available. Try again: ");
      	scanf("%d",&crn);
    	}

    	student[amtofStudents].crn[i] = crn;
    	student[amtofStudents].crnAmt++;
		}

		printf("\nStudent added successfully\n");
	}
	else printf("Invalid Student\n");

	amtofStudents++;
	options();

}

void displayCourseList(){
  printf("\n\tCRN\t\tPREFIX\t\tCR. HOURS\n");
  for(int i=0; i < numberCrnOffered; i++){
    printf("\t%d\t%s\t\t%d\n", crnDatabase[i], crnPrefix[i], crnHrs[i]);
  }
}

int checkCrn(int crn){
	
  for(int i = 0; i < numberCrnOffered; i++){
    if(crnDatabase[i] == crn){
      return 1;
    }
	}
	return 0;
}

int checkID(int id){

  for(int i = 0; i < amtofStudents; i++){
    if(student[i].id == id){
      printf("Student's ID already exist\n");
      return 1;
    } 
	}

	return 0;
}

int getID(){
	int id, x;
	printf("Enter your student's ID: ");
	scanf("%d", &id);

	for ( int i = 0; i < amtofStudents; i++ ){
		if ( id == student[i].id ){
			x = i;
		}
	}

	return x;
}

void search(){
	int id;

	printf("Enter your student's ID: ");
	scanf("%d", &id);

	for ( int i = 0; i <= amtofStudents; i++ ){
		if ( id == student[i].id ){
			printf("Student found!\n");
		}
		else printf("Student not found!\n");
	}
		
	options();
}

void displayStudent(id){
	int x;
	// printf("amtofStudents = %d\n", amtofStudents);
	
	printf("\nCRN\t\tPREFIX\t\tCR. HOURS\n");
	for ( int i = 0; i < student[id].crnAmt; i++){
    for ( x = 0; x < numberCrnOffered; x++){
      if (student[id].crn[i] == crnDatabase[x])
      break;
    }
		printf("%d\t%s\t\t%d\n", crnDatabase[x],crnPrefix[x],crnHrs[x]);
	}

}

void addDrop(){
	int id;
	char yesNo;
	id = getID();

	printf("\nHere are the courses %s is taking:", student[id].name);
	displayStudent(id);

	printf("\n\nChoose from:\n");
	printf("A- Add a new course for %s\n", student[id].name);
	printf("D- Delete a course from %s’s schedule\n", student[id].name);
	printf("C- Cancel operation\n\n");

	printf("Enter your selection: ");
	scanf(" %c", &yesNo);

	while (toupper(yesNo) != 'A'&& toupper(yesNo) != 'D'&& toupper(yesNo) != 'C'){
		printf("Try again. Enter your selection: ");
		scanf(" %c", &yesNo);
	}
	if(toupper(yesNo) == 'A'){
		add(id);
	}
	if(toupper(yesNo) == 'D'){
		del(id);
	}

	options();
}

int add(int id){
	int crn;

  if (student[id].crnAmt >= 4){
    printf("Sorry you can't have more than four courses");
    return 1;
  }

	printf("Enter the course number to add: ");
  scanf("%d", &crn);

	if ( checkCrn(crn) != 1 ){
    printf("Sorry CRN not available\n");
    return 1;
	}
  if ( checkSameCrn(crn, id) == 1){
    printf("Student is already taking the course\n");
    return 1;
  }

  student[id].crn[student[id].crnAmt] = crn;
  
  printf("\nCourse added");
  student[id].crnAmt++;
  return 0;

}

int checkSameCrn(int crn, int id){

	for ( int i = 0; i < student[id].crnAmt; i++ ){
		if ( crn == student[id].crn[i] ){
			return 1; // false
		}
	}

	return 0;
}

int del(int id){
	int crn, pos = 0, x;
	char yesNo;

	printf("Enter the course number to delete: ");
	scanf("%d", &crn);

  if (checkCrn(crn) != 1){
    printf("Sorry CRN not available\n");
    return 1;
  }

	for ( int i = 0; i < student[id].crnAmt; i++){
		if (crn == student[id].crn[i]){
			pos = i;
			break;
		}
	}

	student[id].crnAmt--;
	for(int i = pos; i < student[id].crnAmt; i++){
		student[id].crn[i] = student[id].crn[i+1];
	}

  for ( int i = 0; i < numberCrnOffered; i++ ){
		if (crn == crnDatabase[i]){
			x = i;
			break;
    }
  }

  printf("\n[%d %s] is sucessfully deleted\n", crnDatabase[x], crnPrefix[x]);
  printf("Want to display the new invoice(y or n).\n");
  scanf( " %c" , &yesNo);
  while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N'){
    printf("Try again (y or n).");
    scanf(" %c", &yesNo);
  }
  
	if (toupper(yesNo) == 'Y')
    newPrint(id);

  return 0;
	
}

void invoice(){
  int i,x,idPos, position, id;
  float total = 0, cost;
 
  idPos = getID();

	printf("idPos = %d\n\n", idPos);

  if (idPos != -1){
	printf("\n\tValence Community College\n");
	printf("\tOrlando FLorida 10101\n");
	printf("\t---------------------------------------\n\n");

	printf("\tFee Invoice prepared for student: \n\t%d-%s\n\n", student[idPos].id, student[idPos].name);
	printf("\t1 Credit Hour = 120.25\n\n");
	printf("\tCRN\t\tCR_PREFIX\tCR_HOURS\n");


	for (i = 0;i < student[idPos].crnAmt; i++ ){
		for(x = 0; x < numberCrnOffered;x++){
			if (student[idPos].crn[i] == crnDatabase[x]){
				position = x;
				break;
			}
		}
		cost = COST * crnHrs[position];
		total += cost;
		printf("\t%d\t%s\t\t%d\t\t  $  %.2f\n", crnDatabase[position], crnPrefix[position], crnHrs[position], cost);
	}

	printf("\n\t\t\t\t Health & ID fees $\t 35.00\n\n");
	printf("\t---------------------------------------\n");
	printf("\t\t\t\t Total payments   $  %.2f\n\n", total+HEALTH_FEE);
  }
  options();
}

int newPrint(int id)
{
  int i, position, x; 
  float total=0, cost;
  printf("\n\tValence Community College\n");
  printf("\tOrlando Florida 10101\n");
  printf("\t---------------------------------------\n");

  printf("\tFee Invoice Prepared for Student: \n\t%d-%s\n\n", student[id].id, student[id].name);
  printf("\t1 Credit Hour = 120.25\n\n");
  printf("\tCRN\t CR_PREFIX\tCR_HOURS\n");


  for (i = 0;i < student[id].crnAmt; i++ ){
    for(x = 0; x < numberCrnOffered;x++){
      if (student[id].crn[i] == crnDatabase[x]){
        position = x;
        break;
      }
    }
    cost = COST * crnHrs[position];
    total += cost;
    printf("\t%d\t%s\t\t%d\t\t  $  %.2f\n", crnDatabase[position], crnPrefix[position], crnHrs[position], cost);
    }

    printf("\n\t\t\t\t Health & ID fees $\t 35.00\n\n");
    printf("\t---------------------------------------\n");
    printf("\t\t\t\t Total payments   $  %.2f\n\n", total+HEALTH_FEE);
  
  return 0;
}
