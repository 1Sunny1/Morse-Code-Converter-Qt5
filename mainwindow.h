#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unordered_map>
#include <string>
#include <QString>
#include <QChar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    std::unordered_map<char, QString> morseCodes {
    { ':', "___..." }, { '8', "___.."   },
    { '0', "_____"  }, { 'Q', "__._"    },
    { 'A', "._"     }, { 'D', "_.."     },
    { 'O', "___"    }, { '_', "..__._"  },
    { 'N', "_."     }, { 'R', "._."     },
    { 'B', "_..."   }, { 'E', "."       },
    { 'S', "..."    }, { 'C', "_._."    },
    { '/', "_.._."  }, { 'P', ".__."    },
    { '(', "_.__."  }, { 'F', ".._."    },
    { 'G', "__."    }, { '.', "._._._"  },
    { 'T', "_"      }, { ')', "_.__._"  },
    { 'H', "...."   }, { 'Y', "_.__"    },
    { 'U', ".._"    }, { '9', "____."   },
    { 'K', "_._"    }, { 'I', ".."      },
    { 'V', "..._"   }, { 'J', ".___"    },
    { '"', "._.._." }, { '7', "__..."   },
    { 'X', "_.._"   }, { 'W', ".__"     },
    { '6', "_...."  }, { 'L', "._.."    },
    { '?', "..__.." }, { 'M', "__"      },
    { '-', "_...._" }, { 'Z', "__.."    },
    { '1', ".____"  }, { '2', "..___"   },
    { '!', "_._.__" }, { '3', "...__"   },
    { '@', ".__._." }, { '4', "...._"   },
    { '5', "....."  }, { '=', "_..._"   },
    { ',', "__..__" }, { '\'', ".____." },
    { '+', "._._."  }, { ';', "_._._."  } };

};
#endif // MAINWINDOW_H
