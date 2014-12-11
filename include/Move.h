#ifndef MOVE_H
#define MOVE_H


class Move
{
    public:
        Move();
        int getrowF() { return rowF; }
        void setrowF(int val) { rowF = val; }
        int getcolumnF() { return columnF; }
        void setcolumnF(int val) { columnF = val; }
        int getrowT() { return rowT; }
        void setrowT(int val) { rowT = val; }
        int getcolumnT() { return columnT; }
        void setcolumnT(int val) { columnT = val; }
        int getweight() { return weight; }
        void setweight(int val) { weight = val; }
        void setAll(int row1, int column1, int row2, int column2, int weight);

        int rowF;
        int columnF;
        int rowT;
        int columnT;
        int weight;
};

#endif // MOVE_H
