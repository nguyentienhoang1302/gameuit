#include "ObjectState.h"

ObjectState::ObjectState(void)
{
}


ObjectState::~ObjectState(void)
{
}

 void ObjectState:: onUpdate() 
{
    pData->ppTextureArrays[pData->iCurrentArr]->update();
}

 void ObjectState:: transition(SpriteState* state)
{
	pData -> pState = state; 
	delete this;
}
