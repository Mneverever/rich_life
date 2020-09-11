//a little game by myself.
//2020.8.23
/**** 1: txt file should be used to save "you"
    *2: change_day() should link water, food, health
    ***/    /*
# Malones
This project takes me 3 days during my first year final exam of my collage.
I hope some of you could help me to find the deficiency.
Lots of thanks.
*/

#include <bits/stdc++.h>
#include<windows.h>
#include<rich_life.h>
#include<commodity.h>
using namespace std;

int total_food = 100, total_water = 100, total_health = 100, target;
bool start();
inline void first_look();
inline void last_look();
inline void show(rich_life &a);
void if_you_can_buy_change_buy( rich_life& you, int money, int temp, commodity& com, int t);
void if_you_can_sell_change_sell( rich_life& you, int money, int temp, commodity& com, int t);
void go_to_hospital(rich_life&);
void go_to_get_some_drinks(rich_life&);
void go_to_get_some_food(rich_life&);

int main()
{
        while( start()){
                srand(time(0));
                target = ( 10 + rand() % 20) * 10000;
                rich_life you;
                commodity highPrice_highOccupy(2000, 20);
                commodity lowPrice_lowOccupy(10, 1);
                commodity lowPrice_highOccupy(1, 10);
                commodity highPrice_lowOccupy(20000, 10);
                int price_fluctuation;   //价格波动幅度
                system("cls");
                cout << "your target is : " << target << endl;
                cout << "please cin the fluctuation of price in this game( % ) : ";
                cin >> price_fluctuation;
                Sleep(3000);
                system("cls");
                cout << "**********start**********" << endl;
                Sleep(2000);
                int t;
                double money10 = 0, money20 = 0, money30 = 0, money40 = 0;
                while (you.get_money() <= target && you.get_health() > 0 ){
                        if(you.get_food() < 0 && you.get_water() > 0){
                                cout << "get some foooooooood ! ! ! you are so hungry ! (hp - 10)" << endl;
                                you.changeHealth(-10);
                        }
                        if(you.get_water() < 0 && you.get_food() > 0){
                                cout << "get some waterrrrrrr ! ! ! you are so thirsty ! (hp - 15)" << endl;
                                you.changeHealth(-15);
                        }
                        if( you.get_water() < 0 && you.get_food() < 0){
                                cout << "OMG ! you are thirsty and hungry !(hp - 30)" << endl;
                                you.changeHealth(30);
                        }
                        if( you.get_health() < 10){
                                cout << "just go to hospital, you are dying ! (maybe your hp is not enough for next day)" << endl;
                        }
                        if( you.get_health() < 30){
                                cout << "you are badly hurt! (go to hospital soon)" << endl;
                        }
                        if( you.get_health() < 60){
                                cout << "you've hurt yourself a little" << endl;
                        }

                        srand(time(0));
                        system("cls");
                        first_look();
                        show(you);
                        last_look();
                        cout << endl;
                        first_look();
                        cout << "1->go to hospital or get some food or drinks.  0->sell or buy some thing" << endl ;
                        cin >> t;
                        last_look();
                        Sleep(2000);
                        system("cls");
                        double money1 = ((rand()%( 2*price_fluctuation) - price_fluctuation)/100.0 + 1.0) * highPrice_highOccupy .getprice();
                        double money2 = ((rand()%( 2*price_fluctuation) - price_fluctuation)/100.0 + 1.0) * highPrice_lowOccupy .getprice();
                        double money3 = ((rand()%( 2*price_fluctuation) - price_fluctuation)/100.0 + 1.0) * lowPrice_highOccupy.getprice();
                        double money4 = ((rand()%( 2*price_fluctuation) - price_fluctuation)/100.0 + 1.0) * lowPrice_lowOccupy.getprice();

                        if( t ){   //hospital and so on
                                first_look();
                                cout << "1 : hospital " << endl << "2 : get some drinks" << endl
                                << "3 : get some food" << endl;
                                cin >> t;
                                system("cls");
                                switch(t){
                                case 1:
                                       go_to_hospital(you);
                                case 2:
                                        go_to_get_some_drinks(you);
                                case 3:
                                        go_to_get_some_food(you);
                                }
                        last_look();
                        }

                        Sleep(2000);
                        system("cls");
                        first_look();
                        cout << "if you want to finish this day, please cin 0, else cin a number that you want to buy(1) or sell(2) : ";
                        int a;
                        cin >> a;
                        while( a ){
                                Sleep(1000);
                                system("cls");
                                if( a == 1){   //buy
                                        cout << "1. highPrice_highOccupy : "
                                        << money1
                                        << "\tcapacity : "
                                        << highPrice_highOccupy.getoccupy() << endl
                                        << "you have : " << you.get_HH() << endl ;

                                        cout << "2.  highPrice_lowOccupy : "
                                        << money2
                                        << "\tcapacity : "
                                        << highPrice_lowOccupy .getoccupy() << endl
                                        << "you have : " << you.get_HL() << endl ;

                                        cout << "3. lowPrice_highOccupy : "
                                        << money3
                                        << "\tcapacity : "
                                        << lowPrice_highOccupy.getoccupy() << endl
                                        << "you have : " << you.get_LH() << endl;

                                        cout << "4. lowPrice_lowOccupy : "
                                        << money4
                                        << "\tcapacity : "
                                        << lowPrice_lowOccupy.getoccupy() << endl
                                        << "you have : " << you.get_LL() << endl;

                                }else if( a == 2){   //sell

                                        cout << "1. highPrice_highOccupy : "
                                        << money1 << "\tlast time money : " << money10 << endl
                                        << "\tcapacity : "
                                        << highPrice_highOccupy.getoccupy() << endl
                                        << "you have : " << you.get_HH() << endl ;

                                        cout << "2.  highPrice_lowOccupy : "
                                        << money2 << "\tlast time money : " << money20 << endl
                                        << "\tcapacity : "
                                        << highPrice_lowOccupy .getoccupy() << endl
                                        << "you have : " << you.get_HL() << endl ;

                                        cout << "3. lowPrice_highOccupy : "
                                        <<money3 << "\tlast time money : " << money30 << endl
                                        << "\tcapacity : "
                                        << lowPrice_highOccupy.getoccupy() << endl
                                        << "you have : " << you.get_LH() << endl;

                                        cout << "4. lowPrice_lowOccupy : "
                                        << money4 << "\tlast time money : " << money40 << endl
                                        << "\tcapacity : "
                                        << lowPrice_lowOccupy.getoccupy() << endl
                                        << "you have : " << you.get_LL() << endl;

                                }
                                Sleep(3000);
                                show( you);
                                int t;
                                cout << "which one you want to buy or sell ?" << endl;
                                cin >> t;   //cin which one you want to buy or sell
                                int temp;
                                cout << "how many do you want to buy or sell ? " << endl;
                                cin >> temp;
                                if(a == 1){   //buy

                                        switch(t){
                                        case 1:   //HH
                                                if_you_can_buy_change_buy(you, money1, temp, highPrice_highOccupy, t);
                                                break;
                                        case 2:   //HL
                                                if_you_can_buy_change_buy(you, money2, temp, highPrice_lowOccupy, t);
                                                break;
                                        case 3:   //LH
                                                if_you_can_buy_change_buy(you, money3, temp, lowPrice_highOccupy, t);
                                                break;
                                        case 4:   //LL
                                                if_you_can_buy_change_buy(you, money4, temp, lowPrice_lowOccupy, t);
                                                break;
                                        }
                                }else if( a == 2){   //sell
                                        switch(t){
                                                case 1:   //HH
                                                        if_you_can_sell_change_sell(you, money1, temp, highPrice_highOccupy, t);
                                                        break;
                                                case 2:   //HL
                                                        if_you_can_sell_change_sell(you, money2, temp, highPrice_lowOccupy, t);
                                                        break;
                                                case 3:   //LH
                                                        if_you_can_sell_change_sell(you, money3, temp, lowPrice_highOccupy, t);
                                                        break;
                                                case 4:   //LL
                                                        if_you_can_sell_change_sell(you, money4, temp, lowPrice_lowOccupy, t);
                                                        break;
                                        }
                                }
                                int change1, change2;
                                change1 = rand()%20-10;
                                change2 = rand()%20-10;
                                you.changeFood(change1);
                                you.changeWater(change2);
                                change1 = rand()%20-10;
                                if(change1 > 15)
                                        change2 = rand()%20-10;
                                else
                                        change2 = 0;
                                you.changeHealth(change2);
                                last_look();
                                system("cls");
                                first_look();
                                show(you);
                                money10 = money1;
                                money20 = money2;
                                money30 = money3;
                                money40 = money4;
                                 cout << "if you want to finish this day , please cin 0, else cin a number that you want to buy(1) or sell(2) : " << endl;
                                 cin >> a;
                        }
                        you.changeDay();
                }
                system("cls");
                if(you.get_health() > 0)
                        cout << "you win ! ";
                else
                        cout << "you lose ! ";

        }
        return 0;
}
bool start(){
        cout << "******************************" << endl;
        cout << "0 out ; 1 start : ";
        int a;
        cin >> a;
        if(a ){
                cout <<endl << "start" << endl
                << "******************************";
                return true;
        }else{
                cout <<endl << "end" << endl
                << "******************************";
                return false;
        }
}
void first_look(){
        cout << "*********************************" << endl ;
        cout << "*\t\t\t\t*" << endl ;
}

