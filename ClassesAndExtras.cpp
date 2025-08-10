//here's some additional notes and exercises covering classes that i didn't do previously


// CLASSES AND OBJECTS
// class = user-defined data type that represents objects
// object = instance of a class
// can have attributes (member variables) and methods (member functions)
// classes follow principles of OOP (Object Oriented Programming)
/*
class Human {
    private:    // private members can only be accessed within the class
        std::string name;
        int age;
    
    public:     // public members can be accessed from outside the class
        // constructor - called when object is created
        Human(std::string name, int age) {
            this->name = name;  // 'this' pointer refers to current object
            this->age = age;
        }
        
        // getter methods (accessors)
        std::string getName() {
            return name;
        }
        
        int getAge() {
            return age;
        }
        
        // setter methods (mutators)
        void setName(std::string name) {
            this->name = name;
        }
        
        void setAge(int age) {
            this->age = age;
        }
        
        // member function
        void introduce() {
            std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
        }
};

int main() {
    Human person1("John", 25);  // creating object using constructor
    person1.introduce();
    std::cout << person1.getName() << std::endl;
    
    return 0;
}
*/

// CONSTRUCTORS
// constructor = special method that is automatically called when an object is instantiated
// useful for assigning values to attributes as arguments
/*
class Student {
    public:
        std::string name;
        int age;
        double gpa;
        
        // constructor
        Student(std::string name, int age, double gpa) {
            this->name = name;
            this->age = age;
            this->gpa = gpa;
        }
};

// you can also have multiple constructors (overloaded constructors)
class Pizza {
    public:
        std::string topping1;
        std::string topping2;
        
        Pizza() {  // default constructor
            topping1 = "pepperoni";
            topping2 = "mushroom";
        }
        
        Pizza(std::string topping1) {  // constructor with 1 parameter
            this->topping1 = topping1;
            this->topping2 = "cheese";
        }
        
        Pizza(std::string topping1, std::string topping2) {  // constructor with 2 parameters
            this->topping1 = topping1;
            this->topping2 = topping2;
        }
};
*/

// INHERITANCE
// inheritance = a class can receive attributes and methods from another class
// children classes inherit from parent class
// helps to reuse similar code found within multiple classes
/*
class Animal {  // parent class
    public:
        bool alive = true;
        
        void eat() {
            std::cout << "This animal is eating\n";
        }
};

class Dog : public Animal {  // child class inherits from Animal
    public:
        void bark() {
            std::cout << "The dog goes woof!\n";
        }
};

class Cat : public Animal {  // another child class
    public:
        void meow() {
            std::cout << "The cat goes meow!\n";
        }
};

int main() {
    Dog dog;
    dog.eat();   // inherited method
    dog.bark();  // own method
    std::cout << dog.alive << std::endl;  // inherited attribute
    
    return 0;
}
*/

// STATIC KEYWORD
// static = keyword that makes a variable belong to the class, rather than any objects
// static members are shared among all instances of the class
// can be accessed without creating an object
/*
class Student {
    public:
        std::string name;
        static int numOfStudents;  // static member variable
        
        Student(std::string name) {
            this->name = name;
            numOfStudents++;
        }
        
        static int getCount() {  // static member function
            return numOfStudents;
        }
};

int Student::numOfStudents = 0;  // initialize static member outside class

int main() {
    Student student1("Jeremy");
    Student student2("Alice");
    Student student3("Bob");
    
    std::cout << "Number of students: " << Student::getCount() << std::endl;
    // can access static members using class name, no object needed
    
    return 0;
}
*/

// ENUMS (ENUMERATIONS)
// enum = user-defined data type that consists of paired named-integer constants
// great if you have a set of potential options
/*
enum Day {sunday = 0, monday = 1, tuesday = 2, wednesday = 3, 
          thursday = 4, friday = 5, saturday = 6};

int main() {
    Day today = sunday;
    
    switch(today) {
        case sunday:    std::cout << "It is Sunday\n"; break;
        case monday:    std::cout << "It is Monday\n"; break;
        case tuesday:   std::cout << "It is Tuesday\n"; break;
        // ... and so on
    }
    
    return 0;
}

// can also be used like:
enum Size {SMALL = 8, MEDIUM = 12, LARGE = 16};

int main() {
    Size t_shirt = MEDIUM;
    
    switch(t_shirt) {
        case SMALL:     std::cout << "T-shirt was ordered in size " << SMALL << std::endl; break;
        case MEDIUM:    std::cout << "T-shirt was ordered in size " << MEDIUM << std::endl; break;
        case LARGE:     std::cout << "T-shirt was ordered in size " << LARGE << std::endl; break;
    }
    
    return 0;
}
*/

