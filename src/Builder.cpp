//
// Created by mikhalinho on 25.04.22.
//

#include "headers/Builder.h"

size_t estimate_memory_size(size_t machine_code_size) {
    size_t page_size_multiple = sysconf(_SC_PAGE_SIZE);     // Get the machine page size
    size_t required_memory_size = 0;
    for(size_t factor = 1; machine_code_size > required_memory_size; ++factor)
        required_memory_size = factor * page_size_multiple;

    return required_memory_size;
}

int Builder::Build() {
    FILE* fout = fopen(output_file, "rb");
    size_t file_size = Size_of_file(fout);

    char* text = text_from_file(fout, file_size);

    std::vector<uint8_t> machine_code(text, text + file_size + 1);
    size_t required_memory_size = estimate_memory_size(machine_code.size());

    return 0;
}