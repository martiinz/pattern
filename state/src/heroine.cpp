#include "heroine.h"

Heroine::Heroine()
{
    m_state = std::make_unique<StandingState>();
}

void Heroine::handleInput(Input input)
{
    std::unique_ptr<HeroineState> state = m_state->handleInput(*this, input);

    if (state != nullptr)
    {
        m_state.swap(state);

        // Call the enter action on the new state.
        m_state->enter(*this);
    }
}

void Heroine::update()
{
    m_state->update(*this);
}

void Heroine::setGraphics(const std::string &graphic)
{
    std::cout << ">> set graphic " << graphic << std::endl;
}

void Heroine::superBomb(void)
{
    std::cout << ">> super bomb!" << std::endl;
}
