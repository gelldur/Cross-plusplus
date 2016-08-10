//
// Created by Dawid Drozd aka Gelldur on 7/28/16.
//

#include "Bridge.h"

#include <log.h>

#ifdef PLATFORM_IOS
#include <platform/IosBridge.h>
#elseif PLATFORM_ANDROID
#include <platform/AndroidBridge.h>
#endif

namespace CrossMobile
{

namespace Platform
{

CrossMobile::Platform::Bridge* Bridge::create()
{
#ifdef PLATFORM_IOS
	return new IosBridge();
#elseif PLATFORM_ANDROID
	return new AndroidBridge();
#else
	WLOG("Create DummyBridge");
	return new DummyBridge();
#endif
}

///////////////////////////////////////////////////////////////////////////////
// DummyBridge
///////////////////////////////////////////////////////////////////////////////

std::string DummyBridge::getWritablePath() const
{
	WLOG("Function %s not implemented: %s:%d", __func__, __FILE__, __LINE__);
	return "";
}

}
}
