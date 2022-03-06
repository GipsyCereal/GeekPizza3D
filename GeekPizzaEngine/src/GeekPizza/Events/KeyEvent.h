#pragma once
#include "Event.h"

namespace GeekPizza
{
	class GEEKPIZZA_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(int keyCode)
			:m_KeyCode{keyCode}
		{}
		int m_KeyCode;
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	class GEEKPIZZA_API KeyPressedEvent final : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount) //repeatcount will start going up when holding key after begin small time interval
			:KeyEvent(keyCode),
			m_RepeatCount{repeatCount} {}

		inline int GetRepeatCount() { return m_RepeatCount; }

		virtual std::string ToString() const override
		{
			std::stringstream sStream;
			sStream << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return sStream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class GEEKPIZZA_API KeyReleasedEvent final : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) //repeatcount will start going up when holding key after begin small time interval
			:KeyEvent(keyCode) {}

		virtual std::string ToString() const override
		{
			std::stringstream sStream;
			sStream << "KeyReleasedEvent: " << m_KeyCode;
			return sStream.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	private:
	};
}
