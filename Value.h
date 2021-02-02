#pragma once

#include <vector>
#include <functional>

template<typename T>
class ObservableValue
{
	using Observer = std::function<void(const T&)>;

private:
	T _value;
	std::vector<Observer> _observers;

public:
	const T& get() const
	{
		return _value;
	}

	void set(const T& value)
	{
		_value = value;

		for (auto& observer : _observers)
		{
			observer(_value);
		}
	}

	void observe(Observer observer)
	{
		_observers.push_back(observer);
		observer(_value);
	}
};

struct Values
{
	ObservableValue<int> score;
};