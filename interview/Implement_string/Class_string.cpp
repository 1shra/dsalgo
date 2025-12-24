#include <iostream>
#include <cstring> // for strlen and strcpy
using namespace std;

class String {
public:
    // Constructors
    String() : res(nullptr), len(0) {}
    
    String(const char* ch) {
        len = strlen(ch);
        res = new char[len + 1];
        strcpy(res, ch);
    }
    
    // Copy constructor
    String(const String& str) {
        len = str.len;
        res = new char[len + 1];
        strcpy(res, str.res);
    }
    
    // Assignment operator
    String& operator=(String str) {
        swap(str);
        return *this;
    }
    
    // Destructor
    ~String() {
        delete[] res;
    }
    
    // Swap method
    void swap(String& other) noexcept {
        std::swap(res, other.res);
        std::swap(len, other.len);
    }
    
    // Length accessor
    unsigned int length() const {
        return len;
    }
    
    // Friend operators
    friend ostream& operator<<(ostream& out, const String& str);
    friend istream& operator>>(istream& in, String& str);

private:
    char* res;
    unsigned int len;
};

// Output operator
ostream& operator<<(ostream& out, const String& str) {
    if (str.res) {
        out << str.res;
    }
    return out;
}

// Input operator
istream& operator>>(istream& in, String& str) {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    
    if (in >> buffer) {
        delete[] str.res;
        str.len = strlen(buffer);
        str.res = new char[str.len + 1];
        strcpy(str.res, buffer);
    }
    
    return in;
}

int main() {
    // Test cases
    String s1;
    String s2 = "Hello";
    String s3 = s2;
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    
    cout << "Enter a string: ";
    String s4;
    cin >> s4;
    cout << "You entered: " << s4 << endl;
    
    return 0;
}