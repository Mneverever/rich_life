#include "rich_life.h"
#include<bits/stdc++.h>
rich_life::rich_life(){
        day = 1;
        money = rand()%500+20;
        water = 100 - rand()%15;
        food = 100 - rand()%20;
        health = 100 - rand()%10;
        HH = HL = LL = LH = 0;
        warehouse[0] = 0;
        warehouse[1] = 100;
}
int rich_life::get_water(){
        return water;
}
int rich_life::get_food(){
        return food;
}
int rich_life::get_health(){
        return health;
}
double rich_life::get_money(){
        return money;
}
int rich_life::get_warehouse_now(){
        return warehouse[0];
}
int rich_life::get_warehouse_capacity(){
        return warehouse[1];
}
int rich_life::get_day(){
        return day;
}
int rich_life::get_HH(){
        return HH;
}
int rich_life::get_HL(){
        return HL;
}
int rich_life::get_LH(){
        return LH;
}
int rich_life::get_LL(){
        return LL;
}
void rich_life::changeHH( int a){
        HH += a;
}
void rich_life::changeHL( int a){
        HL += a;
}
void rich_life::changeLH( int a){
        LH += a;
}
void rich_life::changeLL( int a){
        LL += a;
}
void rich_life::changeFood( int a){
        food += a;
        if(food > 100)
                food = 100;
}
void rich_life::changeWater( int a){
        water += a;
        if(water > 100)
                water = 100;
}
void rich_life::changeHealth( int a){
        health += a;
        if(health > 100)
                health = 100;
}
void rich_life::changeMoney( double a){
        money += a;
}
void rich_life::changeWarehouse(int a){
        warehouse[0]+=a;
}
void rich_life::changeDay(){
        day++;
        int change1, change2;
        change1 = rand()%20-10;
        change2 = rand()%20-10;
        you.changeFood(change1);
        you.changeWater(change2);
        change1 = rand()%20-10;
        if(change1 > 5)
                change2 = rand()%20-10;
        else
                change2 = 0;
        you.changeHealth(change2);
}
