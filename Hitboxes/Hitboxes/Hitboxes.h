// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HITBOXES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HITBOXES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HITBOXES_EXPORTS
#define HITBOXES_API __declspec(dllexport)
#else
#define HITBOXES_API __declspec(dllimport)
#endif
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <random>

#include "glm/glm.hpp"
using namespace std;
using namespace glm;
extern "C" {
	typedef struct Vec2
	{
		float x;
		float y;
	};

	typedef struct Vec3
	{
		float x;
		float y;
		float z;
	};


	typedef struct Vec4 {
		float x;
		float y;
		float z;
		float w;
	};

	typedef struct Box
	{
		Vec3 pos;
		Vec2 size;
		//vector<string> tags;
		int boxId;
		Vec4 color;
		bool iFrame = false;

	};

	typedef struct Collision
	{
		Box box1;
		Box box2;
	};
}



class CHitboxes {
public:
	CHitboxes();
	CHitboxes(CHitboxes& other) = delete;
	void operator =(const CHitboxes&) = delete;

	static CHitboxes* GetInstance();
	
	int CreateBox(Box box);
	Box GetBox(int boxId);
	bool TagBox(int boxId, string tag);
	bool UpdateBox(int boxId,Box box);

	bool CollideTags(string tag1, string tag2);
	vector<Collision> Collide();
	bool TagPairCompare(pair<string, string> pair1, pair<string, string> pair2);
protected:
	
	map<int,Box> boxMap;
	map<string, vector<Box>> tagList;
	vector<pair<string, string>> collisionList;
	default_random_engine generator;
	map<int, Box>::iterator doubleBoxIt;

};


static CHitboxes* singleton;


extern "C" {


	HITBOXES_API int CreateBox(Box box)
	{
		return CHitboxes::GetInstance()->CreateBox(box);
	}
	HITBOXES_API Box GetBox(int boxId) 
	{
		return CHitboxes::GetInstance()->GetBox(boxId);
	}

}

int Add(int a, int b) 
{
	return a + b;
}
