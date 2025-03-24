#include <iostream>
#include <string>

class Box {
private:
    double w, h;
    std::string col;

public:
    // Конструктори
    Box() : w(1), h(1), col("white") {}
    Box(double width, double height, std::string color) {
        setWidth(width);
        setHeight(height);
        setColor(color);
    }

    // вказуємо
    void setWidth(double width) { w = (width > 0) ? width : 1; }
    void setHeight(double height) { h = (height > 0) ? height : 1; }
    void setColor(std::string color) { col = color; }

    //отримання
    double getWidth() const { return w; }
    double getHeight() const { return h; }
    std::string getColor() const { return col; }

    // Обчислення площі та периметра
    double getArea() const { return w * h; }
    double getPerimeter() const { return 2 * (w + h); }

    // Вивод
    void print() const {
        std::cout << "Прямокутник: " << w << "x" << h << ", колір: " << col
                  << ", площа: " << getArea() << ", периметр: " << getPerimeter() << std::endl;
    }
};

int main() {
    Box b1;
    Box b2(4, 5, "blue");

    b1.print();
    b2.print();

    b1.setWidth(10);
    b1.setHeight(3);
    b1.setColor("red");
    b1.print();

    return 0;
}
