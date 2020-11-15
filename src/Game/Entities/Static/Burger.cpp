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
    // ingredients.push_back(item);
    ingr.push(item);
    copy.push(item);
}

void Burger::removeIngredient(){
    if(! ingr.empty()){
        // ingredients.pop_back();
        ingr.pop();
        copy.pop();
    }

}

bool Burger::equals(Burger *target){// same ingredients and quantities //order is irrelevant
    if(this->ingr.size() == target->ingr.size()){
        string temp;
        bool flag = true;
        if(quantityOf(this->ingr, "cheese") != quantityOf(target->ingr,"cheese")){
            flag = false;
        }
        if(quantityOf(this->ingr, "lettuce") != quantityOf(target->ingr,"lettuce")){
            flag = false;
        }
        if(quantityOf(this->ingr, "tomato") != quantityOf(target->ingr,"tomato")){
            flag = false;
        }
        if(quantityOf(this->ingr, "patty") != quantityOf(target->ingr,"patty")){
            flag = false;
        }
        if(quantityOf(this->ingr, "bottomBun") != quantityOf(target->ingr,"bottomBun")){
            flag = false;
        }
        if(quantityOf(this->ingr, "topBun") != quantityOf(target->ingr,"topBun")){

            flag = false;
        }
        return flag;
    }else{
        return false;
    }
}

//vector<Item*> ingredients

int Burger::quantityOf(stack<Item*> &ingredients,string ingredientName){
        int temp = 0;
        
        stack<Item*> temporal;

        for(int i = 0; i<ingredients.size(); i++){
            temporal.push(ingredients.top());
            ingredients.pop();
            if(temporal.top()->name == ingredientName){temp++;}
        }

        // for (Item *ingredient : ingredients)
        // {
        //     if(ingredient->name == ingredientName){temp += 1;}
        // }
        return temp;
}

void Burger::render(){
    int counter = 1;
    copy = ingr;
    while(!copy.empty()){
        copy.top()->sprite.draw(x, y -(counter *10), width, height);
        copy.pop();
        counter++;
    }
    
    

}

void Burger::clear(){
    ingredients.empty();
}

