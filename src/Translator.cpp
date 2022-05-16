//
// Created by mikhalinho on 03.05.22.
//

#include "headers/Translator.h"

int Translator::Work(){
    double first    = 0;
    double second   = 0;
    int    integ    = 0;
    for(int i = 0; i < number_of_commands; ++i) {
        integ = (int) array[i];
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
        name                    (new_name)
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
    bytecode = (double*) calloc(non + 1, sizeof(double));

    double doub = 0;
    int pos = 0;
    int j = 0;
    size_t lenstr = strlen(text);

    while(pos < lenstr) {
        sscanf(text + pos, "%lf", &doub);
        array[j++] = doub;
        while (text[pos] >= '0' && text[pos] <= '9' || text[pos] == '.' || text[pos] == ']' && pos < lenstr) pos++;
        while (text[pos] == ' ' && pos < lenstr) pos++;
        //pos+=shift;
        /*while(doub >= magnitude){
            pos++;
            magnitude*=10;
        }
        doub*=100;
        if(      (int) doub % 10  != 0) pos+=3;
        else if( (int) doub % 100 != 0) pos+=2;*/
    }

    number_of_commands = non;
};
