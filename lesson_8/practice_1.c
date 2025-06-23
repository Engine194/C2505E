#include <stdio.h>

struct Student
{
    char name[50];
    char group[20];
    int age;
    float gpa;
};

void insertStudent(struct Student *group, int *length);
void printStudent(struct Student *group, int length);
void printMaxGpa(struct Student *group, int length);
void questionForStop(int *choice, int i, int count);
void sortStudents(struct Student *group, int length);
void preventSkipLine();

int main()
{

    /**
     * 1. Nhap vao 1 danh sach sinh vien cua lop C2505E cho den khi chon stop
     * 2. Luu tru danh sach sinh vien nay vao mot mang Student
     * 3. Hien thi tat ca sinh vien ra man hinh
     * 4. Hien thi ra sinh vien co diem GPA cao nhat
     */

    int choice = 1;
    int i = 0;
    int count;
    printf("Lop co bao nhieu sinh vien: ");
    scanf("%d", &count);
    struct Student c2505e[count];
    preventSkipLine();
    do
    {
        insertStudent(c2505e, &i);
        printStudent(c2505e, i);
        questionForStop(&choice, i, count);
        if (choice == 0 || i >= count)
        {
            printMaxGpa(c2505e, i);
            sortStudents(c2505e, i);
            printStudent(c2505e, i);
            return 0;
        }
    } while (choice != 0 && i < count);
    return 0;
}

void printMaxGpa(struct Student *group, int length)
{
    int maxIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if ((*(group + i)).gpa >= (*(group + maxIndex)).gpa)
            maxIndex = i;
    }
    struct Student maxGpa = *(group + maxIndex);
    printf("Max GPA from Student %s with GPA = %.2f\n", maxGpa.name, maxGpa.gpa);
}

void sortStudents(struct Student *group, int length)
{
    for (int i = length; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (j < i - 1 && (*(group + j)).gpa < (*(group + j + 1)).gpa)
            {
                struct Student temp = *(group + j + 1);
                *(group + j + 1) = *(group + j);
                *(group + j) = temp;
            }
        }
    }
}

void insertStudent(struct Student *group, int *length)
{
    struct Student student;
    printf("Nhap ten sinh vien: ");
    fgets(student.name, sizeof(student.name), stdin);

    printf("Nhap ten lop: ");
    fgets(student.group, sizeof(student.group), stdin);

    printf("Nhap gpa: ");
    scanf("%f", &student.gpa);

    printf("Nhap tuoi: ");
    scanf("%d", &student.age);
    group[*length] = student;
    *length = *length + 1;
};

void printStudent(struct Student *group, int length)
{
    for (int i = 0; i < length; i++)
    {
        struct Student std = *(group + i);
        printf("#%d Ten: %s - Lop: %s - Tuoi: %d - GPA: %.2f\n", i + 1,
               std.name, std.group, std.age, std.gpa);
    }
}

void questionForStop(int *choice, int i, int count)
{
    printf("1 - Continue, 0 - Find student with max GPA and Exit ?\n");
    scanf("%d", choice);
    if (choice != 0)
        preventSkipLine();
}

void preventSkipLine()
{
    getchar();
}