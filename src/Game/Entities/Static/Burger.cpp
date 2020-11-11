//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::removeIngredient(){
    if(! ingredients.empty()){
        ingredients.pop_back();
    }

}

bool Burger::equals(Burger *target){// same ingredients and quantities //order is irrelevant
    if(this->ingredients.size() == target->ingredients.size()){
        string temp;
        bool flag = true;
        if(quantityOf(this->ingredients, "cheese") != quantityOf(target->ingredients,"cheese")){
            flag = false;
        }
        if(quantityOf(this->ingredients, "lettuce") != quantityOf(target->ingredients,"lettuce")){
            flag = false;
        }
        if(quantityOf(this->ingredients, "tomato") != quantityOf(target->ingredients,"tomato")){
            flag = false;
        }
        if(quantityOf(this->ingredients, "patty") != quantityOf(target->ingredients,"patty")){
            flag = false;
        }
        if(quantityOf(this->ingredients, "bottomBun") != quantityOf(target->ingredients,"bottomBun")){
            flag = false;
        }
        if(quantityOf(this->ingredients, "topBun") != quantityOf(target->ingredients,"topBun")){

            flag = false;
        }
        return flag;
    }else{
        return false;
    }
}

int Burger::quantityOf(vector<Item*> ingredients,string ingredientName){
        int temp = 0;
        for (Item *ingredient : ingredients)
        {
            if(ingredient->name == ingredientName){temp += 1;}
        }
        return temp;
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x,y-(counter * 10),width,height);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}