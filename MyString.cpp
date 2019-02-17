#include "MyString.h"
#include <stdexcept>
#include <cstring>

MyString::MyString() : data_(new char[1]{'\0'})
{
}

MyString::MyString(const char * str)
{
    copyFrom(str);
}

MyString::MyString(const MyString& rhs)
{
    copyFrom(rhs);
}

MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs) return *this;
    copyFrom(rhs);
    return *this;
}

MyString& MyString::operator=(const char * str)
{
    copyFrom(str);
    return *this;
}

MyString::MyString(MyString&& rhs) noexcept
{
    swap(*this, rhs);
}

MyString& MyString::operator=(MyString&& rhs) noexcept
{
    if (this == &rhs) return *this;
    swap(*this, rhs);
    return *this;
}

size_t MyString::size() const
{
    return size_;
}

const char* MyString::c_str() const
{
    return (data_) ? const_cast<const char*>(data_) : "";
}

MyString::~MyString()
{
    delete[] data_;
}

MyString::MyString(char * data, size_t size) : data_(data), size_(size)
{
}

void MyString::copyFrom(const char * str)
{
    if (!str) throw std::invalid_argument("Passed argument is NULL");

    size_ = strlen(str);
    data_ = new char[size_ + 1];
    strncpy(data_, str, size_ + 1);
}

void MyString::copyFrom(const MyString& rhs)
{
    delete[] data_;
    size_ = 0;

    if (rhs.data_ && rhs.size_) {
        size_ = rhs.size_;
        data_ = new char[size_ + 1];
        strncpy(data_, rhs.data_, size_ + 1);
    }
}

void swap(MyString& lhs, MyString& rhs)
{
    std::swap(lhs.data_, rhs.data_);
    std::swap(lhs.size_, rhs.size_);
}

std::ostream& operator<<(std::ostream& os, const MyString& rhs)
{
    if (rhs.data_) { os << rhs.data_; }
    return os;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    /* calculate the total length of the string, excluding '\0' */
    size_t temp_size = lhs.size_ + rhs.size_;

    /* allocate a new block for storing whole string + '\0' */
    char * temp_data = new char[temp_size + 1];

    strcpy(temp_data, lhs.data_);
    strcpy(temp_data + lhs.size_, rhs.data_);

    return { temp_data, temp_size };
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    const char* left = lhs.data_;   // left word
    const char* right = rhs.data_;  // right word

    char left_ch = 0;   // character in the left word
    char right_ch = 0;  // character in the right word

    while ((left_ch = tolower(*left++)) && (right_ch = tolower(*right++))) {
        if (left_ch < right_ch) return true;
        if (left_ch > right_ch) return false;
    }
    return (lhs.size_ < rhs.size_) ? true : false;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    const char* left = lhs.data_;   // left word
    const char* right = rhs.data_;  // right word

    char left_ch = 0;   // character in the left word
    char right_ch = 0;  // character in the right word

    while ((left_ch = tolower(*left++)) && (right_ch = tolower(*right++))) {
        if (left_ch > right_ch) return true;
        if (left_ch < right_ch) return false;
    }
    return (lhs.size_ > rhs.size_) ? true : false;
}