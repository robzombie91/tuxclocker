#ifndef AMDPSTATEEDITOR_H
#define AMDPSTATEEDITOR_H

#include <QDialog>
#include <QWidget>
#include <QSlider>
#include <QHBoxLayout>
#include "gputypes.h"

namespace Ui {
class amdPstateEditor;
}

class amdPstateEditor : public QDialog
{
    Q_OBJECT

public:
    explicit amdPstateEditor(QWidget *parent = nullptr);
    ~amdPstateEditor();

private:
    Ui::amdPstateEditor *ui;
    void generateUI();
};

#endif // AMDPSTATEEDITOR_H