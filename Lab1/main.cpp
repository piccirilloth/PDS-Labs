#include "Message.h"
#include "DurationLogger.h"
#include "MessageStore.h"

long Message::id_s = 0;

int main() {
    /*Message msg[10], msg1[10];

    for(int i=0; i<10; i++)
    {
        msg[i].setData(1000000);
    }

    DurationLogger *d = new DurationLogger("copy");
    //copia
    for(int i=0; i<10; i++)
    {
        msg1[i] = msg[i];
    }
    delete d;

    DurationLogger *p = new DurationLogger("move");
    //move
    for(int i=0; i<10; i++)
    {
        msg1[i] = std::move(msg[i]);
    }
    delete p;*/
    MessageStore ms(10);
    for(int i=0; i<100; i++) {
        std::cout << "CONSTRUCTION N " << i << '\n';
        Message *m = new Message(1000000);
        ms.add(*m);
        delete m;
    }
    std::cout << "PRINCIPAL\n";
    ms.printMessages();

    for(int i=0; i<50; i++)
    {
        std::cout << "REMOVING " << i+1 << '\n';
        ms.remove(i);
    }
    std::cout << "REMOVED \n";
    ms.printMessages();

    ms.compact();
    std::cout << "COMPACT \n";
    ms.printMessages();

    return 0;
}
