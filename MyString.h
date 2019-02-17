#pragma once
#include <iostream>

class MyString final
{
private:
    char * data_ = nullptr;
    size_t size_ = 0;

public:
    /* Default constructor */
    MyString();

    /* Constructor for create string from C-string */
    MyString(const char * str);

    /* Copy constructor */
    MyString(const MyString& rhs);

    /* Copy assignment operator */
    MyString& operator=(const MyString& rhs);

    /* C-string assignment operator */
    MyString& operator=(const char * str);

    /* Move constructor */
    MyString(MyString&& rhs) noexcept;

    /* Move assignment operator */
    MyString& operator=(MyString&& rhs) noexcept;

    /* Get size of the current string, excluding '\0' */
    size_t size() const;

    /* Get C-string equivalent */
    const char* c_str() const;

    /* Destructor */
    ~MyString();
    
private:
    /* Auxiliary functions */
    MyString(char * data, size_t size);
    void swap(MyString& rhs);
    void copyFrom(const char * str);
    void copyFrom(const MyString& rhs);

    /* Non-member functions */
    friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend bool operator<(const MyString& lhs, const MyString& rhs);
    friend bool operator>(const MyString& lhs, const MyString& rhs);
};