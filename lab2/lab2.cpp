#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <set>  // для multiset
#include <map>  // для multimap
#include <iterator>
using namespace std;

// Функция для задания 1
int safeInputInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();  // Сбрасываем флаг ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаем ввод
        cout << "Неверный ввод. Пожалуйста, введите целое число: ";
    }
    return value;
}

// Задание 1: Заполнение списка и вывод его элементов
void task1() {
    int n;
    list<int> L;

    // Ввод количества элементов списка
    cout << "Введите количество элементов списка L: ";
    n = safeInputInt();

    // Проверка на корректность ввода
    if (n <= 0) {
        cout << "Количество элементов списка должно быть больше 0!\n";
        return;
    }

    // Ввод элементов списка L
    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        int element = safeInputInt();
        L.push_back(element);
    }

    // Вывод элементов в исходном порядке
    cout << "Элементы списка в исходном порядке: ";
    for (const int& el : L) {
        cout << el << " ";
    }
    cout << endl;

    // Вывод элементов в обратном порядке
    cout << "Элементы списка в обратном порядке: ";
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Задание 2: Работа с вектором и деком
void task2() {
    int n;

    // Ввод четного числа элементов
    cout << "Введите четное количество элементов для вектора и дека: ";
    n = safeInputInt();

    if (n <= 0 || n % 2 != 0) {
        cout << "Количество элементов должно быть положительным и четным!\n";
        return;
    }

    vector<int> V(n);  // Вектор V
    deque<int> D(n);   // Дек D

    // Ввод элементов для вектора
    cout << "Введите " << n << " элементов для вектора:\n";
    for (int i = 0; i < n; ++i) {
        V[i] = safeInputInt();
    }

    // Ввод элементов для дека
    cout << "Введите " << n << " элементов для дека:\n";
    for (int i = 0; i < n; ++i) {
        D[i] = safeInputInt();
    }

    // Сохраняем копию исходного вектора V для использования при изменении дека
    vector<int> originalV(V);

    // Добавляем в конец вектора первую половину дека (в исходном порядке)
    V.insert(V.end(), D.begin(), D.begin() + n / 2);

    // Добавляем в начало дека вторую половину исходного вектора (в обратном порядке)
    D.insert(D.begin(), originalV.rbegin(), originalV.rbegin() + n / 2);

    // Вывод результатов
    cout << "Модифицированный вектор V: ";
    for (const int& el : V) {
        cout << el << " ";
    }
    cout << endl;

    cout << "Модифицированный дек D: ";
    for (const int& el : D) {
        cout << el << " ";
    }
    cout << endl;
}


// Функция для задания 3
void task3() {
    int n;

    // Ввод нечетного числа элементов
    cout << "Введите нечетное количество элементов вектора (>= 5): ";
    n = safeInputInt();

    if (n < 5 || n % 2 == 0) {
        cout << "Количество элементов должно быть нечетным и не меньше 5!\n";
        return;
    }

    vector<int> V(n);

    // Ввод элементов вектора
    cout << "Введите " << n << " элементов вектора:\n";
    for (int i = 0; i < n; ++i) {
        V[i] = safeInputInt();
    }

    // Удаление трех средних элементов
    V.erase(V.begin() + n / 2 - 1, V.begin() + n / 2 + 2);

    // Вывод вектора после удаления
    cout << "Вектор после удаления трех средних элементов: ";
    for (const int& el : V) {
        cout << el << " ";
    }
    cout << endl;
}

double safeInputDouble() {
    double value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный ввод. Пожалуйста, введите число: ";
    }
    return value;
}
// Функция для задания 4: Арифметическая прогрессия
void task4() {
    double A, D;
    int N;

    cout << "Введите первый элемент арифметической прогрессии (A): ";
    A = safeInputDouble();

    cout << "Введите разность арифметической прогрессии (D): ";
    D = safeInputDouble();

    cout << "Введите количество элементов прогрессии (N): ";
    N = safeInputInt();

    if (N <= 0) {
        cout << "Количество элементов должно быть положительным!\n";
        return;
    }

    vector<double> progression(N);

    // Используем алгоритм generate_n для создания арифметической прогрессии
    generate_n(progression.begin(), N, [A, D, i = 0]() mutable { return A + D * i++; });

    // Вывод прогрессии
    cout << "Первые " << N << " членов арифметической прогрессии: ";
    for (const double& el : progression) {
        cout << el << " ";
    }
    cout << endl;
}

