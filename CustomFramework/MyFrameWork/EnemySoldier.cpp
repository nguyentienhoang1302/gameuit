#include "EnemySoldier.h"


EnemySoldier::EnemySoldier(float x, float y, Direction dir, bool isShooter, std::vector<BulletSprite*>& bullet) // : EnemySprite(bullet)
{
    if (isShooter)
    {
        pData = new EnemySoldierData(bullet);
    }
    else
    {
        pData = new EnemySoldierData();
    }

    ((EnemySoldierData*)pData)->isShooter = isShooter;    

    pData->x = x;
    pData->y = y;
    
    this->initTextureArrays(EnemySoldierData::COUNT);
    this->addTextureArray(EnemySoldierData::RUN, "run", 3, 6);
    this->addTextureArray(EnemySoldierData::JUMP, "jump", 1, 60);
    this->addTextureArray(EnemySoldierData::DIE, "jump", 1, 60);
    this->addTextureArray(EnemySoldierData::FALL, "jump", 1, 60);
    this->addTextureArray(EnemySoldierData::DROWNING, "drowning", 2, 8);
    this->addTextureArray(EnemySoldierData::SHOT, "shot", 3, 8);
    this->pData->ppTextureArrays[EnemySoldierData::DESTROY] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 10);
    this->pData->ppTextureArrays[EnemySoldierData::DESTROY]->setAnchorPoint(0.5f, 0.5f);

    pData->dir = dir;
    pData->body = RectF(-9.0f, -33.0f, 18.0f, 33.0f);
    pData->vx = pData->vy = 0;
    pData->score = 100;
    pData->HP = 1;

    pData->pState = new EnemySoldierRunningState(pData);
}

EnemySoldier::~EnemySoldier()
{

}

void EnemySoldier::setSupportCollisionRect(CollisionRectF rect)
{
    this->pData->cSupportRect = rect;
}

void EnemySoldier::die()
{
    this->pData->pState = new EnemySoldierDieState(this->pData);
}

void EnemySoldier::onCameraCollision(RectF cameraRect)
{
    if (this->pData->x - (cameraRect.x + cameraRect.width) >= -SOLDIER_RANGE_TO_TURN)
    {
        if (this->pData->dir.isRight())
            this->pData->dir = Direction::createLeft();
    }

    if (this->pData->dir.isLeft())
    {
        if (this->pData->x <= cameraRect.x)
        {
            this->pData->isDesTroyed = true;
        }
    }
}

void EnemySoldier::loadResources()
{
    TextureArray* temp = new TextureArray("Resources\\Sprites", "soldier", "run", 3, 6);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "soldier", "jump", 1, 60);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "soldier", "drowning", 1, 60);
    delete temp;

    temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 10);
    delete temp;
}