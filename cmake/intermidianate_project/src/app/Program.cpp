#include "Program.h"
#include "MyLib.h"
#include "Printer.h"

int Startup(){
    MyLib::ToString();
    Printer::ToString();
}