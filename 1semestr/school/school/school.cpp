#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <limits>
using namespace std;

struct question
{
    string quest;
    vector <string> opt;
    int answ;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ifstream input;
    input.open("bio.txt", ios::in);
    if (!input)
    {
        cout << "Fail: file \"bio.txt\" wasn't opened";
        return 1;
    }
    vector <question> vopr;
    string line;
    while (getline(input, line))
    {
        if (!line.empty() && line.back() == '\r') 
        {
            line.pop_back();
        }
        if (line.empty())
            continue;
        question q1;
        q1.quest = line;
        for (int i = 0; i < 5; i++)
        {
            getline(input, line);
            q1.opt.push_back(line);
        }
        input >> q1.answ;
        input.ignore();
        vopr.push_back(q1);
    }
    input.close();

    random_device random;
    mt19937 g(random());
    shuffle(vopr.begin(), vopr.end(), g);

    int N = 0;
    int maxN = int(vopr.size());
    if (maxN > 10) maxN = 10;
    while (true)
    {
        cout << "Сколько вопросов вам нужно?(до " << maxN << ")" << endl;
        if (cin >> N && N > 0 && N <= maxN)
            break;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Вы неправильно ввели данные" << endl;
    }
    cout << endl << endl << "ТЕСТ НАЧАЛСЯ" << endl;

    int pravotv = 0;
    for (int i = 0; i < N; i++)
    {
        const question& q = vopr[i];
        cout << q.quest << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << q.opt[j] << endl;
        }

        int answ = 0;
        cout << "Введите ответ: ";
        while (!(cin >> answ) || answ < 1 || answ > 5)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Введите число от 1 до 5: ";
        }

        if (answ == q.answ)
        {
            cout << "Верно! ";
            pravotv++;
        }
        else cout << "Неверно. ";
        cout << "Правильный ответ: " << q.answ << endl;
    }

    int bal = (pravotv * 10) / N;
    cout << endl << "Ваш балл: " << bal << "/10" << endl;
}
