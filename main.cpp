#include <cstdio>

#include "headers/Assembler.h"
#include "headers/Translator.h"


using std::vector;

int main() {
    int number_of_commands = 0;
    FILE* noc = fopen (f_number_of_commands, "rb");
    CREATE_TRANSLATOR(trans, number_of_commands, 1.0);
    fclose(noc);

    trans.Work();

    return 0;
}
