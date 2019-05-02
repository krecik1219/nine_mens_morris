#pragma once

#include <array>
#include <unordered_map>
#include <string>
#include <vector>

#include "player/PlayerColor.hpp"
#include "BoardField.hpp"

namespace model {

struct Move
{
    std::string fromField;
    std::string toField;
    PlayerColor who;

    std::string fieldOponentsCheckerTaken;
};

class GameBoard
{
public:
    GameBoard();
    ~GameBoard();

    GameBoard(const GameBoard& other);
    GameBoard& operator=(const GameBoard& other);
    GameBoard(GameBoard&& other);
    GameBoard& operator=(GameBoard&& other);

    PlayerColor getColorOnField(const std::string& position) const;
    void setColorOnField(const std::string& position, const PlayerColor color);
    void moveChecker(const std::string& checkerOldPos, const std::string& checkerNewPos);

    bool operator==(const GameBoard& other) const;
    std::vector<std::string> getFreeFields() const;
    bool lastMoveFormedMill() const;
    std::vector<std::string> getCheckersWithColor(const PlayerColor color) const;
    bool isCheckerInMill(const std::string& field) const;
    std::vector<std::string> getFreeNeighbours(const std::string& field) const;

    std::string getStrRepr() const;

private:
//    /std::array<PlayerColor, 24> boardBase;
    void makeFieldsRowsColumnsCoupling();

    std::unordered_map<std::string, Field> boardBase;
    std::array<Row, 8> rows;
    std::array<Column, 8> columns;
    Move lastMove;
};

} // namespace model