void last_look(){
        cout << endl << "*\t\t\t\t*" << endl ;
        cout << "*********************************" << endl ;
}

void show( rich_life &you){
        cout << endl;
        cout << "\t\tDAY : " << you.get_day() << endl;
        cout << "total_water : " << total_water << "   " << "total_food : " << total_food << "   " << "total_health : " << total_health << endl;
        cout << "WareHouse  :  " << you.get_warehouse_now() << " / " << you.get_warehouse_capacity() << endl;
        cout << "your water : " << you.get_water() << "   " << "your food : " << you.get_food() << endl;
        cout << "your health : " << you.get_health() << "   " << "your money : " << you.get_money() << endl;
        cout << "your HH : " << you.get_HH() << "   " << "you HL : " << you.get_HL() << endl;
        cout << "your LH : " << you.get_LH() << "   " << "you LL : " << you.get_LL() << endl << endl << endl;
}

void if_you_can_buy_change_buy( rich_life& you , int money, int temp, commodity& com, int t){
        if(you.get_money() - temp*money >= 0 && you.get_warehouse_now() + temp*com.getoccupy()){       //you can buy
                you.changeMoney( -money * temp);
                you.changeWarehouse( com.getoccupy()*temp);
                switch(t){
                case 1:
                        you.changeHH( temp);
                        break;
                case 2:
                        you.changeHL( temp);
                        break;
                case 3:
                        you.changeLH( temp);
                        break;
                case 4:
                        you.changeLL( temp);
                        break;
                }
        }else{
                cout << "you can't buy, because your money is not enough or your warehouse is not bigger enough. ";
        }
}

