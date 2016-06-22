//
// Created by Dawid Drozd aka Gelldur on 6/22/16.
//

#pragma once

#include <Component.h>

/**
 * Implementation is environment specific
 */
class Image: public Component
{
	using inherited = Component;
public:
	virtual void loadImage(const std::string& url);

	COMPONENT_TO_STRING(Image)

	static Image& getNullObject();
};

class NullImage : public Image
{
public:
	virtual void loadImage(const std::string& url) override;
};
