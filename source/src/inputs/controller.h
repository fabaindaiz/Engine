#pragma once

#include <functional>
#include <unordered_map>
#include <deque>
#include "keyboard.h"


namespace Engine
{

using Action = std::function<void()>;
using KeyActions = std::unordered_map<::Engine::Key, Action>;
using ActiveKeys = std::deque<::Engine::Key>;

/* \brief true returned on successful operation. */
class Controller
{
public:
    Controller() = default;

    bool onKeyPress(::Engine::Key key, Action action);

    bool deleteAction(::Engine::Key key);

    void processInputs();

    void press(::Engine::Key key);

private:
    KeyActions mKeyActions;
    ActiveKeys mActiveKeys;
};


} // namespace Engine