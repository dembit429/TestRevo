// updtade 2.0
#include <iostream> 
#include <algorithm> 
#include <chrono>
#include <gtest/gtest.h>
using namespace std;
void printArray(int* array, int length)
{
    for (int index = 0; index < length; index++) {
        cout << array[index] << " ";
    }
    cout << endl;
}

void selectionSort(int* array, int length) {
    // Перебираємо кожен елемент масиву (крім останнього, він вже буде відсортований до того часу, коли ми до нього дійдемо)
    for (int startIndex = 0; startIndex < length - 1; startIndex++)
    {
        // У змінній smallestIndex зберігається індекс найменшого значення, яке ми знайшли в поточній ітерації.
        // Починаємо з того, що найменший елемент в цій ітерації - це перший елемент (індекс 0)
        int smallestIndex = startIndex;
        // Потім шукаємо менший елемент в іншій частині масиву
        for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
        {
            // Якщо ми знайшли елемент, який менше нашого найменшого елементу,
            if (array[currentIndex] < array[smallestIndex])
                // то запам'ятовуємо його
                smallestIndex = currentIndex;
        }
        // smallestIndex тепер найменший елемент.
        // Міняємо місцями наше початкове найменше число з тим, яке ми виявили
        swap(array[startIndex], array[smallestIndex]);
        cout << "Step [" << startIndex + 1 << "]: ";
        for (int index = 0; index < length; index++) {
            cout << array[index] << " ";
        }
        cout << endl;
    }
}

TEST(SelectionSortTest, Test_8_elements) {
    const int length = 8;
    int array[length] = { 9,4,0,0,3,4,4,2 };
    int expected[length] = { 0,0,2,3,4,4,4,9 };
    selectionSort(array, length);
    for (int i = 0; i < length; i++) {
        ASSERT_EQ(array[i], expected[i]);
    }
}

TEST(SelectionSortTest, Test_6_elements) {
    const int length = 6;
    int array[length] = { 3, 5, 2, 1, 5,6 };
    int expected[length] = { 1,2,3,5,5,6 };
    selectionSort(array, length);
    for (int i = 0; i < length; i++) {
        ASSERT_EQ(array[i], expected[i]);
    }
}

int main(int argc, char** argv)
{

    auto start = std::chrono::high_resolution_clock::now();
    const int length = 8;
    int array[length] = { 9,4,0,0,3,4,4,2 };
    cout << "Before: ";
    printArray(array, length);
    selectionSort(array, length);
    cout << "After: ";
    printArray(array, length);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "\n" << "Time: " << duration.count() << " sec." << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}