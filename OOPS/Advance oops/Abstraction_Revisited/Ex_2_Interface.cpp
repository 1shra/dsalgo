// Problem: Create interfaces for different capabilities and implement them in various classes.

// Requirements:
// Create interface Printable with pure virtual function print()
// Create interface Serializable with pure virtual function serialize()
// Create interface Cloneable with pure virtual function clone()
// Create class Document that implements all three interfaces
// Create class Image that implements Printable and Cloneable but not Serializable

#include <iostream>
#include <string>
using namespace std;

// Interfaces (these are perfect!)
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() = default;
};

class Cloneable {
public:
    virtual Cloneable* clone() const = 0;
    virtual ~Cloneable() = default;
};

// Document class
class Document : public Printable, public Serializable, public Cloneable {
private:
    string title;
    string content;
    int pageCount;
    
public:
    Document(const string& t, const string& c, int p) 
        : title(t), content(c), pageCount(p) {}
    
    void print() const override {
        cout << "Document: " << title << " (" << pageCount << " pages)" << endl;
        cout << "Content: " << content << endl;
    }
    
    string serialize() const override {
        // RETURN a string, don't print
        return "DOCUMENT|" + title + "|" + content + "|" + to_string(pageCount);
    }
    
    Cloneable* clone() const override {
        // RETURN a new object
        return new Document(title, content, pageCount);
    }
};

// Image class  
class Image : public Printable, public Cloneable {
private:
    string filename;
    int width;
    int height;
    string format;
    
public:
    Image(const string& f, int w, int h, const string& fmt) 
        : filename(f), width(w), height(h), format(fmt) {}
    
    void print() const override {
        cout << "Image: " << filename << " (" << width << "x" << height << ", " << format << ")" << endl;
        cout << "Displaying image preview..." << endl;
    }
    
    Cloneable* clone() const override {
        // RETURN a new object
        return new Image(filename, width, height, format);
    }
};

// Helper function
void demonstrateInterfaces() {
    cout << "=== DEMONSTRATING INTERFACES ===" << endl;
    
    Document doc("Report", "This is the content of the report...", 5);
    Image img("photo.jpg", 1920, 1080, "JPEG");
    
    cout << "\n--- As Printable ---" << endl;
    Printable* printables[] = {&doc, &img};
    for (auto item : printables) {
        item->print();
        cout << "---" << endl;
    }
    
    cout << "\n--- As Cloneable ---" << endl;
    Cloneable* originalDoc = &doc;
    Cloneable* clonedDoc = originalDoc->clone();  // This creates a copy
    
    Cloneable* originalImg = &img;
    Cloneable* clonedImg = originalImg->clone();  // This creates a copy
    
    // Use the clones to show they work
    cout << "Original Document: ";
    doc.print();
    
    cout << "Cloned Document: ";
    Printable* clonedPrintableDoc = dynamic_cast<Printable*>(clonedDoc);
    if (clonedPrintableDoc) {
        clonedPrintableDoc->print();
    }
    
    cout << "\n--- As Serializable ---" << endl;
    Serializable* serializableDoc = &doc;
    cout << "Serialized: " << serializableDoc->serialize() << endl;
    
    // Clean up cloned objects (important!)
    delete clonedDoc;
    delete clonedImg;
}

int main() {
    demonstrateInterfaces();
    return 0;
}