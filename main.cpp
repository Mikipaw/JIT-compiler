#include <cstdio>

#include "headers/Assembler.h"
#include "headers/Translator.h"

//TODO: compare with cpu from 1st sem

using std::vector;

int main() {
    int number_of_cmds = 100;
    //Assembler(&number_of_cmds);
    //ASM_Listing();

    //FILE* noc = fopen (f_number_of_commands, "wb");
    //fprintf(noc, "%d", number_of_cmds);
    //fclose(noc);

    CREATE_TRANSLATOR(trans, number_of_cmds, 1.0);

    trans.Work();
    trans.Run();

    return 0;
}
