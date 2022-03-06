#pragma once
#include "Event.h"
#include <sstream>
namespace GeekPizza 
{

	class MouseMovedEvent final : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y)
			: m_PosX{ x }
			, m_PosY{ y }
		{}

		inline float GetPosX() const { return m_PosX; }
		inline float GetPosY() const { return m_PosY; }

		std::string ToString() const override 
		{
			std::stringstream ss;

			ss << "MouseMoveEvent: " << m_PosX << ", " << m_PosY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		const float m_PosX, m_PosY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float scrollOffsetX, const float scrollOffsetY)
			: m_ScrollOffsetX{ scrollOffsetX }
			, m_ScrollOffsetY{ scrollOffsetY }
		{}

		inline float GetOffsetX() const { return m_ScrollOffsetX; }
		inline float GetOffsetY() const { return m_ScrollOffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_ScrollOffsetX << ", " << m_ScrollOffsetY;
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton);
		EVENT_CLASS_TYPE(MouseScrolled);
	private:
		const float m_ScrollOffsetX, m_ScrollOffsetY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_MouseButton; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton);

	protected:
		MouseButtonEvent(const int button)
			:m_MouseButton{button}
		{}
		int m_MouseButton;
	
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const int button)
			:MouseButtonEvent(button)
		{}
		inline int GetMouseButton() const { return m_MouseButton; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseButton;
		}
		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const int button)
			:MouseButtonEvent(button)
		{}
		inline int GetMouseButton() const { return m_MouseButton; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_MouseButton;
		}
		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}