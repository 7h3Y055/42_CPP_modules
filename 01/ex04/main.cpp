#include "sed_pro.hpp"

int main(int argc, char **argv){

    if (argc != 4){
        std::cout << "Usage:" << std::endl << argv[0] << " <filename> <pattern> <replace>" << std::endl;
        return 1;
    }

    int status = sed_pro(argv[1], argv[2], argv[3]);

    return status;
}
