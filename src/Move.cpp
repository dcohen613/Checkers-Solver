#include "Move.h"

using namespace std;
Move::Move()
{
    setrowF(0);
    setcolumnF(0);
    setrowT(0);
    setcolumnT(0);
    setweight(0);
}

void Move::setAll(int row1, int column1, int row2, int column2, int w) {
    setrowF(row1);
    setcolumnF(column1);
    setrowT(row2);
    setcolumnT(column2);
    setweight(w);
}
