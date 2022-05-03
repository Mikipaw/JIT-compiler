//
// Created by mikhalinho on 11.04.2022.
//

#ifndef HASHTABLE_SIMPLE_STRING_H
#define HASHTABLE_SIMPLE_STRING_H


#include <cstring>
#include <cstdio>
#include <stdexcept>
#include <cassert>

class simple_string;

/*!
 * @brief compares 2 simple strings
 * @param s1
 * @param s2
 * @return {s1 > s2 => 1}, {s1 == s2 => 0}, {s1 < s2 => -1}
 */
int sscmp(const simple_string& s1, const simple_string& s2);

simple_string* Make_array_from_simple_text_file(const char* file_path, size_t* number_of_cmds);

size_t Size_of_file(FILE* name_of_file);

char* text_from_file(FILE* file_name, size_t size_of_file);

char* text_from_file(FILE* file_name, size_t size_of_file, size_t *number_of_lines);

int Arrange_str_ptrs(simple_string* pointers, size_t number_of_lines, char* text);

class simple_string {
public:
    simple_string() = default;
    explicit simple_string (char* src);
    explicit simple_string (FILE* src);
    explicit simple_string (const char* src);

    //simple_string& operator=(const simple_string& cpu) = delete;
    //simple_string(const simple_string&)                = delete;

    char& operator[](int);
    char& operator[](int) const;


    friend simple_string& operator<<(simple_string& sstr, const char* str);
    friend bool operator==(const simple_string& s1, const simple_string& s2) { return !strcmp(s1.data, s2.data); }

    [[nodiscard]] const char* get_data() const;
    [[nodiscard]] size_t      get_size() const;

    ~simple_string() { delete[] data; }
    char* data = new char[31];
    size_t size = 31;
};


#endif //HASHTABLE_SIMPLE_STRING_H
