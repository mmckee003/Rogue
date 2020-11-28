#pragma once

#include "Event.h"

#include <sstream>

namespace Rogue
{
	class ROGUE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(int KeyCode) : m_KeyCode(KeyCode)
		{

		}
		int m_KeyCode;
	};

	class ROGUE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode, int RepeatCount) : KeyEvent(KeyCode), m_RepeatCount(RepeatCount)
		{

		}

		inline int GetRepeatCount()
		{
			return m_RepeatCount;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class ROGUE_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int KeyCode) : KeyEvent(KeyCode)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}