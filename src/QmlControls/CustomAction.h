/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "MAVLinkLib.h"

#include <QtCore/QObject>

class Vehicle;

class CustomAction: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString label        READ label          CONSTANT)
    Q_PROPERTY(QString description  READ description    CONSTANT)

public:
    CustomAction() { CustomAction(QString(), QString(), MAV_CMD(0), MAV_COMPONENT(0), 0, 0, 0, 0, 0, 0, 0); } // this is required for QML reflection
    CustomAction(
            QString         label,
            QString         description,
            MAV_CMD         mavCmd,
            MAV_COMPONENT   compId,
            float           param1,
            float           param2,
            float           param3,
            float           param4,
            float           param5,
            float           param6,
            float           param7,
            QObject*        parent = nullptr)
        : QObject       (parent)
        , _label        (label)
        , _description  (description)
        , _mavCmd       (mavCmd)
        , _compId       (compId)
        , _params       { param1, param2, param3, param4, param5, param6, param7 }
    {};

    Q_INVOKABLE void sendTo(Vehicle* vehicle);

    QString  label      () const { return _label; }
    QString  description() const { return _description; }

private:
    QString         _label;
    QString         _description;
    MAV_CMD         _mavCmd;
    MAV_COMPONENT   _compId;
    float           _params[7];
};
