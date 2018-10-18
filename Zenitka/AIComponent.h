#ifndef AI_COMPONENT_H
#define AI_COMPONENT_H

#include "ActiveObject.h"

class AIComponent {
public:
	virtual ~AIComponent(void) {}
	virtual void makeActivity(ActiveObject& obj, float time) = 0;
};

#endif