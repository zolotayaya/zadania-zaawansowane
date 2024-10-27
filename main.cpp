#include <iostream>
#include<string>
#include "tamplate.h"
 using namespace std;

class Figure {
public:
    virtual float calculatePerimetr()=0;
    virtual float calculateSquare()=0;
    virtual string getname()=0;
    void print() {
        cout<< getname()<<endl;
        cout<<"Perimeter: "<< calculatePerimetr()<<endl;
        cout<<"Square: "<<calculateSquare()<<endl;

    }
    virtual ~Figure() = default;
};

class Square : public Figure {
public:
    int side;
    Square(int s) : side(s){};
    float calculatePerimetr() override {
        return 4 * side;
    }
    float calculateSquare()override {
        return side*side;
    }
    string getname() override {
        return "Square";
    }

};
class Circle :public Figure {
public:
    int radius;
    Circle (int r):radius(r){}
    float calculatePerimetr() override {
        return 2*3.14*radius;
    }
    float calculateSquare()override {
        return 3.14*radius*radius;
    }
    string getname() override {
        return "Circle";
    }

};
class Reactangle : public Figure {
public:
    float sideA;
    float sideB;
    Reactangle(float a,float b):sideA(a),sideB(b) {}

    float calculatePerimetr() override {
        return 2*sideA+2*sideB;
    }
    float calculateSquare() override {
        return sideA*sideB;
    }
    string getname() override {
        return "Rectangle";
    }
};
class Triangle :public Figure {
public:
    float SideA;
    float SideB;
    float SideC;
    float P;
    Triangle(float a,float b,float c):SideA(a),SideB(b),SideC(c) {
        P=calculatePerimetr()/2;
    }
    float calculatePerimetr() override {
        return SideA+SideB+SideC;
    }

    float calculateSquare() override {
        return sqrt(P*(P-SideA)*(P-SideB)*(P-SideC));//Formula Herona
    }
    string getname() override {
        return "Triangle";
    }
};



int main() {
    LinkedList<Figure> list;
    Square square(5);
    Square sq(4);
    Circle cir(3);
    Triangle tr(2,4,5);
    list.addAtEnd(&square);// Передаем адрес объекта Square
    list.addAtEnd(&cir);
    list.addAtEnd(&sq);
    //list.removeAllFiguresByName("Square");
    list.findByName("Square");
    //list.getFigureAt(1);
    list.addAtEnd(&tr);
    list.print();
    return 0;

}
