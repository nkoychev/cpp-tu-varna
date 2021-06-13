#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class User
{
public:
    string name;
    string surname;
    string neighbourhood;
    string street;
    string strNum;
    string phoneNumber;
    double payment;
    User(string a, string b, string c, string d, string e, string f, double g)
    {
        name = a;
        surname = b;
        neighbourhood = c;
        street = d;
        strNum = e;
        phoneNumber = f;
        payment = g;
    }
};
vector<User> usersArr;
void createUser();
void writeFile(User user);
void printElements();
bool isEmpty();
void vectorSize();
void syncArrayFile();
void findFamily();
void queryUser();
void findStreet();
void sortArr(vector<User>);
bool sortByPayment(const User &lhs, const User &rhs) { return lhs.payment < rhs.payment; }
void tokenize(string const &str, char delim, vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
ofstream usersFile;

int main()
{
    // User user0("Иван", "Петров", "Левски", "Китка", "23б", "0889458632", 32.99);
    // User user1("Петър", "Митков", "Трошево", "Здраве", "54", "0886950325", 56.54);
    // usersArr.push_back(user0);
    // usersArr.push_back(user1);
    int choice;
    // syncArrayFile();
    do
    {

        cout << "\n0. Quit" << endl;
        cout << "1. Създайте потребител " << endl;
        cout << "2. Размер на масива " << endl;
        cout << "3. Елементи в масива " << endl;
        cout << "4. Справка за абонат " << endl;
        cout << "5. Търсене по улица " << endl;
        cout << "6. Сортиране по сума за плащане " << endl;
        cout << "Вашият избор: ";

        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            cout << "Return 0!\n";
            return 0;
        case 1:
            createUser();
            // inputIntegers();
            break;
        case 2:
            vectorSize();
            break;
        case 3:
            cout << "Елементи в масива: " << endl;
            printElements();
            break;
        case 4:
            queryUser();
            break;
        case 5:
            findStreet();
            break;
        case 6:
            sortArr(usersArr);
            break;
        default:
            cout << "Невалиден избор!";
            break;
        }
        if (choice >= 0 && choice <= 6)
        {
#ifdef __linux__
            system("read");
#else
            system("pause");
#endif
        }
    } while (choice != 0);

    return 0;
}

void printElements()
{
    // if (!isEmpty())
    // {
    cout << "Елементите във вектора/масива са: \n";
    // open file for reading

    // print array
    for (int i = 0; i < usersArr.size(); i++)
    {
        cout << usersArr[i].name << " " << usersArr[i].surname << " ,ж.к. " << usersArr[i].neighbourhood
             << " , ул. " << usersArr[i].street << ", №" << usersArr[i].strNum
             << ", тел. " << usersArr[i].phoneNumber << ", за плащане: " << usersArr[i].payment << endl;
    }
    cout << endl;
    //push object to array

    // }
}

