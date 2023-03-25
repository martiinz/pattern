#ifndef HEROINE_STATE_H_
#define HEROINE_STATE_H_

#include "input.h"
#include "heroine.h"

#include <string>
#include <iostream>
#include <memory>

class Heroine;

// abstract state
class HeroineState
{
public:
  virtual ~HeroineState() = default;
  virtual std::unique_ptr<HeroineState> handleInput(Heroine& heroine, Input input) = 0;
  virtual void update(Heroine& heroine) = 0;
  virtual void enter(Heroine& heroine) = 0;
};

class DuckingState : public HeroineState
{
public:
  explicit DuckingState(int chargetime = 0);
  ~DuckingState() override;

  std::unique_ptr<HeroineState> handleInput(Heroine& heroine, Input input) override;
  void update(Heroine& heroine) override;
  void enter(Heroine& heroine) override;

private:
  int chargeTime_;
  const int MAX_CHARGE{10};
};

class StandingState : public HeroineState
{
public:
  explicit StandingState();
  ~StandingState() override;

  std::unique_ptr<HeroineState> handleInput(Heroine& heroine, Input input) override; 
  void update(Heroine& heroine) override;
  void enter(Heroine& heroine) override;

};

#endif /* HEROINE_STATE_H_ */
