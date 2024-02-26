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
    // ���������� ����� ������� ������ (��� ����������, �� ��� ���� ������������ �� ���� ����, ���� �� �� ����� ������)
    for (int startIndex = 0; startIndex < length - 1; startIndex++)
    {
        // � ����� smallestIndex ���������� ������ ���������� ��������, ��� �� ������� � ������� ��������.
        // �������� � ����, �� ��������� ������� � ��� �������� - �� ������ ������� (������ 0)
        int smallestIndex = startIndex;
        // ���� ������ ������ ������� � ����� ������ ������
        for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
        {
            // ���� �� ������� �������, ���� ����� ������ ���������� ��������,
            if (array[currentIndex] < array[smallestIndex])
                // �� �����'������� ����
                smallestIndex = currentIndex;
        }
        // smallestIndex ����� ��������� �������.
        // ̳����� ������ ���� ��������� �������� ����� � ���, ��� �� �������
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