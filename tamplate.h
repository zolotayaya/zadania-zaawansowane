//
// Created by Злата Кенда on 27.10.24.
//

#ifndef TAMPLATE_H
#define TAMPLATE_H
#include<iostream>

using namespace std;
template<typename T>
class LinkedList {
    struct Node {
        T* data;
        Node*next;
        Node*prev;
        Node(T* value) : data(value), next(nullptr), prev(nullptr) {}// конструктор
    };

    ;

    public:

        Node* head;
        Node* tail;

        LinkedList():head(nullptr),tail(nullptr){}

        void addAtEnd(T* figure) {
            Node* newNode = new Node(figure);
            if (!tail) {  // Если список пуст
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
    void addAtBeginning(T* figure) {
            Node* newNode = new Node(figure); // создаем новый узел
            if (!head) { // Если список пуст
                head = tail = newNode; // Новый узел становится и головой, и хвостом
            } else {
                newNode->next = head; // Новый узел указывает на текущую голову
                head->prev = newNode; // Текущая голова указывает на новый узел
                head = newNode; // Обновляем голову на новый узел
            }
        }
        void removeFigureAt(int index) {
            if (index < 0) return;  // Некорректный индекс

            Node* current = head;
            for (int i = 0; current != nullptr && i < index; ++i) {
                current = current->next;
            }

            if (current) {  // Если узел существует
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;  // Если удаляем первый узел
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;  // Если удаляем последний узел
                }

                //delete current;  // Освобождаем память
            }
        }
    void removeFigureByNameBegining( const string& name) {
            Node* current = head; // Начинаем с головы списка

            while (current) {
                // Предположим, что T имеет метод getName(), который возвращает имя
                if (current->data->getname() == name) {
                    // Если узел - это голова
                    if (current == head) {
                        head = current->next; // Обновляем голову
                        if (head) {
                            head->prev = nullptr; // Если список не пуст, обновляем prev для новой головы
                        } else {
                            tail = nullptr; // Если список стал пустым, также обновляем хвост
                        }
                    } else {
                        current->prev->next = current->next; // Обновляем указатель prev
                    }

                    // Если узел - это хвост
                    if (current == tail) {
                        tail = current->prev; // Обновляем хвост
                        if (tail) {
                            tail->next = nullptr; // Если список не пуст, обновляем next для нового хвоста
                        } else {
                            head = nullptr; // Если список стал пустым, также обновляем голову
                        }
                    } else {
                        if (current->next) {
                            current->next->prev = current->prev; // Обновляем указатель next для следующего узла
                        }
                    }

                    //delete current->data; // Освобождаем память для фигуры
                    //delete current; // Освобождаем память для узла
                    return; // Выходим из функции после удаления
                }
                current = current->next; // Переходим к следующему узлу
            }
        }

    void removeFigureByNameEnd(const string& name) {
            Node* current = tail; // Начинаем с хвоста списка

            while (current) {
                // Предположим, что T имеет метод getName(), который возвращает имя
                if (current->data->getname() == name) {
                    // Если узел - это хвост
                    if (current == tail) {
                        tail = current->prev; // Обновляем хвост
                        if (tail) {
                            tail->next = nullptr; // Если список не пуст, обновляем next для нового хвоста
                        } else {
                            head = nullptr; // Если список стал пустым, также обновляем голову
                        }
                    } else {
                        current->next->prev = current->prev; // Обновляем указатель prev для следующего узла
                    }

                    // Если узел - это голова
                    if (current == head) {
                        head = current->next; // Обновляем голову
                        if (head) {
                            head->prev = nullptr; // Если список не пуст, обновляем prev для новой головы
                        } else {
                            tail = nullptr; // Если список стал пустым, также обновляем хвост
                        }
                    } else {
                        current->prev->next = current->next; // Обновляем указатель next для предыдущего узла
                    }

                    //delete current->data; // Освобождаем память для фигуры
                   // delete current; // Освобождаем память для узла
                    return; // Выходим из функции после удаления
                }
                current = current->prev; // Переходим к предыдущему узлу
            }
        }

    void removeAllFiguresByName(const string& name) {
            Node* current = tail; // Начинаем с хвоста списка

            while (current) {
                // Предположим, что T имеет метод getName(), который возвращает имя
                if (current->data->getname() == name) {
                    // Если узел - это хвост
                    if (current == tail) {
                        tail = current->prev; // Обновляем хвост
                        if (tail) {
                            tail->next = nullptr; // Если список не пуст, обновляем next для нового хвosta
                        } else {
                            head = nullptr; // Если список стал пустym, также обновляем голову
                        }
                    } else {
                        current->next->prev = current->prev; // Обновляем указатель prev для следующего узла
                    }

                    // Если узел - это голова
                    if (current == head) {
                        head = current->next; // Обновляем голову
                        if (head) {
                            head->prev = nullptr; // Если список не пуст, обновляем prev для новой головы
                        } else {
                            tail = nullptr; // Если список стал пустym, также обновляем хвост
                        }
                    } else {
                        current->prev->next = current->next; // Обновляем указатель next для предыдущего узла
                    }

                    //delete current->data; // Освобождаем память для фигуры
                    Node* temp = current; // Сохраняем указатель на текущий узел
                    current = current->prev; // Переходим к предыдущему узлу перед удалением
                    delete temp; // Освобождаем память для узла
                } else {
                    current = current->prev; // Переходим к предыдущему узлу
                }
            }
        }

        T* getFigureAt(int index) const {
            if (index < 0) return nullptr;  // Некорректный индекс

            Node* current = head;
            for (int i = 0; current != nullptr && i < index; ++i) {
                current = current->next;
            }

            current->data->print();

            return current ? current->data : nullptr;  // Возвращаем указатель на фигуру или nullptr
        }
    void findByName(const string& name) const {
            Node* current = head; // Начинаем с головы списка
            while (current) {
                if (current->data->getname() == name) {
                   current->data->print();
                }
                current = current->next; // Переходим к следующему узлу
            }
           // return nullptr; // Если объект не найден, возвращаем nullptr
        }

        // Печать всех фигур (например, периметры)
        void print() const {
            Node* current = head;
            while (current) {
                current->data->print();
                current = current->next;
            }
        }

        // Освобождение памяти
       // ~LinkedList() {
         //   Node* current = head;
          //  while (current) {
           //     Node* nextNode = current->next;
           //     delete current->data;  // Освобождаем память для фигуры
            //    delete current;         // Освобождаем память для узла
            //    current = nextNode;
         //   }
      //  }
    };
#endif //TAMPLATE_H
