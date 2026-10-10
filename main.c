/*Файзуллина Дарина Ирековна
ПИ 1-1
 dz 1
 Вариант 5  Удаление повторений
 (Сформировать новый массив, содержащий каждое 
 значение исходного массива только один раз.)*/
 
#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMax(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void performIndividualTask(const int array[], int size);

int main(void)
{
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE)
    {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);
    printArray(array, size);

/* Вызовы функций основной и индивидуальной обработки */

    return 0;
}