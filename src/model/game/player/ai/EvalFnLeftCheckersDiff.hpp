#pragma once

#include "EvalFunction.hpp"
#include <src/model/game/player/PlayerColor.hpp>
#include <src/model/game/GameState.hpp>

namespace model {

class GameState;

namespace ai {

class EvalFnLeftCheckersDiff : public EvalFunction
{
public:
    EvalFnLeftCheckersDiff();
    virtual ~EvalFnLeftCheckersDiff() override;

    EvalFnLeftCheckersDiff(const EvalFnLeftCheckersDiff&);
    EvalFnLeftCheckersDiff& operator=(const EvalFnLeftCheckersDiff&);
    EvalFnLeftCheckersDiff(EvalFnLeftCheckersDiff&&);
    EvalFnLeftCheckersDiff& operator=(EvalFnLeftCheckersDiff&&);

    virtual int evalGameState(const GameState& gameState, const PlayerColor who) override;
};

} // namespace ai
} // namespace model
