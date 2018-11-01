// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once
#include "IPlugin.h"
#include <libintl.h>

class CDialogEditorPlugin : public IPlugin
{
public:
	CDialogEditorPlugin() 
	{
		InitialTranslator("DialogEditor");
	}
	~CDialogEditorPlugin() { /* exit point of the plugin, perform cleanup */ }

	int32       GetPluginVersion() { return 1; };
	const char* GetPluginName() { return "DialogEditor Plugin"; };
	const char* GetPluginDescription() { return "Plugin used as a code sample to demonstrate Sandbox's plugin system"; };

private:
};
