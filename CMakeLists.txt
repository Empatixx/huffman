cmake_minimum_required(VERSION 3.26)
project(HUFFMANN)

set(CMAKE_CXX_STANDARD 17)

add_executable(HUFFMANN main.cpp
        HuffmanNode.cpp
        HuffmanNode.h
        CompareNode.cpp
        CompareNode.h
        HuffmanTree.cpp
        HuffmanTree.h
        HuffmanCompressor.cpp
        HuffmanCompressor.h
        HuffmanDecompressor.cpp
        HuffmanDecompressor.h
        FileUtils.cpp
        FileUtils.h)
