#pragma once

#include "albert/extension/queryhandler/globalqueryhandler.h"
#include "albert/plugin.h"

class Plugin : public albert::plugin::ExtensionPlugin<albert::TriggerQueryHandler> {
Q_OBJECT ALBERT_PLUGIN

public:
    void handleTriggerQuery(TriggerQuery*) const override;
};