// OBJECT ARRAYS
// you can create arrays of objects just like arrays of other data types
/*
class Car {
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;
        
        Car(std::string make, std::string model, int year, std::string color) {
            this->make = make;
            this->model = model;
            this->year = year;
            this->color = color;
        }
        
        void accelerate() {
            std::cout << "You step on the gas!\n";
        }
        
        void brake() {
            std::cout << "You step on the brakes!\n";
        }
};

int main() {
    Car car1("Chevy", "Corvette", 2022, "blue");
    Car car2("Ford", "Mustang", 2023, "red");
    Car car3("Toyota", "Camry", 2021, "silver");
    
    Car cars[] = {car1, car2, car3};
    
    for(Car car : cars) {
        std::cout << &car << '\n';  // prints memory addresses
    }
    
    return 0;
}
*/

// GETTERS AND SETTERS
// abstraction = hiding unnecessary data from outside a class
// getter = function that makes a private attribute readable
// setter = function that makes a private attribute writable
/*
class Stove {
    private:
        int temperature = 0;
        
    public:
        // getter
        int getTemperature() {
            return temperature;
        }
        
        // setter with validation
        void setTemperature(int temperature) {
            if(temperature < 0) {
                this->temperature = 0;
            }
            else if(temperature >= 10) {
                this->temperature = 10;
            }
            else {
                this->temperature = temperature;
            }
        }
};

int main() {
    Stove stove;
    
    stove.setTemperature(1000000);  // will be limited to 10
    std::cout << "The temperature setting is: " << stove.getTemperature() << std::endl;
    
    return 0;
}
*/

// FRIEND KEYWORD
// friend = keyword that allows a function or class to access private members
// not part of the class but has access to private members
/*
class MyClass {
    private:
        int x = 10;
        
    public:
        friend void myFunction(MyClass obj);  // friend function declaration
};

void myFunction(MyClass obj) {
    std::cout << obj.x << std::endl;  // can access private member x
}

int main() {
    MyClass obj;
    myFunction(obj);
    
    return 0;
}
*/

// VECTORS (DYNAMIC ARRAYS)
// vector = dynamic array that can resize itself
// need to #include <vector>
/*
#include <vector>

int main() {
    // 1D vector
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    numbers.push_back(6);  // adds element to end
    numbers.pop_back();    // removes last element
    std::cout << numbers.size() << std::endl;  // prints size
    
    // 2D vector
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // accessing elements
    std::cout << matrix[0][1] << std::endl;  // prints 2
    
    // iterating through 2D vector
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
*/

// FILE I/O (INPUT/OUTPUT)
// need to #include <fstream>
/*
#include <fstream>
#include <iostream>

int main() {
    // Writing to a file
    std::ofstream MyWriteFile("filename.txt");
    MyWriteFile << "Files can be tricky, but it is fun enough!";
    MyWriteFile.close();
    
    // Reading from a file
    std::string myText;
    std::ifstream MyReadFile("filename.txt");
    while(getline(MyReadFile, myText)) {
        std::cout << myText;
    }
    MyReadFile.close();
    
    return 0;
}
*/

// AUTO KEYWORD
// auto = keyword that automatically deduces the type of a variable
// useful when type is obvious or complex
/*
int main() {
    auto x = 42;        // x is int
    auto y = 3.14;      // y is double
    auto z = "Hello";   // z is const char*
    auto w = std::string("World");  // w is std::string
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for(auto num : numbers) {  // auto deduces type as int
        std::cout << num << " ";
    }
    
    return 0;
}
*/

// NULLPTR
// nullptr = keyword represents a null pointer literal
// use instead of NULL or 0 for pointers
/*
int main() {
    int* ptr = nullptr;  // better than int* ptr = NULL;
    
    if(ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    }
    
    return 0;
}
*/

// POLYMORPHISM
// polymorphism = ability of objects of different types to be treated as objects of a common base type
// achieved through virtual functions
/*
class Shape {  // base class
    public:
        virtual void draw() {  // virtual function
            std::cout << "Drawing a shape\n";
        }
};

class Circle : public Shape {
    public:
        void draw() override {  // override keyword (optional but recommended)
            std::cout << "Drawing a circle\n";
        }
};

class Square : public Shape {
    public:
        void draw() override {
            std::cout << "Drawing a square\n";
        }
};

int main() {
    Shape* shapes[] = {new Circle(), new Square()};
    
    for(Shape* shape : shapes) {
        shape->draw();  // calls appropriate derived class method
    }
    
    return 0;
}
*/

