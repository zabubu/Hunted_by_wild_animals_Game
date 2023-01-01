#include "doctest.h"

int main()
{
    doctest::Context context;

    context.setOption("order-by", "nom");


    return context.run();
}
