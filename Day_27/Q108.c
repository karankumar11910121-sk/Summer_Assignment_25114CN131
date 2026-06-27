// Q108. WAP to create marksheet generation system.

#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    char fatherName[50];
    char course[30];
    char branch[30];
    int semester;
    int marks[5];
    int total;
    float percentage;
    char grade[3];
    char division[25];
    char remark[50];
};

int main()
{
    struct Student student;
    int i;
    int pass = 1;

    printf("Enter Roll Number : ");
    scanf("%d", &student.rollNo);

    printf("Enter Student Name : ");
    scanf(" %[^\n]", student.name);

    printf("Enter Father's Name : ");
    scanf(" %[^\n]", student.fatherName);

    printf("Enter Course : ");
    scanf(" %[^\n]", student.course);

    printf("Enter Branch : ");
    scanf(" %[^\n]", student.branch);

    printf("Enter Semester : ");
    scanf("%d", &student.semester);

    printf("\nEnter Marks of 5 Subjects (Out of 100)\n\n");

    student.total = 0;

    for(i = 0; i < 5; i++)
    {
        printf("Subject %d Marks : ", i + 1);
        scanf("%d", &student.marks[i]);

        student.total += student.marks[i];

        if(student.marks[i] < 33)
        {
            pass = 0;
        }
    }

    student.percentage = student.total / 5.0;

    if(pass == 0 || student.percentage < 40)
    {
        strcpy(student.grade, "F");
        strcpy(student.division, "Fail");
        strcpy(student.remark, "Do Better Next Time.");
    }
    else if(student.percentage >= 90)
    {
        strcpy(student.grade, "A+");
        strcpy(student.remark, "Outstanding Performance!");
    }
    else if(student.percentage >= 85)
    {
        strcpy(student.grade, "A");
        strcpy(student.remark, "Excellent! Keep It Up.");
    }
    else if(student.percentage >= 80)
    {
        strcpy(student.grade, "A-");
        strcpy(student.remark, "Very Good Performance.");
    }
    else if(student.percentage >= 75)
    {
        strcpy(student.grade, "B+");
        strcpy(student.remark, "Good Job!");
    }
    else if(student.percentage >= 70)
    {
        strcpy(student.grade, "B");
        strcpy(student.remark, "Good Performance.");
    }
    else if(student.percentage >= 65)
    {
        strcpy(student.grade, "C+");
        strcpy(student.remark, "Above Average.");
    }
    else if(student.percentage >= 60)
    {
        strcpy(student.grade, "C");
        strcpy(student.remark, "Average Performance.");
    }
    else if(student.percentage >= 55)
    {
        strcpy(student.grade, "D+");
        strcpy(student.remark, "Needs Improvement.");
    }
    else if(student.percentage >= 50)
    {
        strcpy(student.grade, "D");
        strcpy(student.remark, "Work Hard.");
    }
    else
    {
        strcpy(student.grade, "E");
        strcpy(student.remark, "Minimum Passing Marks.");
    }

    printf("\n");
    printf("***************************************************************\n");
    printf("                XYZ INSTITUTE OF TECHNOLOGY\n");
    printf("                     STUDENT MARKSHEET\n");
    printf("                  Academic Session : 2026-27\n");
    printf("***************************************************************\n\n");

    printf("Roll Number   : %d\n", student.rollNo);
    printf("Student Name  : %s\n", student.name);
    printf("Father Name   : %s\n", student.fatherName);
    printf("Course        : %s\n", student.course);
    printf("Branch        : %s\n", student.branch);
    printf("Semester      : %d\n", student.semester);

    printf("\n---------------------------------------------------------------\n");
    printf("Subject\t\t\tMarks\n");
    printf("---------------------------------------------------------------\n");

    for(i = 0; i < 5; i++)
    {
        printf("Subject %d\t\t%d\n", i + 1, student.marks[i]);
    }

    printf("---------------------------------------------------------------\n");

    printf("Total Marks   : %d / 500\n", student.total);
    printf("Percentage    : %.2f%%\n", student.percentage);
    printf("Letter Grade  : %s\n", student.grade);

    if(pass && student.percentage >= 40)
    printf("Result        : PASS\n");
    else
    printf("Result        : FAIL\n");

    printf("Remark        : %s\n", student.remark);

    printf("\n---------------------------------------------------------------\n");
    printf("Class Teacher Sign : ________________\n\n");
    printf("Principal Sign     : ________________\n");
    printf("***************************************************************\n");

    return 0;
}