#ifndef ICONNECTBUTTON_H
#define ICONNECTBUTTON_H

#include <QPushButton>

class IConnectButton {
public:
    virtual void            connectButton(QPushButton *) = 0;
    virtual                 ~IConnectButton() = default;
};




#endif // ICONNECTBUTTON_H
