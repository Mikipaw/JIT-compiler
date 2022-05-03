//
// Created by mikhalinho on 11.04.2022.
//

#include "headers/simple_string.h"


simple_string::simple_string(char* src) {
    if (src == nullptr) {
        fprintf(stderr, "Your string is empty!\n");
        return;
    }
    size = strlen(src);
    data = new char[size + 1];
    strcpy(data, src);
}

simple_string::simple_string(const char* src) {
    if (src == nullptr) {
        fprintf(stderr, "Your string is empty!\n");
        throw 1;
    }
    size = strlen(src);
    data = new char[size + 1];
    strcpy(data, src);
}

simple_string::simple_string (FILE* src) : size(Size_of_file(src)),
                                           data(text_from_file(src, Size_of_file(src))) {};

size_t Size_of_file(FILE* name_of_file) {
    fseek(name_of_file, 0, SEEK_END);
    size_t size_of_file = ftell(name_of_file);
    fseek(name_of_file, 0, SEEK_SET);

    return size_of_file;
}

char* text_from_file(FILE* file_name, size_t size_of_file){
    char* result_string = new char[size_of_file + 1];
    fread(result_string, sizeof(char), size_of_file + 1, file_name);

    return result_string;
}

simple_string &operator<<(simple_string &sstr, const char *str) {
    size_t src_size = strlen(str);
    sstr.size += src_size + 1;

    auto new_data = new char [sstr.size + src_size + 1];

    if (sstr.data != nullptr) strcpy(new_data, sstr.data);
    else 0;

    new_data = strcat(new_data, str);

    delete[] sstr.data;
    sstr.data = new_data;

    return sstr;
}

char& simple_string::operator[](int index) {
    if (index > size) {
        fprintf(stderr, "Array index out of bound, exiting...\n");
        throw std::out_of_range("Index out of range!\n");
    }

    return data[index];
}


char& simple_string::operator[](int index) const{
    if (index > size) {
        fprintf(stderr, "Array index out of bound, exiting...\n");
        throw std::out_of_range("Index out of range!\n");
    }

    return data[index];
}

const char* simple_string::get_data() const { return data; }

size_t      simple_string::get_size() const { return size; }

int sscmp(const simple_string& s1, const simple_string& s2) {
    int i = 0;
    while(true) {
        if (s1[i] == '\0' &&
            s2[i] == '\0')
            return 0;

        if (s1[i] == s2[i]) i++;
        else
            return s1[i] - s2[i];
    }
}

int Arrange_str_ptrs(simple_string* pointers, size_t number_of_lines, char* text) {
    assert(pointers != nullptr);
    assert(text != nullptr);
    int number_of_empty_lines = 0;
    //char *ptr = text;
    for (int i = 1; i < number_of_lines; ++i) {
        text = strchr(text, '\0');
        text++;
        pointers[i].data = text;
        pointers[i - 1].size = (int) (pointers[i].data - pointers[i - 1].data);
        if (pointers[i - 1].data[0] == '\n')
            number_of_empty_lines++;
    }

    return number_of_empty_lines;
}

simple_string* Make_array_from_simple_text_file(const char* file_path, size_t* number_of_cmds){
    FILE* command_file = fopen(file_path, "rb");
    try {
        if (command_file == nullptr) {
            throw "Can't open file!";
        }
    } catch (const char* exception) {
        fprintf(stderr, "Error: %s\n", exception);
    }

    size_t size_of_file         = Size_of_file(command_file);
    size_t number_of_commands   = 0;

    char* command_text = (char*) calloc(size_of_file, sizeof(char));
    fread(command_text, sizeof(char), size_of_file, command_file);
    for(int i = 0; i < size_of_file; ++i){
        if(command_text[i] == ' ') number_of_commands++;
    }

    try {
        if (command_text == nullptr)    throw "zero pointer";
        if (number_of_commands++ == 0)  throw "file is empty";
    } catch (const char* exception) {
        fprintf(stderr, "Error: %s\n", exception);
    }

    simple_string* str_array = (simple_string*) calloc(number_of_commands, sizeof(simple_string));
    str_array[0].data = command_text;

    Arrange_str_ptrs(str_array, number_of_commands, command_text);

    *number_of_cmds = number_of_commands;

    return str_array;
}


char* text_from_file(FILE* file_name, size_t size_of_file, size_t *number_of_lines) {
    char* result_string = (char*) calloc(size_of_file + 5, sizeof(char));
    fread(result_string, sizeof(char), size_of_file + 5, file_name);

    for(int i = 0; i < size_of_file; ++i){
        if(result_string[i] == '\n'){
            //result_string[i++]  = '\n';
            result_string[i]    = '\0';
            (*number_of_lines)++;
        }
    }
    return result_string;
}