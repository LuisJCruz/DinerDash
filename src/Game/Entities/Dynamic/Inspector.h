#include "Client.h"

class Inspector : public Client{
    public:
        Inspector(int, int, int, int, ofImage, Burger*, int*);
        bool isInspector() {return true;}
        void tick();
        int *money;
};