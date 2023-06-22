#ifndef MESSENGER_H
#define MESSENGER_H

#include <iostream>

class Messenger
{
    public:
        static void print(const char *m)
        {
            std::cout << m << std::endl;
        }
    protected:

    private:
        Messenger();
};

#endif // MESSENGER_H
