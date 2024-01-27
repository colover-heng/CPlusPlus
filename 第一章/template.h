#include <iostream>

template <typename PieceType>
class GameBoard {
public:
    void setPieceAt(size_t x, size_t y, PieceType* piece);
    PieceType* getPieceAt(size_t x, size_t y) const;
    bool isEmpty() const;
private:
    
};