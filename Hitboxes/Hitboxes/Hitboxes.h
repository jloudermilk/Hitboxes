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

struct Box 
{
	vec3 pos;
	vec2 size;
	vector<string> tags;
	double boxId;
	vec4 color;
	bool iFrame = false;
};

struct Collision 
{
	Box box1;
	Box box2;
};

// This class is exported from the dll

class HITBOXES_API CHitboxes {
public:
	CHitboxes(void) {};

	double CreateBox(vec3 pos,vec2 size);
	Box GetBox(double boxId);
	bool TagBox(double boxId, string tag);
	bool UpdateBox(double boxId,Box box);

	bool CollideTags(string tag1, string tag2);
	vector<Collision> Collide();
	bool TagPairCompare(pair<string, string> pair1, pair<string, string> pair2);
protected:
	map<double,Box> boxMap;
	map<string, vector<Box>> tagList;
	vector<pair<string, string>> collisionList;
	default_random_engine generator;
	map<double, Box>::iterator doubleBoxIt;

};

extern HITBOXES_API int nHitboxes;

HITBOXES_API int fnHitboxes(void);
