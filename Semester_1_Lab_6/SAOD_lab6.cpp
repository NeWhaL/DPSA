#include <iostream>

using namespace std;

// Число сравнений
// В худшем случае, когда массив отсортирован в обратном порядке, количество
// сравнений будет равно n* (n - 1) / 2. В лучшем случае, когда массив уже
// отсортирован, количество сравнений будет равно 0. Число перестановок В худшем
// случае количество перестановок будет равно n - 1. В лучшем случае количество
// перестановок будет равно 0.

void bubble_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

// Число сравнений
// Количество сравнений в сортировке Бэтчера равно n log2 n.
// Число перестановок
// Количество перестановок в сортировке Бэтчера равно n log2 n.
// Сравнение эффективности
// Лучший случай
// В лучшем случае, когда массив уже отсортирован, оба алгоритма потребуют 0
// сравнений и перестановок. Наихудший случай В худшем случае, когда массив
// отсортирован в обратном порядке, алгоритм пузырька потребует n* (n - 1) / 2
// сравнений и n - 1 перестановок.Алгоритм сортировки Бэтчера потребует n log2 n
// сравнений и n log2 n перестановок.

void sortdir(int a[], int i, int j, int dir) {
  if (dir == (a[i] > a[j]))
    swap(a[i], a[j]);
}

/* Pекурсивно сортирует последовательность в порядке возрастания
   (dir == 1), или убывания (dir == 0).
   Сортируемая последовательность начинается с младшей позиции индекса,
   параметр cnt - это количество элементов для сортировки. */
void merge(int a[], int low, int cnt, int dir) {
  if (cnt > 1) {
    int k = cnt / 2;
    for (int i = low; i < low + k; i++)
      sortdir(a, i, i + k, dir);
    merge(a, low, k, dir);
    merge(a, low + k, k, dir);
  }
}
/* Создаём последовательность рекурсивно.
   Сортируем две половинки, затем вызываем merge */
void sort(int a[], int low, int cnt, int dir) {
  if (cnt > 1) {
    int k = cnt / 2;
    sort(a, low, k, 1);
    sort(a, low + k, k, 0);
    merge(a, low, cnt, dir);
  }
}

int main() {
  system("clear");
  bool isRunning = true;
  do {
    int a[] = {3,    7,   4, 8, 6,    2,     1,  5,  9,  1,    -10,
               -100, 321, 6, 3, -321, 3,     0,  9,  71, 94,   17,
               81,   99,  9, 1, -10,  -1032, 31, 83, 34, -3001};
    int N = sizeof(a) / sizeof(a[0]);

    cout << "original array:" << endl;
    for (int i = 0; i < N; i++) {
      cout << a[i] << " ";
    }
    cout << endl;

    int selection_menu;
    do {
      cout << "1 - bubble sort,\n2 - betcher sort,\n3 - exit\n";
      cin >> selection_menu;
    } while (selection_menu < 0 && selection_menu > 4);

    switch (selection_menu) {
    case 1:
      bubble_sort(a, N);
      cout << "sorted array:" << endl;
      for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
      }
      cout << endl;
      break;
    case 2:
      sort(a, 0, N, 1); // по возрастанию
      cout << "Sorted array:" << endl;
      for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
      cout << endl;
      break;
    case 3:
      isRunning = false;
      break;
    }
  } while (isRunning);

  return 0;
}
