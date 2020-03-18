#include "mainwindow.h"
#include "ui_mainwindow.h"

//This file contains function that connects all ui buttons.
//There's no much i can do against its largeness,
//i mean, i can split this function into many specialized functions "connect "X" Buttons"
//where "X" is unique class where button connections could be, but it would be redundant and readability
//wouldn't be much improved if at all.
//You can forgive me this time i guess :)

void MainWindow::connectAllButtons() {
    keyboard->connectButton(ui->pushButton_1);
    keyboard->connectButton(ui->pushButton_2);
    keyboard->connectButton(ui->pushButton_3);
    keyboard->connectButton(ui->pushButton_4);
    keyboard->connectButton(ui->pushButton_5);
    keyboard->connectButton(ui->pushButton_6);
    keyboard->connectButton(ui->pushButton_7);
    keyboard->connectButton(ui->pushButton_8);
    keyboard->connectButton(ui->pushButton_9);
    keyboard->connectButton(ui->pushButton_10);
    keyboard->connectButton(ui->pushButton_11);
    keyboard->connectButton(ui->pushButton_12);
    keyboard->connectButton(ui->pushButton_13);
    keyboard->connectButton(ui->pushButton_14);
    keyboard->connectButton(ui->pushButton_15);
    keyboard->connectButton(ui->pushButton_16);
    keyboard->connectButton(ui->pushButton_17);
    keyboard->connectButton(ui->pushButton_18);
    keyboard->connectButton(ui->pushButton_19);
    keyboard->connectButton(ui->pushButton_20);
    keyboard->connectButton(ui->pushButton_21);
    keyboard->connectButton(ui->pushButton_22);
    keyboard->connectButton(ui->pushButton_23);
    keyboard->connectButton(ui->pushButton_24);
    keyboard->connectButton(ui->pushButton_25);
    keyboard->connectButton(ui->pushButton_26);
    keyboard->connectButton(ui->pushButton_27);
    keyboard->connectButton(ui->pushButton_28);
    keyboard->connectButton(ui->pushButton_29);
    keyboard->connectButton(ui->pushButton_30);
    keyboard->connectButton(ui->pushButton_31);
    keyboard->connectButton(ui->pushButton_32);
    keyboard->connectButton(ui->pushButton_33);
    keyboard->connectButton(ui->pushButton_34);
    keyboard->connectButton(ui->pushButton_35);
    keyboard->connectButton(ui->pushButton_36);
    keyboard->connectButton(ui->pushButton_37);
    keyboard->connectButton(ui->pushButton_38);
    keyboard->connectButton(ui->pushButton_39);
    keyboard->connectButton(ui->pushButton_40);
    keyboard->connectButton(ui->pushButton_41);
    keyboard->connectButton(ui->pushButton_42);
    keyboard->connectButton(ui->pushButton_43);
    keyboard->connectButton(ui->pushButton_44);
    keyboard->connectButton(ui->pushButton_45);
    keyboard->connectButton(ui->pushButton_46);
    keyboard->connectButton(ui->pushButton_47);
    keyboard->connectButton(ui->pushButton_48);
    keyboard->connectButton(ui->pushButton_49);
    keyboard->connectButton(ui->pushButton_50);
    keyboard->connectButton(ui->pushButton_51);
    keyboard->connectButton(ui->pushButton_52);
    keyboard->connectButton(ui->pushButton_53);
    keyboard->connectButton(ui->pushButton_54);
    keyboard->connectButton(ui->pushButton_55);
    keyboard->connectButton(ui->pushButton_56);
    keyboard->connectButton(ui->pushButton_57);
    keyboard->connectButton(ui->pushButton_58);
    keyboard->connectButton(ui->pushButton_59);
    keyboard->connectButton(ui->pushButton_60);
    keyboard->connectButton(ui->pushButton_61);
    keyboard->connectButton(ui->pushButton_62);
    keyboard->connectButton(ui->pushButton_63);
    keyboard->connectButton(ui->pushButton_65);
    keyboard->connectButton(ui->pushButton_66);
    keyboard->connectButton(ui->pushButton_67);
    keyboard->connectButton(ui->pushButton_68);
    keyboard->connectButton(ui->pushButton_69);
    keyboard->connectButton(ui->pushButton_70);
    keyboard->connectButton(ui->pushButton_72);

    //////////////////////////////
    //Code buttons from Help tab//
    //////////////////////////////

    helpButton->connectButton(ui->pushButton_79);
    helpButton->connectButton(ui->pushButton_81);
    helpButton->connectButton(ui->pushButton_82);
    helpButton->connectButton(ui->pushButton_83);
    helpButton->connectButton(ui->pushButton_84);
    helpButton->connectButton(ui->pushButton_85);
    helpButton->connectButton(ui->pushButton_86);
    helpButton->connectButton(ui->pushButton_87);
    helpButton->connectButton(ui->pushButton_88);
    helpButton->connectButton(ui->pushButton_89);
    helpButton->connectButton(ui->pushButton_90);
    helpButton->connectButton(ui->pushButton_91);
    helpButton->connectButton(ui->pushButton_92);
    helpButton->connectButton(ui->pushButton_93);
    helpButton->connectButton(ui->pushButton_94);
    helpButton->connectButton(ui->pushButton_95);
    helpButton->connectButton(ui->pushButton_96);
    helpButton->connectButton(ui->pushButton_97);
    helpButton->connectButton(ui->pushButton_98);
    helpButton->connectButton(ui->pushButton_99);
    helpButton->connectButton(ui->pushButton_100);
    helpButton->connectButton(ui->pushButton_101);
    helpButton->connectButton(ui->pushButton_102);
    helpButton->connectButton(ui->pushButton_103);
    helpButton->connectButton(ui->pushButton_104);
    helpButton->connectButton(ui->pushButton_105);
    helpButton->connectButton(ui->pushButton_106);
    helpButton->connectButton(ui->pushButton_107);
    helpButton->connectButton(ui->pushButton_108);
    helpButton->connectButton(ui->pushButton_109);
    helpButton->connectButton(ui->pushButton_110);
    helpButton->connectButton(ui->pushButton_111);
    helpButton->connectButton(ui->pushButton_112);
    helpButton->connectButton(ui->pushButton_113);
    helpButton->connectButton(ui->pushButton_114);
    helpButton->connectButton(ui->pushButton_115);
    helpButton->connectButton(ui->pushButton_116);
    helpButton->connectButton(ui->pushButton_117);
    helpButton->connectButton(ui->pushButton_118);
    helpButton->connectButton(ui->pushButton_119);
    helpButton->connectButton(ui->pushButton_120);
    helpButton->connectButton(ui->pushButton_121);
    helpButton->connectButton(ui->pushButton_122);
    helpButton->connectButton(ui->pushButton_123);
    helpButton->connectButton(ui->pushButton_124);
    helpButton->connectButton(ui->pushButton_125);
    helpButton->connectButton(ui->pushButton_126);
    helpButton->connectButton(ui->pushButton_127);
    helpButton->connectButton(ui->pushButton_128);
    helpButton->connectButton(ui->pushButton_129);
    helpButton->connectButton(ui->pushButton_130);
    helpButton->connectButton(ui->pushButton_131);
    helpButton->connectCloseButton(ui->closeButton);
    helpButton->connectCloseButton(ui->closeButton2);

    //////////////////////////////////////////
    //About buttons from Fast Example widget//
    //////////////////////////////////////////

    aboutButton->connectButton(ui->aboutButton_1);
    aboutButton->connectButton(ui->aboutButton_2);
    aboutButton->connectButton(ui->aboutButton_3);
    aboutButton->connectCloseButton(ui->closeAboutButton);
}
