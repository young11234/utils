
#include "ops.h"

int main(int argc, char* argv[])
{
    int ret = 0;

    int cnt = 1;
    if (argc == 2)
    {
        cnt = atoi(argv[1]);
    }

    for (int i = 0; i < cnt; ++i)
    {
        printf("loop: %d\n", i);
        Operator* op_add = GetOperator("add");
        op_add->forward();

        Operator* op_mul = GetOperator("mul");
        op_mul->forward();
    }

    printf("ok\n");

    return ret;
}