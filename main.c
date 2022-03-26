//主函数
#include "public.h"
#include "main.h";
#include <windows.h>

void main(void)
{
    int i,j;
    int choice;     //记录用户选择
    int n1, n2;     //分别记录用户输入的学生总数和课程总数
    char Welcome[] = ">>>Welcome to Student Status Management System<<<";
    char Tip1[] = "\n\nThe Options Offered Are As Follows:\n";
    char Tip2[] = "Please input your choice:\n";
    char Tip3[] = "Loading... Please wait\n";
    //创建结构体数组
    STUDENT stu[MAX_STU];
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        printf("***");
        Sleep(30);
    }
    i = 0;
    while (Welcome[i] != '\0')
    {
        printf("%c", Welcome[i]);
        Sleep(30);
        i++;
    }
    for (i = 0; i < 6; i++)
    {
        printf("***");
        Sleep(30);
    }
    //提示语句
    i = 0;
    while (Tip1[i] != '\0')
    {
        printf("%c", Tip1[i]);
        Sleep(30);
        i++;
    }
    printf("1>Input record\n"
           "2>Calculate total and average score of every course\n"
           "3>Calculate total average score of every student\n"
           "4>Sort in ascending order by total score of every student\n"
           "5>Sort in ascending order by number\n"
           "6>Sort in ascending order by name\n"
           "7>Search by number\n"
           "8>Search by name\n"
           "9>Statistic analysis for every course\n"
           "10>List record\n"
           "0>Exit\n"
           );
    printf("\n\n");
    for (i = 0; i < 85; i++)
    {
        printf("*");
    }
    //用户选择
    printf("\n");
    do
    {
        i = 0;
        while (Tip2[i] != '\0')
        {
            printf("%c", Tip2[i]);
            Sleep(30);
            i++;
        }
        scanf("%d", &choice);
        getchar();
        i = 0;
        while (Tip3[i] != '\0')
        {
            printf("%c",Tip3[i]);
            Sleep(30);
            i++;
        }
        printf("\n");
        //从以下到switch前都为动态进度条，以增强用户体验
        for (i = 0; i <= 10; i++)
        {
            printf("\r%d%-5%\t[", i*10);
            for (j = 0; j < i; j++)
            {
                printf("*****");
            }
            printf(">");
            for (j = 10; j > i; j--)
            {
                printf(".....");
            }
            printf("]");
            Sleep(30);
        }
        printf("\n\n");
        switch (choice)
        {
            case 1:
                n1 = getStuNum();
                n2 = getCourseNum();
                ReadRecord(stu, n1, n2);
                break;
            case 2:
                SumAndAverForCourse(stu, n1, n2);
                break;
            case 3:
                SumAndAverForStu(stu, n1, n2);
                break;
            case 4:
                SortBySum(stu, n1, n2);
                break;
            case 5:
                SortByID(stu, n1, n2);
                break;
            case 6:
                SortByName(stu, n1, n2);
                break;
            case 7:
                SearchByID(stu, n1 ,n2);
                break;
            case 8:
                SearchByName(stu, n1, n2);
                break;
            case 9:
                ScoreAnalyse(stu, n1, n2);
                break;
            case 10:
                ALLResult(stu, n1, n2);
                break;
            case 0:
                printf("Exit Successfully!");
                break;
            default:
                printf("Please input a valid choice!!!");
                break;
        }
    }while (choice != 0);
}
