#include <stdio.h>
#include <stdlib.h>

int mas(int n, int A[n][n])
{
    printf("Введіть елементи матриці A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (scanf("%d", &A[i][j]) != 1)
            {
                return 1;
            }
        }
    }
    printf("Матриця \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d \t" , A[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void diagonal(int n, int A[n][n])
{
    printf("Головна діагональ: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i][i]);
    }
}

int *maxdiag(int n, int A[n][n])
{
    int *max = &A[0][0];
    for (int i = 1; i < n; i++)
    {
        if (A[i][i] > *max)
        {
            max = &A[i][i];
        }
    }
    return max;
}

int *mindiag(int n, int A[n][n])
{
    int *min = &A[0][0];
    for (int i = 1; i < n; i++)
    {
        if (A[i][i] < *min)
        {
            min = &A[i][i];
        }
    }
    return min;
}
int difference(int *min, int *max)
{
    return *max - *min;
}

void menu()
{
    int n = 0, h;
    int *max, *min;
    int A[n][n];
    int m = 0;
    do
    {
        printf("\n1. Ввести елементи матриці");
        printf("\n2. Головна діагональ");
        printf("\n3. Знайти різницю між максимальним і мінімальним значеннями на головній діагоналі");
        printf("\n0. Вихід з програми\n");
        printf("\nВведіть номер (0-3): ");
        scanf("%d", &h);
        switch (h)
        {
        case 1:
            m = 1;
            printf("Введіть n = ");
            if (scanf("%d", &n) != 1 || n <= 0)
            {
                m = 0;
                printf("Некоректне значення n\n");
                break;
            }
            

            if (mas(n, A) != 0)
            {
                m = 0;
                printf("Помилка при введенні матриці\n");
                break;
            }
            break;
        case 2:
            if (m == 1)
            {
                diagonal(n, A);
            }
            else
            {
                printf("Спочатку введіть елементи матриці");
                break;
            }
            break;
        case 3:
            if (m == 1)
            {
                max = maxdiag(n, A);
                min = mindiag(n, A);
                int dif = difference(min, max);
                printf("Мінімальне значення на головній діагоналі: %d\n", *min);
                printf("Максимальне значення на головній діагоналі: %d\n", *max);
                printf("Різниця між максимальним і мінімальним значеннями на головній діагоналі: %d\n", dif);
            }
            else
            {
                printf("Спочатку введіть елементи матриці");
                break;
            }

            break;
        case 0:
            printf("Вихід з програми\n");
            break;
        default:
            printf("Неправильна цифра\n");
            break;
        }
    } while (h != 0);
}

int main()
{
    menu();
    return 0;
}
