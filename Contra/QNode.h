#ifndef __QNODE_H__
#define __QNODE_H__

#include "FrameWork\define.h"
#include "objects\BaseObject.h"
#include "pugixml-1.7\src\pugixml.hpp"
using namespace pugi;
class QNode
{
private:
	RECT _bound;
	INT64 _id;
	int _level;
	QNode* _parent;
	QNode* _childs[4];

	//vector<BaseObject*>  _listOject;
	vector<string> _listObject;


public:
	QNode(int id, int level, RECT bound, QNode* parent);
	void insertObject(BaseObject* baseobject);
	void insertObject(string name);
	RECT getBound();
	INT64 getId();
	int getLevel();
	QNode* getParent();
	void setParent(QNode* parent);
	QNode** getChilds();
	void setChilds(QNode* nodes[4]);
	bool isLeaf();


	vector<string> getAllObject();

	// H�m n�y g�y delay. Kh�ng d�ng h�m n�y.
	vector<string> getlistObject(RECT bound);



	static void loadChild(xml_node& node, QNode* parent);
	static QNode* loadQuadTree(const string path);
	static QNode* initNode(xml_node& node);

	/*
	L?y object m� bound ?� l�n
		@bound: hcn
		@botleft: b?ng true n?u hcn t�nh theo bot-left, false l� top-left
		th�m ?? kh?i m?t c�ng chuy?n b�n ngo�i
	*/
	vector<string> GetActiveObject(RECT bound, bool botleft = false);
	void fetchActiveObject(RECT bound);
	static vector<string> ActiveObject;
	~QNode();
};



#endif // !__QNODE_H__