// Функция для задания 5: Поиск "нулевого элемента" и вставка
void task5() {
    int n;

    // Ввод четного числа элементов
    cout << "Введите четное количество элементов вектора: ";
    n = safeInputInt();

    if (n <= 0 || n % 2 != 0) {
        cout << "Количество элементов должно быть положительным и четным!\n";
        return;
    }

    vector<int> V(n);

    // Ввод элементов вектора
    cout << "Введите " << n << " элементов вектора:\n";
    for (int i = 0; i < n; ++i) {
        V[i] = safeInputInt();
    }

    // Поиск элемента первой половины, совпадающего с элементом второй половины
    auto it = find_first_of(V.begin(), V.begin() + n / 2, V.begin() + n / 2, V.end());

    // Если элемент найден, вставляем его перед последним элементом первой половины
    if (it != V.begin() + n / 2) {
        V.insert(V.begin() + n / 2 - 1, *it);
    }
    else {
        cout << "Совпадающий элемент не найден!\n";
    }

    // Вывод результата
    cout << "Вектор после модификации: ";
    for (const int& el : V) {
        cout << el << " ";
    }
    cout << endl;
}

// Функция для задания 6: Циклический сдвиг с использованием rotate_copy
void task6() {
    int k, n;

    // Ввод количества элементов
    cout << "Введите количество элементов списка L (>= 10): ";
    n = safeInputInt();

    if (n < 10) {
        cout << "Количество элементов списка должно быть >= 10!\n";
        return;
    }

    // Ввод значения K
    cout << "Введите значение K (0 < K < 5): ";
    k = safeInputInt();

    if (k <= 0 || k >= 5) {
        cout << "Значение K должно быть от 1 до 4!\n";
        return;
    }

    list<int> L;
    cout << "Введите " << n << " элементов списка:\n";
    for (int i = 0; i < n; ++i) {
        L.push_back(safeInputInt());
    }

    // Копируем первые 5 элементов и выполняем циклический сдвиг вправо
    list<int> firstPart(L.begin(), next(L.begin(), 5));
    rotate_copy(firstPart.begin(), next(firstPart.begin(), 5 - k), firstPart.end(), back_inserter(L));

    // Копируем последние 5 элементов и выполняем циклический сдвиг влево
    list<int> lastPart(prev(L.end(), 5), L.end());
    rotate_copy(lastPart.begin(), next(lastPart.begin(), k), lastPart.end(), inserter(L, L.begin()));

    // Вывод результата
    cout << "Модифицированный список: ";
    for (const int& el : L) {
        cout << el << " ";
    }
    cout << endl;
}

// Функция для задания 7: Вставка отсортированной половины вектора
void task7() {
    int n;

    // Ввод четного числа элементов
    cout << "Введите четное количество элементов вектора: ";
    n = safeInputInt();

    if (n <= 0 || n % 2 != 0) {
        cout << "Количество элементов должно быть положительным и четным!\n";
        return;
    }

    vector<int> V(n);
    vector<int> sortedHalf(n / 2);

    // Ввод элементов вектора
    cout << "Введите " << n << " элементов вектора:\n";
    for (int i = 0; i < n; ++i) {
        V[i] = safeInputInt();
    }

    // Копируем первую половину отсортированного вектора в новый вектор
    partial_sort_copy(V.begin(), V.end(), sortedHalf.begin(), sortedHalf.end());

    // Вставляем элементы в конец исходного вектора
    V.insert(V.end(), sortedHalf.begin(), sortedHalf.end());

    // Вывод результата
    cout << "Модифицированный вектор: ";
    for (const int& el : V) {
        cout << el << " ";
    }
    cout << endl;
}

