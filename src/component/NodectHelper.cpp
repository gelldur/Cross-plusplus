//
// Created by Dawid Drozd aka Gelldur on 6/30/16.
//

#include "NodectHelper.h"
#include "Container.h"

namespace NodectHelper
{

Nodect& find(Nodect& nodect, const std::string& tag)
{
	return nodect.getComponent<Container>().get(tag);
}

void nest(Nodect& owner, Nodect&& nodect)
{
	owner.getComponent<Container>().add(std::move(nodect));
}

}