#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int student_grade[300];
    int length = argc -1;

    for (int i = 0; i < length; i++)
    {
        student_grade[i] = atoi(argv[i+1]);
    }

    int sum = cal_sum(student_grade, length);
    printf("The sum is: %d\n", sum);

    return 0;
}

int cal_sum(int grades[], int lenght)
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum += grades[i];
    }

    return sum;
}