#pragma once

#include <format>
#include <string>
#include <iterator>

// Convenience class to ensure all buffers are null-terminated
class StringBuffer {
    std::string m_buffer;

public:
    template <typename... Args>
    inline void format(const std::format_string<Args...>& fmt_str, Args&&... args)
    {
        // Format the string and append to the buffer
        std::format_to(std::back_inserter(m_buffer), fmt_str, std::forward<Args>(args)...);
        m_buffer.push_back('\0'); // Ensure null termination
    }

    template <typename... Args>
    inline void format_(const std::format_string<Args...>& fmt_str, Args&&... args)
    {
        std::format_to(std::back_inserter(m_buffer), fmt_str, std::forward<Args>(args)...);
    }

    inline const char* data() const { return m_buffer.c_str(); }

    inline void clear() { m_buffer.clear(); }

    inline void push_back(char c) { m_buffer.push_back(c); }
};

