// Hitboxes.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Hitboxes.h"


// This is an example of an exported variable
HITBOXES_API int nHitboxes=0;

// This is an example of an exported function.
HITBOXES_API int fnHitboxes(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CHitboxes::CHitboxes()
{
    return;
}


double CHitboxes::CreateBox(vec3 pos, vec2 size) {
    Box box;
    box.pos = pos;
    box.size = size;
    //this might cause a clash but should work initially
    //need a better option, maybe with a uuid 
    normal_distribution<double> distribution(1.0, 100.0);
    double boxId = distribution(generator);
    doubleBoxIt = boxMap.find(boxId);
    if(doubleBoxIt != boxMap.end())
        double boxId = distribution(generator);
    boxMap.emplace(boxId, box);
    return boxId;
}

Box CHitboxes::GetBox(double boxId)
{
    doubleBoxIt = boxMap.find(boxId);
    if (doubleBoxIt != boxMap.end())
        return boxMap.at(boxId);
    Box box;
    box.boxId = -1.0;
    return box;
}

bool CHitboxes::TagBox(double boxId, string tag)
{
    //find box

    //check if tag is in boxes tag list

   //add box to tag map
    return false;
}

bool CHitboxes::UpdateBox(double boxId, Box box)
{
    doubleBoxIt = boxMap.find(boxId);
    if (doubleBoxIt != boxMap.end())
    {
        boxMap.at(boxId) = box;
        return true;
    }
    return false;
}

bool CHitboxes::CollideTags(string tag1, string tag2)
{
    //iterate pairs and add in tag if it doesnt exist

    return false;
}

vector<Collision> CHitboxes::Collide()
{
    //check collision for ear pair 

    //add collisions to list

    return vector<Collision>();
}

bool CHitboxes::TagPairCompare(pair<string, string> pair1, pair<string, string> pair2)
{
    if((pair1.first == pair2.first && pair1.second == pair2.second) ||(pair1.first == pair2.second && pair1.second == pair2.first))
        return true;
    return false;
}
