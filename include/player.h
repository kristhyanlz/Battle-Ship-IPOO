#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>

class Player
{
    public:
        Player();
        virtual ~Player();
        void crear(int n);
    protected:
    private:
//        string name;
        int tam, id, **tabla;
        static int sello;
        bool ini;
};

#endif // PLAYER_H
