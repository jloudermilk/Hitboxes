
#if defined(_MSC_VER)
//  Microsoft 
#define DllExport __declspec(dllexport)
#elif defined(__GNUC__)
//  GCC
#define DllExport __attribute__((visibility("default")))
#else
//  do nothing? ¯\_(ツ)_/¯
#define DllExport
#pragma warning Unknown dynamic link import/export semantics.
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
	struct Vec2
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
	bool UpdateBox(int boxId, Box box);

	bool CollideTags(string tag1, string tag2);
	vector<Collision> Collide();
	bool TagPairCompare(pair<string, string> pair1, pair<string, string> pair2);
protected:

	map<int, Box> boxMap;
	map<string, vector<Box>> tagList;
	vector<pair<string, string>> collisionList;
	default_random_engine generator;
	map<int, Box>::iterator doubleBoxIt;

};


static CHitboxes* singleton;


extern "C" {


	DllExport int CreateBox(Box box)
	{
		return CHitboxes::GetInstance()->CreateBox(box);
	}
	DllExport Box GetBox(int boxId)
	{
		return CHitboxes::GetInstance()->GetBox(boxId);
	}

}


