#ifndef NEWPROFILE_H
#define NEWPROFILE_H

#include <QDialog>
#include <QAbstractButton>
#include <QSettings>
#include <QListWidget>
#include <QStyledItemDelegate>

namespace Ui {
class newProfile;
}

class newProfile : public QDialog
{
    Q_OBJECT

public:
    explicit newProfile(QWidget *parent = nullptr);
    ~newProfile();

signals:
    void mousePressEvent(QMouseEvent* event);

private slots:
    void on_saveButton_clicked();
    void on_profileNameEdit_textChanged(const QString &arg1);
    void on_cancelButton_clicked();
    void listProfiles();
    void editEntryName(QListWidgetItem *item);

    void on_addButton_pressed();

    void rightClick(QMouseEvent *event);
private:
    Ui::newProfile *ui;
    QString newProfileName;
};
// New class for editing so we can detect when the editing has finished
class SignalItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    Q_DISABLE_COPY(SignalItemDelegate)
public:
    explicit SignalItemDelegate(QObject* parent = Q_NULLPTR):QStyledItemDelegate(parent){
        QObject::connect(this,&SignalItemDelegate::closeEditor,this,&SignalItemDelegate::editFinished);
    }
    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE {
    void editStarted();
    return QStyledItemDelegate::setEditorData(editor,index);
    }
Q_SIGNALS:
    void editStarted();
    void editFinished();
};
#endif // NEWPROFILE_H