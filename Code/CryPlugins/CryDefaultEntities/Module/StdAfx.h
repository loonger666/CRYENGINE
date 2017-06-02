// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#define eCryModule eCryM_EnginePlugin

#include <CryCore/Platform/platform.h>

#include <CryEntitySystem/IEntitySystem.h>

#include <CrySchematyc/CoreAPI.h>

#include "PluginDll.h"

template<class T>
static IEntityClass* RegisterEntityWithDefaultComponent(const char* name, const char* editorCategory = "", const char* editorIcon = "", bool bIconOnTop = false)
{
	IEntityClassRegistry::SEntityClassDesc clsDesc;
	clsDesc.sName = name;

	clsDesc.editorClassInfo.sCategory = editorCategory;
	clsDesc.editorClassInfo.sIcon = editorIcon;
	clsDesc.editorClassInfo.bIconOnTop = bIconOnTop;

	struct CObjectCreator
	{
		static IEntityComponent* Create(IEntity* pEntity, SEntitySpawnParams& params, void* pUserData)
		{
			return pEntity->CreateComponentClass<T>();
		}
	};

	clsDesc.pUserProxyCreateFunc = &CObjectCreator::Create;

	return gEnv->pEntitySystem->GetClassRegistry()->RegisterStdClass(clsDesc);
}