bool isEmpty()
{
    if (usersArr.empty())
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
void vectorSize()
{
    if (!isEmpty())
    {
        cout << "Размер на масива: " << usersArr.size() << endl;
    }
}

void createUser()
{
    if (usersArr.size() >= 30)
    {
        cout << "Масивът е пълен (до 30 потребителя)" << endl;
        return;
    }
    string name;
    string surname;
    string neighbourhood;
    string street;
    string strNum;
    string phoneNumber;
    double payment;

    cout << "Име: " << endl;
    cin >> name;
    cout << "Фамилия: " << endl;
    cin >> surname;
    cout << "Квартал: " << endl;
    cin >> neighbourhood;
    cout << "Улица: " << endl;
    cin >> street;
    cout << "Номер: " << endl;
    cin >> strNum;
    cout << "Тел. Номер: " << endl;
    cin >> phoneNumber;
    cout << "За Плащане: " << endl;
    cin >> payment;

    User newUser(name, surname, neighbourhood, street, strNum, phoneNumber, payment);
    usersArr.push_back(newUser);
    writeFile(newUser);
}

void writeFile(User user)
{
    usersFile.open("users.txt", ios_base::app); // append to file
    if (usersFile.is_open())
    {
        usersFile << user.name << "," << user.surname << "," << user.neighbourhood << ","
                  << user.street << "," << user.strNum << "," << user.phoneNumber << "," << user.payment << endl;
    }
    usersFile.close();
}

void syncArrayFile()
{
    ifstream usersFile("users.txt");
    if (usersFile.is_open())
    {
        string line;

        //     // ignore first line
        getline(usersFile, line);
        char delim = ',';

        while (!usersFile.eof())
        {
            getline(usersFile, line);
            string elem = line;
            vector<string> tempArr;
            tokenize(elem, delim, tempArr);

            // for (auto &elem : tempArr)
            // {
            //     cout << elem << endl;
            // }
            // // tempArr[6] = stod(tempArr[6]);
            // double converted = stod(tempArr[6]);
            // cout << converted << endl;
            User tempUser(tempArr[0], tempArr[1], tempArr[2], tempArr[3], tempArr[4], tempArr[5], stod(tempArr[6]));
            usersArr.push_back(tempUser);
        }
    }
}

void findFamily()
{
    string surname;
    cout << "Въведете фамилия: " << endl;
    cin >> surname;
    cout << "Потребители с фамилия " << surname << ": " << endl;
    bool exist = false;
    for (int i = 0; i < usersArr.size(); i++)
    {
        if (surname == usersArr[i].surname)
        {
            cout << usersArr[i].name << " " << usersArr[i].surname << " ,ж.к. " << usersArr[i].neighbourhood
                 << " , ул. " << usersArr[i].street << ", №" << usersArr[i].strNum
                 << ", тел. " << usersArr[i].phoneNumber << ", за плащане: " << usersArr[i].payment << endl;
            exist = true;
        }
    }
    string result = (exist) ? "endl;" : "Няма потребител/и с тази фамилия \n";
    cout << result;
}

void findPhone()
{
    string phoneNumber;
    cout << "Въведете тел. номер: " << endl;
    cin >> phoneNumber;
    bool exist = false;

    for (int i = 0; i < usersArr.size(); i++)
    {
        if (phoneNumber == usersArr[i].phoneNumber)
        {
            cout << "Потребител с номер " << phoneNumber << endl;
            cout << usersArr[i].name << " " << usersArr[i].surname << " ,ж.к. " << usersArr[i].neighbourhood
                 << " , ул. " << usersArr[i].street << ", №" << usersArr[i].strNum
                 << ", тел. " << usersArr[i].phoneNumber << ", за плащане: " << usersArr[i].payment << endl;
            exist = true;
        }
    }
    string result = (exist) ? "endl;" : "Няма потребител с този тел. номер \n";
    cout << result;
}

void findStreet()
{
    string street;
    cout << "Въведете улица: " << endl;
    cin >> street;
    bool exist = false;

    cout << "Потребители живеещи на улица: " << street << endl;
    for (int i = 0; i < usersArr.size(); i++)
    {
        if (street == usersArr[i].street)
        {
            cout << usersArr[i].name << " " << usersArr[i].surname << " ,ж.к. " << usersArr[i].neighbourhood
                 << " , ул. " << usersArr[i].street << ", №" << usersArr[i].strNum
                 << ", тел. " << usersArr[i].phoneNumber << ", за плащане: " << usersArr[i].payment << endl;
            exist = true;
        }
    }
    string result = (exist) ? "endl;" : "Няма потребители живеещи на тази улица \n";
    cout << result;
}

void sortArr(vector<User> usersArr)
{
    vector<User> sortedArray;
    for (int i = 0; i < usersArr.size(); i++)
    {
        sortedArray.push_back(usersArr[i]);
    }
    sort(sortedArray.begin(), sortedArray.end(), sortByPayment);
    for (User &user : sortedArray)
    {
        cout << user.name << " " << user.surname << " ,ж.к. " << user.neighbourhood
             << " , ул. " << user.street << ", №" << user.strNum
             << ", тел. " << user.phoneNumber << ", за плащане: " << user.payment << endl;
    }
    cout << endl;
}

void queryUser()
{

    int choice;
    do
    {
        cout << "0. Назад" << endl;
        cout << "1. Търси по фамилия" << endl;
        cout << "2. Търси по тел. номер" << endl;

        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            cout << "Обратно към главно меню\n";
            return;
        case 1:
            findFamily();
            break;
        case 2:
            findPhone();
        }
        if (choice >= 0 && choice <= 2)
        {
#ifdef __linux__
            system("read");
#else
            system("pause");
#endif
        }
    } while (choice != 0);
}