// OPERATOR OVERLOADING
// allows you to redefine how operators work with user-defined classes
/*
class Student {
    private:
        int grade;
        
    public:
        Student(int grade) {
            this->grade = grade;
        }
        
        // overload + operator
        Student operator+(const Student& other) {
            return Student(this->grade + other.grade);
        }
        
        // overload << operator for output
        friend std::ostream& operator<<(std::ostream& os, const Student& student) {
            os << "Grade: " << student.grade;
            return os;
        }
};

int main() {
    Student student1(85);
    Student student2(92);
    Student result = student1 + student2;  // uses overloaded + operator
    
    std::cout << result << std::endl;  // uses overloaded << operator
    
    return 0;
}
*/

// COPY CONSTRUCTOR
// special constructor that creates a copy of an existing object
/*
class MyClass {
    private:
        int* data;
        
    public:
        // regular constructor
        MyClass(int value) {
            data = new int(value);
        }
        
        // copy constructor
        MyClass(const MyClass& other) {
            data = new int(*other.data);  // deep copy
            std::cout << "Copy constructor called\n";
        }
        
        // destructor
        ~MyClass() {
            delete data;
            std::cout << "Destructor called\n";
        }
        
        int getValue() const {
            return *data;
        }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1;  // copy constructor called
    
    std::cout << obj2.getValue() << std::endl;
    
    return 0;
}
*/

// DESTRUCTORS
// destructor = special method that is called when an object is destroyed
// used to free up resources that the object may have acquired
/*
class MyClass {
    public:
        MyClass() {  // constructor
            std::cout << "Constructor called\n";
        }
        
        ~MyClass() {  // destructor (has ~ symbol)
            std::cout << "Destructor called\n";
        }
};

int main() {
    MyClass obj;  // constructor called
    
    return 0;  // destructor called when obj goes out of scope
}
*/

// LAMBDA EXPRESSIONS (C++11)
// lambda = anonymous function that can be defined inline
// useful for short functions that are used once
/*
int main() {
    // basic lambda
    auto greet = []() {
        std::cout << "Hello from lambda!\n";
    };
    greet();
    
    // lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << add(5, 3) << std::endl;
    
    // lambda with capture
    int x = 10;
    auto addX = [x](int y) {  // captures x by value
        return x + y;
    };
    std::cout << addX(5) << std::endl;
    
    // lambda with reference capture
    int count = 0;
    auto increment = [&count]() {  // captures count by reference
        count++;
    };
    increment();
    std::cout << count << std::endl;  // prints 1
    
    return 0;
}
*/

// SMART POINTERS (C++11)
// need to #include <memory>
// smart pointers automatically manage memory
/*
#include <memory>

int main() {
    // unique_ptr = exclusive ownership of a resource
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    std::cout << *ptr1 << std::endl;
    // automatically deleted when ptr1 goes out of scope
    
    // shared_ptr = shared ownership of a resource
    std::shared_ptr<int> ptr2 = std::make_shared<int>(100);
    std::shared_ptr<int> ptr3 = ptr2;  // both point to same object
    std::cout << *ptr2 << std::endl;
    std::cout << ptr2.use_count() << std::endl;  // prints 2 (reference count)
    
    return 0;
}
*/

// MOVE SEMANTICS (C++11)
// move = transfer ownership of resources instead of copying
// std::move() converts an object to an rvalue reference
/*
#include <utility>

class MyString {
    private:
        char* data;
        size_t size;
        
    public:
        // constructor
        MyString(const char* str) {
            size = strlen(str);
            data = new char[size + 1];
            strcpy(data, str);
        }
        
        // move constructor
        MyString(MyString&& other) noexcept {
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        
        // destructor
        ~MyString() {
            delete[] data;
        }
};

int main() {
    MyString str1("Hello");
    MyString str2 = std::move(str1);  // move constructor called
    
    return 0;
}
*/

// RANGE-BASED FOR LOOPS (Enhanced)
// already covered foreach loops, but here's more detail
// range-based for loop (C++11 feature)
/*
int main() {
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
    
    // traditional for loop
    for(int i = 0; i < names.size(); i++) {
        std::cout << names[i] << std::endl;
    }
    
    // range-based for loop
    for(const auto& name : names) {  // const auto& for efficiency
        std::cout << name << std::endl;
    }
    
    return 0;
}
*/

