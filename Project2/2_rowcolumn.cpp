#include <iostream>
using namespace std;

const int DEFAULT_ROW_COLUMN_VALUE = -99999;

///// RowColumnClass /////
class RowColumnClass
{
  public:
    RowColumnClass();
    RowColumnClass(int inRow, int inCol);

    void setRowCol(int inRow, int inCol);
    void setRow(int inRow);
    void setCol(int inCol);
    int getRow();
    int getCol();
    void addRowColTo(RowColumnClass &inRowCol);
    void printRowCol();

  private:
    int rowIndex;
    int colIndex;
};

RowColumnClass::RowColumnClass()
{
  setRowCol(DEFAULT_ROW_COLUMN_VALUE, DEFAULT_ROW_COLUMN_VALUE);
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  setRowCol(inRow, inCol); 
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
  setRow(inRow);
  setCol(inCol);
}

void RowColumnClass::setRow(int inRow)
{
  rowIndex = inRow;
}

void RowColumnClass::setCol(int inCol)
{
  colIndex = inCol;
}

int RowColumnClass::getRow()
{
  return rowIndex;
}

int RowColumnClass::getCol()
{
  return colIndex;
}

void RowColumnClass::printRowCol()
{
  cout << "[" << getRow() << "," << getCol() << "]";
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
  setRowCol(rowIndex + inRowCol.getRow(), colIndex + inRowCol.getCol());
}