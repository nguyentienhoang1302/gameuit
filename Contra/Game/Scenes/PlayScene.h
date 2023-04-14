
#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "../../Graphics/Sprite.h"
#include "../Managers/SpriteManager.h"
#include "../Managers/SceneManager.h"
#include "../Managers/SoundManager.h"
#include "../../Graphics/Text.h"
#include "../../Graphics/Animation.h"
#include "../../Debug.h"
#include "../../Tiles/Map.h"
#include "../../QNode.h"
#include "../../Graphics/Scenario.h"

#include "../Objects/Bullets/BulletManager.h"
#include "../Objects/Enemies/RockFall.h"
#include "../Objects/Enemies/RedCannon.h"
#include "../Objects/Enemies/Soldier.h"
#include "../Objects/Enemies/Rifleman.h"
#include "../Objects/Enemies/WallTurret.h"
#include "../Objects/Enemies/Boss.h"
#include "../Objects/Enemies/ScubaSoldier.h"

#include "../Objects/RockFly.h"
#include "../Objects/Fire.h"
#include "../Objects/Bill.h"
#include "../Objects/Bridge.h"
#include "../Objects/Land.h"
#include "../Objects/Help.h"
#include "../Objects/Falcon.h"
#include "../Objects/BaseObject.h"
#include "../Objects/AirCraft.h"
#include "Scene.h"


#define BOSS_VIEWPORT_ANCHOR		6112

using namespace std;
US_FRAMEWORK

ACTOR_SCENARIO
class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	bool init() override;
	void updateInput(float dt) override;
	void update(float dt) override;
	void draw(LPD3DXSPRITE spriteHandle) override;
	void release() override;


	void setViewport(Viewport* viewport);
	//static Viewport* getViewport();

	// Trả về một đối tượng theo id.
	// id: kiểu enum eID, định danh một đối tượng.
	// return: đối tượng cần tìm.
	BaseObject* getObject(eID id);

	// Lấy đối tượng bill.
	Bill* getBill();
private:
	void destroyobject();				// kiển tra nếu object hết hạn sử dụng thì phá huỷ đối tượng
	Text* _text;

	Help* _help;

	// Danh sách đối tượng dùng để tạo quadtree.
	map <string, BaseObject*> _mapobject;

	// Danh sách các đối tượng hoạt động rộng không thể đưa vào quadtree.
	// (Ví dụ main character)
	vector<BaseObject*> _listobject;

	// Danh sách đối tượng nằm trong vùng active.
	// Mỗi vòng lặp sẽ được kiểm tra chỉnh sửa tại update, và sử dụng lại tại draw.
	vector<BaseObject*>   _active_object;

	vector<IControlable*> _listControlObject;
	Map* background;

	// quadtree
	QNode* _root;
	// Trỏ đến bill, một số đối tượng cần truyền bill vào để xử lý, lấy ở đây.
	BaseObject* _bill;
	BaseObject* _bulletmanager;

	void updateViewport(BaseObject* objTracker);


	bool flagbossScenario;
	ScenarioManager* _director;
	ScenarioManager* _directorKillBoss;

	void killbossScene_Bill(float deltatime, bool& isFinish);
	void bossScene_Viewport(float dt, bool& finish);
	void playPassBossSound(float dt, bool& finish);
	void playBossStage1Sound(float dt, bool& finish);
	// Xử lý kéo màn hình khi gặp bốt.
	void ScenarioMoveViewport(float deltatime);

	// Xử lý thằng bill tự đi sau khi giết boss
	void ScenarioKillBoss(float deltatime);

	bool checkGameLife();

};

#endif // !__PLAY_SCENE_H__
