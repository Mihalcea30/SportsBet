
#ifndef OOP_SESSION_H
#define OOP_SESSION_H

#include "Bilet.h"
#include "MakeBilet.h"

///Singleton
class Session {
private:
    Session() = default;
public:
    Session(const Session&) = delete;
    Session& operator=(const Session&) = delete;
    static Session& get_session() {
        static Session sess;
        return sess;
    }
    void MakeSession();
};
#endif //OOP_SESSION_H
