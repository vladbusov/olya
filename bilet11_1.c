#include <stdio.h>
/*
    ВВОД:
    5
    5 4 3 2 1
    ВЫВОД:
    original arr[0] = 5
    original arr[1] = 4
    original arr[2] = 3
    original arr[3] = 2
    original arr[4] = 1
    update arr[0] = 2
    update arr[1] = 4
 */

void insertion_sort(int* arr, int n) { // сортировка вставками, передаем аргумент по указателю на массив
    for (int i = 0; i < n; i++) {
        int min_idx = 0;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) // находим минимум
                min_idx = j;

            // меняем местами
            int tmp = arr[min_idx]; // временная переменная
            arr[min_idx] = arr[i];
            arr[i] = tmp;
        }
    }
}

void delete_value(int* arr, int n, int idx_value) {
    for (int i = idx_value; i <= n; i++)
        arr[i] = arr[i+1];
}

int main() {
    int array_X[50]; // массив целочисленных значений integer выделенный на стеке
    int n; // целочисленная переменная

    scanf("%d", &n); // функция чтения из потока ввода stdin
    // %d  - значит мы считываем целое число, первым аргументом передается формат данных, которые мы считываем %s - строка
    // %c - символ , %f - число с плавающей точкой
    // & - операция взятия адреса, по которому располагается переменная
    // нужно для того, чтобы по этому адресу можно было записать считанное значение, в противном случае без взятия адреса просто
    // создатся копия этой переменной

    for (int i = 0; i < n; i++) {  // n раз проходимся по массиву от 0 до n - 1 и считываем целочисленные значения
        scanf("%d", &array_X[i]); // array[i] получение i-го элемента массива
        printf("original arr[%d] = %d\n", i, array_X[i]);
    }


    for (int i = 0; i < n; i++) { // чистим массив от нечетных значений
        if (array_X[i] % 2 != 0) {
            delete_value(array_X, n, i); // удаляем значения
            n--; // уменьшаем размер
            i--; // отменяем иттерацию
        }
    }

    insertion_sort(array_X, n); // сортируем оставшиеся элементы
    for (int i = 0; i < n; i++)   // n раз проходимся по массиву от 0 до n - 1
        printf("updated arr[%d] = %d\n", i, array_X[i]);

    return 0;
}