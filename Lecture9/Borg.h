// Contract

#ifndef BORG_H
#define BORG_H

class Borg {
    public:
        Borg(int ordinalIn);
        void attack();
        void stateName();
        // static void stateBorgCount(); 

    private:
        int ordinal;
        static int borgCount;
};

#endif