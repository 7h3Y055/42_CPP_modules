#include "sed_pro.hpp"

int sed_pro(std::string file, std::string match, std::string replace){
    std::ifstream ifile(file.c_str());
    std::string buffer;
    size_t pos = 0;

    if (!ifile.is_open()){
        std::perror(file.c_str());
        return 1;
    }
    if (getline(ifile, buffer, '\0')){
        pos = buffer.find(match, 0);
        while(pos != std::string::npos){
            buffer.erase(pos, match.length());
            buffer.insert(pos, replace);
            pos = buffer.find(match, pos + replace.length());
        }
    } else{
        std::cout << "Empty file !" << std::endl;
        return 1;
    }

    std::ofstream ofile((file + ".replace").c_str());
    ofile << buffer;
    ifile.close();
    ofile.close();
    return 0;
}

