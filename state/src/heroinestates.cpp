#include "heroinestates.h"

DuckingState::DuckingState(int chargetime)
: chargeTime_(chargetime)
{
    /* do enter function here */
    std::cout << ">>> Ducking State ctor" << std::endl;
}

DuckingState::~DuckingState()
{
    std::cout << ">>> Ducking State deconst" << std::endl;
}

std::unique_ptr<HeroineState> DuckingState::handleInput(Heroine& heroine, Input input)
{
    if (input == Input::RELEASE_DOWN)
    {
        return std::make_unique<StandingState>();
    }

    return nullptr;
}

void DuckingState::update(Heroine& heroine)
{
    chargeTime_++;
    if (chargeTime_ > MAX_CHARGE)
    {
        heroine.superBomb();
    }
}

void DuckingState::enter(Heroine& heroine)
{
    heroine.setGraphics("duck");
}

StandingState::StandingState(void)
{
    /* do enter function here */
    std::cout << ">>> Standing State ctor" << std::endl;
}

StandingState::~StandingState()
{
    std::cout << ">>> Standing State deconst" << std::endl;
}

std::unique_ptr<HeroineState> StandingState::handleInput(Heroine& heroine, Input input)
{
if (input == Input::PRESS_DOWN)
{
    return std::make_unique<DuckingState>();
}

return nullptr;
}

void StandingState::update(Heroine& heroine)
{
    /* just idle standing */
}

void StandingState::enter(Heroine& heroine)
{
    heroine.setGraphics("stand");
}
