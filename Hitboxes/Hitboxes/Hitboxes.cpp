// Hitboxes.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Hitboxes.h"


// This is the constructor of a class that has been exported.
CHitboxes::CHitboxes()
{
    return;
}


CHitboxes* CHitboxes::GetInstance()
{
    if (singleton == nullptr){
    singleton = new CHitboxes();
    }
    return singleton;
}


int CHitboxes::CreateBox(Box box) {

    //this might cause a clash but should work initially
    //need a better option, maybe with a uuid 
    uniform_int_distribution<int> distribution(1, 10000);
    int boxId = distribution(generator);
    doubleBoxIt = boxMap.find(boxId);
    if(doubleBoxIt != boxMap.end())
        unsigned int boxId = distribution(generator);
    box.boxId = boxId;
    boxMap.emplace(boxId, box);
    return boxId;
}

Box CHitboxes::GetBox(int boxId)
{
    doubleBoxIt = boxMap.find(boxId);
    if (doubleBoxIt != boxMap.end())
        return boxMap.at(boxId);
    Box box;
    box.boxId = -1.0;
    return box;
}

bool CHitboxes::TagBox(int boxId, string tag)
{
    //find box

    //check if tag is in boxes tag list

   //add box to tag map
    return false;
}

bool CHitboxes::UpdateBox(int boxId, Box box)
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
