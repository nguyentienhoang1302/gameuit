#include "PlayScene.h"


PlayScene ::PlayScene()
{
    std:: string mapName = "stage" + std::to_string(UIComponents::getInstance() ->getCurrentStage());

    pMap = new Map(mapName);

	lifeTexture = new Texture*[2];

	for (int i = 0; i < 2; i++)
	{
		lifeTexture[i] = NULL;
	}
	


    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;

    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));

	cam = new Camera(viewPort,pMap ->getResX(), pMap ->getResY(), pMap->getMapRect(), pMap ->getCameraTranslatePoint());

	pPlayer = new PlayerSprite*[2];

	pPlayer[0] = new PlayerSprite(0, pMap ->getResX(), pMap ->getResY(), cam ->getMoveDir());

	nPlayers = UIComponents:: getInstance() -> getNumberPlayer();

	if( nPlayers == 2)
	{
		pPlayer[1] = new PlayerSprite(1, pMap ->getResX(), pMap ->getResY(), cam ->getMoveDir());
	}
	else
	{
		pPlayer[1] = NULL;
	}
	lifeTexture[0] = new Texture("Resources\\Sprites\\player\\life00.png", "life00");
	if( nPlayers == 2)
	{
		lifeTexture[1] = new Texture("Resources\\Sprites\\player2\\life200.png", "life200");
	}
	isPause = false;
	isFinish = false;
	isGameOver = false;
	nTransitionFrames = 5 * 60;
	count = 0;

	Sound::getInstance()->play("stage" + std::to_string(UIComponents::getInstance() -> getCurrentStage()), true , 1);
}

PlayScene ::~PlayScene()
{
	delete pPlayer;
	pPlayer = NULL;
	delete viewPort;
	viewPort = NULL;

	delete cam;
	cam = NULL;
	delete pMap;
	pMap = NULL;
	delete lifeTexture;
	lifeTexture = NULL;

}

void PlayScene::onCollision()
{
	for (int i = 0; i < nPlayers; i++)
	{
		pMap -> onCollisionvsPlayer(pPlayer[i], cam);
	}
    pMap->onCollision(cam);
}

void PlayScene::handleInput()
{
    while (!KeyBoard::getInstace()->isEmpty())
    {
        KeyEvent e = KeyBoard::getInstace()->readKey();
		for (int i = 0; i < nPlayers; i++)
		{
			if( e.getCode() == UIComponents::getInstance() ->getKey(UIComponents::SELECT, i) )
			{
				if (e.isRelease())
				{
					isPause = !isPause;
				}
				break;
			}
			else if ( e.getCode() == VK_F1 ) 
			{
				if (e.isRelease())
				{
					Sound::getInstance() ->mute();
				}
			}
			else if ( e.getCode() == VK_F2)
			{
				if (e.isRelease())
				{
					Sound::getInstance() ->unMute();
					Sound::getInstance()->play("stage" + std::to_string(UIComponents::getInstance() -> getCurrentStage()), true , 1);
				}
			}
			else if( !isPause)
			{
				char keyCode = e.getCode();
				if( keyCode == UIComponents::getInstance() ->getKey(UIComponents::RIGHT,i) )
				{
					if (e.isPress())
					{
						pPlayer[i]->getState()->onMovePressed(Direction::createRight());
					}
					else
					{
						pPlayer[i]->getState()->onMoveReleased(Direction::createRight());
					}
				}
				else if ( keyCode == UIComponents::getInstance() -> getKey(UIComponents::LEFT, i))
				{
					if (e.isPress())
					{
						pPlayer[i]->getState()->onMovePressed(Direction::createLeft());
					}
					else
					{
						pPlayer[i]->getState()->onMoveReleased(Direction::createLeft());
					}
				}
				else if ( keyCode == UIComponents::getInstance() -> getKey(UIComponents::UP ,i))
				{
					if (e.isPress())
					{
						pPlayer[i]->getState()->onVeticalDirectionPressed(Direction::createUp());
					}
					else
					{
						pPlayer[i]->getState()->onVeticalDirectionReleased();
					}
				}
				else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::DOWN ,i))
				{
					if (e.isPress())
					{
						pPlayer[i]->getState()->onVeticalDirectionPressed(Direction::createDown());
					}
					else
					{
						pPlayer[i]->getState()->onVeticalDirectionReleased();
					}
				}
				else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::JUMP ,i ))
				{
					if (e.isPress())
					{
						pPlayer[i]->getState()->onJumpPressed();
					}
					else
					{
						pPlayer[i]->getState()->onJumpRelease();
					}
				}
				else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::FIRE ,i ))
				{
					if (e.isPress())
					{
						pPlayer[i]->getState()->onFirePressed();
					}
				}		
			}

		}
    }

	KeyBoard::getInstace() ->flush();

}
void PlayScene::onUpdate()
{
	if( isGameOver )
	{
		count++;
		if( count == nTransitionFrames)
		{
            //GameSaveLoad::getInstance()->checkAndSaveScore(UIComponents::getInstance()->getScore());
			SceneManager::getInstance()->createScene(new GameOverScene());
			return;
		}
	}
	else if( isFinish )
	{
		count++;
		if( count == nTransitionFrames)
		{
			if( UIComponents::getInstance() ->getCurrentStage() < 3 )
			{
				UIComponents::getInstance() ->setStage( UIComponents::getInstance() ->getCurrentStage() + 1 );
				SceneManager::getInstance()->createScene(new LoadingScene());
			}
			else
			{
				SceneManager::getInstance()->createScene(new EndingScene());
			}
			return;
		}
	}

	handleInput();

	if( !isPause )
	{
		update();
		onCollision();
		isFinish = pMap -> isFinish();
		int lifes = 0;
		for (int i = 0; i < nPlayers; i++)
		{
			lifes += UIComponents::getInstance() ->getLifes(i);
		}
		if(lifes <= 0)
		{
			isGameOver = true;
		}
	}

	
}
void PlayScene::render()
{
	if(isEffectOn)
	{
		 Graphics::getInstance()->beginRender();
   

		 unsigned int Passes  = 0;



		 for(int i=0; i < Passes; ++i)
		 {
			 Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
			 D3DXMATRIX mtxViewProj;
			 D3DXMatrixOrthoOffCenterLH(&mtxViewProj, 0.5f, 256 + 0.5f,
				 256 + 0.5f, 0.5f, 0.0f, 1.0f);


			 pMap->draw(cam);
			 
			 for (int i = 0; i < nPlayers; i++)
			 {
				 if(!pPlayer [i] -> isPlayerOver())
				 {
					 pPlayer [i] -> draw(cam);
				 }
			 }

			 Graphics::getInstance() ->getSpriteHandler() -> End();
		 }


		 Graphics::getInstance() ->getSpriteHandler() -> End();

		 Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND);
		 for (int i = 0; i < nPlayers; i++)
		 {
			 int lifes = min (UIComponents::getInstance() ->getLifes(i) , 5);
			 int x = 0;
			 int y = 0;
			 int offset = 16;
			  x = offset * 5 * i;
			 for (int j = 0; j < lifes - 1 ; j++)
			 {
				 lifeTexture[i] ->draw(x, y);
				 x += offset;
			 }
		 }
		 
		 
		 Graphics::getInstance() ->getSpriteHandler() -> End();

		 Graphics::getInstance()->endRender();
	}
	else
	{
		Graphics::getInstance()->beginRender();
		Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);

		pMap->draw(cam);
		for (int i = 0; i < nPlayers; i++)
		{
			if(!pPlayer [i] -> isPlayerOver())
			{
				pPlayer [i] -> draw(cam);
			}
		}
		 for (int i = 0; i < nPlayers; i++)
		 {
			 int lifes = min (UIComponents::getInstance() ->getLifes(i) , 5);
			 int x = 0;
			 int y = 0;
			 int offset = 16;
			  x = offset * 5 * i;
			 for (int j = 0; j < lifes - 1 ; j++)
			 {
				 lifeTexture[i] ->draw(x, y);
				 x += offset;
			 }
		 }

		Graphics::getInstance() ->getSpriteHandler() -> End();
		Graphics::getInstance()->endRender();
	}
   
}

