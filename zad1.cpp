#include <iostream>
#include <vector>

using namespace std;
vector<int> myArr;
int numbersInArray, sizeOfArray, tempNum;

bool isEmpty();
void createArray();
void inputIntegers();
void vectorSize();
void printElements();
float averageNumber(vector<int>);
string sumOfNonZero(vector<int>);
void findMax();

int main()
{
    int initChoice, choice;

    createArray();
    inputIntegers();

    do
    {

        cout << "\n0. Quit" << endl;
        cout << "1. Ре-инициализирай масива " << endl;
        cout << "2. Размер на масива " << endl;
        cout << "3. Елементи в масива " << endl;
        cout << "4. Средно аритметично на всички числа " << endl;
        cout << "5. Всички без 0 и сбор" << endl;
        cout << "6. Mаксимално положително число" << endl;
        cout << "Вашият избор: ";

        cin >> choice;
        cout << endl;
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
            cout << "Елементи в масива: " << endl;
            printElements();
            break;
        case 4:
            cout << "Средно аритметично на всички числа: " << averageNumber(myArr) << endl;
            break;
        case 5:
            cout << sumOfNonZero(myArr);
            break;
        case 6:
            findMax();
            break;
        default:
            cout << "Невалиден избор!";
            break;
        }
        if (choice >= 0 && choice <= 6)
        {
#ifdef _WIN32
            system("pause")
#else __linux__
            system("read");
#endif
        }
    } while (choice != 0);
}

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

    if (numbersInArray > 25 || numbersInArray <= 0)
    {
        cout << "Невалидно число за брой на елементи в масива! \n";
        cin.clear();            // Clear the error state
        cin.ignore(1024, '\n'); // Discard all characters in the stream
        createArray();
    }
    myArr.resize(numbersInArray);
}
void inputIntegers()
{
    cout << "Въведете " << numbersInArray << " числа в масива: \n";
    for (int i = 0; i < myArr.size(); i++)
    {
        cin >> tempNum;
        while (!cin)
        {
            cin.clear();            // Clear the error state
            cin.ignore(1024, '\n'); // Discard all characters in the stream
            cout << "Въведения елемент не е число, въведете отново: " << endl;
            cin >> tempNum;
        }
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
float averageNumber(vector<int> myArr)
{
    if (!isEmpty())
    {
        int sum = 0;
        for (int i = 0; i < myArr.size(); i++)
        {
            sum += myArr[i];
        }
        return (float)sum / (float)myArr.size();
    }
}
string sumOfNonZero(vector<int> myArr)
{
    if (!isEmpty())
    {
        int sum = 0;
        int zeroCounter = 0;
        for (int i = 0; i < myArr.size(); i++)
        {
            sum += myArr[i];
            zeroCounter += (myArr[i] == 0) ? 1 : 0;
        }
        return "Сумата на всички числа (дори без/с 0) е: " + to_string(sum) +
               ". 0-те в масива са " + to_string(zeroCounter) + " на брой. \n";
    }
}
void findMax()
{
    int max = myArr[0];
    int index;
    for (int i = 0; i < myArr.size(); i++)
    {
        if (myArr[i] > max)
        {
            max = myArr[i];
            index = i;
        }
    }
    cout << "Най-голямо число в масива: " << max << endl;
    cout << "Неговият индекс: " << index << endl;
}
