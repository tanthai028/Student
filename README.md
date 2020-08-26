# Student
Student is a C program I made during Fall of my freshman year of college to implement all the basics of C program that I’ve learned for the semester. The program creates a fee invoice application for students attending Valence Community College, allowing the user to add, edit, delete, search a student and print their invoice.

# Usage 
For your convenience, here is how you could do it in CMD environment.

1. First compile: gcc student.c
2. After compilation, to run the program, you would type the following command: a.exe

# Sample Run
**Example edge case:**  
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
**Adding a student**  
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
**Deleting a course**  
```
Choose the following options:
    1. Add new student
    2. Add/Delete Course
    3. Search
    4. Invoice
    0. Exit

Enter your selection: 2
Enter your student's ID: 5900

Here are the courses John Smith is taking:
CRN     PREFIX      CR. HOURS
4587    MAT 236     4
4599    COP 220     3


Choose from:
A- Add a new course for John Smith
D- Delete a course from John Smith’s schedule
C- Cancel operation

Enter your selection: D
Enter the course number to delete: 4587

[4587 MAT 236] is sucessfully deleted
Want to display the new invoice(y or n).
y

    Valence Community College
    Orlando Florida 10101
    ---------------------------------------
    Fee Invoice Prepared for Student: 
    5900-John Smith

    1 Credit Hour = 120.25

    CRN  CR_PREFIX  CR_HOURS
    4599    COP 220     3         $  360.75

                 Health & ID fees $  35.00

    ---------------------------------------
                 Total payments   $  395.75
```
