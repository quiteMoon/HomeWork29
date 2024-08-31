#include <iostream>
#include <string>

using namespace std;

//class Pet {
//protected:
//    string name;
//    string species;
//
//public:
//    Pet(const string& n, const string& s) : name(n), species(s) {}
//
//    void display() const {
//        cout << "Name: " << name << "\nSpecies: " << species << endl;
//    }
//
//    ~Pet() = default;
//};
//
//class Dog : public Pet {
//private:
//    string breed; 
//    int age;
//
//public:
//    Dog(const string& n, const string& b, int a) : Pet(n, "Dog"), breed(b), age(a) {}
//
//    void display() const {
//        Pet::display();
//        cout << "Breed: " << breed << "\nAge: " << age << " years" << endl;
//    }
//};
//
//class Cat : public Pet {
//private:
//    string color;
//    bool indoor;
//
//public:
//    Cat(const string& n, const string& c, bool in) : Pet(n, "Cat"), color(c), indoor(in) {}
//
//    void display() const {
//        Pet::display();
//        cout << "Color: " << color << "\nIndoor: " << (indoor ? "Yes" : "No") << endl;
//    }
//};
//
//class Parrot : public Pet {
//private:
//    bool canTalk;
//
//public:
//    Parrot(const string& n, bool talk) : Pet(n, "Parrot"), canTalk(talk) {}
//
//    void display() const {
//        Pet::display();
//        cout << "Can Talk: " << (canTalk ? "Yes" : "No") << endl;
//    }
//};
//
//int main() {
//    Dog myDog("Buddy", "Golden Retriever", 5);
//    Cat myCat("Whiskers", "Gray", true);
//    Parrot myParrot("Polly", true);
//
//    cout << "Dog:\n";
//    myDog.display();
//    cout << "\nCat:\n";
//    myCat.display();
//    cout << "\nParrot:\n";
//    myParrot.display();
//}


using namespace std;

class String {
protected:
    char* str;
    size_t length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* cstr) {
        if (cstr) {
            length = strlen(cstr);
            str = new char[length + 1];
            strcpy_s(str, length + 1, cstr);
        }
        else {
            str = nullptr;
            length = 0;
        }
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;

        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
        return *this;
    }

    size_t getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];

        strcpy_s(newStr, newLength + 1, str);
        strcat_s(newStr, newLength + 1, other.str);

        String result(newStr);
        delete[] newStr;
        return result;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    const char* getStr() const {
        return str;
    }

    void print() const {
        if (str) {
            cout << str;
        }
        else {
            cout << "(порожній рядок)";
        }
    }
};

class BitString : public String {
private:
    bool isValidBitString(const char* cstr) {
        while (*cstr) {
            if (*cstr != '0' && *cstr != '1') {
                return false;
            }
            cstr++;
        }
        return true;
    }

public:
    BitString() : String() {}

    BitString(const char* cstr) : String() {
        if (isValidBitString(cstr)) {
            length = strlen(cstr);
            str = new char[length + 1];
            strcpy_s(str, length + 1, cstr);
        }
        else {
            length = 0;
            str = nullptr;
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        if (this == &other) return *this;

        String::operator=(other);
        return *this;
    }

    ~BitString() {}

    void negate() {
        if (str) {
            for (size_t i = 0; i < length; i++) {
                str[i] = (str[i] == '0') ? '1' : '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        return BitString((String::operator+(other)).getStr());
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + " " + s2;
    s3.print();
    cout << endl;

    BitString b1("10101");
    BitString b2("00110");
    BitString b3 = b1 + b2;
    b3.print();
    cout << endl;

    b3.negate();
    b3.print(); 
    cout << endl;
}
