#include "menu.h"
#include "UnitTest_DynArray.h"
#include "UnitTest_LinkList.h"
#include "UnitTest_ArraySeq.h"
#include "UnitTest_LinkListSeq.h"
#include "UnitTest_Vector.h"

#include <iostream>

int main()
{
    //setlocale(LC_CTYPE, "Russian");

    UnitTest_DynArray();
    UnitTest_LinkList();
    UnitTest_ArraySeq();
    UnitTest_LinkListSeq();
    UnitTest_Vector();

    FuncMenu();

    return 0;
}