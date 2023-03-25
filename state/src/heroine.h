#ifndef HEROINE_H_
#define HEROINE_H_

#include "input.h"
#include "heroinestates.h"

#include <string>
#include <iostream>
#include <memory>

class HeroineState;

class Heroine
{
public:
  explicit Heroine();
  virtual ~Heroine() = default;

  virtual void handleInput(Input input);
  virtual void update();
  virtual void setGraphics(const std::string &graphic);
  virtual void superBomb(void);

private:
    std::unique_ptr<HeroineState> m_state;
};

#endif /* HEROINE_H_ */
