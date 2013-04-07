/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p snapshotinterface /home/ndr/projects/libsystemd-qt/dbus/introspection/org.freedesktop.systemd1.Snapshot.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef SNAPSHOTINTERFACE_H_1365342324
#define SNAPSHOTINTERFACE_H_1365342324

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generic-types.h"

/*
 * Proxy class for interface org.freedesktop.systemd1.Snapshot
 */
class OrgFreedesktopSystemd1SnapshotInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.systemd1.Snapshot"; }

public:
    OrgFreedesktopSystemd1SnapshotInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopSystemd1SnapshotInterface();

    Q_PROPERTY(bool Cleanup READ cleanup)
    inline bool cleanup() const
    { return qvariant_cast< bool >(property("Cleanup")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Remove()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Remove"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif
