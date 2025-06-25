#include <stdio.h>
#include <string.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Book
{
    char title[100];
    char author[50];
    struct Date publishDate;
};

void insertBooks(struct Book *books, int *count, int total);
void printBooks(struct Book *books, int total);
void printDate(struct Date date);
void sortBooksByPublishDate(struct Book *books, int total);
void findLatestPublishDate(struct Book *books, int total);
int isNewerDate(struct Date a, struct Date b);
int isTheSameDate(struct Date a, struct Date b);
void preventSkipLine();

int main()
{

    /**
     * Write a program to:
     * a) (2 points) Input information for `n` books and print them.
     * b) (2 points – for high-performing students) Find and print the book with the most recent publish date.
     */
    int n;
    do
    {
        printf("Enter numbers of books to import (n) = ");
        scanf("%d", &n);
    } while (n <= 0);
    preventSkipLine();
    int count = 0;
    struct Book books[n];
    insertBooks(books, &count, n);
    printf("List of books:\n");
    printBooks(books, n);
    sortBooksByPublishDate(books, n);
    findLatestPublishDate(books, n);
    return 0;
}

void insertBooks(struct Book *books, int *count, int total)
{
    while (*count < total)
    {
        struct Book newBook;
        struct Date bookDate;
        printf("#%d/%d Book information:\n", *count + 1, total);
        printf("Title: ");
        fgets(newBook.title, sizeof(newBook.title), stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0';

        printf("Author: ");
        fgets(newBook.author, sizeof(newBook.author), stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0';

        printf("Publish date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &bookDate.day, &bookDate.month, &bookDate.year);

        newBook.publishDate = bookDate;
        books[*count] = newBook;
        *count = *count + 1;
        preventSkipLine();
    }
};

void printBooks(struct Book *books, int total)
{
    for (int i = 0; i < total; i++)
    {
        struct Book element = *(books + i);
        printf("#%d \"%s\" by author \"%s\" publish in ", i + 1, element.title, element.author);
        printDate(element.publishDate);
        printf("\n");
    }
};

void printDate(struct Date date)
{
    printf("%d/%d/%d", date.day, date.month, date.year);
};

void sortBooksByPublishDate(struct Book *books, int total)
{
    for (int i = total; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (j < total - 1 && isNewerDate((*(books + j)).publishDate, (*(books + j + 1)).publishDate))
            {
                struct Book temp = *(books + j);
                *(books + j) = *(books + j + 1);
                *(books + j + 1) = temp;
            }
        }
    }
};

void findLatestPublishDate(struct Book *books, int total)
{
    struct Book latestBooks[total];
    struct Book *ptr = latestBooks;
    struct Date latestPublishDate = (*books).publishDate;
    int count = 0;
    // Find other books might be published on the same date
    for (int i = 0; i < total; i++)
    {
        if (isTheSameDate((*(books + i)).publishDate, latestPublishDate))
        {
            *(ptr + count) = *(books + i);
            count++;
        }
    }
    printf("Book(s) with the most recent publish date:\n");
    printBooks(latestBooks, count);
};

int isTheSameDate(struct Date a, struct Date b)
{
    if (a.year == b.year && a.month == b.month && a.day == b.day)
    {
        return 1;
    }
    return 0;
};

int isNewerDate(struct Date a, struct Date b)
{
    if (a.year > b.year)
    {
        return 0;
    }
    else if (a.year < b.year)
    {
        return 1;
    }
    else
    {
        if (a.month > b.month)
        {
            return 0;
        }
        else if (a.month < b.month)
        {
            return 1;
        }
        else
        {
            if (a.day > b.day)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
};

void preventSkipLine()
{
    getchar();
};