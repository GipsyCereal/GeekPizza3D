#pragma once
#include "Event.h"

namespace GeekPizza
{
	class WindowResizedEvent final : public Event
	{
	public:
		WindowResizedEvent(const unsigned x, const unsigned y)
			: m_Width{x}
			, m_Height{y}
		{}

		unsigned GetWidth() const { return m_Width; }
		unsigned GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowResize)
	private:
		const unsigned m_Width, m_Height;
	};

	class WindowClosedEvent final : public Event
	{
	public:
		WindowClosedEvent(){}

		std::string ToString() const override
		{
			return "WindowResizedEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowClose)
	private:

	};

	class AppTickEvent final : public Event
	{
	public:
		AppTickEvent() {}

		std::string ToString() const override
		{
			return "AppTickEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppTick)
	private:
	};

	class AppUpdateEvent final : public Event
	{
	public:
		AppUpdateEvent() {}

		std::string ToString() const override
		{
			return "AppUpdateEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppUpdate)
	private:
	};

	class AppRenderEvent final : public Event
	{
	public:
		AppRenderEvent() {}

		std::string ToString() const override
		{
			return "AppRenderEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppRender)
	private:
	};
}