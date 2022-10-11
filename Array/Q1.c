#include<stdio.h>

struct employee{
    int empid;
    char ename[20];
    int age;
    int salary;
};

int main(){
    struct employee e;
    printf("Enter the employee id : ");
    scanf("%d",&e.empid);
    getchar();
    printf("Enter the employee name : ");
    scanf("%s",e.ename);
    printf("Enter the employee age : ");
    scanf("%d",&e.age);
    printf("Enter the employee salary : ");
    scanf("%d",&e.salary);


    printf("\nEmployee Details are :- \n");
    printf("Employee id is %d \n", e.empid);
    printf("Employee name is %s \n", e.ename);
    printf("Employee age is %d \n", e.age);
    printf("Employee salary is %d \n", e.salary);

return 0;
}