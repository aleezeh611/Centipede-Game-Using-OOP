/*
 * GameObject.cpp
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#include "GameObject.h"

GameObject::GameObject() {  }

void GameObject::setBomb(int x, int y){//do nothing
//	cout<<"this setBomb gameobj"<<endl;
 }
bool GameObject::collision(int x, int y){
// to prevent derived classes that are not using this function from becoming abstract classes
}
GameObject::~GameObject() {
//	cout<<"dest gameobject"<<endl;
}

