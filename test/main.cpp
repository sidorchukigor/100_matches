#define CTEST_MAIN
#include <ctest.h>
#include "lib.h"
#include <stdio.h>

using namespace std;

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
//////////////////////////////////////////////////////
int mock_player(int matches)
{
    return matches-10;
}
CTEST(game, test1)
{   
    int res = game(mock_player, mock_player);
    ASSERT_EQUAL(0, res);

}
//////////////////////////////////////////////////////
CTEST(easy_ai, test1)
{
    ASSERT_EQUAL(1, easy_ai(10));
}

CTEST(easy_ai, test2)
{
    ASSERT_EQUAL(1, easy_ai(8));
}

CTEST(easy_ai, test3)
{
    ASSERT_EQUAL(1, easy_ai(6));
}
//////////////////////////////////////////////////////
CTEST(complex_ai, test1)
{
    ASSERT_EQUAL(89, complex_ai(92));
}

CTEST(complex_ai, test2)
{
    ASSERT_EQUAL(1, complex_ai(11));
}

CTEST(complex_ai, test3)
{
    ASSERT_EQUAL(45, complex_ai(47));
}

CTEST(complex_ai, test4)
{
    ASSERT_EQUAL(34, complex_ai(38));
}

CTEST(complex_ai, test5)
{
    ASSERT_EQUAL(78, complex_ai(84));
}

CTEST(complex_ai, test6)
{
    ASSERT_EQUAL(23, complex_ai(28));
}
//////////////////////////////////////////////////////