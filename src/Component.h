//
// Created by Dawid Drozd aka Gelldur on 07.03.16.
//

#pragma once

#include <string>
#include <cassert>

#define COMPONENT_TO_STRING(NAME) virtual const char* toString() const override{ return #NAME;}

class NativeObject;

class Context;

class Component
{
public:
	friend class NativeObject;

	Component() = default;
	virtual ~Component();

	Component(Component const&) = delete;
	Component& operator=(Component const&) = delete;

	virtual const char* toString() const = 0;

	bool isNullObject() const
	{
		return _owner == nullptr;
	}

protected:
	NativeObject* getOwner() const
	{
		assert(_owner != nullptr);
		return _owner;
	}

	Context* getContext() const;

private:
	NativeObject* _owner = nullptr;
};

//TODO check getIdForType and move to other dir
extern int counter;

template<class T>
inline int getIdForType()
{
	static int id = ++counter;
	return id;
}