void if_you_can_sell_change_sell(rich_life& you, int money, int temp, commodity & com, int t){
        switch(t){
        case 1:
                if( you.get_HH() < temp){   //your com is not enough
                        cout << "Your commodity is not enough.";
                }else{
                        you.changeHH(-temp);
                        you.changeMoney( temp*money);
                        you.changeWarehouse( -com.getoccupy()*temp);
                }
                break;
        case 2:
                if( you.get_HL() < temp){   //your com is not enough
                        cout << "Your commodity is not enough.";
                }else{
                        you.changeHL(-temp);
                        you.changeMoney( temp*money);
                        you.changeWarehouse( -com.getoccupy()*temp);
                }
                break;
        case 3:
                if( you.get_LH() < temp){   //your com is not enough
                        cout << "Your commodity is not enough.";
                }else{
                        you.changeLH(-temp);
                        you.changeMoney( temp*money);
                        you.changeWarehouse( -com.getoccupy()*temp);
                }
                break;
        case 4:
                if( you.get_LL() < temp){   //your com is not enough
                        cout << "Your commodity is not enough.";
                }else{
                        you.changeLL(-temp);
                        you.changeMoney( temp*money);
                        you.changeWarehouse( -com.getoccupy()*temp);
                }
                break;
        }
}
void go_to_hospital(rich_life& you){
        show(you);
        cout << "\t\thospital\t\t"<< endl << endl << endl;
        int t;
        int hp[4];
        int money[4];
        srand(time(0));
        for( t = 0; t < 4; t++){
                hp[t] = 10*(t+1);
                money[t] = 20*(t+1) + rand()%40 - 20;
        }
        printf( "1 : +%d hp , %d rmb\n2 : +%d hp , %d rmb\n3 : +%d hp , %d rmb\n4 : +%d hp , %d rmb\n",
                hp[0], money[0], hp[1], money[1], hp[2], money[2], hp[3], money[3]);
        cout << endl << "which one is your need ? " << endl;
        cin >> t;
                you.changeHealth(hp[t-1]);
                you.changeMoney(-money[t-1]);
                you.changeDay();
}
void go_to_get_some_drinks(rich_life& you){
show(you);
        cout << "\t\tDrinks\t\t"<< endl << endl << endl;
        int t;
        int hp[4];
        int money[4];
        srand(time(0));
        for( t = 0; t < 4; t++){
                hp[t] = 5*(t+1);
                money[t] = 10*(t+1) + rand()%10 - 5;
        }
        printf( "1 : +%d water , %d rmb\n2 : +%d water , %d rmb\n3 : +%d water , %d rmb\n4 : +%d water , %d rmb\n",
                hp[0], money[0], hp[1], money[1], hp[2], money[2], hp[3], money[3]);
        cout << endl << "which one is your need ? " << endl;
        cin >> t;
                you.changeWater(hp[t-1]);
                you.changeMoney(-money[t-1]);
                you.changeDay();
}
void go_to_get_some_food(rich_life & you){
show(you);
        cout << "\t\tFood\t\t"<< endl << endl << endl;
        int t;
        int hp[4];
        int money[4];
        srand(time(0));
        for( t = 0; t < 4; t++){
                hp[t] = 10*(t+1);
                money[t] = 15*(t+1) + rand()%15 - 5;
        }
        printf( "1 : +%d food , %d rmb\n2 : +%d food , %d rmb\n3 : +%d food , %d rmb\n4 : +%d food , %d rmb\n",
                hp[0], money[0], hp[1], money[1], hp[2], money[2], hp[3], money[3]);
        cout << endl << "which one is your need ? " << endl;
        cin >> t;
                you.changeFood(hp[t-1]);
                you.changeMoney(-money[t-1]);
                you.changeDay();
}
//thanks for reading :)
