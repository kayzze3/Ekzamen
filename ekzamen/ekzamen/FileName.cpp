#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

// Функція для обчислення суми непарних елементів масиву
double sumOfOddElements(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int size = 10;  // Розмір масиву (можна змінювати)

    double arr[size];

    // Введення елементів масиву
    cout << "Введіть " << size << " дійсних чисел для масиву:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Визначення максимального та мінімального елементів та їхніх індексів
    double maxElement = arr[0], minElement = arr[0];
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }

    // Обчислення суми непарних елементів
    double sumOdd = sumOfOddElements(arr, size);

    // Обчислення добутку елементів між максимальним і мінімальним
    double productBetweenMinMax = 1.0;
    int start, end;
    if (maxIndex < minIndex) {
        start = maxIndex + 1;
        end = minIndex;
    }
    else {
        start = minIndex + 1;
        end = maxIndex;
    }
    for (int i = start; i < end; ++i) {
        productBetweenMinMax *= arr[i];
    }

    // Виведення результатів
    cout << "Сума непарних елементів: " << sumOdd << endl;
    cout << "Добуток елементів між максимальним і мінімальним: " << productBetweenMinMax << endl;

    // Сортування масиву за спаданням
    sort(arr, arr + size, greater<double>());

    // Виведення відсортованого масиву
    cout << "Масив, відсортований за спаданням: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}