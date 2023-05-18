#include "DemoScene.h"


DemoScene::DemoScene()
{

    std::string mapName = "demo";
    pMap = new Map(mapName);
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
    cam = new Camera(viewPort, pMap->getResX(), pMap->getResY(), pMap->getMapRect(), pMap->getCameraTranslatePoint());
    pPlayer = new PlayerSprite(0, pMap->getResX(), pMap->getResY(), cam->getMoveDir());
}


DemoScene::~DemoScene()
{
}

void DemoScene::onUpdate()
{
    handleInput();
    update();
    onCollision();

}

void DemoScene::update()
{
    pMap->onUpdatePlayerProperties(pPlayer, NULL, cam);
    pMap->onUpdate(cam);
    pMap->onSupportSprite();
    pMap->onSupportPlayer(pPlayer);
    pPlayer->update();
    cam->update(pPlayer->getX(), pPlayer->getY());
    pPlayer->setCameraRect(cam->getRect());
}

void DemoScene::onCollision()
{
    pMap->onCollision(cam);
    pMap->onCollisionvsPlayer(pPlayer, cam);
}

void DemoScene::handleInput()
{
    while (!KeyBoard::getInstace()->isEmpty())
    {
        KeyEvent e = KeyBoard::getInstace()->readKey();
        char keyCode = e.getCode();


        if (keyCode == UIComponents::getInstance()->getKey(UIComponents::RIGHT, 0))
        {
            if (e.isPress())
            {
                pPlayer->getState()->onMovePressed(Direction::createRight());
            }
            else
            {
                pPlayer->getState()->onMoveReleased(Direction::createRight());
            }
        }
        else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::LEFT, 0))
        {
            if (e.isPress())
            {
                pPlayer->getState()->onMovePressed(Direction::createLeft());
            }
            else
            {
                pPlayer->getState()->onMoveReleased(Direction::createLeft());
            }
        }
        else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::UP, 0))
        {
            if (e.isPress())
            {
                pPlayer->getState()->onVeticalDirectionPressed(Direction::createUp());
            }
            else
            {
                pPlayer->getState()->onVeticalDirectionReleased();
            }
        }
        else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::DOWN, 0))
        {
            if (e.isPress())
            {
                pPlayer->getState()->onVeticalDirectionPressed(Direction::createDown());
            }
            else
            {
                pPlayer->getState()->onVeticalDirectionReleased();
            }
        }
        else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::JUMP, 0))
        {
            if (e.isPress())
            {
                pPlayer->getState()->onJumpPressed();
            }
            else
            {
                pPlayer->getState()->onJumpRelease();
            }
        }
        else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::FIRE, 0))
        {
            if (e.isPress())
            {
                pPlayer->getState()->onFirePressed();
            }
        }
    }

    KeyBoard::getInstace()->flush();
}

void DemoScene::render()
{

    Graphics::getInstance()->beginRender();
    Graphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
    pMap->draw(cam);
    pPlayer->draw(cam);
    Graphics::getInstance()->getSpriteHandler()->End();
    Graphics::getInstance()->endRender();
}