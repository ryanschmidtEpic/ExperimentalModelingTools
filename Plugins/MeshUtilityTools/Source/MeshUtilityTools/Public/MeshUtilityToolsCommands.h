// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class MESHUTILITYTOOLS_API FMeshUtilityToolsCommands : public TCommands<FMeshUtilityToolsCommands>
{
public:
	FMeshUtilityToolsCommands();

	TSharedPtr<FUICommandInfo> BeginMeshCleanerTool;

	/**
	 * Initialize commands
	 */
	virtual void RegisterCommands() override;
};