// ABSTRACT CLASSES AND PURE VIRTUAL FUNCTIONS
// abstract class = class that cannot be instantiated
// contains at least one pure virtual function
/*
class Shape {  // abstract base class
    public:
        virtual void draw() = 0;  // pure virtual function (= 0 makes it pure)
        virtual double area() = 0;
};

class Circle : public Shape {
    private:
        double radius;
        
    public:
        Circle(double r) : radius(r) {}
        
        void draw() override {
            std::cout << "Drawing a circle\n";
        }
        
        double area() override {
            return 3.14159 * radius * radius;
        }
};

int main() {
    // Shape shape;  // ERROR: cannot instantiate abstract class
    Circle circle(5.0);
    circle.draw();
    std::cout << "Area: " << circle.area() << std::endl;
    
    return 0;
}
*/

// MULTIPLE INHERITANCE
// a class can inherit from multiple base classes
/*
class Animal {
    public:
        void eat() {
            std::cout << "This animal eats\n";
        }
};

class Flyable {
    public:
        void fly() {
            std::cout << "This creature flies\n";
        }
};

class Bird : public Animal, public Flyable {  // inherits from both classes
    public:
        void chirp() {
            std::cout << "The bird chirps\n";
        }
};

int main() {
    Bird bird;
    bird.eat();   // from Animal
    bird.fly();   // from Flyable
    bird.chirp(); // own method
    
    return 0;
}
*/

// NAMESPACE (ENHANCED)
// creating custom namespaces
/*
namespace Math {
    const double PI = 3.14159;
    
    double circleArea(double radius) {
        return PI * radius * radius;
    }
    
    double square(double x) {
        return x * x;
    }
}

namespace Physics {
    const double GRAVITY = 9.81;
    
    double force(double mass) {
        return mass * GRAVITY;
    }
}

int main() {
    std::cout << Math::circleArea(5) << std::endl;
    std::cout << Physics::force(10) << std::endl;
    
    // using directive
    using namespace Math;
    std::cout << square(4) << std::endl;  // can use without Math:: prefix
    
    return 0;
}
*/

// EXCEPTION HANDLING (ADVANCED)
// custom exception classes
/*
class DivisionByZeroException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Division by zero error!";
        }
};

double divide(double a, double b) {
    if(b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

int main() {
    try {
        double result = divide(10, 0);
        std::cout << result << std::endl;
    }
    catch(const DivisionByZeroException& e) {
        std::cerr << "Custom error: " << e.what() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Standard error: " << e.what() << std::endl;
    }
    catch(...) {  // catch all other exceptions
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    return 0;
}
*/

// REFERENCES
// reference = alias for an already existing variable
// must be initialized when declared
// cannot be changed to refer to another variable
/*
int main() {
    int x = 10;
    int& ref = x;  // ref is a reference to x
    
    std::cout << x << std::endl;    // prints 10
    std::cout << ref << std::endl;  // prints 10
    
    ref = 20;  // changes x through reference
    std::cout << x << std::endl;    // prints 20
    
    return 0;
}
*/

// CONST KEYWORD (ADVANCED USAGE)
/*
int main() {
    // const variables
    const int x = 5;  // cannot be modified
    
    // const pointers
    int a = 10, b = 20;
    const int* ptr1 = &a;      // pointer to const int (can't change value through pointer)
    int* const ptr2 = &a;      // const pointer to int (can't change address)
    const int* const ptr3 = &a; // const pointer to const int (can't change either)
    
    // const member functions
    /*
    class MyClass {
        private:
            int value;
            
        public:
            MyClass(int v) : value(v) {}
            
            int getValue() const {  // const member function
                return value;       // can only read, not modify
            }
    };
    */
    
    return 0;
}
*/

// INITIALIZATION LISTS
// more efficient way to initialize member variables in constructors
/*
class Rectangle {
    private:
        double width;
        double height;
        
    public:
        // using initialization list (preferred method)
        Rectangle(double w, double h) : width(w), height(h) {
            // constructor body can be empty or contain additional logic
        }
        
        // vs regular assignment in constructor body
        // Rectangle(double w, double h) {
        //     width = w;   // less efficient
        //     height = h;
        // }
        
        double area() const {
            return width * height;
        }
};

int main() {
    Rectangle rect(5.0, 3.0);
    std::cout << "Area: " << rect.area() << std::endl;
    
    return 0;
}
*/
