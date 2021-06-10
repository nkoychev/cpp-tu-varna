#include <iostream>
#include <vector>

using namespace std;
vector<int> myArr;
int numbersInArray, sizeOfArray, tempNum;

bool isEmpty()
{
    if (myArr.empty())
    {
        cout << "Масивът е празен! \n"
             << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void createArray()
{
    cout << "Въведете брой на числата в масива: (1~25)\n";
    cin >> numbersInArray;
    myArr.resize(numbersInArray);
}
void inputIntegers()
{
    cout << "Въведете " << numbersInArray << " числа в масива: ";
    for (int i = 0; i < myArr.size(); i++)
    {
        cin >> tempNum;
        myArr[i] = tempNum;
    }
    // Cleanup 0 in the end of the vector
}
void vectorSize()
{
    if (!isEmpty())
    {
        cout << "Размер на масива: " << myArr.size() << endl;
    }
}
void printElements()
{
    if (!isEmpty())
    {
        cout << "Елементите във вектора/масива са: ";
        for (int i = 0; i < myArr.size(); i++)
        {
            cout << myArr[i] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "0. Quit" << endl;
        cout << "1. Play game!" << endl;
        cout << "2. Размер на масива: " << endl;
        cout << "3. Стойности в масива: " << endl;

        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Return 0!\n";
            return 0;
        case 1:
            createArray();
            inputIntegers();
            break;
        case 2:
            vectorSize();
            break;
        case 3:
            cout << "Стойности в масива: " << endl;
            printElements();
            break;
        }

    } while (choice != 0);
}
