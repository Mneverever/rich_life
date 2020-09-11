#include "commodity.h"
commodity::commodity(int price_, int occupy_){
       price = price_;
       occupy = occupy_;
}
commodity::getoccupy(){
        return occupy;
}
commodity::getprice(){
        return price;
}
