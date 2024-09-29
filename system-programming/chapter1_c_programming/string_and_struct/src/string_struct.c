#include <stdio.h>
#include <stdlib.h>
#include "string_struct.h"
#include <string.h>

void WrongMemoryManagement()
{
    char *hello_string = malloc(14);
    //                ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
    // hello_string ----> | g | a | r | b | a | g | e | g | a | r | b | a | g | e |
    //                ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾
    hello_string = "Hello Person!";
    // (chuỗi hằng số trong phân đoạn văn bản)
    // hello_string ----> [ "H" , "e" , "l" , "l" , "o" , " " , "P" , "e" , "r" , "s" , "o" , "n" , "!" , "\0" ]
    //___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
    // memory_leak -----> | g | a | r | b | a | g | e | g | a | r | b | a | g | e |
    //                  ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾ ‾‾‾
    hello_string[9] = 't'; // segfault!!
}

void TestStringTok()
{
    char *upped = strdup("strtok,is,tricky,!!");
    char *start = strtok(upped, ",");
    do
    {
        printf("%s\n", start);
    } while ((start = strtok(NULL, ",")));
}

void RunMemoryManagement()
{
    // test memory management
    //WrongMemoryManagement();
    TestStringTok();
}