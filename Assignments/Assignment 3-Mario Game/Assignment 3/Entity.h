#pragma once

#include "Components.h"

#include <string>
#include <tuple>

typedef std::tuple<
	CTransform,
	CLifeSpan,
	CInput,
	CBoundingBox,
	CAnimation,
	CGravity,
	CState
> componentTuple;


class Entity
{
	friend class EntityManager;

	size_t m_id = 0;
	std::string m_tag = "Default";
	bool m_active = true;
	componentTuple m_components;

	//constructor and destructor
	Entity(const size_t id, const std::string& tag);
	
public:

	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();

	template <typename T>
	bool hasComponent() const
	{
		return getComponent<T>().has;
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		auto& component = getComponent<T>();
		component = T(std::forward<TArgs>(mArgs)...);
		component.has = true;
		return component;
	}

	template<typename T>
	T& getComponent()
	{
		return std::get<T>(m_components);
	}

	template<typename T>
	const T& getComponent() const
	{
		return std::get<T>(m_components);
	}

	template<typename T>
	void removeComponent()
	{
		getComponent<T>() = T();
	}


};

