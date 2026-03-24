//
// Created by 13191 on 2026/3/24.
//

#ifndef HYPERIONENGINE_TIMESTEP_H
#define HYPERIONENGINE_TIMESTEP_H

namespace Hyperion
{
    class Timestep
    {
    public:
        Timestep(float time = 0.0f)
            : m_Time(time)
        {
        };

        operator float() const { return m_Time; };

        float GetSeconds() const { return m_Time; }
        float GetMilliseconds() const { return m_Time * 1000.0f; }

    private:
        float m_Time;
    };
} // Hyperion

#endif //HYPERIONENGINE_TIMESTEP_H