void PlayScene :: update()
{
	
		pMap -> onUpdatePlayerProperties(pPlayer[0], pPlayer[1], cam );
		pMap->onUpdate(cam);
		int nplayernotOver = 0;
		for (int i = 0; i < nPlayers; i++)
		{
			if(!pPlayer[i] -> isPlayerOver())
			{
				pMap->onSupportPlayer(pPlayer[i]);
				nplayernotOver++;
			}
		}
		pMap -> onSupportSprite();
		for (int i = 0; i < nPlayers; i++)
		{
			if(!pPlayer[i] -> isPlayerOver())
			{
				pPlayer[i] -> update();
			}
		}
		int iplayer = 0;
		if(nplayernotOver == 1)
		{
			for (int i = 0; i < nPlayers; i++)
			{
				if(!pPlayer[i] -> isPlayerOver())
				{
					iplayer = i;
				}
			}
		}
		
		if(nplayernotOver == 2 )
		{
			cam ->update( pPlayer[0]->getX(), pPlayer[0]->getY() ,pPlayer[1]->getX(), pPlayer[1]->getY());
		}
		else if( nplayernotOver == 1)
		{
			cam ->update( pPlayer[iplayer]->getX(), pPlayer[iplayer]->getY());
		}
		

		for (int i = 0; i < nPlayers; i++)
		{
			if(!pPlayer[i] -> isPlayerOver())
			{
				pPlayer[i] -> setCameraRect (cam ->getRect());
			}
		}
	
	
	
	if(isEffectOn)
	{


		for (int i = 0; i < nPlayers; i++)
		{
			if(!pPlayer [i] -> isPlayerOver())
			{
				float resultX = pPlayer[i] -> getCenterX() - cam -> getX() + cam -> getViewport() -> getPort().x;
				float resultY = pPlayer[i] -> getCenterY() - cam -> getY() + cam -> getViewport() -> getPort().y;
				resultX = ( resultX - SCWIDTH / 2 ) / (SCWIDTH / 2);
				resultY = ( SCHEIGHT / 2 - resultY ) / (SCHEIGHT / 2);
			}
		}

		
		
	}
	
}