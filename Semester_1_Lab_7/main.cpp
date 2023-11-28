#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

// Вводится файл о неуспевающих студентах со следующей структурой записей:
// Факультет
// Группа
// Фамилия студента
// Число хвостов
// Записи по каждому факультету, а также по каждой группе следуют друг за
// другом. После каждого экзамена число хвостов у студентов увеличивается.
// Факультеты на основании многолетней статистики заранее сообщают о максимально
// возможном количестве должников. Требуется обеспечить коррекцию информации с
// помощью индексирования файла. Для расширения файла необходимо зарезервировать
// области переполнения по каждому факультету. Организовать вставку путем сдвига
// записей вперед до ближайшей области переполнения. Предусмотреть реорганизацию
// файла неуспевающих в окончательной редакции.

using namespace std;

struct Student {
  int faculty;    // факультет
  int group;      // группа
  string surname; // фамилия студента
  int num_tail;   // число хвостов

  Student() : faculty(0), group(0), surname(""), num_tail(0) {}
  Student(int f, int g, string s, int nt)
      : faculty(f), group(g), surname(s), num_tail(nt) {}
};

struct Index {
  int index;
  list<Student>::iterator it;
  Index(int i, list<Student>::iterator iter) : index(i), it(iter) {}
};

int RandFillStudents(list<Student> &students) {
  int faculties;
  do {
    cout << "Введите количество факультетов: ";
    cin >> faculties;
  } while (faculties <= 0 or faculties > 5);

  string surname = "surname";

  int num_group = 1;
  for (int i = 1; i <= faculties; i++) {
    int amount_student_in_faculty = rand() % 8 + 5;
    for (int j = 0; j < amount_student_in_faculty; j++) {
      students.push_back(Student(i, num_group, surname, rand() % 8 + 5));
      if (j >= 4) {
        num_group = 2;
      }
    }
    num_group = 1;
  }
  return faculties;
}

void Print(list<Student> &students) {
  cout << "Faculty "
       << " Group "
       << " Surname "
       << " Tails " << endl;
  for (auto it : students) {
    cout << it.faculty << "        " << it.group << "      " << it.surname
         << "  " << it.num_tail << endl;
  }
}

void Exam(list<Student> &students, vector<Index> &indexes, int amount_faculty) {
  for (int i = 0; i < amount_faculty; i++) {
    int amount_new_students = rand() % 5 + 1;
    for (int j = 0; j < amount_new_students; j++) {
      int num_group = rand() % 2 + 1;
      if (num_group > 1) {
        int delta = 0;
        while (true) {
          if (indexes[i].it->group == 1) {
            indexes[i].it++;
            delta--;
          } else {
            students.insert(indexes[i].it, Student(indexes[i].it->faculty,
                                                   num_group, "new_stn", 1));
            advance(indexes[i].it, delta - 1);
            break;
          }
        }
      } else
        students.insert(indexes[i].it, Student(indexes[i].it->faculty,
                                               num_group, "new_stn", 1));
    }
  }
}

int main() {
  srand(time(NULL));
  list<Student> students;
  vector<Index> indexes;

  int amount_faculty = RandFillStudents(students);
  list<Student>::iterator iterator = students.begin();

  for (int i = 1; i <= amount_faculty; i++) {
    int counter = 0;
    for (list<Student>::iterator it = students.begin(); it != students.end();
         ++it) {
      if (i != it->faculty) {
        counter++;
      } else {
        cout << "it->faculty == " << it->faculty << endl;
        indexes.push_back(Index(i, it));
        break;
      }
    }
  }

  // for (int i = 0; i < amount_faculty; i++) {
  //   cout << "faculty == " << indexes[i].it->faculty
  //        << " group == " << indexes[i].it->faculty
  //        << " surname ==  " << indexes[i].it->surname
  //        << " tails == " << indexes[i].it->num_tail << endl;
  // }
  cout << "size == " << students.size() << endl;
  Print(students);
  Exam(students, indexes, amount_faculty);
  cout << "size == " << students.size() << endl;
  Print(students);
  return 0;
}
