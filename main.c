/*Файзуллина Дарина Ирековна
ПИ 1-1
 dz 1
 Вариант 5  Удаление повторений*/
 
#include <stdio.h>

#define MAX_SIZE 100
#define MIN_VALUE (-100)
#define MAX_VALUE 100

int inputArray(int arr[], int n);
void printArray(const int arr[], int n);
int findMin(const int arr[], int n);
int findMax(const int arr[], int n);
long long calculateSum(const int arr[], int n);
double calculateAverage(const int arr[], int n);
int calculatePositive(const int arr[], int n);
int calculateNegative(const int arr[], int n);
int calculateZero(const int arr[], int n);
void printArrayRange(const int arr[], int n, int a, int b);
void printArrayWithoutDuplicates(const int arr[], int n);

int main(void)
{
    int arr[MAX_SIZE];
    int n;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    if (!inputArray(arr, n)) {
        return 1;
    }

    printf("\nИсходный массив:\n");
    printArray(arr, n);

    int minI = findMin(arr, n);
    int maxI = findMax(arr, n);
    long long sum = calculateSum(arr, n);
    double average = calculateAverage(arr, n);
    int positive = calculatePositive(arr, n);
    int negative = calculateNegative(arr, n);
    int zero = calculateZero(arr, n);

    printf("Минимальный элемент = %d, его индекс = %d\n", arr[minI], minI);
    printf("Максимальный элемент = %d, его индекс = %d\n", arr[maxI], maxI);
    printf("Сумма элементов = %lld\n", sum);
    printf("Среднее арифметическое = %.2f\n", average);
    printf("Положительных элементов = %d\n", positive);
    printf("Отрицательных элементов = %d\n", negative);
    printf("Нулевых элементов = %d\n", zero);

    int a, b;
    printf("\nВведите границы диапазона индексов [a, b] (от 0 до %d):\n", n - 1);
    printf("Введите a: ");
    if (scanf("%d", &a) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }
    printf("Введите b: ");
    if (scanf("%d", &b) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }
    if (a < 0 || b >= n || a > b) {
        printf("Ошибка: должно выполняться 0 <= a <= b <= %d\n", n - 1);
        return 1;
    }

    printArrayRange(arr, n, a, b);
    printArrayWithoutDuplicates(arr, n);

    return 0;
}

/* Возвращает 1 при успехе, 0 при ошибке ввода. */
int inputArray(int arr[], int n)
{
    printf("Введите %d элементов массива (от %d до %d):\n",
           n, MIN_VALUE, MAX_VALUE);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Ошибка ввода\n");
            return 0;
        }
        if (arr[i] < MIN_VALUE || arr[i] > MAX_VALUE) {
            printf("Ошибка значения: элемент должен быть от %d до %d\n",
                   MIN_VALUE, MAX_VALUE);
            return 0;
        }
    }
    return 1;
}

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Возвращает индекс минимального элемента. */
int findMin(const int arr[], int n)
{
    int minI = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minI]) minI = i;
    }
    return minI;
}

/* Возвращает индекс максимального элемента. */
int findMax(const int arr[], int n)
{
    int maxI = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxI]) maxI = i;
    }
    return maxI;
}

long long calculateSum(const int arr[], int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(const int arr[], int n)
{
    return (double)calculateSum(arr, n) / n;
}

int calculatePositive(const int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) count++;
    }
    return count;
}

int calculateNegative(const int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) count++;
    }
    return count;
}

int calculateZero(const int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count++;
    }
    return count;
}

/* Выводит элементы с индексами от a до b включительно. */
void printArrayRange(const int arr[], int n, int a, int b)
{
    printf("Элементы с индексами [%d, %d]: ", a, b);
    for (int i = a; i <= b && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArrayWithoutDuplicates(const int arr[], int n)
{
    int uniqueArr[MAX_SIZE];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr[uniqueCount++] = arr[i];
        }
    }

    printf("Массив без повторений: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", uniqueArr[i]);
    }
    printf("\n");
}