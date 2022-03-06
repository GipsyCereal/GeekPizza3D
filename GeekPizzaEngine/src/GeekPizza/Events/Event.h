#pragma once
#include "gppch.h"
#include "spdlog/fmt/ostr.h" //ostream overloading
#include "Core.h"

namespace GeekPizza 
{
	//Events are blocking atm -> event occurance has to instantly be dealt with, with many events this might block/buffer
	//the application while it's trying to deal with all the events that are being triggered,
	//Improvable in future by implementing an Event Queue that buffers event in an event bus to then
	//process them in a set update stage

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleases, MouseMoved, MouseScrolled
	};

	//"filter" for when you only want a specific category, like if you'd want to see all mouse events
	enum EventCategory
	{
		None = 0,
		//BITFIELD FOR FILTERING MULTIPLE (SUB)CATEGORIES --> MOUSEBUTTON IS ALSO INPUT --> BITMASK THOSE 2 IN
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3), // Mouse Movement
		EventCategoryMouseButton = BIT(4)
	};

	/* EVENT CLASS TYPE MACRO (less obsolete code repetition)*/
	//GetStaticEventType(): returns the type of the class u call it on e.g. PressKeyEvent.GetStaticEventType()
	//GetEventType(): returns the type of the event object u call it on (polymorphism)
	//GetName(): stringify type param and return
#define EVENT_CLASS_TYPE(type)	static EventType GetStaticEventType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticEventType(); }\
								virtual const char* GetName() const override {return #type;}

	
#define EVENT_CLASS_CATEGORY(categoryFlags) virtual int GetCategoryFlags() const override{ return categoryFlags; }
	
	class GEEKPIZZA_API Event 
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0; //returns the flags of class' categories (e.g. bit 3 and 4 for mouse categories)
		inline virtual std::string ToString() const { return GetName(); }
	
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_IsHandled;


	};

	class GEEKPIZZA_API EventDispatcher 
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>; //bool return type, takes param type T
	public:
		EventDispatcher(const Event& e)
			:m_Event{ e } {}

		template<typename T>
		bool Dispatch(EventFn<T>& func)
		{
			if (m_Event.GetEventType == T::GetStaticType())
			{
				m_Event.m_IsHandled = func(static_cast<T&>m_Event); //cast the Event m_Event to the actual EventType of the Event, pass that to func
				return true;
			}
			return false;
		}
			
	private:
		const Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}