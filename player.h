#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();
        void crear(int n);
    protected:
    private:
        int tam, id, **tabla;
        static int sello;
        bool ini;
};

#endif // PLAYER_H
