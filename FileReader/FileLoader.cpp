//
// Created by lukasz on 10/29/16.
//

#include "FileLoader.h"

FileLoader::FileLoader(const std::string &filePath) : filePath(filePath) {
    file.open(filePath,std::ios_base::in);
}

FileLoader::FileLoader() {

}
