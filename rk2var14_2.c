#include <stdio.h>


int main() {
    int matrix_B[25][25]; // двумерный массив - массив двойной вложенности, как дома у каждого есть пакет с пакетами

    int n, m; // n - целочисленная переменная ширины матрицы, m - переменная высоты матрицы
    scanf("%d %d", &n, &m); // функция чтения из потока ввода stdin
    // вводим размер матрицы через пробел, как например "5 6"

    for (int i = 0; i < m; i++) // проходимся по строкам
        for (int j = 0; j < n; j++) // проходимся по столбцам
            scanf("%d", &matrix_B[i][j]); // считываем элемент матрицы

    int min_idx = 0;
    for (int i = 0; i < m || i < n; i++) // || - это "или" булева операция дизъюнкции истинности значений ( && - операция "и")
        // проходим по диагонали матрицы
        if (matrix_B[i][i] < matrix_B[min_idx][min_idx]) // ищем минимум
            min_idx = i;

    int product = 1;
    for (int i = 0; i < n; i++)
        product *= matrix_B[min_idx][i]; // находим произведение


    for (int i = 0; i < m; i++) { // проходимся по строкам
        for (int j = 0; j < n; j++) // проходимся по столбцам
            printf("%5d ", matrix_B[i][j]); // считываем элемент матрицы // 5d - выравнивание в 5 символов для красоты
        printf("\n"); // переход на новую строку
    }

    printf("product of array = %d\n", product);

    return 0;
}
