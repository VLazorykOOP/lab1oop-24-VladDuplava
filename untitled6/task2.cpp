#include <iostream>

class Vector {
private:
    double* data;
    size_t size;
    static int objectCount;

public:
    // Конструктор без параметрів
    Vector() : size(1) {
        data = new double[1]{0};
        objectCount++;
    }

    // Конструктор з одним параметром
    Vector(size_t size) : size(size) {
        data = new double[size]{};
        objectCount++;
    }

    // Конструктор з двома параметрами
    Vector(size_t size, double value) : size(size) {
        data = new double[size];
        for (size_t i = 0; i < size; i++)
            data[i] = value;
        objectCount++;
    }

    // Конструктор копіювання
    Vector(const Vector& other) : size(other.size) {
        data = new double[size];
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];
        objectCount++;
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new double[size];
            for (size_t i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
        objectCount--;
    }

    // Встановлення та отримання значення
    void setElement(size_t index, double value) {
        if (index < size) data[index] = value;
    }
    double getElement(size_t index) const {
        return (index < size) ? data[index] : 0.0;
    }

    // Друк вектора
    void print() const {
        for (size_t i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    // Арифметичні операції
    Vector operator+(const Vector& other) const {
        Vector result(size);
        for (size_t i = 0; i < size; i++)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    Vector operator*(double scalar) const {
        Vector result(size);
        for (size_t i = 0; i < size; i++)
            result.data[i] = data[i] * scalar;
        return result;
    }

    // Кількість об'єктів
    static int getObjectCount() {
        return objectCount;
    }
};

int Vector::objectCount = 0;

int main0() {
    Vector v1;
    Vector v2(5, 2.5);
    v1.print();
    v2.print();

    v2.setElement(2, 10.0);
    std::cout << "v2[2] = " << v2.getElement(2) << std::endl;

    Vector v3 = v2 * 2.0;
    v3.print();

    std::cout << "Об'єктів Vector: " << Vector::getObjectCount() << std::endl;
    return 0;
}
