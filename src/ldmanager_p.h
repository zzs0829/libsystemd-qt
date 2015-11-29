/*
 * Copyright (C) 2013  Andrea Scarpino <me@andreascarpino.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef LD_MANAGER_P_H
#define LD_MANAGER_P_H

#include "ldmanagerinterface.h"

#include "ldmanager.h"

namespace Systemd
{
namespace Logind
{
class LogindPrivate : public Notifier
{
    Q_OBJECT

public:
    static const QString LD_DBUS_SERVICE;
    static const QString LD_DBUS_DAEMON_PATH;

    LogindPrivate();
    ~LogindPrivate();
    OrgFreedesktopLogin1ManagerInterface ildface;

    Seat::Ptr getSeat(const QString &id);
    Session::Ptr getSession(const QString &id);
    Session::Ptr getSessionByPID(const uint &pid);
    User::Ptr getUser(const uint &id);
    User::Ptr getUserByPID(const uint &pid);
    Permission canHibernate();
    Permission canHybridSleep();
    Permission canPowerOff();
    Permission canReboot();
    Permission canSuspend();
    void hibernate(const bool interactive);
    void hybridSleep(const bool interactive);
    QList<LoginInhibitor> listInhibitors();
    QList<Seat::Ptr> listSeats();
    QList<Session::Ptr> listSessions();
    QList<User::Ptr> listUsers();
    void powerOff(const bool interactive);
    void reboot(const bool interactive);
    void suspend(const bool interactive);

protected Q_SLOTS:
    void onPrepareForShutdown(const bool active);
    void onPrepareForSleep(const bool active);
    void onSeatNew(const QString &id, const QDBusObjectPath &seat);
    void onSeatRemoved(const QString &id, const QDBusObjectPath &seat);
    void onSessionNew(const QString &id, const QDBusObjectPath &session);
    void onSessionRemoved(const QString &id, const QDBusObjectPath &session);
    void onUserNew(const uint &id, const QDBusObjectPath &user);
    void onUserRemoved(const uint &id, const QDBusObjectPath &user);

private:
    Permission stringToPermission(const QString &permission) const;
    void init();
};
}
}

#endif
