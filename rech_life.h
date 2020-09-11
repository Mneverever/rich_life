#ifndef RICH_LIFE_H
#define RICH_LIFE_H
class rich_life{
        public:
                rich_life();
                int get_food();
                int get_water();
                int get_health();
                double get_money();
                int get_warehouse_now();
                int get_warehouse_capacity();
                int get_HH();
                int get_HL();
                int get_LH();
                int get_LL();
                void changeHH(int );
                void changeHL(int );
                void changeLH(int );
                void changeLL(int );
                void changeWater(int);
                void changeFood(int);
                void changeHealth(int);
                void changeMoney(double);
                void changeWarehouse(int );
                int get_day();
                void changeDay();
        private:
                friend class commodity;
                int day;
                int food, water, health;
                double money;
                int HH, HL, LL, LH; //highPrice_HighOccupy, ...
                int warehouse[2];   //0 now  1 capacity
};

#endif // RICH_LIFE_H
