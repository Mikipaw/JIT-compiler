//
// Created by mikhalinho on 03.05.22.
//

#include "headers/Translator.h"
#include <iostream>

int read_register_eax() {
    int ret;
    asm ("mov[ret],eax");
    return ret;
}

int Translator::Work(){
    int64_t    first    = 0;
    int64_t    second   = 0;
    int64_t    integ    = 0;

    for(int i = 0; i < number_of_commands; ++i) {
        integ = (int64_t) array[i];
        switch (integ) {
#define DEF_CMD(name, num, code, hash){                                 \
                    case num:                                           \
                    code;                                               \
                    break;                                              \
                }
#include "commands.h"

#undef DEF_CMD
            default:
                return ERROR_UNKNOWN_COMMAND;
        }
        //printf("%d\n", i);
    }

    return ALL_OK;
}

Translator::Translator(size_t num_of_coms, int my_id, const char* new_name):
        number_of_commands      (num_of_coms),
        mark                    (new int[10]),
        name                    (new_name),
        RAM                     (new int64_t[400])
{
    for(int i = 0; i < 10; ++i) {
        mark[i] = 0;
    }

    FILE* input = fopen(output_file, "rb");
    assert(input != nullptr);

    size_t size_of_file = Size_of_file(input);
    size_t non = 0;

    char* text = text_from_file(input, size_of_file + 1, &non);
    fclose(input);

    array = (double*) calloc(non + 1, sizeof(double));

    double doub = 0;
    int pos = 0;
    int j = 0;
    size_t lenstr = strlen(text);

    while(pos < lenstr) {
        sscanf(text + pos, "%lf", &doub);
        array[j++] = doub;
        while (text[pos] >= '0' && text[pos] <= '9' || text[pos] == '.' || text[pos] == ']' && pos < lenstr) pos++;
        while (text[pos] == ' ' && pos < lenstr) pos++;
    }
    //number_of_commands = non;
};

int Translator::Run() const {
    void *exec = mmap(nullptr, ind, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    std::memcpy(exec, &bytecode[0], ind);
    mprotect(exec, ind, PROT_READ | PROT_EXEC);
    reinterpret_cast<void (*)()>(exec)();
    /*int(*exec)();
    exec = (int(*)())&bytecode[0];
    (int)(*exec)(); */
}

int Translator::compute_dist(int src, int dest) {
    int pos = 0, end = 0;
    int result = 1;
    if (src > dest) {
        pos = dest;
        end = src;
    }
    else {
        pos = src;
        end = dest;
    }

    int curr = 0;
    while (pos < end) {
        result++;
        curr = array[pos++];
        switch (curr) {
            case 40:
                 curr = array[pos++];
                 if (curr == 0) {
                     curr = array[pos++];
                 if (curr < 63) result++;
                 else result += 1;
                 }
                break;
            case 9:
                result++;
                break;
            case 23:
                result += 5;
                pos++;
                break;
            case 1:
                result += 4;
                break;
            case 2:
                result += 4;
                break;
            case 21:
                result += 2;
                pos++;
                break;
            case 10:
                result += 11;
                break;
            default:
                result++;
                break;
        }
    }
    return result / 2;
}
