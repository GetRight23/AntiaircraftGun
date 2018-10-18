#ifndef SIMPLE_AI_H
#define SIMPLE_AI_H

#include "AIComponent.h"
#include "Constants.h"

class AISimple : public AIComponent {
public:
	virtual void makeActivity(ActiveObject& obj, float time) override final;
};


#endif