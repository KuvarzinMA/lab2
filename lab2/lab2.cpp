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
void task1() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    list<int> L;
    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L.push_back(x);
    }

    // Вывод в исходном порядке
    cout << "Элементы списка L в исходном порядке: ";
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;

    // Вывод в обратном порядке
    cout << "Элементы списка L в обратном порядке: ";
    L.reverse();
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;
}

// Функция для задания 2
void task2() {
    int n;
    cout << "Введите количество элементов (четное число): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Ошибка: количество элементов должно быть четным!" << endl;
        return;
    }

    vector<int> V(n);
    deque<int> D(n);

    cout << "Введите " << n << " элементов вектора V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    cout << "Введите " << n << " элементов дека D:\n";
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }

    // Добавление первой половины элементов дека в конец вектора
    V.insert(V.end(), D.begin(), D.begin() + n / 2);

    // Добавление второй половины элементов вектора в начало дека в обратном порядке
    D.insert(D.begin(), V.rbegin() + n / 2, V.rend());

    // Вывод обновленного вектора
    cout << "Обновленный вектор V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;

    // Вывод обновленного дека
    cout << "Обновленный дек D: ";
    for (int x : D) {
        cout << x << " ";
    }
    cout << endl;
}

// Функция для задания 3
void task3() {
    int N;
    cout << "Введите количество элементов вектора (нечетное, >= 5): ";
    cin >> N;

    if (N < 5 || N % 2 == 0) {
        cout << "Ошибка: количество элементов должно быть нечетным и >= 5!" << endl;
        return;
    }

    vector<int> V(N);
    cout << "Введите " << N << " элементов вектора V:\n";
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    // Удаление трех средних элементов
    int mid = N / 2;
    V.erase(V.begin() + mid - 1, V.begin() + mid + 2);

    // Вывод обновленного вектора
    cout << "Обновленный вектор V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;
}

// Функция для задания 4: Арифметическая прогрессия
void task4() {
    double A, D;
    int N;
    cout << "Введите первый элемент (A), разность (D) и количество элементов (N): ";
    cin >> A >> D >> N;

    vector<double> progression(N);

    // Используем generate_n для генерации элементов арифметической прогрессии
    generate_n(progression.begin(), N, [=, n = 0]() mutable {
        return A + n++ * D;
        });

    cout << "Первые " << N << " членов арифметической прогрессии: ";
    for (double x : progression) {
        cout << x << " ";
    }
    cout << endl;
}

// Функция для задания 5: Поиск "нулевого элемента" и вставка
void task5() {
    int n;
    cout << "Введите количество элементов (четное число): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Ошибка: количество элементов должно быть четным!" << endl;
        return;
    }

    vector<int> V(n);
    cout << "Введите " << n << " элементов вектора V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    // Поиск элемента в первой половине, который совпадает с элементом из второй половины
    auto first_half_begin = V.begin();
    auto first_half_end = first_half_begin + n / 2;
    auto second_half_begin = first_half_end;
    auto second_half_end = V.end();

    auto it = find_first_of(first_half_begin, first_half_end, second_half_begin, second_half_end);

    if (it != first_half_end) {
        V.insert(it, *it); // Вставляем найденный элемент перед ним же
    }

    // Вывод обновленного вектора
    cout << "Обновленный вектор V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;
}

// Функция для задания 6: Циклический сдвиг с использованием rotate_copy
void task6() {
    int K, n;
    cout << "Введите число K (0 < K < 5): ";
    cin >> K;

    if (K <= 0 || K >= 5) {
        cout << "Ошибка: K должно быть от 1 до 4!" << endl;
        return;
    }

    cout << "Введите количество элементов списка (не менее 10): ";
    cin >> n;

    if (n < 10) {
        cout << "Ошибка: должно быть минимум 10 элементов!" << endl;
        return;
    }

    list<int> L;
    cout << "Введите " << n << " элементов списка L:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L.push_back(x);
    }

    // Создание итераторов для 5 первых и 5 последних элементов
    auto first_five_begin = L.begin();
    auto first_five_end = next(first_five_begin, 5);
    auto last_five_begin = prev(L.end(), 5);
    auto last_five_end = L.end();

    // Место для сдвига на K позиций вправо (для первых 5 элементов)
    list<int> shifted_right(5);
    rotate_copy(first_five_begin, prev(first_five_end, K), first_five_end, shifted_right.begin());

    // Место для сдвига на K позиций влево (для последних 5 элементов)
    list<int> shifted_left(5);
    rotate_copy(last_five_begin, next(last_five_begin, K), last_five_end, shifted_left.begin());

    // Вставка полученных элементов в список
    L.insert(L.end(), shifted_right.begin(), shifted_right.end()); // В конец
    L.insert(L.begin(), shifted_left.begin(), shifted_left.end()); // В начало

    // Вывод обновленного списка
    cout << "Обновленный список L: ";
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;
}

// Функция для задания 7: Вставка отсортированной половины вектора
void task7() {
    int n;
    cout << "Введите количество элементов вектора (четное число): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Ошибка: количество элементов должно быть четным!" << endl;
        return;
    }

    vector<int> V(n);
    cout << "Введите " << n << " элементов вектора V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    // Вектор для частичной сортировки
    vector<int> sorted_half(n / 2);
    partial_sort_copy(V.begin(), V.end(), sorted_half.begin(), sorted_half.end());

    // Вставка первой половины отсортированного вектора в конец
    V.insert(V.end(), sorted_half.begin(), sorted_half.end());

    // Вывод обновленного вектора
    cout << "Обновленный вектор V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;
}
void task8() {
    list<string> L;
    int n;
    cout << "Введите количество слов в списке L: ";
    cin >> n;

    // Проверка корректности ввода
    if (n < 2) {
        cout << "Количество слов должно быть >= 2 для корректной работы!\n";
        return;
    }

    cout << "Введите " << n << " слов:\n";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        L.push_back(word);
    }

    deque<string> D;

    // adjacent_difference требует начальный элемент, поэтому пропускаем первый результат
    adjacent_difference(next(L.begin()), L.end(), inserter(D, D.begin()), [](const string& a, const string& b) {
        return string(1, b.back()) + string(1, a.front());
        });

    // Вывод дека
    cout << "Элементы дека D: ";
    for (const string& str : D) {
        cout << str << " ";
    }
    cout << endl;
}

void task9() {
    int N, size0;
    cout << "Введите количество векторов (N): ";
    cin >> N;

    cout << "Введите размер вектора V0: ";
    cin >> size0;

    if (N <= 0 || size0 <= 0) {
        cout << "Количество векторов и размер вектора V0 должны быть больше 0!\n";
        return;
    }

    vector<int> V0(size0);
    cout << "Введите элементы вектора V0:\n";
    for (int i = 0; i < size0; ++i) {
        cin >> V0[i];
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int sizeI;
        cout << "Введите размер вектора V" << i << ": ";
        cin >> sizeI;

        if (sizeI < size0) {
            cout << "Размер вектора V" << i << " должен быть не меньше размера V0!\n";
            continue;
        }

        vector<int> Vi(sizeI);
        cout << "Введите элементы вектора V" << i << ":\n";
        for (int j = 0; j < sizeI; ++j) {
            cin >> Vi[j];
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
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов должно быть положительным!\n";
        return;
    }

    vector<int> V(n);
    cout << "Введите " << n << " элементов вектора V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
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
