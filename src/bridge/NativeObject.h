//
// Created by Dawid Drozd aka Gelldur on 6/17/16.
//

#pragma once

#include <map>
#include <string>
#include <memory>

#include <log.h>
#include <Component.h>
#include <utils/Utils.h>

class Context;

class NativeObject
{
public:
	static NativeObject* nullObject;

	NativeObject(const std::string& tag, std::shared_ptr<Context> context);
	NativeObject(NativeObject&& other);

	~NativeObject();

	NativeObject(const NativeObject& other) = delete;
	NativeObject& operator=(const NativeObject& other) = delete;

	void addComponentWithId(int id, std::unique_ptr<Component>&& component);

	const std::string& getTag() const
	{
		return _tag;
	}

	Context* getContext() const
	{
		assert(_context != nullptr);
		return _context.get();
	}

	template<class T>
	NativeObject& addComponent(std::unique_ptr<T>&& component)
	{
		static_assert(std::is_base_of<Component, T>(), "T must be child of Component");

		if (_context == nullptr)
		{
			WLOG("NullObject(%s) ignoring call: %s in: %s:%d", getTag().c_str(), __func__, __FILE__, __LINE__);
			return *this;
		}

		addComponentWithId(getIdForType<T>(), std::move(component));
		return *this;
	}

	template<class T, class... Args>
	NativeObject& addComponent(Args&& ... args)
	{
		if (_context == nullptr)
		{
			WLOG("NullObject(%s) ignoring call: %s in: %s:%d", getTag().c_str(), __func__, __FILE__, __LINE__);
			return *this;
		}

		addComponentWithId(getIdForType<T>(), std::make_unique<T>(std::forward<Args>(args)...));
		return *this;
	}

	template<class T>
	T& getComponent()
	{
		const int id = getIdForType<T>();
		auto found = _components.find(id);
		if (found == _components.end())
		{
			auto& nullObject = T::getNullObject();
			WLOG("Missing component: %s for %s", nullObject.toString(), _tag.c_str());

			return nullObject;
		}

		T* casted = dynamic_cast<T*>(found->second.get());
		if (casted == nullptr)
		{
			throw std::bad_cast();
		}
		return *casted;
	}

private:
	std::shared_ptr<Context> _context;
	std::string _tag;
	std::map<int, std::unique_ptr<Component>> _components;
};