void task8() {
    int n;
    cout << "Введите количество слов в списке: ";
    n = safeInputInt();

    if (n <= 1) {
        cout << "Количество слов должно быть больше 1!\n";
        return;
    }

    list<string> L;
    deque<string> D;

    cout << "Введите " << n << " слов:\n";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        L.push_back(word);
    }

    // Создание строк, объединяющих первую букву левого слова и последнюю букву правого слова
    auto it1 = L.begin();
    auto it2 = next(L.begin());

    while (it2 != L.end()) {
        string combined = string(1, (*it1)[0]) + string(1, (*it2).back());
        D.push_back(combined);
        ++it1;
        ++it2;
    }

    // Вывод результата
    cout << "Сформированный дек: ";
    for (const string& el : D) {
        cout << el << " ";
    }
    cout << endl;
}

void task9() {
    int N, size0;
    cout << "Введите количество векторов (N): ";
    N = safeInputInt();

    cout << "Введите размер вектора V0: ";
    size0 = safeInputInt();

    if (N <= 0 || size0 <= 0) {
        cout << "Количество векторов и размер вектора V0 должны быть больше 0!\n";
        return;
    }

    vector<int> V0(size0);
    cout << "Введите элементы вектора V0:\n";
    for (int i = 0; i < size0; ++i) {
        V0[i] = safeInputInt();
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int sizeI;
        cout << "Введите размер вектора V" << i << ": ";
        sizeI = safeInputInt();

        if (sizeI < size0) {
            cout << "Размер вектора V" << i << " должен быть не меньше размера V0!\n";
            continue;
        }

        vector<int> Vi(sizeI);
        cout << "Введите элементы вектора V" << i << ":\n";
        for (int j = 0; j < sizeI; ++j) {
            Vi[j] = safeInputInt();
        }

        multiset<int> setV0(V0.begin(), V0.end()), setVi(Vi.begin(), Vi.end());
        if (includes(setVi.begin(), setVi.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }

    cout << "Количество векторов, содержащих все элементы V0: " << count << endl;
}
// Задание 10: Группировка элементов вектора по последней цифре и multimap
void task10() {
    int n;
    cout << "Введите количество элементов вектора V: ";
    n = safeInputInt();

    if (n <= 0) {
        cout << "Количество элементов должно быть положительным!\n";
        return;
    }

    vector<int> V(n);
    cout << "Введите " << n << " элементов вектора V:\n";
    for (int i = 0; i < n; ++i) {
        V[i] = safeInputInt();
    }

    multimap<int, int> M;

    // Вставляем элементы в multimap, группируя по последней цифре
    for (int x : V) {
        int last_digit = x % 10;  // Последняя цифра числа
        M.insert(pair<int, int>(last_digit, x));  // Вставляем элемент в multimap
    }

    // Вывод содержимого multimap с использованием стандартного синтаксиса
    cout << "Группировка элементов по последней цифре:\n";
    for (multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << "Ключ (последняя цифра): " << it->first << " -> Значение: " << it->second << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    while (true) {
        cout << "\nВыберите задание:\n";
        cout << "1. Задание 1: Работа с списком\n";
        cout << "2. Задание 2: Работа с вектором и деком\n";
        cout << "3. Задание 3: Удаление средних элементов вектора\n";
        cout << "4. Задание 4: Арифметическая прогрессия\n";
        cout << "5. Задание 5: Поиск совпадающего элемента и вставка нулевого элемента\n";
        cout << "6. Задание 6: Циклический сдвиг с использованием rotate_copy\n";
        cout << "7. Задание 7: Добавление первой половины отсортированного вектора\n";
        cout << "8. Задание 8: Создание дека с помощью adjacent_difference\n";
        cout << "9. Задание 9: Поиск векторов, содержащих элементы V0 с помощью includes\n";
        cout << "10. Задание 10: Группировка элементов вектора по последней цифре и multimap\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 0:
            cout << "Выход из программы...\n";
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
