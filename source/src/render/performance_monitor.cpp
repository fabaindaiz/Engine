
#include "performance_monitor.h"

#include <string>
#include <sstream>
#include <iomanip>


namespace Engine
{

void PerformanceMonitor::update(float currentTime)
{
    _framesCounter += 1;
    _timer += currentTime - _currentTime;
    _currentTime = currentTime;
    
    if (_timer > _period)
    {
        _framesPerSecond = _framesCounter / _timer;
        _milisecondsPerFrame = 1000.0 * _timer / _framesCounter;
        _framesCounter = 0;
        _timer = 0.0;
    }
}

std::ostream& operator<<(std::ostream& os, const Engine::PerformanceMonitor& perfMonitor)
{
    os << std::fixed << std::setprecision(2)
        << "[" << perfMonitor.getFPS() << " fps - "
        << perfMonitor.getMS() << " ms]";
    return os;
}

} // namespace Engine