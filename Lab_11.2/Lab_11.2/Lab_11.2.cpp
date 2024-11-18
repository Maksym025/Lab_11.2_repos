#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <Windows.h>
using namespace std;

void Print(const char* fName);
void Process(const char* fName, const char* resultFile);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Print("t.txt");
    Process("t.txt", "result.txt");
    Print("result.txt");
    return 0;
}

void Print(const char* fName) {
    cout << endl << "Файл \"" << fName << "\":\n";
    ifstream f(fName);
    if (!f.is_open()) {
        cerr << "Помилка відкриття файлу для читання: " << fName << endl;
        return;
    }

    string line;
    while (getline(f, line)) {
        cout << line << endl;
    }
    f.close();
    cout << endl;
}

void Process(const char* fName, const char* resultFile) {
    ifstream f(fName);
    if (!f.is_open()) {
        cerr << "Помилка відкриття файлу для читання: " << fName << endl;
        return;
    }

    string text, lastWord;
    while (f >> text) {
        lastWord = text; 
    }
    f.close();

    
    int countA = 0;
    for (char ch : lastWord) {
        if (ch == 'a' || ch == 'A') {
            countA++;
        }
    }

   
    ofstream result(resultFile);
    if (!result.is_open()) {
        cerr << "Помилка відкриття файлу для запису: " << resultFile << endl;
        return;
    }

    result << "Кількість літер 'а' в останньому слові: " << countA << endl;
    result.close();
}
