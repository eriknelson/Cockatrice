#ifndef SHORTCUTSSETTINGS_H
#define SHORTCUTSSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QMap>
#include <QKeySequence>

class ShortcutsSettings : public QObject
{
    Q_OBJECT
public:
    ShortcutsSettings(QString settingsFilePath, QObject *parent = 0);
    ~ShortcutsSettings() { }

    QList<QKeySequence> getShortcut(QString name, QList<QKeySequence> defaultShortCut);
    QList<QKeySequence> getShortcut(QString name, QKeySequence defaultShortCut);
    QKeySequence getSingleShortcut(QString name, QKeySequence defaultShortCut);
    QList<QKeySequence> getDefaultShortCut(QString name);

    void setShortcuts(QString name, QList<QKeySequence> secuence);
    void setShortcuts(QString name, QKeySequence secuence);

signals:

public slots:

private:
    QString settingsFilePath;
    QMap<QString,QList<QKeySequence> > shortCuts;
    QMap<QString,QList<QKeySequence> > defaultShortCuts;

    QString stringifySecuence(QList<QKeySequence> secuence) const;
    QList<QKeySequence> parseSecuenceString(QString stringSecuence);
};

#endif // SHORTCUTSSETTINGS_H
