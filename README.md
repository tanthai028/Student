# Student
Student is a C program I made during Fall of my freshman year of college to implement all the basics of C program that I’ve learned for the semester. The program creates a fee invoice application for students attending Valence Community College, allowing the user to add, edit, delete, search a student and print their invoice.

# Usage 
For your convenience, here is how you could do it in CMD environment.

1. First compile: gcc student.c
2. After compilation, to run the program, you would type the following command: a.exe

# Sample Run
```
Choose the following options:
    1. Add new student
    2. Add/Delete Course
    3. Search
    4. Invoice  
    0. Exit

Enter your selection: 3
Enter your student's ID: 8989
Student not found!
```

```
Choose the following options:
    1. Add new student
    2. Add/Delete Course
    3. Search
    4. Invoice
    0. Exit

Enter your selection: 1
Enter the student's id: 5900
Enter the student's name: John Smith
Enter how many courses John Smith is taking (up to 4 courses)? 2

    CRN     PREFIX      CR. HOURS
    4587    MAT 236     4
    4599    COP 220     3
    8997    GOL 124     1
    9696    COP 100     3
    1232    MAC 531     2
    9856    STA 100     3
    8520    TNV 400     4
    8977    CMP 100     3

Enter the 2 course numbers: 4587 4599

Student added successfully
```

```
Choose from the following options:
1- Add a new student
2- Add/Delete a course
3- Search for a student
4- Print fee invoice
0- Exit program
Enter your selection: 4 Enter the student’s id: 5959 (Assume that student 5959 has been already added)
VALENCE COMMUNITY COLLEGE
ORLANDO FL 10101
```

```
Fee Invoice Prepared for Student:
5959-ALLAL TAZI
1 Credit Hour = $120.25
CRN CR_PREFIX CR_HOURS
4587 MAT 236 4 $ 481.00
4599 COP 220 3 $ 360.75
Health & id fees $ 35.00
```

Total Payments $ 876.75
--------------------
```
Choose from the following options:
1- Add a new student
2- Add/Delete a course
3- Search for a student
4- Print fee invoice
0- Exit program
Enter your selection: 2
Enter the student’s id: 5959
Here are the courses [ALLAL TAZI] is taking:
CRN PREFIX CR. HOURS
4587 MAT 236 4
4599 COP 220 3
Choose from:
A- Add a new course for [ALLAL TAZI]
D- Delete a course from [ALLAL TAZI]’s schedule
C- Cancel operation
Enter your selection: D <<< Your code should accept lower case d
Enter course Number to delete: 4599
[4599 COP 220] is deleted successfully!
Want to display the new invoice? Y/N: y <<< Your code should accept lower case y/n
VALENCE COMMUNITY COLLEGE
ORLANDO FL 10101
```

```
Fee Invoice Prepared for Student:
5959-ALLAL TAZI
1 Credit Hour = $120.25
CRN CR_PREFIX CR_HOURS
4588 MAT 236 4 $ 481.00
Health & id fees $ 35.00
--------------------------------------
Total Payments $ 516.00
```

```
Choose from the following options:
1- Add a new student
2- Add/Delete a course
3- Search for a student
4- Print fee invoice
0- Exit program
Enter your selection: 0
Goodbye!
```
