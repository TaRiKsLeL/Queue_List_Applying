// DataStructures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "windows.h"
#include <fstream>
#include <list>
#include <queue>
using namespace std;

class MyIO {
public:
    static ifstream file;

    static void openFile(const string path);
    static void closeFile();
    static int getValue();
    static int getReadOrWriteConsent();
};

ifstream MyIO::file;

void MyIO::openFile(const string path) {
    file.open(path);
}

void MyIO::closeFile(){ file.close(); }

int MyIO::getValue(){
    while (true) 
    {
        int a;
        cin >> a;

        if (std::cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(32767, '\n'); 
            cout << "Ууупс.Ввід не правильний. Повторіть ще раз\n";
        }
        else
        {
            cin.ignore(32767, '\n'); // удаляем лишние значения
            return a;
        }
    }
}

int MyIO::getReadOrWriteConsent() {
    cout << "Прочитати з файлу чи записати вручну? 0/1\n";
    int val = 0;
    do {
       val = getValue();
    } while (val > 1 || val < 0);
    return val;
}


class CollectionsManager {
public:
    static void initList(list<int>& list);
    static void initQueue(queue<int>& queue);
    static void initCollections(list<int>& list, queue<int>& queue);

    static double serArithm(list<int> list);
    static double serArithm(queue<int> queue);

    static int getMin(list<int>& list);
    static int getMin(queue<int> queue);

    static int getMax(list<int>& list);
    static int getMax(queue<int> queue);

    static int elementByIndex(const list<int>& list,const int& index);
    static int elementByIndex(queue<int> queue, const int& index);

    static int indexByElement(const list<int>& list, const int& element);
    static int indexByElement(queue<int> queue, const int& element);

};

void CollectionsManager::initList(list<int>& list) {
    cout << "========== Ініціалізація List'a ============\n";
    int size = 5;
    cout << "Розмір: "; size = MyIO::getValue();
    while (size--) {
        cout << "Введіть елемент: ";    list.push_back(MyIO::getValue());
    }

    cout << "=========================================\n";
}

void CollectionsManager::initQueue(queue<int>& queue) {
    cout << "========== Ініціалізація Queue ============\n";
    int size = 5;
    cout << "Розмір: "; size = MyIO::getValue();
    while (size--) {
        cout << "Введіть елемент: ";    queue.push(MyIO::getValue());
    }

    cout << "=========================================\n";
}

void CollectionsManager::initCollections(list<int>& list, queue<int>& queue) {
    cout << "\n========== Ініціалізація List та Queue ===========\n";
    int size = 5;
    cout << "Розмір: "; size = MyIO::getValue();
    while (size--) {
        cout << "Введіть елемент: ";    int val = MyIO::getValue();
        list.push_back(val);
        queue.push(val);
    }

    cout << "=============================================\n";
}

double CollectionsManager::serArithm(list<int> list) {

    int sum = 0;

    for (auto it = list.begin(); it != list.end(); ++it) {
        sum += *it;
    }
    return sum / list.size();
}

double CollectionsManager::serArithm(queue<int> queue) {

    int sum = 0, size = queue.size();
    while (!queue.empty())
    {
        sum+=queue.front();

        queue.pop();
    }
    return sum / size;
}

int CollectionsManager::getMin(list<int>& list){
    auto it = list.begin();
    int min = *it;
    for (; it != list.end(); ++it) {
        if (min > * it) {
            min = *it;
        }
    }
    return min;
}
int CollectionsManager::getMin(queue<int> queue) {

    int min = queue.front();
    while (!queue.empty()) {
        int val = queue.front();

        if (min > val)
        {
            min = val;
        }
        queue.pop();

    }
    return min;
}

int CollectionsManager::getMax(list<int>& list) {
    auto it = list.begin();
    int max = *it;
    for (; it != list.end(); ++it) {
        if (max < * it) {
            max = *it;
        }
    }
    return max;
}
int CollectionsManager::getMax(queue<int> queue) { 
    int max = queue.front();
    while (!queue.empty()) {
        int val = queue.front();

        if (max < val)
        {
            max = val;
        }
        queue.pop();

    }
    return max;
}

int CollectionsManager::elementByIndex(const list<int>& list, const int& index) {
    auto l_front = list.begin();
    advance(l_front, index);
    return *l_front;
}

int CollectionsManager::elementByIndex(queue<int> queue, const int& index) {
    
    int ind = index;
    while (ind--) {
        queue.pop();
    }
    return queue.front();
}


int CollectionsManager::indexByElement(const list<int>& list, const int& element) {
    auto it = find(list.begin(), list.end(), element);
    return distance(list.begin(), it);
}

int CollectionsManager::indexByElement(queue<int> queue, const int& element) {
    int index=-1;
    int i = 0;
    while (!queue.empty()) {
        int val = queue.front();

        if (element== val)
        {
            index = i;
        }
        queue.pop();
        i++;
    }
    return index;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list<int> list;
    queue<int> queue;


    if (MyIO::getReadOrWriteConsent()) { // Якщо повернулась 1, то записати вручну 
        CollectionsManager::initList(list);
        CollectionsManager::initQueue(queue);
        
    }
    else {                               // Якщо повернувся 0, то зчитати з файлу 
        cout << "Покищо функція в розробці\n";
        return 0;
    }

    cout << "\n\n=========== Розміри List/Queue ===============";
    cout << "\nРозмір List: " << list.size();
    cout << "\nРозмір Queue: " << queue.size();

    cout << "\n\n=========== Середнє арифметичне List/Queue ===============";
    cout << "\nList: " << CollectionsManager::serArithm(list);
    cout << "\nQueue: " << CollectionsManager::serArithm(queue);

    cout << "\n\n=========== List/Queue MIN MAX ===============";
    int minInList = CollectionsManager::getMin(list);
    cout << "\nList min: " << minInList;
    cout << "\tList max: " << CollectionsManager::getMax(list);

    int minInQueue = CollectionsManager::getMin(queue);
    cout << "\nQueue min: " << minInQueue;
    cout << "\tQueue max: " << CollectionsManager::getMax(queue);

    cout << "\n\n=========== Елементи List та Queue за індексом 4 (розрахунок з 0) ===============";
    cout << "\nList: " << CollectionsManager::elementByIndex(list,4);
    cout << "\nQueue: " << CollectionsManager::elementByIndex(queue, 4);

    cout << "\n\n=========== Елементи в колекціях List та Queue перед мінімальними ===============";

    int minInListIndex =  CollectionsManager::indexByElement(list, minInList);
    int minInQueueIndex = CollectionsManager::indexByElement(queue, minInQueue);

    cout << "\nЕлемент List перед MIN: " << CollectionsManager::elementByIndex(list, minInListIndex - 1);
    cout << "\nЕлемент Queue перед MIN: " << CollectionsManager::elementByIndex(queue, minInQueueIndex -1);
}

