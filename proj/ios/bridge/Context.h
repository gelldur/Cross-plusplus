//
// Created by Dawid Drozd aka Gelldur on 6/17/16.
//

#pragma once

class Context
{
public:
	Context(id nativeObject)
			: _nativeObject(nativeObject)
	{
	}

	id getNative()
	{
		return _nativeObject;
	}

private:
	id _nativeObject;
};

