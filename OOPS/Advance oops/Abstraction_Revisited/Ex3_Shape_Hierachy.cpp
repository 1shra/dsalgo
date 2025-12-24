// Problem: Expand the Shape example we discussed with more functionality.

// Requirements:
// Abstract class Shape should have:
// calculateArea() (pure virtual)
// calculatePerimeter() (pure virtual)
// display() (concrete, can be overridden)
// getColor() and setColor() (concrete)
// Create classes Triangle, Square, and Ellipse

// Add a function that takes an array of Shape pointers and calculates total area
// Challenge: Add a pure virtual function scale(double factor) and implement it in each derived class.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    
public:
    Shape(const string& c = "black") : color(c) {}
    
    // Pure virtual functions - must be implemented by derived classes
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void scale(double factor) = 0;  // Challenge function
    
    // Concrete functions - can be used as-is or overridden
    virtual void display() const {
        cout << "Shape color: " << color << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
    
    // Getter and setter for color
    string getColor() const { return color; }
    void setColor(const string& c) { color = c; }
    
    virtual ~Shape() = default;
};

// TODO: Implement Triangle class
class Triangle : public Shape {
private:
    double base;
    double height;
    double side1, side2;  // For perimeter calculation
    
public:
    // Constructor
    Triangle(double b, double h, double s1, double s2, const string& c = "black") 
        : Shape(c), base(b), height(h), side1(s1), side2(s2) {}
    
    // Implement pure virtual functions
    double calculateArea() const override {
        return (base * height) / 2;
    }
    
    double calculatePerimeter() const override {
        return base + side1 + side2;
    }
    
    void scale(double factor) override {
        // Scale all dimensions by factor
        base*=factor;
        height*=factor;
        side1*=factor;
        side2*=factor;
    }
    
    // Optional: Override display for better formatting
    void display() const override {
        cout << "Triangle:" << endl;
        Shape::display();  // Call base class display
        // Add triangle-specific info
    }
};

// TODO: Implement Square class
class Square : public Shape {
private:
    double side;
    
public:
    Square(double s, const string& c = "black") : Shape(c), side(s) {}
    
    double calculateArea() const override {
        return side * side;
    }
    
    double calculatePerimeter() const override {
        return 4 * side;
    }
    
    void scale(double factor) override {
        // Scale side by factor
        side*=factor;
    }
    
    void display() const override {
        cout << "Square:" << endl;
        Shape::display();
        cout << "Side length: " << side << endl;
    }
};

// TODO: Implement Ellipse class
class Ellipse : public Shape {
private:
    double majorAxis;  // Longer radius
    double minorAxis;  // Shorter radius
    
public:
    Ellipse(double major, double minor, const string& c = "black") 
        : Shape(c), majorAxis(major), minorAxis(minor) {}
    
    double calculateArea() const override {
        return 3.14 * majorAxis * minorAxis;
    }
    
    double calculatePerimeter() const override {
      int a = majorAxis, b = minorAxis;
      return 3.14*(3*(a+b)-sqrt(((3*a)+b)*(a+(3*b))));
    }
    
    void scale(double factor) override {
        // Scale both axes by factor
        majorAxis*=factor;
        minorAxis*=factor;
    }
    
    void display() const override {
        cout << "Ellipse:" << endl;
        Shape::display();
        cout << "Major axis: " << majorAxis << ", Minor axis: " << minorAxis << endl;
    }
};

// TODO: Implement this function
double calculateTotalArea(Shape* shapes[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += shapes[i]->calculateArea();
    }
    return total;
}

void demonstrateShapes() {
    cout << "=== SHAPE DEMONSTRATION ===" << endl;
    
    // Create different shapes
    Triangle tri(5.0, 4.0, 3.0, 4.0, "red");
    Square sq(6.0, "blue");
    Ellipse ellipse(8.0, 5.0, "green");
    
    // Display each shape
    cout << "\n--- Individual Shapes ---" << endl;
    tri.display();
    cout << "---" << endl;
    sq.display();
    cout << "---" << endl;
    ellipse.display();
    
    // Test polymorphism with array
    cout << "\n--- Polymorphism Test ---" << endl;
    Shape* shapes[] = {&tri, &sq, &ellipse};
    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << "---" << endl;
    }
    
    // Calculate total area
    cout << "\n--- Total Area Calculation ---" << endl;
    double total = calculateTotalArea(shapes, 3);
    cout << "Total area of all shapes: " << total << endl;
    
    // Test scaling
    cout << "\n--- Scaling Test ---" << endl;
    cout << "Before scaling - Square area: " << sq.calculateArea() << endl;
    sq.scale(2.0);  // Double the size
    cout << "After scaling (2x) - Square area: " << sq.calculateArea() << endl;
    
    // Test with scaled shapes
    cout << "\n--- All Shapes After Scaling ---" << endl;
    tri.scale(1.5);
    ellipse.scale(0.5);
    
    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << "---" << endl;
    }
    
    // Final total area
    total = calculateTotalArea(shapes, 3);
    cout << "Final total area after scaling: " << total << endl;
}

int main() {
    demonstrateShapes();
    return 0;
}