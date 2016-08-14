//
// Created by Dawid Drozd aka Gelldur on 6/17/16.
//

#pragma once

#include <JniObject.h>

class Context
{
public:
	Context(JniObject nativeObject)
			: _nativeObject(nativeObject)
	{
	}

	JniObject& getNative();

	static void setApplicationContext(jobject appContext);
	static JniObject& getApplicationContext();

private:
	JniObject _nativeObject;
};


